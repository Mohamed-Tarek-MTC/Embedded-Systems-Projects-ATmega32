# Hexadecimal Counter using 7-Segment

## 📖 Description

This project implements a hexadecimal counter (0x0 to 0xF) using a single 7-segment display connected to the ATmega32 microcontroller. 
The displayed value increments automatically with a fixed delay before wrapping around and restarting from zero.

---

## ✨ Features

- Counts from 0 to F in hexadecimal.
- Automatic overflow from F back to 0.
- Uses a reusable 7-segment driver.
- Simple and modular implementation.

---

## 🛠 Hardware

- ATmega32
- Common Anode/Common Cathode 7-Segment Display (Configured in Code as Common Cathode)

---

## 📚 Drivers Used

### MCAL

- DIO

### HAL

- 7-Segment

---

## 🧠 Embedded Concepts

- GPIO Configuration
- Digital Output Control
- Hexadecimal Representation


---

## 📂 Folder Structure

```
Code/
Proteus/
Images/
README.md

```

## 👨‍💻 Author

**Mohamed Tarek**

Embedded Software Engineer