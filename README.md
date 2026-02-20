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
| 1 (VSS)   | GND        |
| 2 (VDD)   | 5V         |
| 3 (VO)    | GND        |
| 4 (RS)    | GPIO 14    |
| 5 (RW)    | GND        |
| 6 (EN)    | GPIO 27    |
| 11 (D4)   | GPIO 26    |
| 12 (D5)   | GPIO 25    |
| 13 (D6)   | GPIO 33    |
| 14 (D7)   | GPIO 32    |
| 15 (LED+) | 5V         |
| 16 (LED-) | GND        |

---

### 🔋 Voltage Divider (330kΩ + 330kΩ)

| Connection | Details |
|------------|----------|
| Battery +  | 330kΩ → GPIO 34 |
| GPIO 34    | 330kΩ → GND |
| Battery –  | GND |

Divider Ratio = 2:1

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
