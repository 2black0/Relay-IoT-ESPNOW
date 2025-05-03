#include <ESP8266WiFi.h>
#include <espnow.h>

const int r1 = 16;
const int r2 = 14;
const int r3 = 12;
const int r4 = 13;
const int r5 = 2;
const int r6 = 0;
const int r7 = 4;
const int r8 = 5;

typedef struct test_struct {
  bool re1;
  bool re2;
  bool re3;
  bool re4;
  bool re5;
  bool re6;
  bool re7;
  bool re8;
} test_struct;

test_struct myData;

void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));

  digitalWrite(r1, myData.re1);
  digitalWrite(r2, myData.re2);
  digitalWrite(r3, myData.re3);
  digitalWrite(r4, myData.re4);
  digitalWrite(r5, myData.re5);
  digitalWrite(r6, myData.re6);
  digitalWrite(r7, myData.re7);
  digitalWrite(r8, myData.re8);
  
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("relay 1: ");
  Serial.println(myData.re1);
  Serial.print("relay 2: ");
  Serial.println(myData.re2);
  Serial.print("relay 3: ");
  Serial.println(myData.re3);
  Serial.print("relay 4: ");
  Serial.println(myData.re4);
  Serial.print("relay 5: ");
  Serial.println(myData.re5);
  Serial.print("relay 6: ");
  Serial.println(myData.re6);
  Serial.print("relay 7: ");
  Serial.println(myData.re7);
  Serial.print("relay 8: ");
  Serial.println(myData.re8);
  Serial.println();
}

void pin_setup(){
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(r6, OUTPUT);
  pinMode(r7, OUTPUT);
  pinMode(r8, OUTPUT);
}

void init_pin(){
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  digitalWrite(r5, HIGH);
  digitalWrite(r6, HIGH);
  digitalWrite(r7, HIGH);
  digitalWrite(r8, HIGH);
}
 
void setup() {
  Serial.begin(115200);
  pin_setup();
  init_pin();
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}