🔋 ESP32 Smart Battery Tester ⚡📊

Measure your 1.5V AA/AAA cell voltage accurately using ESP32 and a 16x2 LCD display — with real-time voltage and battery percentage.

🔧 Features

Real-time voltage measurement

Battery percentage display

Low voltage warning (slow blink)

High voltage warning (fast blink)

Smooth startup animation

Calibration support for higher accuracy

~1% error compared to multimeter

🔌 Wiring
📟 LCD to ESP32
LCD Pin	ESP32 GPIO
RS	GPIO 14
E	GPIO 27
D4	GPIO 26
D5	GPIO 25
D6	GPIO 33
D7	GPIO 32
🔋 Voltage Divider (330kΩ + 330kΩ)
Component	Connection
Battery +	330kΩ → GPIO 34
GPIO 34	330kΩ → GND
Battery –	GND

Divider Ratio = 2.0

📦 Components Required

ESP32 Dev Board

16x2 LCD

2× 330kΩ resistors

Jumper wires

1.5V AA/AAA cell

🧠 How It Works

The ESP32 reads the battery voltage using a voltage divider circuit.
The ADC value is averaged for stability and adjusted using a calibration factor.
The LCD displays:

Voltage (in volts)

Battery percentage (for 1.0V – 1.5V dry cells)

Warning messages for low or high voltage

⚙️ Calibration

If readings differ slightly from your multimeter:

Measure battery voltage using a multimeter

Compare with ESP32 reading

Adjust CALIBRATION_FACTOR in code

📜 License

This project is licensed under the MIT License.

🎥 YouTube Tutorial: (Add your link here)
