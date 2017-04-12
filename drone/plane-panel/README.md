# Plane Control Panel

__Author__: Bei Chen Liu

__Description__: A control panel for the drone project, functionality includs:
- An Arduino Leonardo clone to indicate ROS activity.
- An LED to indicate if the battery is connected.
- An LED to indicate if the motherboad is powered.
- An LED to indicate the status of the DCDC-NUC PSU.
- Cutouts for fiting 3 kill swtich
- Cutout for the reset bottom for the computer

## TODO:
- Fix label for JPSU (Polarity is flipped)
- Add more silk labels

## Connectors:
**J3**: Leonardo analog connector:
- Pin 1: VUSB
- Pin 2: A0
- Pin 3: A1
- PIn 4: A2
- Pin 5: A3
- Pin 6: USB GND

**J4**: Leonardo USB connector
- Pin 1: VUSB
- Pin 2: D-
- Pin 3: D+
- Pin 4: NC
- Pin 5: USB GND

**J5**: Leonardo I2C UART connector:
- Pin 1: VUSB
- Pin 2: SCL
- Pin 3: SDA
- PIn 4: RX
- Pin 5: TX
- Pin 6: USB GND

**J6**: Leonardo PWM connector:
- Pin 1: VUSB
- Pin 2: D6
- Pin 3: D9
- PIn 4: D10
- Pin 5: D5
- Pin 6: USB GND

**J8**: Leonardo PWM connector:
- Pin 1: VUSB
- Pin 2: SCK
- Pin 3: MOSI
- PIn 4: MISO
- Pin 5: RESET
- Pin 6: USB GND

**JBAT**: Main battery connector:
- Pin 1: GND
- Pin 2: VBat

**JIO**: Computer Power LED connector:
- Pin 1: VLED
- Pin 2: GND

**JPSU**: Computer PSU status LED connector:
- Pin 1: GND
- Pin 2: Signal (Solder to anode of the on-board LED)
- Pin 3: VCC (3.3V from the MCU)
