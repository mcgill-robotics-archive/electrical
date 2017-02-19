# DRV8842 DC Brushed Motor Driver (v2)

Second iteration of driver board for the brushed DC motors in Mars Rover arm.

## Notes:

- Custom version of TI DRV8842, datasheet: (http://www.ti.com/lit/ds/symlink/drv8842.pdf)

- This version incorporates two DRV8842 chips as opposed to one in the first version.

- It uses a single 80-pin LSEM connector for power, ground and the motor outputs OUT1, OUT2. This is connected to the Tiva controller via the arm backplane.

- IN1 and IN2 are the logic input controls fot OUT1 and OUT2 respectively.

- nRESET is the reset input: low initializes logic and disables H-bridge outputs.

- nSLEEP is the sleep mode input: high to enable device, low to enter sleep mode.

- nFAULT is the fault status: low when in fault condition.

- Currents I0-I4 are the input currents: set to high (hardwired).

- DCY singals are the decay modes: set ot high (hardwired) for fast decay.
