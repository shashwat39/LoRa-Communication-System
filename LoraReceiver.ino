/*********
  Modified from the examples of the Arduino LoRa library
  More resources: https://randomnerdtutorials.com
*********/

#include <SPI.h>
#include <LoRa.h>
#include <BluetoothSerial.h>
//define the pins used by the transceiver module
#define SCK 18
#define MISO 19
#define MOSI 23
#define SS 5
#define RST 14
#define DIO0 2
BluetoothSerial SerialBT;
// int counter = 0;

void setup() {
  //initialize Serial Monitor
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Receiver");
  SerialBT.begin("Receiver");
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {

// Recieveing the data
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.println(LoRaData); 
      SerialBT.print(LoRaData);
      SerialBT.println();
    }

    // print RSSI of packet
    //Serial.print("' with RSSI ");
    //Serial.println(LoRa.packetRssi());
  }

// Sending the data
  if(SerialBT.available()){
    String d = SerialBT.readString();
    Serial.print("Sending packet: ");
    Serial.print(d);
    Serial.print(" : ");
//    Serial.println(counter);
    Serial.println(d);
    //Send LoRa packet to receiver
    LoRa.beginPacket();
    LoRa.print(d);
//    LoRa.print(counter);
    LoRa.endPacket();
  
//    counter++;
  
    delay(2000);
  }
}
