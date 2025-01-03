# ABS for QMX+ transceiver - V1.2
## (Integrated Automatic antenna tuner, internal battery with charger and speaker)

QMX+ Battery Charger and ATU Companion Board             |  QMX+ ATU Mounting Board | Back of the Companion board | All-in-One QMX+ Field minimalistic config
:-------------------------:|:-------------------------:|:-------------------------:|:-------------------------:
![](https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version1.2/Photos/IMG_1165.jpeg)  |  ![](https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version1.2/Photos/IMG_1161.jpeg)  |  ![](https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version1.2/Photos/IMG_1334.jpeg)  |  <img src="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version1.2/Photos/IMG_1172.jpeg" width=120% height=30%>

After Hans Summers (G0UPL) has released his <a href="http://qrp-labs.com/qmxp.html">QMX+ transeiver</a> - it quickly became popular both as a TRX and as a DIY development platform inviting projects like this.

I have made a prototype using QMX+ Dev Kit and later thought that the QRP communiuty would benefit from it too, so I designed PCB's to make the reproduction easier.

The ATU is based on N7DDC's 7x7 ATU minituarized by Barb (WB2CBA):
https://antrak.org.tr/blog/usdx-sota-modular-all-mode-sdr-hf-transceiver-for-qrp-operations/
 
<a href="ATU-100_Custom_Firmware">Custom firmware</a> was written for the ATU.
 
Battery and charger mod is based on my <a href="https://github.com/AC8L/PSU-for-uSDX-SOTA">previous work</a>, which in turn, is also based on Barb's <a href="https://antrak.org.tr/blog/usdx-sdr-ssb-sota-transceiver-battery-pack/
">original design.</a>

**I am releasing design materials, PCB fabrication files, and code under open source license and to be free for ham radio community to embrace and enjoy DIY building. Or commercially selling.**

**This is a humble attempt to contribute to QRP Labs noble mission of providing high quality low cost transmitters to hams to ease their entry to the hobby.**

**Anyone who wants to commercialize and sell this solution as modules, semi kit or as a full kit are allowed to do so under these terms:**

**- Commercial seller can not alter design and has to keep it in it’s original published form.</br>**
**- Recognition of originators and designers AC8L and WB2CBA for their work on their site.**

Because of minimum batch of 5 for the PCB order plus shipment, project is very well suited for the group build or club projects. If anyone wants to make money out of it - you have my blessings and prayers for the success!

There are active discussions on group build and group purchase on QRP Labs forum hosted by groups.io, please visit https://groups.io/g/QRPLabs.

I can only do a limited support and further development on best effort basis.

Sardar - AC8L, 4K6SA, VA3DUA.</br>
Vienna, VA 10/13/2024</br>
AC8L@ARRL.NET

### Notes for the ABS v1.2 release
Since the inception of ABS back in August 2024 there have been active discussions going on on QRP Labs forum. Version 1.2 has incorporated many of useful feedback provided through the forum. The release of version 1.2 would not be possible without that feedback. While it is difficult to name everyone who provded a feedback I want to acknowledge Cal (AD8Q), Stan (KC7XE), Jeff (W1NC) and Dirk (DK7CVD) who spent a tremendous amount of time (almost fulltime job) to build and test (and few times even scrap) intermediate revisions of PCB's at their own expense until design has stabilized.

# Build steps at a glance

**WARNING 1! Anyone who are about to try these experimental solutions are doing so at their own risk and I do not carry any repsonsibility for any loss as a result of trying proposed solution, including but not limited to the material loss or loss of health!!!**

**WARNING 2! Before you proceed with spending money and time, please take a note that the battery mod is compatible with QMX+ 12V build only!!! Do not use it with QMX+ built for 9V power supply, you will damage the rig!!!**

