# Integrated Automatic antenna tuner, internal battery with a charger and speaker for QRP Labs QMX+ transceiver

The ATU is based on N7DDC's 7x7 ATU minituarized by Barb (WB2CBA):
https://antrak.org.tr/blog/usdx-sota-modular-all-mode-sdr-hf-transceiver-for-qrp-operations/
 
Custom firmware was written for the ATU.
 
Battery and charger is based on my previous work:
https://github.com/AC8L/PSU-for-uSDX-SOTA
 Which in turn, is also based on Barb's original design:
https://antrak.org.tr/blog/usdx-sdr-ssb-sota-transceiver-battery-pack/


I am releasing PCB fabrication files and code under open source license.

# Build steps at glance
1. Build QMX+
2. Build ATU
3. Upload ATU custom firmware to PIC16F1938 and plug it to ATU board
4. Build QMX+ ATU Mount Board (insall ATU to the board and QMX+ connectors)
5. Build QMX+ ATU Companion Board. Keep power (battery) switch on the OFF position until the last moment before closing the enclosure top!
6. Upload companion board formware into ATMEGA328P chip. Use Ardiuno UNO board for that.
7. Install ATMEGA328P chip into the companion board
8. Install ATU mount board with ATU into the QMX+ board.
9. Insert 18650 batteries and install ATU Companion board on top of the ATU monut board. Make sure battery power switch is still on OFF position!
10. Insert QMX+ assembly with companion boards into its enclosure, screw in fron and back panels of the enclosure.
11. Switch ATU companion board's battery switch to the ON position.
12. Carefully insert and srew in QMX+ enclosure's top. 


Detailed Build Instructions TBD in-progress
