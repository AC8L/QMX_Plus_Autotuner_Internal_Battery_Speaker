# ABS for QMX+ transceiver - V2 (beta)
## (Integrated Automatic antenna tuner, internal battery with charger and speaker)

ABS ATU and Audio Amplifier Board             | ABS Battery Board | All-in-One QMX+ Field minimalistic config
:-------------------------:|:-------------------------:|:-------------------------:
![](https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version2-beta/Photos/IMG_1554.jpeg)  |  ![](https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version2-beta/Photos/IMG_1413.jpeg)  |  <img src="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version2-beta/Photos/IMG_1172.jpeg" width=120% height=30%>

**This branch is for ver 2 of a solution. It is beta, work is still in progress. For the latest stable release use main branch!**

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
**- Recognition of originators and designers AC8L, WB2CBA and N7DDC for their work on their site.**

Because of minimum batch of 5 for the PCB order plus shipment, project is very well suited for the group build or club projects. If anyone wants to make money out of it - you have my blessings and prayers for the success!

There are active discussions on group build and group purchase on QRP Labs forum hosted by groups.io, please visit https://groups.io/g/QRPLabs.

I can only do a limited support and further development on best effort basis.

Sardar - AC8L, 4K6SA, VA3DUA.</br>
Vienna, VA 10/13/2024</br>
AC8L@ARRL.NET

# Build steps at a glance

**WARNING! Before you proceed with spending money and time, please take a note that the battery mod is compatible with QMX+ 12V build only!!! Do not use it with QMX+ built for 9V power supply, you will damage the rig!!!**

1. Decide how you want to build the ABS ATU/Audio board:
  a. Using SMA connectors;
  b. Using coax jumper wires for QMX+ integration. 
2. If you decided on option (a), ignore this step. Otehrwise for option (b) - build <a href="http://qrp-labs.com/qmxp.html">QMX+</a> with following mods:
   - Do not solder the jumper wire on JP501 as instructed on Rev2.00 build document's page 37! The ATU will play the role of that jumper wire.
   - Make sure to solder-in the 2-row 5-pin female connector into JP501.
   - Plug in a temporary jumper wire (breadboard prototyping wire is a good choice) into the female connector at JP501 at pins corresponding to a soldered jumper wire in the instruction document's page 37.
   - Thoroghly calibrate and test the QMX+ build according to the assembly manual. Making a couple of QSO's is a good idea.
   - Remove temporary jumper wire.
   - If QMX+ was already built and operational - carefully remove jumper wire on JP501, use suction tool to cleanup soldering pads and holes to prepare them for 2x5 female connector.     
3. Build ABS ATU/Audio board.
4. Upload <a href="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version2-beta/ATU-100_Custom_Firmware/ABS_for_QMX_Plus_1938_board_V2.1_fw_00.hex.zip">ATU custom firmware from this repository</a> into the PIC16F1938 using supplied programming ICSP connector on the ATU PCB.
board)
5. Front panel replacement. We have 2 options for the front panel replcement:
   - Printing the replacement front panel on a 3D printer (budget option). STL files can be downloaded from <a href="ABS_Front_Panel_Mod_For_ATU/3D Prints/ABS Front Panel with ATU Control.stl">here.</a> PETG filament is recommended due to the outdoor exposure.
   - Ordering the front panel from JLCPCB (most aesthetically appealing option). When ordered along with other PCB's - the front panel will add negligeable cost. Otherwise if ordered separately the shipping cost to US (about $20) is the most cosiderable portion of the total cost. There are two versions of the PCB front panel:
     - with LED manually soldered from the back. Fabrication files are <a href="ABS_Front_Panel_Mod_For_ATU/PCB version THT v1.1/GERBER-ABS Front Panel Mod_THT_v1.1.zip">here</a>.
     - with SMD LED factory-soldered on the front. Fabrication files are <a href="ABS_Front_Panel_Mod_For_ATU/PCB version SMD with LED v1.2/Fabrication_Files/">here</a>.
6. Rear panel replacement. There are two versions of a rear panel replacement and each version has two options - 3D printed part or a PCB:
   - If ATU is being built with SMA connectors:
     - 3D printed <a href="ABS_Rear_Panel_Mod_For_Battery_V2/ABS Rear Panel Mod - SMA v2.2/3D Prints/ABS Rear Panel with Battery Slide Switch - V.2.2 - SMA.stl">variant</a>.
     - PCB variant:  Fabrication files are <a href="ABS_Rear_Panel_Mod_For_Battery_V2/ABS Rear Panel Mod - SMA v2.2/GERBER-ABS Rear Panel Mod SMA_v2.2.zip">here</a>.
   - If ATU is being built without SMA connectors (using internal coax jumper wires):
     - 3D printed <a href="ABS_Rear_Panel_Mod_For_Battery_V2/ABS Rear Panel Mod - No SMA v2.2/3D Prints/ABS Back Panel with Battery Slide Switch - V.2.2 - NO SMA.stl">variant</a>.
     - PCB variant:  Fabrication files are <a href="ABS_Rear_Panel_Mod_For_Battery_V2/ABS Rear Panel Mod - No SMA v2.2/GERBER-ABS Rear Panel Mod_v2.2_NO_SMA.zip">here</a>.