1. Build <a href="http://qrp-labs.com/qmxp.html">QMX+</a> with following mods:
   - Do not solder the jumper wire on JP501 as instructed on Rev2.00 build document's page 37! The ATU will play the role of that jumper wire.
   - Make sure to solder-in the 2-row 5-pin female connector into JP501.
   - Plug in a temporary jumper wire (breadboard prototyping wire is a good choice) into the female connector at JP501 at pins corresponding to a soldered jumper wire in the instruction document's page 37.
   - Thoroghly calibrate and test the QMX+ build according to the assembly manual. Making a couple of QSO's is a good idea.
   - Remove temporary jumper wire.
   - If QMX+ was already built and operational - carefully remove jumper wire on JP501, use suction tool to cleanup soldering pads and holes to prepare them for 2x5 female connector.     
2. Build ATU with <a href="https://antrak.org.tr/blog/usdx-sota-modular-all-mode-sdr-hf-transceiver-for-qrp-operations/">instructions at the WB2CBA's page</a> with following mods:
   - Do not source and solder two BNC connectors.
   - Do not source and solder the fixed 100uH inductor L8.
   - Do not source and solder male pin connectors to the ATU board. We will use different ones for our integration.
   - Use only ATU section of the page, ignore the rest for the purpose of this project.
3. Upload <a href="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/raw/refs/heads/version1.2/ATU-100_Custom_Firmware/QMX%2B_1938_EXT_board_V2_fw.hex.zip">ATU custom firmware from this repository</a> into the PIC16F1938 and plug it to the ATU board.
4. Build <a href="QMX+_ATU_Mount_Board_THT_v1.2/QMX_Plus_ATU_Mount_Board_THT_v1.2 - Front.jpg">QMX+ ATU Mount Board</a> (install the ATU itself and QMX+ connectors to the Mount board)
5. If building the ATU configuration of ABS - perform the front panel mod. We have 2 options for the front panel modification:
   - Printing the replacement front panel on a 3D printer (budget option). STL file can be downloaded from <a href="QMX+_Front_Panel_Mod_For_ATU/3D Prints/QMX+ Front Panel with ATU Control.stl">here.</a> PETG filament is recommended due to the outdoor exposure.
   - Ordering the front panel from JLCPCB (most aesthetically appealing option). When ordered along with other PCB's - the front panel will add negligeable cost. Otherwise if ordered separately the shipping cost to US (about $30) is the most cosiderable portion of the total cost. There are two versions of the PCB front panel:
     - with LED manually soldered from the back. Fabrication files are <a href="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/raw/refs/heads/version1.2/QMX%2B_Front_Panel_Mod_For_ATU/PCB%20version%20THT%20v1.0/GERBER-QMX_Plus%20Front%20Panel%20Mod_THT_v1.0.zip">here</a>.
     - with SMD LED factory-soldered on the front. Fabrication files are <a href="QMX+_Front_Panel_Mod_For_ATU/PCB version SMD with LED v1.1/Fabrication_Files">here</a>.
6. Build <a href="QMX+_ATU_Companion_Board_THT_v1.3/QMX_Plus_ATU_Companion_Board_THT_v1.3 - Front.jpg">QMX+ ATU Companion Board.</a> Keep power (battery) switch in the OFF position until the last moment before closing the enclosure top!
7. Upload <a href="QMX_plus_ATU_Companion_Board_ATMEGA328P/QMX_plus_ATU_Companion_Board_ATMEGA328P.ino">companion board firmware</a> into ATMEGA328P chip. Use Ardiuno UNO R3 board for that.
8. Install ATMEGA328P chip into the companion board
9. Install ATU mount board with ATU into the QMX+ board.
10. Insert 18650 batteries and install ATU Companion board on top of the ATU mounting board. Make sure battery power switch is still in OFF position!
11. Insert QMX+ assembly with companion boards into its enclosure, screw-in front and back panels of the enclosure.
12. Carefully insert and screw-in QMX+ enclosure's top.
13. Switch ATU companion board's battery switch to the ON position.

