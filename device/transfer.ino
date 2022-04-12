#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9, 10);

byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"};

byte recievedData[3];

uint32_t timer;
int timeout = 2500;

bool connectionOpen = false;

void initTransfer() {
  radio.begin();
  radio.setAutoAck(1);
  radio.setRetries(0,15);
  radio.enableAckPayload();
  radio.setPayloadSize(32);

  radio.openReadingPipe(1,address[0]);
  radio.setChannel(0x10);

  radio.setPALevel (RF24_PA_MAX);
  radio.setDataRate (RF24_250KBPS); 

  radio.powerUp();
  radio.startListening();
}

void transferLoop() {
   byte pipeNo;              
   if (radio.available(&pipeNo)) {
    if (!connectionOpen) {
      Serial.println("connect");
      connectionOpen = true;
    }
    
    timer = millis();
    radio.read( &recievedData, sizeof(recievedData) );
  //  Serial.println(recievedData[2]);
   }
   checTtimer();
}

void checTtimer() {
  if (millis() - timer >= timeout) {
    if (connectionOpen) {
      Serial.println("disconnect");
      connectionOpen = false;
      timer+= timeout;
      recievedData[2] = 0;
      reset();
    }
       
  }
}

byte getData(int id) {
  return recievedData[id];
}
