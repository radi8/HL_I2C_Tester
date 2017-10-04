# HL_I2C_Tester

The purpose of this tester is to simulate the I2C output of a Hermes-Lite radio and in particular the beta 5 version of HL2. The tester will accept inputs from a set of digital outputs in the J16 connector style or from a USB connection from a computer as detailed below. The unit is built around an Arduino Nano which are very cheap from many sources and can be dedicated to this task or recovered when testing is complete as the user needs.

**1. The J17 Inputs:**

To enable a Hermes-Lite 1.x to drive filters designed for the I2C output of an HL2, a set of inputs are provided to mate with the J16 style output connector of an HL1 and are connected up as shown below

CN2        |     |Arduino Pins
-----------|-----|--------------------
01 USER6R  |---- |D12 Data in
02 GND     |---- |GND
03 USER5R  |---- |D11 Data in
04 GND
05 USER4R  |---- |D10 Data in
06 GND
07 USER3R  |---- |D9 Data in
08 PTTR    |---- |D2
09 USER2R  |---- |D8 Data in
10 COMR
11 USER1R  |---- |D7 Data in
12 USER0R  |---- |D6 Data in
13 3.3V    |---- |I2C Level Translator
14 N/C

The Arduino "Data In" pins are configured with pullups enabled so the open collector outputs of CN2 will pull them down on signal as is also the case with the PTTR line.
A signal on the data lines produce an active LOW output.
PTT is open collector so due to the pullups no signal = RX and a LOW will switch to TX.
The Arduino is run off 5 volts so a 5 volt to 3.3 volt level translator is needed for the I2C bus with 3.3 volts on the Hermes-Lite side. The 3.3v is picked up from CN2 Pin 13. A circuit diagram for a simple level translator for an I2C bus is included in the documentation.

**2. The USB input:**

For someone who either does not have an HL1x or HL2 but woukld like to do filter testing for the HL2 models which are driven from an I2C bus a band button press simulator has been written which will drive this Arduino project and produce the necessary I2C outputs to switch the filters. The test drive unit is written in Qt5 and has been compiled and tested on Linux Mint 18.1. There is no reason why it will not compile on Windows x or Mac. It is simply a matter of plugging the USB port of the computer to the USB port of the Arduino and choosing 9600 Baud N, 8, 1 and clicking connect. Clicking the band buttons will output the entered values. The computer interface is on this Git Repository.