# Ordering PCB's
I personally have a habit ordering PCB's from <a href="https://jlcpcb.com">JLCPCB</a> (again, I am not affiliated with them!). For the convenience, all 5 PCB's can be ordered in one order.
1. ATU <a href="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/raw/refs/heads/version1.2/ATU%20Fabrication%20Files/ATU_Fabrication_Files.zip">(link to download fabrication files is here)</a>

*It is important to use fabrication files from this repository rather than original from Barb's page. BOM has been optimized for ABS to include currently available components and the entire power supply component circuit was removed. CPL file has been fixed for proper component placement.*

2. ATU Mount PCB - <a href="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/raw/refs/heads/version1.2/QMX%2B_ATU_Mount_Board_THT_v1.2/GERBER-QMX_Plus_ATU_Mount_Board_THT_v1.2.zip">fabrication files for latest revison</a>
3. QMX+ Companion PCB - <a href="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/raw/refs/heads/version1.2/QMX+_ATU_Companion_Board_THT_v1.3/GERBER-QMX_Plus_ATU_Companion_Board_THT_v1.3.zip">fabrication files for latest revison</a>
4. Optionally, order one of the versions of the front panel PCB:
     - with LED manually soldered from the back. Fabrication files are <a href="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/raw/refs/heads/version1.2/QMX%2B_Front_Panel_Mod_For_ATU/PCB%20version%20THT%20v1.0/GERBER-QMX_Plus%20Front%20Panel%20Mod_THT_v1.0.zip">here</a>.
     - with SMD LED factory-soldered on the front. Fabrication files are <a href="QMX+_Front_Panel_Mod_For_ATU/PCB version SMD with LED v1.1/Fabrication_Files">here</a>.
5. Rear panel PCB - <a href="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/raw/refs/heads/version1.2/QMX+_Rear_Panel_Mod_For_Battery_V1/GERBER-QMX_Plus Rear Panel Mod_v1.0.zip">fabrication files for latest revison</a>

*- If you are ordering PCB's from JLCPCB - for front and rear panels select black PCB color.*

*- If you are ordering PCB's from JLCPCB - for ALL the PCB's (except the ATU) - for the option of "Mark on PCB" - select "Order Number (Specify Position)".*

# Group build manager (organizer)
Usually in group builds it supoposed to be the responsibility of a group build manager to:
1. Order PCB's.
2. Assemble kit bags.
3. Burn Arduino bootloader and load the sketch from this repo into it.
4. Upload the ATU firmware from this repo into the PIC16F1938 microcontroller.
- Due to shipping restrictions, group build manager must not source and ship batteries, leaving their purchase for each individual participant.

# Build configurations
There are various build configurations possible:
1. All inclusive - ATU, battery, speaker.
2. ATU only
3. Battery only
4. Speaker only
5. ATU and battery
6. ATU and speaker
7. Battery and speaker
- For all configurations you still will have to order both - ATU Mount and Companion PCB's from this repositiry. Even if some portions will be left unpopulated - PCB's are mechanically and electrically interdependent on each other.  
- For configurations (3),(4) and (7) - you do not need to order the ATU.
- For configurations (2),(4) and (6) - you do not need to order the real panel PCB.
- For any non-complete configuration you can gradually add other components later on.
- Barb (WB2CBA) has <a href="https://antrak.org.tr/blog/usdx-sota-modular-all-mode-sdr-hf-transceiver-for-qrp-operations/">detailed instructions on the ordering process from JLCPCB at the ATU link</a> for both "plain" PCB's and PCB's with SMD components populated. It will be difficuilt to add anything else to his writings.

