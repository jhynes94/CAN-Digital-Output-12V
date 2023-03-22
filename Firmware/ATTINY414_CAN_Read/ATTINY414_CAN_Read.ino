#include <SPI.h>
#include <mcp2515.h>

#define OUT_1 6
#define OUT_2 0
#define OUT_3 1
#define OUT_4 4

bool blink_Out_1 = false
bool blink_Out_2 = false
bool blink_Out_3 = false
bool blink_Out_4 = false

struct can_frame canMsg;
MCP2515 mcp2515(7);

unsigned int device_CAN_ID = 1;

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
      
      unsigned int mask = 0b00000010;
      if((canMsg.data[0]&mask) != 0){
        digitalWrite(OUT_1, HIGH);
      }
      else {
        digitalWrite(OUT_1, LOW);
      }
      
      /*
      //Iterates Through Data    
      for (int i = 0; i<canMsg.can_dlc; i++) {
        //canMsg.data[i],HEX);
      }
      */
    }
  }
}