# Battery Monitor

__Author__: Bei Chen Liu

__Description__: A simple battery monitor circuit that use an ATtiny45 or an 
ATtiny85 to measure the battery voltage through a voltage divider and 
visualized the voltage with WS2812B LEDs when the on-board button is pressed.

## Parameters:
Operating Range: **7.5V to 35V** (limited by the voltage regulator).

## Connectors:
**J1**: Battery Connector:
- Pin 1: VBat+
- Pin 2: VBat-

**J2**: ICSP to programe the micro-controller:
- Pin 1: 5V
- Pin 2: SCK
- Pin 3: MISO
- Pin 4: MOSI
- Pin 5: Reset
- Pin 6: Ground

## TODO: 
Use internal 2.56V reference for better accuracy.