# Bill of Materials (BOM)
Discalimer: I am not affiliated with any supplier and do not receive any monetary or other benefit from referring to their products!
I am using USA suppliers, other regions have better suppliers for BOM sourcing.
## QMX+
 - 8xM3 Nylon screw, 6mm: http://shop.qrp-labs.com/SPAREPARTS/sparepartsqmx/hscrewm3p6
   - or from Digikey part 732-13704-ND
   - or from kit: https://a.co/d/bzrrWku
 - 3xM3 Nylon screw, 12mm: https://a.co/d/bzrrWku
   - or from Digikey part RPC2024-ND
 - 6xM3 Nylon Hex nut: https://shop.qrp-labs.com/m3nut
   - or from kit: https://a.co/d/bzrrWku
   - or from Digikey part 732-12637-ND
 - 3xM3 Nylon Hex Standoff spacer female-female, 11mm: https://shop.qrp-labs.com/hex11
   - or from Amazon: https://a.co/d/94ycTzV
   - or from Digikey part RPC4425-ND
 - 2xM3 Nylon Hex Standoff spacer female-female, 15mm - from kit: https://a.co/d/bzrrWku
   - or from Digikey part 36-25512-ND  
 - 2xM3 Nylon Hex Standoff spacer male-female, 20mm - from kit:  https://a.co/d/bzrrWku
   - or from Digikey part 36-25505-ND
 - JP101 one of 2x2 4-pin double row female connector: https://shop.qrp-labs.com/con2x2f
   - or from Amazon: https://a.co/d/acgPCxS
   - or from Digikey part S7105-ND
 - JP501: one of 2x5 10-pin double row female connector: https://shop.qrp-labs.com/con2x5f
   - or from Amazon: https://a.co/d/iHggplQ
   - or Digikey part 732-2861-ND
 - JP301: one of 1x4 4-pin single row female connector: https://shop.qrp-labs.com/con1x4f
   - or from Amazon: https://a.co/d/03AtQEI
   - or from Digikey part S7002-ND
 - JP106: one of 1x3 3-pin single row female connector: https://a.co/d/5E9IhZu
   - cut 3-pin module from the strip.
   - or from Digikey part S7001-ND
## ATU
 - See https://antrak.org.tr/blog/usdx-sota-modular-all-mode-sdr-hf-transceiver-for-qrp-operations/
 - Do not source and solther two BNC connectors
 - Do not source and solther the fixed 100uH inductor L8.
 - Do not source and solther male pin connectors to the ATU board. We will use different ones for our integration. 
 - two of 8-pin single row male pin header (Digikey part 664-G800W268018EU-ND)
   - Alternative from Amazon: https://a.co/d/2SuiWnt
   - just cut two 8-pin sections from the strip.
## ATU Mounting PCB
 - J1: 1x10 pin 2.54mm Female pin Header Connector Extra Tall: https://a.co/d/21eQjdI
   - the 1x6 connector from the same Amazon kit will be used for JP102 on a companion board BOM
   - or Digikey part SSW-110-03-T-S-ND
 - J2: JST XH2.54 PCB mount male connector: https://a.co/d/9YMnd1q
   - The pigtail from the same kit will be used for the LED connection from the front panel.
   - Although the same part is mentioned here and for the front panel - you need to source only one item.
 - J3: 2-pin single row male pin header: https://a.co/d/2SuiWnt
 - JP102: two 1x2 pin 2.54mm Male pin Header Connector Extra Tall: https://a.co/d/2l7o6wW
   - These are sold in a bulk, you will have to cut 1x2 out of it. Effectively, we will end up having one 2x2 double row Extra Tall Connector.
   - Same strip is used for the Companion board BOM.
 - JP106: 1x3 3pin 2.54mm male pin Header Connector Extra Tall: https://a.co/d/2l7o6wW
 - JP302: 4-pin single row male pin header (Digikey part 664-G800W268018EU-ND)
   - Alternative from Amazon: https://a.co/d/2SuiWnt 
 - JP501: 2x5 10-pin double row male pin header: https://a.co/d/dF83x28
   - cut 2x5 section from the strip.
