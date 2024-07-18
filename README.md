# LoRa Communication System

This repository contains Arduino sketches for establishing bi-directional communication using LoRa modules and Bluetooth serial, enabling wireless data transmission between devices in real-time.

## Project Description

The repository includes two Arduino sketches:

### LoraReceiver.ino

Configures an Arduino board as a LoRa receiver. It initializes the LoRa module, receives data packets, prints them to the Serial Monitor, and sends them to a connected Bluetooth device using Bluetooth Serial.

### LoraSender.ino

Sets up an Arduino board as a LoRa sender. It initializes the LoRa module, sends data packets typed into the Serial Monitor via LoRa to the receiver.

## Setup

### Hardware Requirements

- Arduino boards (two for sender and receiver)
- LoRa modules (compatible with SX1278/SX1276)
- Bluetooth module (for communication with LoraReceiver)

### Software Requirements

- Arduino IDE
- Libraries: LoRa, SPI (included with Arduino IDE), BluetoothSerial (for LoraReceiver)

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/shashwat/LoRa-Communication-System.git

2. Open each `.ino` file in the Arduino IDE.

3. Upload `LoraReceiver.ino` to one Arduino board and `LoraSender.ino` to another.

4. Follow the wiring instructions and ensure all necessary modules are connected properly.

## Usage

1. Upload `LoraReceiver.ino` to the Arduino acting as the receiver.
2. Upload `LoraSender.ino` to the Arduino acting as the sender.
3. Open the Serial Monitor for each Arduino to view communication logs and debug messages.
