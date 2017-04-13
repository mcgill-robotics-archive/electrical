# Ground Station Gimbal HAT

__Author:__ Bei Chen Liu

__Description:__ A Raspberry Pi HAT used for Drone Ground Station Gimbal.

## TODO:
- Add poweroff button.
- Add system status LEDs.

## How-to:
Operating range: **10V to 14V**.
Under voltage lockout: **10V**.
Under voltage resotre: **11V**.
Nominal voltage: **12V**.
Maximun voltage: **16V**. 

The HAT can back power the RPi, to start the RPi:
- With the switch in the off posisition, connect 3 cell lipo battery. 
- The Vin LED should light up.
- Switch on the switch. 
- The RPi should boot and the 5V0 and 3V3 LEDS should light up.

To poweroff:
- SSH into the RPi and shutdown through command line.
- Wait for the power and activity LEDs to stop blinking.
- Switch off the switch.
- Disconnect the battery.

## Features:
- 9-axes imu (MPU9250) for orientation and absolute heading.
- GPS (FGPMMOPA6C) for absolute location.
- PWM controller (PCA9633) to generate motor control signals.
- 5V buck convertor (TPS54302) to back power RPi with 3A max output.
- Three-phase motor driver (L6234) for driving the motor.
- Real time clock (DS3231M) for time keeping.
- Current sensor (INA219) to monitor total current consumption and input voltage.

## Connectors:
- B1: Backup battery connector to be used with 12mm coin cell battery.
- J2: Power Input connector, pin 1 and 2 are ground, pin 3 and 4 are power.
- J3: Phase power output for the gimbal motor.
- J_RPI1: Connector header for RPi.
- J_RPI2: Connector header fot RPi.
- JP5: Write protect for the HAT EEPROM, solder to enable write, desolder to disbale write.
- SW1: On-Off switch for the buck convertor, it shorts the enable pin of TPS54302 to ground to disable the convertor.

## LEDs:
- Vin: Vin power LED.
- 5V0: 5.0V power LED.
- 3V3: 3.3V power LED.
- FIX: GPS fix LED:
	+ On for 1 sec, off for 1 sec: Not fixed.
	+ Constant off: Fixed.  

## Detail Explanation:
- Input voltage come in from J2 and go through shunt resistor of the current monitor, then to the buck capacitor. Then split to power the buck convertor and the motor driver.
	- Motor driver is controlled by the RPi and the PCA9633. All the enble pins are connected to gether and is controlled by the pin 11 (GPIO 17) of the RPi. The PWM signals are generated the by PCA9633.
	- Buck convertor controller is TPS54302 and can take up to 26V, but the maximum voltage is limited by the voltage rating of the input capactior, thus the true maxinum input voltage is 16V. The under voltage lockout is controlled by the resisistor R3 and R4 and is set to stop at 10V and restore at 11V to protect the battery for ecess drainage. The output voltage is set by the feed back resistors R1 and R2 to 5V to power the RPi. The output of the buck convertor is connected to an OR-ing diode made up of the PFET and matched PNP transistors and then directly to 5V net of the RPi. It is safe to connect both 5V from USB power connector and the 5V from the buck convertor. All the rest of the components are powered by RPi's 3.3V line.
		- There are 4 components connected to the ARM I2C line:
			- Current sensor INA219 at 0x40.
			- PWM controller PCA9633 at 0x03 (reset), 0x62 (normal).
			- 9-axis IMU MPU9250 at 0x69.
			- Real time clock DS3231M at 0x68. This device should be claimed by the kernel driver through `config.txt` settings.
		- GPS module FGPMMOPA6C is connected to the ARM UART line. You need to either disable to UART or use mini-UART for the Bluetooth for RPi3 through `config.txt` to have stable communication with the GPS module. 
	- A coin cell battery is provided to use and backup supply for the real time clock and the GPS.
