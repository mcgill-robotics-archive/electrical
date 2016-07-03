# Arm Encoder Interface

__Author:__ Steven Dahdah

__Description:__ Designed to bolt on to a CUI `AMT203-V` (or similar), and act as a quadrature counter with index channel. In addition, it can connect to an ams `AS5130-ASSP` absolute magnetic encoder to perform homing (using the three-wire PWM mode).

Communicates with a master device over SPI. Includes a serial port so it can be debugged and programmed with an external FTDI.