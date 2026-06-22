# Smart Green House System

## 📖 Description

This project implements a distributed **Smart Green House System** using two **ATmega32** microcontrollers communicating through the **UART protocol**.

The system is divided into two MCUs:

- **Land MCU** responsible for monitoring environmental sensors and controlling greenhouse actuators.
- **HMI MCU** responsible for displaying information, receiving user commands, and allowing configuration through the LCD and keypad.

The Land MCU continuously monitors the surrounding environment, including temperature, humidity, soil moisture, and water tank level. According to predefined thresholds and the selected operating mode, it automatically controls irrigation, ventilation, Humidifying the air and alarm functions.

The HMI MCU provides a user-friendly interface using keypad and LM044L LCD for selecting plant profiles, monitoring sensor readings, configuring operating parameters, and viewing the current greenhouse status in real time.

The project demonstrates distributed embedded systems, UART communication, sensor interfacing, automation algorithms, modular firmware architecture, and reusable driver development.

---

## ✨ Features

- Database for each plant Stored in EEPROM (Temperature, Humidity, Soil moisture and Days to Harvest).
- Automatic irrigation system.
- Automatic ventilation control.
- Automatic air humidifying control.
- Water tank level monitoring.
- Temperature monitoring.
- Humidity monitoring.
- Soil moisture monitoring.
- LCD monitoring interface.
- Keypad configuration.
- Plant profile selection.
- UART communication between two MCUs.
- Automatic and manual operating modes.
- Modular driver architecture.

---

## 🔄 Project Flow

1. The system initializes both MCUs.
2. The HMI MCU displays the main menu.
3. The user selects the desired plant to be planted if there is no planted one.
4. Configuration data is sent to the Land MCU via UART.
5. The Land MCU continuously reads all environmental sensors.
6. Sensor readings are compared with predefined thresholds.
7. Irrigation, fan, lighting, and other actuators are automatically controlled.
8. Current sensor values and system status are transmitted back to the HMI MCU.
9. The LCD continuously displays the greenhouse status while allowing further user interaction.
10. Electricity cut down handling by save the current planting stage and the planted days in the EEPROM. 

---

## 🛠 Hardware

- ATmega32 (2 MCUs)
- Keypad
- LCD (20x4 LM044L)
- Temperature Sensor
- Humidity Sensor
- Soil Moisture Sensor (represented as POT)
- Ultra Sonic Sensor
- Water Pump
- DC Fan
- AC (represented as Motor)
- Red-LED/BUZZER
- 32.768 KHz Crystal Oscillator 
- 1N5408 Diodes
- IRLZ34N MOSFETs


---

## 📚 Drivers Used

### MCAL

- DIO
- ADC
- USART
- Timers

### HAL

- LCD
- Keypad
- LED
- Ultra Sonic
- Motor

---

## 🧠 Embedded Concepts

- Distributed Embedded Systems
- UART Communication
- Sensors Interfacing
- ADC channels switching
- Automation Algorithms
- Environmental Monitoring
- Closed-Loop Control
- Driver Abstraction
- Modular Programming
- Real-Time Monitoring

---

## 📂 Folder Structure

```
Code/
Simulation/
Images/
README.md

```

## 👨‍💻 Author

**Mohamed Tarek**

Embedded Software Engineer