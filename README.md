# CAN-Digital-Output-12V
CAN controlled Digital Outputs providing 12V power with __ Current each.

## Items to complete
1. Detemine MOSFET to use for design (based on Current(A)/Costs constraints).
2. Design better interface board to use Arduino Nano Programmer
    1. JST Connector to Arduino Development Board
    2. 2.54mm Connector with standard interface board
    3. Consider adding UART connector as well.
3. Determine modes needed for device
    1. CAN ID changing?
    2. CAN Mode changing?
    3. How this should be modified? (DIP swich or via SW)

## Development Setup

Programming the ATTiny is a bit difficult. Setup can be completed using the following tutorial:
https://youtu.be/AL9vK_xMt4E

The library used for SPI enabled CAN device:
https://github.com/autowp/arduino-mcp2515

PEAK CAN usb device is used for interfacing and development. The software to run this is called <b>pcanview<b>


## Far Future items

Future Tutorial for programming an alternative way:
https://www.youtube.com/watch?v=ra7bT74EGUs