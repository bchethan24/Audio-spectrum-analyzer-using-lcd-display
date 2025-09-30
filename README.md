# Audio Spectrum Analyzer Using LCD Display

This project demonstrates a simple **Audio Spectrum Analyzer** built using an **Arduino Mega 2560** and a **16×2 LCD (LCD1602A)**.  
The system captures audio input via an AUX cable, processes it, and displays the signal levels on the LCD in real time.

---

## 📚 Project Overview
The aim of this project is to **visualize audio amplitude/spectrum** using an embedded system.  
It was done as part of the **Microprocessor and Microcontrollers Practice** course at **IIITDM Kurnool**.

---

## 🛠️ Equipment / Tools Used
- Arduino Mega 2560
- LCD 1602A Display
- Breadboard
- AUX-to-AUX cable (for audio input)
- Jumper wires
- Arduino IDE Software

---

## ⚙️ Hardware Connections
| LCD Pin No. | Pin Label | Arduino Mega Pin |
|-------------|-----------|------------------|
| 1           | VSS       | GND              |
| 2           | VDD       | 5V               |
| 3           | VO        | Pin 6            |
| 4           | RS        | Pin 12           |
| 5           | RW        | GND              |
| 6           | E         | Pin 11           |
| 11          | D4        | Pin 5            |
| 12          | D5        | Pin 4            |
| 13          | D6        | Pin 3            |
| 14          | D7        | Pin 2            |
| 15          | A (+ve backlight) | 3.3V     |
| 16          | K (–ve backlight) | GND      |

**Audio Jack Connections:**
- Yellow → 3.3V  
- Red → A0 (Analog Input)  
- Black → GND  

---

## 🚀 How It Works
1. The audio signal from a phone/laptop enters the Arduino via the AUX input.
2. The Arduino samples the input signal and computes its amplitude.
3. The processed data is shown as a spectrum bar/levels on the 16×2 LCD.
4. The display updates in real time as the audio changes.

---

## 📦 Software
- **Arduino IDE** for uploading the program
- Libraries used:
  - `LiquidCrystal.h` (for controlling the LCD)
  - *(Optional)* FFT library if you extend it to show frequency bins

---

Circuit connections are uploaded in repository
---
## 📈 Applications
- Real-time audio visualization
- Educational demonstration of signal processing
- Basic audio measurement tool for DIY projects
