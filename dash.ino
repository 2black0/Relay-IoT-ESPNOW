void prepare_slider() {
  slidera1on.attachCallback([&](int value) {
    Serial.println("Slider Relay A1 ON Triggered: " + String(value));
    slidera1on.update(value);
    fileSystem.saveToFile("/a1on.txt", value);
    dashboard.sendUpdates();
  });

  slidera1off.attachCallback([&](int value) {
    Serial.println("Slider Relay A1 OFF Triggered: " + String(value));
    slidera1off.update(value);
    fileSystem.saveToFile("/a1off.txt", value);
    dashboard.sendUpdates();
  });

  slidera2on.attachCallback([&](int value) {
    Serial.println("Slider Relay A2 ON Triggered: " + String(value));
    slidera2on.update(value);
    fileSystem.saveToFile("/a2on.txt", value);
    dashboard.sendUpdates();
  });

  slidera2off.attachCallback([&](int value) {
    Serial.println("Slider Relay A2 OFF Triggered: " + String(value));
    slidera2off.update(value);
    fileSystem.saveToFile("/a2off.txt", value);
    dashboard.sendUpdates();
  });

  slidera3on.attachCallback([&](int value) {
    Serial.println("Slider Relay A3 ON Triggered: " + String(value));
    slidera3on.update(value);
    fileSystem.saveToFile("/a3on.txt", value);
    dashboard.sendUpdates();
  });

  slidera3off.attachCallback([&](int value) {
    Serial.println("Slider Relay A3 OFF Triggered: " + String(value));
    slidera3off.update(value);
    fileSystem.saveToFile("/a3off.txt", value);
    dashboard.sendUpdates();
  });

  slidera4on.attachCallback([&](int value) {
    Serial.println("Slider Relay A4 ON Triggered: " + String(value));
    slidera4on.update(value);
    fileSystem.saveToFile("/a4on.txt", value);
    dashboard.sendUpdates();
  });

  slidera4off.attachCallback([&](int value) {
    Serial.println("Slider Relay A4 OFF Triggered: " + String(value));
    slidera4off.update(value);
    fileSystem.saveToFile("/a4off.txt", value);
    dashboard.sendUpdates();
  });

  slidera5on.attachCallback([&](int value) {
    Serial.println("Slider Relay A5 ON Triggered: " + String(value));
    slidera5on.update(value);
    fileSystem.saveToFile("/a5on.txt", value);
    dashboard.sendUpdates();
  });

  slidera5off.attachCallback([&](int value) {
    Serial.println("Slider Relay A5 OFF Triggered: " + String(value));
    slidera5off.update(value);
    fileSystem.saveToFile("/a5off.txt", value);
    dashboard.sendUpdates();
  });

  slidera6on.attachCallback([&](int value) {
    Serial.println("Slider Relay A6 ON Triggered: " + String(value));
    slidera6on.update(value);
    fileSystem.saveToFile("/a6on.txt", value);
    dashboard.sendUpdates();
  });

  slidera6off.attachCallback([&](int value) {
    Serial.println("Slider Relay A6 OFF Triggered: " + String(value));
    slidera6off.update(value);
    fileSystem.saveToFile("/a6off.txt", value);
    dashboard.sendUpdates();
  });

  slidera7on.attachCallback([&](int value) {
    Serial.println("Slider Relay A7 ON Triggered: " + String(value));
    slidera7on.update(value);
    fileSystem.saveToFile("/a7on.txt", value);
    dashboard.sendUpdates();
  });

  slidera7off.attachCallback([&](int value) {
    Serial.println("Slider Relay A7 OFF Triggered: " + String(value));
    slidera7off.update(value);
    fileSystem.saveToFile("/a7off.txt", value);
    dashboard.sendUpdates();
  });

  slidera8on.attachCallback([&](int value) {
    Serial.println("Slider Relay A8 ON Triggered: " + String(value));
    slidera8on.update(value);
    fileSystem.saveToFile("/a8on.txt", value);
    dashboard.sendUpdates();
  });

  slidera8off.attachCallback([&](int value) {
    Serial.println("Slider Relay A8 OFF Triggered: " + String(value));
    slidera8off.update(value);
    fileSystem.saveToFile("/a8off.txt", value);
    dashboard.sendUpdates();
  });

  sliderb1on.attachCallback([&](int value) {
    Serial.println("Slider Relay B1 ON Triggered: " + String(value));
    sliderb1on.update(value);
    fileSystem.saveToFile("/b1on.txt", value);
    dashboard.sendUpdates();
  });

  sliderb1off.attachCallback([&](int value) {
    Serial.println("Slider Relay B1 OFF Triggered: " + String(value));
    sliderb1off.update(value);
    fileSystem.saveToFile("/b1off.txt", value);
    dashboard.sendUpdates();
  });

  sliderb2on.attachCallback([&](int value) {
    Serial.println("Slider Relay B2 ON Triggered: " + String(value));
    sliderb2on.update(value);
    fileSystem.saveToFile("/b2on.txt", value);
    dashboard.sendUpdates();
  });

  sliderb2off.attachCallback([&](int value) {
    Serial.println("Slider Relay B2 OFF Triggered: " + String(value));
    sliderb2off.update(value);
    fileSystem.saveToFile("/b2off.txt", value);
    dashboard.sendUpdates();
  });

  sliderb3on.attachCallback([&](int value) {
    Serial.println("Slider Relay B3 ON Triggered: " + String(value));
    sliderb3on.update(value);
    fileSystem.saveToFile("/b3on.txt", value);
    dashboard.sendUpdates();
  });

  sliderb3off.attachCallback([&](int value) {
    Serial.println("Slider Relay B3 OFF Triggered: " + String(value));
    sliderb3off.update(value);
    fileSystem.saveToFile("/b3off.txt", value);
    dashboard.sendUpdates();
  });

  sliderb4on.attachCallback([&](int value) {
    Serial.println("Slider Relay B4 ON Triggered: " + String(value));
    sliderb4on.update(value);
    fileSystem.saveToFile("/b4on.txt", value);
    dashboard.sendUpdates();
  });

  sliderb4off.attachCallback([&](int value) {
    Serial.println("Slider Relay B4 OFF Triggered: " + String(value));
    sliderb4off.update(value);
    fileSystem.saveToFile("/b4off.txt", value);
    dashboard.sendUpdates();
  });

  sliderb5on.attachCallback([&](int value) {
    Serial.println("Slider Relay B5 ON Triggered: " + String(value));
    sliderb5on.update(value);
    fileSystem.saveToFile("/b5on.txt", value);
    dashboard.sendUpdates();
  });

  sliderb5off.attachCallback([&](int value) {
    Serial.println("Slider Relay B5 OFF Triggered: " + String(value));
    sliderb5off.update(value);
    fileSystem.saveToFile("/b5off.txt", value);
    dashboard.sendUpdates();
  });

  sliderb6on.attachCallback([&](int value) {
    Serial.println("Slider Relay B6 ON Triggered: " + String(value));
    sliderb6on.update(value);
    fileSystem.saveToFile("/b6on.txt", value);
    dashboard.sendUpdates();
  });

  sliderb6off.attachCallback([&](int value) {
    Serial.println("Slider Relay B6 OFF Triggered: " + String(value));
    sliderb6off.update(value);
    fileSystem.saveToFile("/b6off.txt", value);
    dashboard.sendUpdates();
  });

  sliderb7on.attachCallback([&](int value) {
    Serial.println("Slider Relay B7 ON Triggered: " + String(value));
    sliderb7on.update(value);
    fileSystem.saveToFile("/b7on.txt", value);
    dashboard.sendUpdates();
  });

  sliderb7off.attachCallback([&](int value) {
    Serial.println("Slider Relay B7 OFF Triggered: " + String(value));
    sliderb7off.update(value);
    fileSystem.saveToFile("/b7off.txt", value);
    dashboard.sendUpdates();
  });

  sliderb8on.attachCallback([&](int value) {
    Serial.println("Slider Relay B8 ON Triggered: " + String(value));
    sliderb8on.update(value);
    fileSystem.saveToFile("/b8on.txt", value);
    dashboard.sendUpdates();
  });

  sliderb8off.attachCallback([&](int value) {
    Serial.println("Slider Relay B8 OFF Triggered: " + String(value));
    sliderb8off.update(value);
    fileSystem.saveToFile("/b8off.txt", value);
    dashboard.sendUpdates();
  });
}
