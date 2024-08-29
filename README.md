# RFID-Based PC Access Control System 🛡️🔑

Welcome to the **RFID-Based PC Access Control System**! This project leverages an RFID reader and Arduino to provide secure access control for your PC.

## 📋 Description
This system uses an **MFRC522 RFID reader** to authenticate users based on their RFID cards. It can simulate keyboard inputs to perform actions such as logging into applications or locking/unlocking the PC.

## 🚀 Features
- **RFID Authentication**: Read and verify RFID card UIDs.
- **Keyboard Simulation**: Automate PC login or lock/unlock functions.
- **Customizable**: Easily modify UID and associated actions.

## ⚙️ Hardware Required
- **MFRC522 RFID reader**
- **Arduino board** (e.g., Uno, Nano)
- **Push button** (for triggering actions)

## 📦 Libraries Used
- [Keyboard](https://www.arduino.cc/en/Reference/Keyboard)
- [SPI](https://www.arduino.cc/en/Reference/SPI)
- [MFRC522](https://github.com/miguelbalboa/rfid)

## 🔧 Setup
1. **Hardware Setup**: Connect the MFRC522 to the Arduino using the specified pins.
2. **Software Setup**: Upload the provided code to the Arduino. Modify the `card1` variable with your RFID card UID and adjust actions as needed.

## 🛠️ Code Overview
The code handles RFID card reading, UID verification, and performs actions based on the button state:
- **Button Pressed**: Simulates login credentials.
- **Button Not Pressed**: Locks/unlocks the PC.

## 📝 Notes
- Customize the `'card1'` variable with your card's UID.
- Adjust the code for different actions as needed.
