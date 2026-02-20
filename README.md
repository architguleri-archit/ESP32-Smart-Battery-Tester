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
| VSS     | GND        |
| VDD     | 5V         |
| VO      | GND        |
| RS      | GPIO 14    |
| RW      | GND        |
| E       | GPIO 27    |
| D4      | GPIO 26    |
| D5      | GPIO 25    |
| D6      | GPIO 33    |
| D7      | GPIO 32    |
| LED+    | 5V         |
| LED-    | GND        |

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
