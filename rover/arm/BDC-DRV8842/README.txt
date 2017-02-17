# DRV8842 DC Brushed Motor Driver (v2)

Second iteration of driver board for the brushed DC motors in Mars Rover arm.

## Notes:

- Custom version of TI DRV8842, datasheet: (http://www.ti.com/lit/ds/symlink/drv8842.pdf)

- This version incorporates two DRV8842 chips as opposed to one in the first version.

- It uses a single 80-pin LSEM connector for power, ground and outputs. This is connected to the Tiva controller via the arm backplane.

- For each chip, currents I0-I4 are the input currents, set to high (hardwired).

- For each chip, the DCY singals are the decay modes that are set ot high (hardwired) for fast decay.
