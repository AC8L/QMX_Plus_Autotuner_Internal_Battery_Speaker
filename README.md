# Integrated Automatic antenna tuner, internal battery with a charger and speaker for QRP Labs QMX+ transceiver

The ATU is based on N7DDC's 7x7 ATU minituarized by Barb (WB2CBA):
https://antrak.org.tr/blog/usdx-sota-modular-all-mode-sdr-hf-transceiver-for-qrp-operations/
 
Custom firmware was written for the ATU.
 
Battery and charger is based on my previous work:
https://github.com/AC8L/PSU-for-uSDX-SOTA
 Which in turn, is also based on Barb's original design:
https://antrak.org.tr/blog/usdx-sdr-ssb-sota-transceiver-battery-pack/


I am releasing PCB fabrication files and code under open source license. Feel free to use materials in any way you think suitable.

Because of minimum batch of 5 for the PCB order plus shipment, project is very well suited for the group build. If anyone wants to make money out of it - you have my blessings and prayers for the success!

I can only do a limited support and further development on best effort basis.

# Build steps at a glance
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
12. Carefully insert and screw-in QMX+ enclosure's top.

# Ordering PCB's
I personally have a habit ordering PCB's from JLCPCB (again, I am not associated with them!). For the convenience, all 3 PCB's can be ordered in one order.
1. ATU (see link above to download fabrication files)
2. ATU Mount PCB - from this repo
3. QMX+ Companion PCB - from this repo

# Group build manager 
Usually in group builds it is the responsibility of a group build manager to:
1. Order PCB's.
2. Assemble kit bags.
3. Burn Arduino bootloader and load the sketch from this repo into it.
4. Upload the ATU firmware from this repo into the PIC16F1938 microcontroller.

# Build configurations
There are various build configurations posssible:
1. All inclusive - ATU, battery, speaker.
2. ATU only
3. Battery only
4. Speaker only
5. ATU and battery
6. ATU and speaker
7. Battery and speaker
- For all configurations you still will have to order both PCB's from this repositiry. Even some portions will be left unpopulated - PCB's are mechanically and electrically interdependent on each other.  
- For configurations (3),(4) and (7) - you do not need to order the ATU.
- For any non-complete configuration you can gradually add other components later on.
- Barb (WB2CBA) has detailed instructions on the ordering process at the ATU link above. It will be difficuilt to add anything else to his writing.

# BOM (currenly writing this section, wait until I remove this warning!)
Discalimer: I am not associated with any supplier and do not receive any monetary or other benefit from referring to their products!
I am using USA suppliers, other regions have better suppliers for BOM sourcing.
## QMX+
 - Various female pin Connectors TBD
## ATU
 - See https://antrak.org.tr/blog/usdx-sota-modular-all-mode-sdr-hf-transceiver-for-qrp-operations/
 - Do not source and solther two BNC connectors.
 - Do not source and solther male pin connectors to the ATU board. We will use different ones for our integration. 
 - Assortment of male pin connectors TBD
## ATU Mounting PCB
  - Connectors TBD
## Companion PCB
 - U1: ATMEGA328P-PU (Digikey part ATMEGA328P-PU-ND)
   - For Digikey part you will have to burn the Arduino bootloader. Instructions: https://www.youtube.com/watch?v=AwbcOT2z69k
   - If you want to source the ATMEGA with bootloader burned: https://a.co/d/9rrcNaf
 - U2: CD4066BE bilateral switch (Digikey Part 296-2061-5-ND)
 - U3: LM386N-4 Operational amplifier (Digikey part 296-43960-5-ND)
 - U8: 1xBMS battery charger/protection board https://a.co/d/gX6wQ45
   - Sometimes one vendor is unavailable, other comes in. But these parts are generally are always available. Make sure to source 3S 40A 12.6V model!
 - R1,R2: 1K THT Resistor (Digikey part )
 - R3: 10K THT Resistor (Digikey part )
 - R4: 7.5K THT resistor (Digikey part MFR-25FRF52-7K5)
 - R5: 10 Ohm THT resistor (Digikey part )
 - 1x28Pos DIP Socket for U1 (Digikey Part A120353-ND). If you bought ATMEGA from Amazon with socket included - you do not need this.
 - 1x14Pos DIP Socket for U2 (Digikey part AE9989-ND)
 - 1x8Pos DIP Socket for U3 (Digikey part A120347-ND)
 - TBD...
 
Detailed Build Instructions TBD in-progress

# Some work to be done:
- Test ATU and battery charger implications into the QMX+ performance in the context of the parasitic interference
- The speaker and amplifier was a last moment addition with a brief breadbord prototyping. Schematics will definitely benefit from fine tuning.
- Implement band switching for external amps through AUX port. Utilize LPF0 to LPF5 signals from QMX+.
