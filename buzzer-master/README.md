# Buzzer
Small buzzer to hide and will go off randomly, designed to be simple, cheap, and compact. Intended to be disposable.
The code can run on any Arduino or microcontroller, all you need is one digital output pin!

_Notes: The buzzer is meant to annoy for as long as possible without getting removed. To that end, try to ensure you don't ring too often or for too long otherwise it will give people more of a reason to be search for it, and make it easier to locate._

**_This system can be adapted to other things you want to go off randomly that can be controlled 'digitally', like lights or solenoids._**

### Approaches
There are to ways to approach this prank, the easiest is using an Arduino or another similar development board. This will reduce the complexity and labour needed, but potentially increase cost.

The other approach is making an embedded system. This will require more logistics to set up but will pay off when scaled up. This is based around programming a microcontroller directly; the provided designs use an ATtiny85 (should work for with a ATtiny13/25/45 as well) and making a circuit board or using a protoboard to connect other components.

### Easy route (Using an Arduino)
So you've decided to take the easier route, no shame in that.

#### Bill of materials
All these parts can be readily found in most hobbyist stores, such as Creatron. The tools can be borrowed from B&G.
- Arduino or other dev board. The Arduino Nano is particularly well suited for this
- Power source, ideally batteries. Should be >=6V, 9V batteries are simpler and cheaper than 4 AAs but won't last as long.
  - Connector for power source if needed. Having pre-installed lead wires makes things easier.
- DC buzzer
- Wire

Tools:
- Soldering iron
- Solder wire
- Electrical tape (optional)

#### Assembly
1. Solder your power source ground (negative, usually black) to any ground (GND) on the dev board
   - Skip this and the next step if you are using a power supply you can just plug into your dev board
2. Solder your power source positive (usually red) to the input power (VIN) or equivalent on the dev board
3. Solder the positive end of the buzzer to a digital output on you board
   - **Avoid pins D0 and D1 on Arduinos! Use D2 instead.**
4. Solder the negative end of the buzzer to a ground (GND) pin on the dev board

#### Programming and Deployment
1. Connect your dev board to your computer
2. Download and open the sketch in the "buzz" folder in your IDE of choice (probably Arduino)
3. Apply an adjustment you would like to the code
   - **Make sure you set the buzzer pin to the right value**
4. Upload the code to the dev board and see if it works
5. Before deploying, disconnect the board from the computer and use your final power source until you are certain it will work.
   - Observing two or three bursts should suffice.
   - If you are impatient you can upload a version with shorter intervals to have it run through a couple bursts quickly before reverting to your old values

### Harder Route (Embedded Design)
This will require more prep than the other route but can pay off if you are going for scale or merely the learning experience. The instructions for this will be more open ended than the other, as it is assumed you know or are more willing to figure things out.

### Bill of materials
- Microcontroller (ATtiny85 was used in the provided design)
  - Look into getting an IC socket so you can easily remove the microcontroller to reprogram it, at least for your first unit.
- DC buzzer
- 5V regulator (100mA capacity is plenty) (78L05Z is used in the design)
- NPN transistor or N-channel MOSFET (2N3904 was used)
- Two 1kOhm resistors
- 100nF capacitor (>=6V rating)
- Circuit boards or protoboard

Tools:
- You ought to know
- Breadboard (if using Arduino as ISP, see [Programming](#programming))
- Jumper wires (if using Arduino as ISP, see [Programming](#programming))
- Arduino (if using Arduino as ISP, see [Programming](#programming))

### Preparing circuit boards (if desired)
If you decide to have circuit boards made, there are EAGLE files prepared for you in the "buzzerPCB" folder. There are two versions, one that is more compact and makes use of surface mount parts which should be sent off to a professional PCB manufacturer to be made if desired. Due its size and shape it is easily panelized so you can easily get dozens of these made.

The other version is a single layer variant which uses entirely through-hole components. This one is meant to be made using the MIE makerspace (**_they'll make them free of charge_**, just don't be a dick to them) or anywhere else circuit boards can get milled. 

If you want to reach out to the MIE makerspace look them up on the MIE website, ask Mario, or ask third or fourth year mechs for help. We will not post their contact info here.

### Assembly
You've probably got this figured out anyway. Straight forward circuit board assembly if you went that way, if you opted for protoboard, good luck. Hopefully you can find some help in the schematics if needed regardless of the path chosen.

### Programming
Programming embedded microcontroller is up to you. A tried and true method we've used for AVR microcontrollers is using an Arduino as an ISP option in the Arduino IDE, this is pretty cheap since any spare Arduino can really used and it only requires six (6) jumpers and a breadboard to seat the microcontroller being programmed. However the details are out of the scope of a README like this so here's a link to a good tutorial for [programming an ATtiny85 using an Arduino as an ISP](https://create.arduino.cc/projecthub/arjun/programming-attiny85-with-arduino-uno-afb829). It will cover everything you need assuming you already have some core knowledge in using Arduinos.
