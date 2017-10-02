# Drone Kill Switch

__Author__: Bei Chen Liu

__Description__: A simple [high-side PMOS switch](http://www.onsemi.com/pub/Collateral/AND9093-D.PDF) to allow user to turn on or off high current components. Component values are highly configurable, please refer to previously linked document to set values.

## Component Explanations:
- **Q1**: P-Channel MOSFET, current and voltage rating required depend on application.
- **R1**: PMOS gate pull up resistor, disable the PMOS when the physical switch is open.
- **R2**: PMOS gate pull down resitor, forms a voltage divider with R1 to protect the gate from excessive gate-source voltage.
- **R3**: Resistor for external LEDs. Does not need to be populated if not used.
- **R4, D1**: LED indicator for input voltage. Does not need to be populated if not used.
- **R5, D2**: LED indicator for output voltage. Does not need to be populated if not used.
- **S1**: Connector for external switch. The kill switch will mimic the state of the external switch.
	- **Pin 1, Pin 2**: Ground connections.
	- **Pin 3**: Switch connection, connect swithch between this pin and ground to control the circuit.
	- **Pin 4**: External LED connection: connect the anode of the LED to this pin and cathod to ground. Use R3 as current-limiting resisitance. Can be left floating when not used. 

