# 🔌 ESP8266 Wireless Relay Control System with Dashboard & ESP-NOW

This project provides a complete **wireless relay control system** using multiple ESP8266 boards. It features a real-time web-based dashboard using **[ESPDash](https://github.com/ayushsharma82/ESP-DASH)** and fast peer-to-peer communication using **ESP-NOW** protocol.

---

## 🧱 Project Structure

```

.
├── LICENSE
├── Project
│   ├── master
│   │   ├── dash.ino
│   │   ├── esp8266-relay-networking.ino
│   │   └── variable.h
│   └── slave
│       └── relay-client-esp8266-espnow.ino
└── README.md

```

---

## 🧠 System Overview

- **Master (Dashboard - Node A)**:  
  Hosts a web interface using ESPDash. Sends real-time relay control commands over ESP-NOW.

- **Slave (Relay Client - Node B)**:  
  Listens via ESP-NOW. Receives data and updates 8 relay pins based on struct-based commands.

- **Communication**:  
  Uses **ESP-NOW** for low-latency, Wi-Fi-less communication.

---

## 📋 Features

✅ Control up to 8 relays per ESP8266 slave node  
✅ Add more slaves with unique MAC addresses  
✅ Web dashboard for interactive control (sliders/buttons)  
✅ Real-time relay status sync  
✅ Designed for reliability and expandability

---

## ⚙️ Requirements

Install these libraries via Arduino Library Manager or manually:
- **ESPAsyncWebServer**
- **AsyncTCP**
- **ESPDash**
- **ESP-NOW (built into ESP8266 core)**

---

## 🚀 Getting Started

### 🔧 1. Set Up the Dashboard Node (Master)
- Open `Project/master/dash.ino`
- Update:
  ```cpp
  const char* ssid = "YourSSID";
  const char* password = "YourPassword";
  uint8_t broadcastAddress[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX}; // Node B MAC
  ```

* Flash to an ESP8266 device. Access the IP address in browser to control relays.

### 🔧 2. Set Up the Relay Node (Slave)

* Open `Project/slave/relay-client-esp8266-espnow.ino`
* Flash to the second ESP8266 (relay board)
* Relays will auto-update based on dashboard control

---

## 📝 Shared Data Structure

Defined in `variable.h` and used by both master and slave:

```cpp
typedef struct test_struct {
  bool re1, re2, re3, re4, re5, re6, re7, re8;
} test_struct;
```

---

## 💡 Example Use-Cases

* Smart home lighting and device automation
* Lab experiment toggling (lights, pumps, etc.)
* Wireless switchboard or classroom demo kits

---

## 🧾 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙌 Credits

Created and maintained by **[2black0](mailto:2black0@gmail.com)**
Built with ❤️ using [ESP-DASH](https://github.com/ayushsharma82/ESP-DASH) and [ESP-NOW](https://espressif-docs.readthedocs-hosted.com/projects/esp-now)

---

> Ready to flash your relays and go wireless? Clone, modify, and expand!