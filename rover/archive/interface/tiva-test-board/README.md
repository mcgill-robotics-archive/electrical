# Tiva Test Board

Test board for the [TI TM4C123GH6PM](http://www.ti.com/product/TM4C123GH6PM), the microcontroller we plan to integrate into all motor control boards and some power boards next year.

## Notes:

- Basically a custom version of [this](http://www.ti.com/tool/ek-tm4c123gxl) Launchpad Board, but with better decoupling, analog reference filtering, and no integrated debugger.

- Includes an 8-bit bidirectional level shifter for easier testing.

- Code can be uploaded to it from one of the TI Launchpads we purchased using the JTAG connector.

- Powered off the USB VBUS.
