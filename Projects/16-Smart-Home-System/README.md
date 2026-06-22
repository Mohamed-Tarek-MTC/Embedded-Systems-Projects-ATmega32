# Smart Home System

## 📖 Description

This project implements a complete distributed **Smart Home System** using three **ATmega32** microcontrollers communicating through the **UART protocol**.

The system is divided into three independent ECUs:

- **Security MCU** responsible for user authentication and access control.
- **Control MCU 1** responsible for user interaction through the LCD and keypad (HMI MCU).
- **Control MCU 2** responsible for controlling home devices such as lighting, motors, and sensors reads monitoring.

The Isolated Security MCU stores the system password inside EEPROM and validates every login request before allowing access to enter the home making the inside and outside MCUs work parallelly.
Inside the home  the control MCUs communicate together to execute user commands to observe the status of devices in every part of the home (2 Rooms - Bathroom - Kitchen - Salon) and controling them.
The project demonstrates modular firmware architecture, reusable embedded drivers, inter-MCU communication, EEPROM data storage, menu-driven interfaces, and real-time peripheral control.

---

## ✨ Features

- Password-protected smart home.
- EEPROM password storage.
- User authentication.
- UART communication between three MCUs.
- LCD user interface.
- Keypad navigation.
- LED control.
- DC/Servo motor control.
- Multiple MCU architecture.
- Modular driver-based software design.

---

## 🔄 Project Flow

1. System powers up.
2. Security MCU loads the stored password from EEPROM.
3. User enters the password using the keypad.
4. Password is checked by the Security MCU.
5. Security MCU validates the password.
6. If authentication succeeds, door is opened.
7. inside the home user selects the required home function.
8. Commands are exchanged between the control MCUs.
9. LEDs, motors, and connected peripherals are controlled accordingly.
10. The system continues serving commands until shutdown.

---

## 🛠 Hardware

- ATmega32 (3 MCUs)
- LCDs
- Keypads
- LEDs
- LM35 Temperature Sensors
- DC Motors (represents ACs and Fans)
- Servo Motor (Doors)
- 1N5408 Diodes
- IRLZ34N MOSFETs

---

## 📚 Drivers Used

### MCAL

- DIO
- USART
- EEPROM
- ADC

### HAL

- LCD
- Keypad
- LED
- DC/Servo Motor

---

## 🧠 Embedded Concepts

- Multi-MCU Embedded Systems
- UART Communication
- EEPROM Data Storage
- Password Authentication
- Menu-Driven Interface
- ADC Channels Switching
- Driver Abstraction
- Modular Programming
- Distributed Embedded Architecture
- Command-Based Communication
- Interrupt Handling
- Peripheral Control

---

## 📂 Folder Structure

Code/
Simulation/
Images/
README.md

```

## 👨‍💻 Author

**Mohamed Tarek**

Embedded Software Engineer