6. Build <a href="ABS_Battery_Speaker_PCB/ABS_Battery_Board_v1.5.2 - Front.jpg">ABS Battery and Speaker Board.</a> Keep power (battery) switch on the OFF position until the last moment before closing the enclosure top!
7. Insert 18650 batteries and install Battery and Speaker board on top of the ATU board. Make sure battery power switch is still on OFF position!
8. Insert QMX+ assembly with ABS solution installed into its enclosure, screw-in front and back panels of the enclosure.
9. Switch Battery board's switch to the ON position.
10. Carefully insert and screw-in QMX+ enclosure's top.

# Ordering PCB's
I personally have a habit ordering PCB's from <a href="https://jlcpcb.com">JLCPCB</a> (again, I am not associated with them!). For the convenience, all 3 PCB's can be ordered in one order.
1. ATU and Audio amp PCB. Fabrication files are <a href="ABS_ATU_Audio_Amp_PCB/Fabrication Files">here</a>.
2. Battery/Speaker PCB. Fabrication files are <a href="ABS_Battery_Speaker_PCB/GERBER-QMX_Plus_Battery_Board_v1.5.2.zip">here</a>.
3. Order one of the versions of the front panel PCB (see fabrication links above).
3. Order one of the versions of the rear panel PCB (see fabrication links above).

*If you are ordering PCB's from JLCPCB:*
 - for the front and rear panel PCBs from JLCPCB - select black PCB color.
 - for all PCB orders make sure for the option of "Mark on PCB" - select "Order Number (Specify Position)".

# Group build manager (organizer)
Usually in group builds it supoposed to be the responsibility of a group build manager to:
1. Order PCB's.
2. Assemble kit bags.
3. Burn Arduino bootloader and load the sketch from this repo into it.
4. Upload the ATU firmware from this repo into the PIC16F1938 microcontroller.
- Due to shipping restrictions, group build manager must not source and ship batteries, leaving their purchase for each individual participant.

# Build configurations
There are two possible build configurations:
1. All inclusive - ATU, battery, speaker (audio amplifier).
2. ATU and speaker (audio amp) only.  
- For configuration (2) you do not need to order the Battery and Speaker PCB. If you decide later that you want o add a battery board - you can do that. It is a non-destrcutive mod.
- Barb (WB2CBA) has <a href="https://antrak.org.tr/blog/usdx-sota-modular-all-mode-sdr-hf-transceiver-for-qrp-operations/">detailed instructions on the ordering process from JLCPCB at the ATU link</a> for both "plain" PCB's and PCB's with SMD components populated. It will be difficuilt to add anything else to his writings.

# Bill of Materials (BOM)
Discalimer: I am not associated with any supplier and do not receive any monetary or other benefit from referring to their products!
I am using USA suppliers, other regions have better suppliers for BOM sourcing.
## QMX+
 - 7xM3 Nylon screw, 6mm: http://shop.qrp-labs.com/SPAREPARTS/sparepartsqmx/hscrewm3p6
   - or from Digikey part 732-13704-ND
   - or from kit: https://a.co/d/bzrrWku
 - 2xM3 Nylon screw, 12mm: https://a.co/d/bzrrWku
   - or from Digikey part RPC2024-ND
 - 5xM3 Nylon Hex nut: https://shop.qrp-labs.com/m3nut
   - or from kit: https://a.co/d/bzrrWku
   - or from Digikey part 732-12637-ND
 - 3xM3 Nylon Hex Standoff spacer female-female, 11mm: https://shop.qrp-labs.com/hex11
   - or from Amazon: https://a.co/d/94ycTzV
   - or from Digikey part RPC4425-ND
 - 2xM3 Nylon Hex Standoff spacer female-female, 15mm - from kit: https://a.co/d/bzrrWku
   - or from Digikey part 36-25512-ND  
 - 1xM3 Nylon Hex Standoff spacer male-female, 15mm - from kit:  https://a.co/d/bzrrWku
   - or from Digikey part 36-25503-ND
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

