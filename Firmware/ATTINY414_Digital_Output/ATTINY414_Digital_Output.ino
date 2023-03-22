#include <SPI.h>
#include <mcp2515.h>

#define OUT_1 6
#define OUT_2 0
#define OUT_3 1
#define OUT_4 4

bool blink_Out_1 = false;
bool blink_Out_2 = false;
bool blink_Out_3 = false;
bool blink_Out_4 = false;

struct can_frame canMsg;
MCP2515 mcp2515(7);

unsigned int device_CAN_ID = 1;

unsigned long currentMillis;
unsigned long previousMillis = 0;
const unsigned long interval = 1000;
int ledState = LOW;

void setup() {
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();

  //Setup Digital Outputs
  pinMode(OUT_1, OUTPUT);
  pinMode(OUT_2, OUTPUT);
  pinMode(OUT_3, OUTPUT);
  pinMode(OUT_4, OUTPUT);
}

void loop() {

  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
      
    //If it is the correct CAN ID
    if(canMsg.can_id == device_CAN_ID){
      
      if(canMsg.data[0] > 0){
        digitalWrite(OUT_1, HIGH);
        blink_Out_1 = false;
        if(canMsg.data[0] > 10){
          blink_Out_1 = true;
        } 
      }
      else {
        digitalWrite(OUT_1, LOW);
        blink_Out_1 = false;
      }


      if(canMsg.data[1] > 0){
        digitalWrite(OUT_2, HIGH);
        blink_Out_2 = false;
        if(canMsg.data[1] > 10){
          blink_Out_2 = true;
        }
      }
      else {
        digitalWrite(OUT_2, LOW);
        blink_Out_2 = false;
      }

      if(canMsg.data[2] > 0){
        digitalWrite(OUT_3, HIGH);
        blink_Out_3 = false;
        if(canMsg.data[2] > 10){
          blink_Out_3 = true;
        }
      }
      else {
        digitalWrite(OUT_3, LOW);
        blink_Out_3 = false;
      }
      
      if(canMsg.data[3] > 0){
        digitalWrite(OUT_4, HIGH);
        blink_Out_4 = false;
        if(canMsg.data[3] > 10){
          blink_Out_4 = true;
        }
      }
      else {
        digitalWrite(OUT_4, LOW);
        blink_Out_4 = false;
      }

      /*
      //Iterates Through Data    
      for (int i = 0; i<canMsg.can_dlc; i++) {
        //canMsg.data[i],HEX);
      }
      */
    }
  }
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    if(blink_Out_1 == true){
      digitalWrite(OUT_1, ledState);
    }
    if(blink_Out_2 == true){
      digitalWrite(OUT_2, ledState);
    }
    if(blink_Out_3 == true){
      digitalWrite(OUT_3, ledState);
    }
    if(blink_Out_4 == true){
      digitalWrite(OUT_4, ledState);
    }
  }
}