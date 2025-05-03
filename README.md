# 🔌 ESP8266 Relay Control System with Dashboard Interface

This project demonstrates a robust and scalable wireless relay control system using multiple ESP8266 boards. It includes an interactive web dashboard powered by **[ESPDash](https://github.com/ayushsharma82/ESP-DASH)** to monitor and control up to 16 relay outputs (8 from each board), with networking support between Node A and Node B via ESP-NOW protocol.

---

## 📁 Project Structure

```
.
├── LICENSE
├── README.md
└── Project
    ├── dash.ino                    # Web dashboard interface with ESPDash
    ├── esp8266-relay-networking.ino # Relay controller with ESP-NOW communication
    └── variable.h                  # Shared configurations, structure definitions, and UI widgets
```

---

## 🎯 Features

✅ Control up to 16 relay channels (8 from each board)
✅ Web-based control panel with **sliders** for intuitive interaction
✅ Wireless communication between two ESP8266 boards using **ESP-NOW**
✅ Real-time status updates and relay toggling
✅ Support for **asynchronous web server** and **SPIFFS** for efficient UI handling

---

## 🧠 Architecture Overview

* **Node A (Web Dashboard)**: Hosts the ESPDash-based UI and sends commands to Node B via ESP-NOW.
* **Node B (Relay Receiver)**: Receives ESP-NOW messages from Node A and activates the appropriate relays.
* **ESP-NOW**: Ensures low-latency peer-to-peer communication without requiring an external router.

---

## 🖼️ Web Dashboard Preview

> Designed using ESPDash: visually appealing, responsive, and lightweight

* Sliders to activate/deactivate each relay (A1–A8, B1–B8)
* Status reflected in real-time
* Auto-refresh capabilities every second (`timerDelay = 1000ms`)

---

## ⚙️ Dependencies

* [ESPDash by Ayush Sharma](https://github.com/ayushsharma82/ESP-DASH)
* ESP8266 core for Arduino (install via Board Manager)
* ESPAsyncWebServer
* AsyncTCP
* SPIFFS filesystem

To install libraries via Arduino Library Manager or directly:

```
ESPAsyncWebServer
ESPAsyncTCP
ESP-DASH
```

---

## 🛠️ Getting Started

1. **Set WiFi Credentials** in `variable.h`:

   ```cpp
   const char* ssid = "YourNetwork";
   const char* password = "YourPassword";
   ```

2. **Update ESP-NOW MAC Addresses** in `variable.h` to match target devices:

   ```cpp
   uint8_t broadcastAddress1[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX};
   ```

3. **Flash `dash.ino`** to Node A (dashboard master)
   **Flash `esp8266-relay-networking.ino`** to Node B (relay receiver)

4. **Connect to WiFi**, and access the ESP’s IP to open the control dashboard.

---

## 🧾 Example Use-Cases

* Smart home automation
* Classroom or laboratory power control
* Industrial relay control interface
* IoT test bench with visual feedback

---

## 🧪 Advanced Customization

* Modify or extend `test_struct` in `variable.h` to include more states or devices
* Enhance dashboard with graphs, switch toggles, or notifications
* Integrate with MQTT or Blynk if needed for remote access beyond LAN

---

## 📝 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙌 Credits

Developed by [2black0](mailto:2black0@gmail.com) as part of IoT dashboard and relay communication exploration using ESP8266 and ESPDash.