## ATU / Audio Amp PCB
<img src="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version2-beta/ABS_ATU_Audio_Amp_PCB/ABS_ATU_Audio_Amp_PCB_v2.0- Front with Components Assembled 3D.png" width=50% height=50%>
<img src="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version2-beta/ABS_ATU_Audio_Amp_PCB/ABS_ATU_Audio_Amp_PCB_v2.0- Back.jpg" width=50% height=50%>

 - U4: LM386N-4 Operational amplifier (Digikey part 296-43960-5-ND)
 - 1x8Pos DIP Socket for U4 (Digikey part A120347-ND)
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
 - SW1: PCB Mount Slide Switch THT Right angled (Digikey Part EG1917-ND)
 - RF_IN,RF_OUT: angled SMA connectors, PCB mountable: (Digikey part 931-1361-ND)
   - Alternative from Amazon: https://a.co/d/7zYzlCo
 - 1 x BN43-202 Binocular core for tandem match 
 - 3 x T37-6 toroid core
 - 2 x T37-2 toroid core
 - 2 x T37-1 toroid core
   - All toroid cores and BN43-202 binocular core can be sourced from: https://kitsandparts.com/toroids.php
 - 0.50 mm / AWG24 enameled inductor wire: https://a.co/d/7Qasw5C
 - PIC ICSP programming header: 5 Position Header Connector (Digikey part: S5480-ND)

## Battery/Speaker PCB
<img src="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version2-beta/ABS_Battery_Speaker_PCB/ABS_Battery_Board_v1.5.2 - Front.jpg" width=50% height=50%>
<img src="https://github.com/AC8L/QMX_Plus_Autotuner_Internal_Battery_Speaker/blob/version2-beta/ABS_Battery_Speaker_PCB/ABS_Battery_Board_v1.5.2 - Back.jpg" width=50% height=50%>

 - U4, U5, U7 - 18650 battery holder (THT) (Digikey part 36-1043-ND)
 - U8: 1xBMS battery charger/protection board https://a.co/d/gX6wQ45
   - Sometimes one vendor is unavailable, other comes in. But these parts are generally are always available. Make sure to source 3S 40A 12.6V model!
 - 3x18650 Lithium Batteries. 18650BatteryStore.com part number INR18650-25R.
   - These are original Samsung 25R 18650 2500mAh 20A Batteries. Not problematic ones from Amazon and a such.
   - Alternative from Digikey, part number 1568-1488-ND
 - SW1: PCB Mount Slide Switch THT Right angled (Digikey Part EG1917-ND)
 - J1: 1x10 pin 2.54mm Male pin Header Connector Extra Tall: https://a.co/d/2l7o6wW
   - These are sold in a bulk, you will have to cut 1x10 out of it. Do not worry, we use some for the ATU Mount PCB as well.
 - JP102: 2x3 6pin 2.54mm connector, long needles: https://a.co/d/4Ca8vJi
   - For JP102 we need 2x2 female connector. But again, I could not source one with long needes. So, I just cut two side needles leaving plastic part intact.  
 - JP106: 1x6 6pin 2.54mm Female Socket Long needle stackable header: https://a.co/d/21eQjdI
   - For JP106 we need actually 3-pin connector. However I could not source one with long needles. So, I just cut 3 pins. Leaving the plastic though intact!
 - LS1: Speaker 2W 8Ohm 28mm: https://a.co/d/bBaHMG7
   - or Digikey part 102-3850-ND
 - Power supply/charger for batteries: https://a.co/d/hriKC1F
   - It is very important to use this recommended power supply for the best charging experience and from the safety perspective! The BMS module used in battery board is not a charger. Its purpose is to manage balanced battery charge and discharge.
 - U1: Mini-Voltmeter: https://a.co/d/epVwKYk

 ## Front Panel
 - SW1: Generic button: https://a.co/d/eFSJQzc
   - or Digikey part EG2025-ND
 - D1: 3mm LED (Digikey part 732-5008-ND)
 - J1: JST XH2.54 pigtail with PCB mount male connector: https://a.co/d/9YMnd1q
 - 2-pin jumper (Digikey part 1528-4934-ND)
 - 40cm of 30 AWG Kynar wire: https://a.co/d/ix2YHia
   - or Digikey part K229-ND

## Digikey part list
For the ordering convenience, below is the part list from Digkey for one build. List contains the vast majority of parts that can be sourced from Digikey except for some minor parts, like few pin headers and BMS battery charger.
https://www.digikey.com/en/mylists/list/WN7WP7HZ7G

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
(Work in progress)

# Known issues
 - ATU-100 design used for the ABS underperforms on 6m band. If using an ATU on a 6m band is absolutely important for you - build the ATU with SMA connectors. This way when using 6m - ATU can be unplugged from QMX+. Then you can either use a resonant antenna or look for a commercial ATU solution.

# Some future work:
- Design ATU based on Dave's (N7DDC) ATU-10 schematic using latching relays.
