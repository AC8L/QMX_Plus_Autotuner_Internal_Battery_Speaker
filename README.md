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
1. Build QMX+ with following mods:
   - Do not solther the jumper wire on JP501 as instructed on Rev2.00 build document's page 37! The ATU will play the role of that jumper wire.
   - Make sure to solder-in the 2-row 5-pin female connector into JP501.
   - Plug in a temporary jumper wire (breadboard prototyping wire is a good choice) into the female connector at JP501 at pins corresponding to a soldered jumper wire in the instruction document's page 37.
   - Thoroghly calibrate and test the QMX+ build according to the assembly manual. Making a couple of QSO's is a good idea.
   - Remove temporary jumper wire.    
2. Build ATU with instructions at the WB2CBA's page with following mods:
   - Do not source and solther two BNC connectors.
   - Do not source and solther male pin connectors to the ATU board. We will use different ones for our integration. 
3. Upload ATU custom firmware into the PIC16F1938 and plug it to the ATU board.
4. Build QMX+ ATU Mount Board (install the ATU itself and QMX+ connectors to the Mount board)
5. Build QMX+ ATU Companion Board. Keep power (battery) switch on the OFF position until the last moment before closing the enclosure top!
6. Upload companion board formware into ATMEGA328P chip. Use Ardiuno UNO board for that.
7. Install ATMEGA328P chip into the companion board
8. Install ATU mount board with ATU into the QMX+ board.
9. Insert 18650 batteries and install ATU Companion board on top of the ATU mounting board. Make sure battery power switch is still on OFF position!
10. Insert QMX+ assembly with companion boards into its enclosure, screw-in front and back panels of the enclosure.
11. Switch ATU companion board's battery switch to the ON position.
12. Carefully insert and srew in QMX+ enclosure's top. 


Detailed Build Instructions TBD in-progress
