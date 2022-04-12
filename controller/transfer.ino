#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9, 10);

byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"};
 
byte transmitData[3];

void initTransfer() {
  radio.begin();
  radio.setAutoAck(1);   
  radio.setRetries(0, 15);
  radio.enableAckPayload();
  radio.setPayloadSize(32);
  
  radio.openWritingPipe(address[0]);
  radio.setChannel(0x10);

  radio.setPALevel (RF24_PA_MAX);
  radio.setDataRate (RF24_250KBPS);
  
  radio.powerUp();
  radio.stopListening();
}

void setData(int index, int data) {
  transmitData[index] = data;
}

void sendData() {
  radio.write(&transmitData, sizeof(transmitData));
}
