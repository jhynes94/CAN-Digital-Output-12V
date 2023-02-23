#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(7);


void setup() {
  // Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
  
  // Serial.println("------- CAN Read ----------");
  // Serial.println("ID  DLC   DATA");
}

void loop() {
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {

    int LED_pin = 4;
    pinMode(LED_pin, OUTPUT);
    for(int i=0; i<5; i++){
        digitalWrite(LED_pin, HIGH);  // turn the LED on (HIGH is the voltage level)
        delay(100);                      // wait for a second
        digitalWrite(LED_pin, LOW);   // turn the LED off by making the voltage LOW
        delay(100);   
    }
    
    // Serial.print(canMsg.can_id, HEX); // print ID
    // Serial.print(" "); 
    // Serial.print(canMsg.can_dlc, HEX); // print DLC
    // Serial.print(" ");
    
    for (int i = 0; i<canMsg.can_dlc; i++)  {  // print the data
      // Serial.print(canMsg.data[i],HEX);
      // Serial.print(" ");
    }

    // Serial.println();      
  }

}