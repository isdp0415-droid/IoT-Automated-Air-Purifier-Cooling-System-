# Hardware Connection Guide

## 1. Dual-Controller Communication (UART)
This connects the Master (Logic) to the Slave (Driver). 
**Note:** A common ground (GND) connection is required for data transmission to work.

| Master Board (Arduino R4) | Slave Board (Arduino R3) | Description |
| :--- | :--- | :--- |
| **TX** (Pin 1) | **RX** (Pin 0) | Data Transmission |
| **GND** | **GND** | Common Ground Reference |

> **⚠️ IMPORTANT:** Disconnect the wire from **RX (Pin 0)** on the Slave Board while uploading the code. Reconnect it after the upload is complete.

---

## 2. Master Node (Sensing)
**Board:** Arduino R4 Minima / WiFi

| Component | Pin Label | Arduino Pin | Notes |
| :--- | :--- | :--- | :--- |
| **DS18B20 Sensor** | VCC | 5V | |
| | GND | GND | |
| | DATA | D2 | Requires 4.7kΩ pull-up resistor between Data and VCC |

---

## 3. Slave Node (Actuation)
**Board:** Arduino R3
**Power:** External 12V Power Supply required for Fan and Valve (do not power directly from Arduino 5V).

| Component | Pin Label | Arduino Pin | Circuit Notes |
| :--- | :--- | :--- | :--- |
| **DC Cooling Fan** | GATE / IN | ~D9 (PWM) | Use logic-level MOSFET (e.g., IRLZ44N) or Motor Driver |
| **Water Valve** | IN | D7 | Use 5V Relay Module |

### Circuit Diagrams
#### Fan Motor Driver (MOSFET Setup)
The fan requires high current and cannot be driven directly by the pin.


#### Temperature Sensor (DS18B20)
Standard wiring with pull-up resistor.