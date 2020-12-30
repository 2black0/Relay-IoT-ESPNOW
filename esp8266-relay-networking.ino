#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPDash.h>
#include <Effortless_SPIFFS.h>
#include "variable.h"
#include <espnow.h>

void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  char macStr[18];
  Serial.print("Packet to:");
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status: ");
  if (sendStatus == 0) {
    Serial.println("Delivery success");
  }
  else {
    Serial.println("Delivery fail");
  }
}

void connect_wifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    return;
  }
  Serial.println(" ");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void write_data() {
  Serial.println("Write Data");
  String y;
  int x;

  for (int a = 0; a < 2; a++) {
    for (int i = 0; i < 16; i++) {
      if (a < 1) {
        if (i < 8) {
          y = "/a" + String(int(i + 1)) + "on" + ".txt";
        } else {
          y = "/a" + String(int(i - 7)) + "off" + ".txt";
        }
      } else {
        if (i < 8) {
          y = "/b" + String(int(i + 1)) + "on" + ".txt";
        } else {
          y = "/b" + String(int(i - 7)) + "off" + ".txt";
        }
      }

      int str_len = y.length() + 1;
      char z[str_len];
      y.toCharArray(z, str_len);

      if (a < 1) {
        x = ta[i];
      } else {
        x = tb[i];
      }

      Serial.print("Save ");
      Serial.print(x);
      Serial.print(" Second to ");
      Serial.println(y);
      fileSystem.saveToFile(z, x);
    }
  }
}

void read_data() {
  Serial.println("Read Data");
  String y;
  int x;

  for (int a = 0; a < 2; a++) {
    for (int i = 0; i < 16; i++) {
      if (a < 1) {
        if (i < 8) {
          y = "/a" + String(int(i + 1)) + "on" + ".txt";
        } else {
          y = "/a" + String(int(i - 7)) + "off" + ".txt";
        }
      } else {
        if (i < 8) {
          y = "/b" + String(int(i + 1)) + "on" + ".txt";
        } else {
          y = "/b" + String(int(i - 7)) + "off" + ".txt";
        }
      }

      int str_len = y.length() + 1;
      char z[str_len];
      y.toCharArray(z, str_len);

      //Serial.println(y);
      fileSystem.openFromFile(z, x);

      if (a < 1) {
        ta[i] = x;
        txa[i] = x;
      } else {
        tb[i] = x;
        txb[i] = x;
      }

      Serial.print(z);
      Serial.print(" : ");
      Serial.print(x);
      Serial.println(" Second");
    }
  }
}

void update_dash() {
  slidera1on.update(ta[0]);
  slidera2on.update(ta[1]);
  slidera3on.update(ta[2]);
  slidera4on.update(ta[3]);
  slidera5on.update(ta[4]);
  slidera6on.update(ta[5]);
  slidera7on.update(ta[6]);
  slidera8on.update(ta[7]);
  slidera1off.update(ta[8]);
  slidera2off.update(ta[9]);
  slidera3off.update(ta[10]);
  slidera4off.update(ta[11]);
  slidera5off.update(ta[12]);
  slidera6off.update(ta[13]);
  slidera7off.update(ta[14]);
  slidera8off.update(ta[15]);

  sliderb1on.update(tb[0]);
  sliderb2on.update(tb[1]);
  sliderb3on.update(tb[2]);
  sliderb4on.update(tb[3]);
  sliderb5on.update(tb[4]);
  sliderb6on.update(tb[5]);
  sliderb7on.update(tb[6]);
  sliderb8on.update(tb[7]);
  sliderb1off.update(tb[8]);
  sliderb2off.update(tb[9]);
  sliderb3off.update(tb[10]);
  sliderb4off.update(tb[11]);
  sliderb5off.update(tb[12]);
  sliderb6off.update(tb[13]);
  sliderb7off.update(tb[14]);
  sliderb8off.update(tb[15]);
}

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  delay(500);
  eSPIFFS fileSystem(&Serial);

  Serial.println(" ");
  //write_data();
  read_data();

  swStatus = digitalRead(swPin);
  if (swStatus) {
    Serial.println("\nNormal Mode");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    if (esp_now_init() != 0) {
      Serial.println("Error initializing ESP-NOW");
      return;
    }
    esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
    esp_now_register_send_cb(OnDataSent);
    esp_now_add_peer(broadcastAddress1, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
    esp_now_add_peer(broadcastAddress2, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  } else {
    Serial.println("\nMaintenance Mode");
    connect_wifi();
    prepare_slider();
    server.begin();
    update_dash();
    dashboard.sendUpdates();
  }
}

void loop() {
  if (swStatus) {
    if ((millis() - lastTime) > timerDelay) {
      for (int i = 0; i < 8; i++) {
        //Serial.println("i:" + String(i));
        if (ta[i] > 0) {
          ra[i] = 0;
          ta[i] = ta[i] - 1;
          //Serial.println("ta["+ String(i) + "]:" + String(ta[i]));
          if (ta[i] == 0) {
            ta[8 + i] = txa[8 + i];
          }
        } else {
          ra[i] = 1;
          ta[8 + i] = ta[8 + i] - 1;
          //Serial.println("ta["+ String(8+i) + "]:" + String(ta[8+i]));
          if (ta[8 + i] == 0) {
            ta[i] = txa[i];
          }
        }
        //Serial.println("ra["+ String(i) + "]:" + String(ra[i]));
      }

      for (int i = 0; i < 8; i++) {
        //Serial.println("i:" + String(i));
        if (tb[i] > 0) {
          rb[i] = 0;
          tb[i] = tb[i] - 1;
          //Serial.println("tb["+ String(i) + "]:" + String(tb[i]));
          if (tb[i] == 0) {
            tb[8 + i] = txb[8 + i];
          }
        } else {
          rb[i] = 1;
          tb[8 + i] = tb[8 + i] - 1;
          //Serial.println("ta["+ String(8+i) + "]:" + String(tb[8+i]));
          if (tb[8 + i] == 0) {
            tb[i] = txb[i];
          }
        }
        //Serial.println("rb["+ String(i) + "]:" + String(rb[i]));
      }

      set_relay(ra[0], ra[1], ra[2], ra[3], ra[4], ra[5], ra[6], ra[7]);
      esp_now_send(broadcastAddress1, (uint8_t *) &test, sizeof(test));

      set_relay(rb[0], rb[1], rb[2], rb[3], rb[4], rb[5], rb[6], rb[7]);
      esp_now_send(broadcastAddress2, (uint8_t *) &test, sizeof(test));

      lastTime = millis();
    }
  } else {
    if ((millis() - lastTime) > timerDelays) {
      lastTime = millis();
    }
  }
}

void set_relay(bool re1, bool re2, bool re3, bool re4, bool re5, bool re6, bool re7, bool re8) {
  test.re1 = re1;
  test.re2 = re2;
  test.re3 = re3;
  test.re4 = re4;
  test.re5 = re5;
  test.re6 = re6;
  test.re7 = re7;
  test.re8 = re8;
}