## Companion PCB
 - U1: ATMEGA328P-PU (Digikey part ATMEGA328P-PU-ND)
   - For Digikey part you will have to burn the Arduino bootloader. Instructions: https://www.youtube.com/watch?v=AwbcOT2z69k
   - If you want to source the ATMEGA with bootloader burned: https://a.co/d/9rrcNaf
 - Y1: 16Mhz Crystal (Digikey part 3155-16M20P2/49US-ND)
 - U2,U6: CD4066BE bilateral switch (Digikey part 296-2061-5-ND)
 - U3: LM386N-4 Operational amplifier (Digikey part 296-43960-5-ND)
 - U4,U5,U7 - 18650 battery holder (THT) (Digikey part 36-1043-ND) 
 - U8: 1xBMS battery charger/protection board https://a.co/d/gX6wQ45
   - Sometimes one vendor is unavailable, other comes in. But these parts are generally are always available. Make sure to source 3S 40A 12.6V model!
 - 3x18650 Lithium Batteries. 18650BatteryStore.com part number INR18650-25R.
   - These are original Samsung 25R 18650 2500mAh 20A Batteries. Not problematic ones from Amazon and a such.
   - Alternative from Digikey, part number 1568-1488-ND
 - D1 3mm LED (Digikey part 732-5008-ND)
   - Feel free choising different colors.
 - R1,R2: 3K THT Resistor (Digikey part 13-MFR-25FRF52-3KTR-ND)
 - R3: 10K THT Resistor (Digikey part 13-MFR-25FRF52-10KCT-ND)
 - R4: 7.5K THT resistor (Digikey part MFR-25FRF52-7K5)
 - R5: 10 Ohm THT resistor (Digikey part 10.0XBK-ND)
 - R6: 750 Ohm THT resistor (Digikey part 13-MFR-25FRF52-750RCT-ND)
 - C1,C2: 22pF ceramic capacitor THT (Digikey part BC1055CT-ND) 
 - C3: 1000uF electrolytic capacitor THT (Digikey part 1189-1583-1-ND)
 - C4: 47nF ceramic capacitor THT (Digikey part BC5153-ND)
 - C5,C6: 100uF electrolytic capacitors THT (Digikey part 399-6601-ND)
 - 1x28Pos DIP Socket for U1 (Digikey part A120353-ND). If you bought ATMEGA from Amazon with socket included - you do not need this.
 - 2x14Pos DIP Socket for U2 and U6 (Digikey part AE9989-ND)
 - 1x8Pos DIP Socket for U3 (Digikey part A120347-ND)
 - SW1: PCB Mount Slide Switch THT Right angled (Digikey Part EG1917-ND)
 - J1: 1x10 pin 2.54mm Male pin Header Connector Extra Tall: https://a.co/d/2l7o6wW
   - These are sold in a bulk, you will have to cut 1x10 out of it. Do not worry, we use some for the ATU Mount PCB as well.
 - JP102: 2x3 6pin 2.54mm connector, long needles: https://a.co/d/4Ca8vJi
   - For JP102 we need 2x2 female connector. But again, I could not source one with long needes. So, I just cut two side needles leaving plastic part intact.  
 - JP106: 1x6 6pin 2.54mm Female Socket Long needle stackable header: https://a.co/d/21eQjdI
   - For JP106 we need actually 3-pin connector. However I could not source one with long needles. So, I just cut 3 pins. Leaving the plastic though intact!
 - "ATU Firmware": 3-pin single row male pin header (Digikey part 664-G800W268018EU-ND)
   - Alternative from Amazon: https://a.co/d/2SuiWnt 
 - Jumper pin shorting (shunt connector) for "ATU Firmware" selector jumper. Digikey part 952-2169-ND.
 - LS1: Speaker 2W 8Ohm 28mm: https://a.co/d/bBaHMG7
   - or Digikey part 102-3850-ND
 - Power supply/charger for batteries: https://a.co/d/hriKC1F
   - It is very important to use this recommended power supply for the best charging experience and from the safety perspective!  
 ## Front Panel
 - SW1:  Digikey part 2223-TS02-66-60-BK-160-LCR-D-ND
 - D1: 3mm LED (Digikey part 732-5008-ND)
 - J1: JST XH2.54 pigtail with PCB mount male connector: https://a.co/d/9YMnd1q
 - 2-pin jumper (Digikey part 1528-4934-ND)
 - 40cm of 30 AWG Kynar wire: https://a.co/d/ix2YHia
   - or Digikey part K229-ND

