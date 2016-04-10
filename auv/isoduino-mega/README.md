# Isoduino Mega 640/1280/2560

__Author:__ Bei Chen Liu

__Description:__ An isolated Arduino Compatible development board specially designed for robotics operation.

__Features:__
* Isolated UART to protect computer from motor noise.
* Switching regulator to allow bigger range of voltage input.

__3D Rander:__ ![](isoduino-mega_lay_3d1.png)

__Schematic:__ ![](isoduino-mega_sch_s1.jpg) ![](isoduino-mega_sch_s2.jpg) ![](isoduino-mega_sch_s3.jpg)

__Layout:__ ![](isoduino-mega_lay_l1.jpg) ![](isoduino-mega_lay_l2.jpg)

## Changelog:
### Version 1.3
- Change the non isolated mode name from 'USB Mode' to 'Bypass Mode'
- Added a power mux to handle power switching from isolated mode to bypass mode
- Added power LED for mode indication
- Change user LED behavior: LED will turn on if the pin is high
- Update components and front silk
- Added back silkscreen
