# Electrical-Heater-AMIT

# AMIT: AVR Interfacing Project Electric Heater

Final Project In AMIT Learning Embedded Systems Diploma.  

## Project Overview 



This Project is a part of the AMIT Learning Embedded Diploma. It aims to demostrate the proficincy of writing bare metal derivers and interfacing with different inter and external MCU peripherals. 

The project is based on the Microchip ATmega32 Microcontroller. Which allows the user to set a desired temprature via push buttons and 7 Segment Display and then the device will control the Heating and Cooling Elements to reach the desired temprature and maintain it. Various compentnets of the ATmega32 have been utilized. Timers, ADC, DIO, EPPROM and Interrputs, just to name a few. 


## Technical Requirments 

![Picture1](https://user-images.githubusercontent.com/77552628/188188336-02be2e59-c079-402f-8ac9-d45186f85172.png)

### Specifications –Temperature Setting
1. “Up” or “Down” buttons are used to change the required water 
temperature (set temperature).
2. Pressing “Up” or “Down” button, enters the temperature setting mode.
3. After entering temperature setting mode, a single “Up” button press increase 
the set temperature by 5 degrees.
4. After entering temperature setting mode, a single “Down” button press 
decrease the set temperature by 5 degrees.
5. Minimum possible set temperature is 35 degrees.
6. Maximum possible set temperature is 75 degrees.
7. “External E2PROM” should save the set temperature once set.
8. If the electric water heater is turned OFF then ON, the stored set temperature 
should be retrieved from the “External E2PROM”.
9.   The initial set temperature is 60 degrees.

### Specifications –ON/OFF Behavior
1.   If power is connected to the heater, the electric water heater is in OFF state.
2.   If the “ON/OFF” button is released and the electric water heater is in OFF state, 
the electric water heater goes to ON state.
3.   If the “ON/OFF” button is released and the electric water heater is in ON state, 
the electric water heater goes to OFF state.
4.   In the OFF state, all display should be turned OFF.

### Specifications –Temperature Sensing
1.   The temperature sensor measures the water temperature.
2.   The water temperature should increase, if the “Heating Element” is ON.
3.   The water temperature should decrease, if the “Cooling Element” is ON.
4.    Temperature should be sensed once every 100 ms.
5.   The decision to turn ON or OFF either the “Heating Element” or the “Cooling 
Element” based on the average of the last 10 temperature readings.

###  Specifications –Heating/Cooling Elements
1.   The “Heating Element” should be turned ON, if the current water temperature is less 
than the set temperature by 5 degrees.
2.   The “Cooling Element ” should be turned OFF, if the current water temperature is less 
than the set temperature by 5 degrees.
3.   The “Heating Element ” should be turned OFF, if the current water temperature is 
greater than the set temperature by 5 degrees.
4.   The “Cooling Element” should be turned ON, if the current water temperature is 
greater than the set temperature by 5 degrees.

###  Specifications –Seven Segments
1.  Seven segment by default show the current water temperature or the set 
temperature.
2.  By default, the 2 seven segment display are show the current water 
temperature.
3.  If the electric water heater is in the temperature setting mode, the 2 seven 
segment displays should blink every 1 second and show the set temperature.
4.  In the temperature setting mode, every change in the set temperature should 
be reflected on the 2 seven segment displays.
5.  The 2 seven segment display should exit the temperature setting mode, if the 
“UP” and “Down” buttons are not pressed for 5 seconds.

###  Specifications –Heating Element Led
1.   If the “Heating Element” is ON, the “Heating Element Led” should blink every 1 
second.
2.   If the “Cooling Element” is OB, the “Heating Element Led” should be ON.

## Software 

<p align="center"><img  width="250" height="250" src="https://user-images.githubusercontent.com/77552628/188197139-ef6bbca8-52f0-4369-97d9-327c3e0a3322.png"></p>

MicroChip Stdio was used as a software development environment.Impelemting the Software Layed Achiturcre and Writing each layer from scratch. 

<p align="center"><img  width="250" height="250" src="https://user-images.githubusercontent.com/77552628/188197966-5469af03-a498-46f9-8ad9-5c5842da28a8.png"></p>

Protues was used as a Circuit Simultion software.

### FlowChart 
<p align="center"><img  src="https://user-images.githubusercontent.com/77552628/188196432-704cfcec-aaf0-4e8f-832a-270966370c94.svg"></p>

### Simulation 

<p align="center"><img  src="https://user-images.githubusercontent.com/77552628/188198564-84dcaaee-fb10-4a94-a15e-51779215a89d.png"></p>
