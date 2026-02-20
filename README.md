# 🔋 ESP32 Smart Battery Tester ⚡📊

Measure 1.5V AA/AAA cell voltage accurately using ESP32 and a 16x2 LCD display.

---

## 🔧 Features

- Real-time voltage measurement  
- Battery percentage display  
- Low voltage warning (slow blink)  
- High voltage warning (fast blink)  
- Smooth startup animation  
- Calibration support  
- Accurate readings compared to a multimeter  

---

## 🔌 Wiring

### 📟 LCD to ESP32

| LCD Pin | ESP32 GPIO |
|---------|------------|
| 1VSS     | GND        |
| 2VDD     | 5V         |
| 3VO      | GND        |
| 4RS      | GPIO 14    |
| 5RW      | GND        |
| 6EN       | GPIO 27    |
| 11D4      | GPIO 26    |
| 12D5      | GPIO 25    |
| 13D6      | GPIO 33    |
| 14D7      | GPIO 32    |
| 15LED+    | 5V         |
| 16LED-    | GND        |

---

### 🔋 Voltage Divider (330kΩ + 330kΩ)

| Connection | Details |
|------------|----------|
| Battery +  | 330kΩ → GPIO 34 |
| GPIO 34    | 330kΩ → GND |
| Battery –  | GND |

Divider Ratio = 2.1

---

## 📦 Components Required

- ESP32 Dev Board  
- 16x2 LCD  
- 2 × 330kΩ resistors  
- Jumper wires  
- 1.5V AA/AAA battery  

---

## ⚙️ Calibration

1. Measure battery voltage using a multimeter  
2. Compare with ESP32 reading  
3. Adjust `CALIBRATION_FACTOR` in the code if needed  

---

## 📜 License

This project is licensed under the MIT License.

---

🎥 **YouTube Tutorial:**  
https://youtu.be/JIdBcHnp1kY
