const char* ssid = "Wifi-Roboto";
const char* password = "arDY1234";

bool swStatus = 0;
const int swPin = 5;

int ta[16];
int tb[16];
int txa[16];
int txb[16];
bool ra[8];
bool rb[8];
char filea[16];
char fileb[16];
String filex;

uint8_t broadcastAddress1[] = {0x2C, 0xF4, 0x32, 0x14, 0xFB, 0x6A};
uint8_t broadcastAddress2[] = {0x84, 0xCC, 0xA8, 0x82, 0xF5, 0x95};

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

test_struct test;
test_struct test2;

unsigned long lastTime = 0;
unsigned long timerDelay = 1000;
unsigned long timerDelays = 10000;

AsyncWebServer server(80);
ESPDash dashboard(&server);
eSPIFFS fileSystem;

Card slidera1on(&dashboard, SLIDER_CARD, "Relay A1 ON", "", 1, 60);
Card slidera1off(&dashboard, SLIDER_CARD, "Relay A1 OFF", "", 1, 60);
Card slidera2on(&dashboard, SLIDER_CARD, "Relay A2 ON", "", 1, 60);
Card slidera2off(&dashboard, SLIDER_CARD, "Relay A2 OFF", "", 1, 60);
Card slidera3on(&dashboard, SLIDER_CARD, "Relay A3 ON", "", 1, 60);
Card slidera3off(&dashboard, SLIDER_CARD, "Relay A3 OFF", "", 1, 60);
Card slidera4on(&dashboard, SLIDER_CARD, "Relay A4 ON", "", 1, 60);
Card slidera4off(&dashboard, SLIDER_CARD, "Relay A4 OFF", "", 1, 60);
Card slidera5on(&dashboard, SLIDER_CARD, "Relay A5 ON", "", 1, 60);
Card slidera5off(&dashboard, SLIDER_CARD, "Relay A5 OFF", "", 1, 60);
Card slidera6on(&dashboard, SLIDER_CARD, "Relay A6 ON", "", 1, 60);
Card slidera6off(&dashboard, SLIDER_CARD, "Relay A6 OFF", "", 1, 60);
Card slidera7on(&dashboard, SLIDER_CARD, "Relay A7 ON", "", 1, 60);
Card slidera7off(&dashboard, SLIDER_CARD, "Relay A7 OFF", "", 1, 60);
Card slidera8on(&dashboard, SLIDER_CARD, "Relay A8 ON", "", 1, 60);
Card slidera8off(&dashboard, SLIDER_CARD, "Relay A8 OFF", "", 1, 60);

Card sliderb1on(&dashboard, SLIDER_CARD, "Relay B1 ON", "", 1, 60);
Card sliderb1off(&dashboard, SLIDER_CARD, "Relay B1 OFF", "", 1, 60);
Card sliderb2on(&dashboard, SLIDER_CARD, "Relay B2 ON", "", 1, 60);
Card sliderb2off(&dashboard, SLIDER_CARD, "Relay B2 OFF", "", 1, 60);
Card sliderb3on(&dashboard, SLIDER_CARD, "Relay B3 ON", "", 1, 60);
Card sliderb3off(&dashboard, SLIDER_CARD, "Relay B3 OFF", "", 1, 60);
Card sliderb4on(&dashboard, SLIDER_CARD, "Relay B4 ON", "", 1, 60);
Card sliderb4off(&dashboard, SLIDER_CARD, "Relay B4 OFF", "", 1, 60);
Card sliderb5on(&dashboard, SLIDER_CARD, "Relay B5 ON", "", 1, 60);
Card sliderb5off(&dashboard, SLIDER_CARD, "Relay B5 OFF", "", 1, 60);
Card sliderb6on(&dashboard, SLIDER_CARD, "Relay B6 ON", "", 1, 60);
Card sliderb6off(&dashboard, SLIDER_CARD, "Relay B6 OFF", "", 1, 60);
Card sliderb7on(&dashboard, SLIDER_CARD, "Relay B7 ON", "", 1, 60);
Card sliderb7off(&dashboard, SLIDER_CARD, "Relay B7 OFF", "", 1, 60);
Card sliderb8on(&dashboard, SLIDER_CARD, "Relay B8 ON", "", 1, 60);
Card sliderb8off(&dashboard, SLIDER_CARD, "Relay B8 OFF", "", 1, 60);
