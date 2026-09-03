# Skin Conductance Stress-Meter Prototype 🧪⚡

An Arduino-based bio-feedback device that measures real-time Galvanic Skin Response (GSR) / skin resistance changes to detect stress levels and prompt visual/audio alerts.

## 📌 Project Overview
The Skin Conductance Stress-Meter measures skin resistance using an analog voltage divider circuit connected to two conductive finger pads. Human skin resistance drops as emotional arousal or stress triggers sweat gland activation. The Arduino processes these analog signals (ADC) and drives dynamic visual (LED bar) and audible (buzzer) feedback.

## 🛠 Hardware Components
* **Microcontroller:** Arduino Uno
* **Bio-Sensing:** Custom finger pads / Galvanic Skin Response (GSR) probes
* **Calibration:** 10kΩ Potentiometer (for sensitivity baseline adjustment)
* **Feedback Outputs:** 
  * 3x Status LEDs (Green = Calm, Yellow = Mild Stress, Red = High Stress)
  * Piezo Buzzer (Frequency modulation for elevated stress)
* **Prototyping:** Breadboard, jumpers, 10kΩ resistor

## 🔌 Circuit & Pinout Configuration
| Component | Arduino Pin | Description |
| :--- | :--- | :--- |
| **GSR Probe Input** | Pin A0 | Analog voltage reading from skin divider |
| **Calibration Pot** | Pin A1 | Baseline sensitivity reference |
| **Green LED** | Pin 2 | Calm state indicator |
| **Yellow LED** | Pin 3 | Moderate stress indicator |
| **Red LED** | Pin 4 | High stress alert |
| **Buzzer (+)** | Pin 5 | Acoustic feedback output |

## 🚀 Key Features
* **Analog Signal Processing:** Real-time ADC conversion and baseline drift filtering.
* **Non-blocking Execution:** Built with `millis()` timing loops for zero-latency sensor monitoring.
* **Dynamic Multi-Level Alerts:** Progressive feedback based on calibrated baseline deviation.

## 💻 Firmware Math Model
The raw ADC values ($0 - 1023$) correlate to skin resistance via a fixed voltage divider:

$$V_{\text{out}} = V_{\text{in}} \times \left( \frac{R_{\text{skin}}}{R_{\text{fixed}} + R_{\text{skin}}} \right)$$

Higher stress decreases $R_{\text{skin}}$, causing measurable shifts in $V_{\text{out}}$.

## 👤 Author
**Николай Стоянов**
* LinkedIn: [nikolay-stoyanov-ce](https://www.linkedin.com/in/nikolay-stoyanov-ce)
* GitHub: [BlindHunterN](https://github.com/BlindHunterN)
