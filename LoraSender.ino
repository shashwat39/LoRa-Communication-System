#include <SoftwareSerial.h>

#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define SCK 13
#define MISO 12
#define MOSI 11
#define SS 10
#define RST 9
#define DIO0 4

//int counter = 0;
//String c="Himasnhu";
//String d = "hji";

SoftwareSerial BTSerial(2,3);

void setup() {
  //initialize Serial Monitor
  Serial.begin(9600);
  BTSerial.begin(9600);
  
  while (!Serial);
  Serial.println("LoRa Sender");

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

// Recieving the data
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.println(LoRaData);
    }
  }

// Sending the data
  if (Serial.available()) {
    String d = Serial.readString();
    Serial.println(d);
    Serial.print("Sending packet: ");
    Serial.println(d);
  
    //Send LoRa packet to receiver
    LoRa.beginPacket();
    LoRa.print(d);
    //LoRa.print(counter);
    LoRa.endPacket();
    
    delay(2000);
  }
} 
