# Airspeed Sensor
From the datasheet:
"The MS4525DO is a small, ceramic based, PCB mounted pressure transducer from Measurement Specialties...[it]  is fully calibrated and temperature compensated with a total error band (TEB) of less than 1.0% over the compensated pressure range. The sensor operates from single supply of either 3.3 or 5.0VDC and requires a single external component for proper operation.
The rugged ceramic transducer is available in side port, top port, and manifold mount and can measure absolute, gauge, differential, vacuum or compound pressure from 1 to 150psi. The 1/8? barbed pressure ports mate securely with 3/32? ID tubing."

## Inputs
- `+5V`: Voltage (supplied from board)
- `GND`: Ground
- `SCLK`: I2C Clock
- `SDA`: I2C Data

### Components Used
- `U1`: MS4525DO-DS TE Connectivity Airspeed Sensor
- `C1`: 100nF
- `R1 & R2`: 4.7k? 

#### [Datasheet to airspeed sensor](http://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Data+Sheet%7FMS4525DO%7FB2%7Fpdf%7FEnglish%7FENG_DS_MS4525DO_B2.pdf%7FCAT-BLPS0002)

