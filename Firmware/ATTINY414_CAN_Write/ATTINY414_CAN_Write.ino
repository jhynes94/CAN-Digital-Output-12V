// Based on https://github.com/autowp/arduino-mcp2515

#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg1;
struct can_frame canMsg2;
MCP2515 mcp2515(7);


void setup() {
  canMsg1.can_id  = 0xFF;
  canMsg1.can_dlc = 8;
  canMsg1.data[0] = 0x8E;
  canMsg1.data[1] = 0x87;
  canMsg1.data[2] = 0x32;
  canMsg1.data[3] = 0xFA;
  canMsg1.data[4] = 0x26;
  canMsg1.data[5] = 0x8E;
  canMsg1.data[6] = 0xBE;
  canMsg1.data[7] = 0x86;

  canMsg2.can_id  = 0x036;
  canMsg2.can_dlc = 8;
  canMsg2.data[0] = 0x0E;
  canMsg2.data[1] = 0x00;
  canMsg2.data[2] = 0x00;
  canMsg2.data[3] = 0x08;
  canMsg2.data[4] = 0x01;
  canMsg2.data[5] = 0x00;
  canMsg2.data[6] = 0x00;
  canMsg2.data[7] = 0xA0;
  
}

void printErrorNumberLED(int testError){
  int LED_pin = 4;
  pinMode(LED_pin, OUTPUT);
  for(int i=0; i<testError; i++){
      digitalWrite(LED_pin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(300);                      // wait for a second
      digitalWrite(LED_pin, LOW);   // turn the LED off by making the voltage LOW
      delay(300);   
  }
};


void loop() {

  MCP2515::ERROR testError = mcp2515.reset();
  printErrorNumberLED(testError);
  testError = mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ);
  printErrorNumberLED(testError);
  testError = mcp2515.setNormalMode();
  printErrorNumberLED(testError);
  mcp2515.sendMessage(&canMsg1);
  mcp2515.sendMessage(&canMsg2);

  if (mcp2515.checkError() == true){
    int LED_pin = 4;
    pinMode(LED_pin, OUTPUT);
    for(int i=0; i<5; i++){
        digitalWrite(LED_pin, HIGH);  // turn the LED on (HIGH is the voltage level)
        delay(100);                      // wait for a second
        digitalWrite(LED_pin, LOW);   // turn the LED off by making the voltage LOW
        delay(100);   
    }
    mcp2515.reset();
  }

  
  delay(2000);
}