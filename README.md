# LED_Display_arduino


Overview
--------------------------------------------
* Name: LED_Display_arduino
* Title: Arduino Based LED Display unit.
* Description: An Arduino Based LED Display unit with 15 LEDs and 20 lighting modes. 
  A Potentiometer selects mode and a push button activates selected mode.
* Author: Gavin Lyons
* URL: https://github.com/gavinlyonsrepo/LED_Display_arduino

Library
--------------------------
* Custom library written by author, Display_LED_library available at repository URL 
* Version 1.0.1 
* Display_LED_lib.h // to drive the LED arrays

Software Used
------------------
Arduino Version 1.8.5

Eagle Version 9.1.3

Files required
----------------------
* Main file. arduino_LED_Display.ino
* Custom library header. Display_LED_lib.h
* Custom library file. Display_LED_lib.cpp

Parts List
------------------------------
The schematic drawn in eagle is in docs folder. 

You will need following parts.

>
> ATmega328p micro-controller as per schematic or alternatively a Arduino uno/nano module.
>
> Resistors. 15 x 200ohms , 220ohms, 660ohms, 10K
>
> LEDS. (2.3V drop) 15, 5 red , 5 amber , 5 green 
>
> one 10 k potentiometer 
>
> one pushbutton
>
> one 16 Mhz crystal 
>
> One Lm317 voltage regulator 
>
> Capacitors. two x 22pF, three x 100nF , 1uF
>

Features
----------------------
The user selects the mode via the potentiometer whose ADC range 0->5 volts (10 bit 1023) are mapped to 1-20.
For each of the twenty modes. The user presses the push button to activate the mode. This starts an Interrupt service routine which reads pot value and changes the mode.  The push button is hardware de-bounced by a capacitor.

There are 15 LEDs, five red, five amber, five green.
These LED's have a 2.3V drop across them. so (Vs-Vd/R) = (5-2.3/200) = 15mA per LED for a total LED current consumption of 200mA when and if all LEDS are on in theory but internal resistence of chip drivers reduces this figure slightly.
The Maximum rated output for all GPIO pins  is 200mA so this design pushes the ATmega328p chip close to limit.

Actual measured Current consumption of the entire circuit:

1. 20mA, no LEDS on.
2. 200mA, All LEDS on 
3. 32mA, one LED on.


Most of the code is in a custom library developed for this project by author, called "Display_LED_lib".
The library is in the repository. 

The modes are 
1. All Leds off
2. All Leds on
3. All red Leds on
4. All amber Leds on
5. All green Leds on
6. knight rider_1  (led chaser)
7. knight rider_2  (led chaser)
8. knight rider_3  (led chaser)
9. knight rider_4  (led chaser)
10. Traffic light sequence
11.  All LEDS Flash on and off
12. flash red-amber-green in rapid  sequence
13. Fade in and out the 6 Leds are connected to pins with PWM capability 
14. Random 1 led turn on and off
15. Random 3 led turn on and off
16. Random Multiple LEDs from each array 
17. Police car lights
18. Rapid blink same as 11 but much faster.
19. Fancy Pattern 
20. Most modes combined in a repeat loop.

LED Array Pin Layout

| Pin Uno | Pin Atmega  | PWM  | Colour |   
| --- | --- | --- | --- |
|  D3 |  PD3 | Yes  | red  |   
|  D4  | PD4  | no  |  red |   
|  D5 |  PD5 |  Yes | red  |   
| D6  |  PD6 |  Yes |  red |   
|  D7 |  PD7 | no  | red  |   
| D8  | PB0  |  no |  amber |   
| D9  | PB1  |   Yes|  amber  |   
| D10  | PB2  |  Yes | amber   |   
| D11  | PB3  |  Yes | amber   |   
| D12  | PB4  |  no | amber   |   
| D13  | PB5  |  no |  green |   
|  A0 | PC0  |  no |  green |   
|  A1 | PC1  |  no |  green |   
|  A2 | PC2  |  no | green  |   
| A3  | PC3  |  no |  green |   



![schematic image ](https://github.com/gavinlyonsrepo/LED_Display_arduino/blob/master/docs/eagle/led_display.png)
 
Copyright
---------
Copyright (C) 2018 Gavin Lyons 
see LICENSE.md in documentation section 
for more details

