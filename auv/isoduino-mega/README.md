# Isoduino Mega640

__Author:__ Bei Chen Liu

__Description:__ An isolated Arduino Compatible devolopment board specially designed for robotics operation.

__Features:__ 
* Isolated UART to protect computer from motor noise.
* Switching regulator to allow big range of voltage input.

__3D Rander:__ ![](isoduino-mega_lay_3d1.png)

__Schematic:__ ![](isoduino-mega_sch_s1.jpg) ![](isoduino-mega_sch_s2.jpg) ![](isoduino-mega_sch_s3.jpg)

__Layout:__ ![](isoduino-mega_lay_l1.jpg) ![](isoduino-mega_lay_l2.jpg)


__AVRdude:__
'''
avrdude -P /dev/tty.usbserial-DA00WYQF -b 19200 -c avrisp -p m640 -v -e -U efuse:w:0xF5:m -U hfuse:w:0xD6:m -U lfuse:w:0xFF:m;
avrdude -P /dev/tty.usbserial-DA00WYQF -b 19200 -c avrisp -p m640 -v -e -U flash:w:/Users/baycken/Desktop/optiboot_atmega640.hex -U lock:w:0x0F:m
'''