## Digikey part list
For the ordering convenience, below is the part list from Digkey for one build. List contains the vast majority of parts that can be sourced from Digikey except for some minor parts, like few pin headers and BMS battery charger.
https://www.digikey.com/en/mylists/list/7D3XLG5MMR

## Alternative US sourcing option
If you are located in US,  prefer brick & mortar style shopping and in addition are lucky enough to live near one of many <a href="https://www.microcenter.com">Microcenter</a> stores - it carries many if not all parts in the part list either individualy or in a variety of sets. Look at the Maker section of the store, prices are lower or competitve to Amazon. It may be worth paying a visit to the store, if not for the parts, but to replenish the <a href="https://www.bawls.com">BAWLS</a> stock for sure :smile:

## Approximate cost estimate 
 Below is a rough estimate (with most pessimistic unoptimized assumption) for few configurations based on 10/13/24 simulation of JLPCB ordering plus US shipment and, Digikey part list cost. Estimation is based on a minimum batch of 5 PCB order and can be significantly lower with higer batch size. With current inflation rates next year this info will be well outdated.
### All Inclusive
 - ATU: $115 per 5
 - ATU Mount PCB: $8.40 per 5
 - ATU Companion PCB: $8.40 per 5
 - shipment to US: $42
 - Total per 5 PCB of each and shipment: $174
 - Total per set of 3 PCB's of each type: 174/5 = approx. $35 
 - Total other parts per 1 build: approx 60$ + shipment.
 - Grand Total per 1 build: $105 max.
### Battery only
 - ATU Mount PCB: $8.40 per 5
 - ATU Companion PCB: $8.40 per 5
 - shipment to US: $26
 - Total per 5 PCB of each and shipment: $43
 - Total per set of 3 PCB's of each type: 43/5 = approx. $8.60 
 - Total other parts per 1 build: approx 15-20$.
 - Grand Total per 1 build: 30$ max.

# Detailed Build Instructions
Can be found <a href="ABS_for_QMX_Plus_Assembly_Instructions_v1.2.pdf">here.</a>

# ABS V1.2 Release notes
## ATU Mount PCB v1.2
 - Fixed proper routing of audio input to the switched output of QMX+ "Ear" front connector.
 - Added routing from ATU Bypass button to the J1 connector.
 - Widened Vcc (+5V) trace to the ATU +5V pad.
 - Added additional mounting M3 hole for better mechanical assembly between ATU Mounting PCB (v1.2) and Companion Board (v1.3).
## Companion Board V1.3
 - Fixed significant voltage drops (1-2.5V) due to narrow and long traces. Expected voltage drop between RX and TX now should not exceed 0.3V.
 - Changed on/off switch to an angled version for safety reasons. It now can be controlled with closed enclosure and newly intrioduced rear panel PCB.
 - Added two M3 mounting holes for better mechanical and electrical rigidity.
 - Added a second bilateral switch and curcuit to manipulate the ATU bypass button from Arduino code.
 - Added an "ATU Firmware" jumper for an easy switch between ATU Firmware V1 and V2 (beta). 
 ## Front Panel Modification
 - Removed an option of drilling the OEM front panel.
 ## Rear panel V1.0
 - Newly introduced.

# Known issues
 - For some taste the LED might be too bright. If that is the case, change R1 adn R2 values on Companion PCB to 2.2k or 3k, or 3.5k. Higher the values lower the brightness.

# Some future work:
- Test ATU and battery charger implications into the QMX+ performance in the context of the parasitic interference
- The speaker and amplifier was a last moment addition with a brief breadbord prototyping. Schematics will definitely benefit from fine tuning.
- Implement band switching for external amps through AUX port.
- Utilize upcoming BASIC script functionality in QMX+ to read SWR values from QMX+ itself and control ATU relays. Simplify ATU design by eliminating a transformer and Stockton bridge.
- Convert ATU design to use latched relays.