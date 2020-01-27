# Exercises made in one of the 3rd year Embedded Software course
```
All exercises are made during fall 2019 
and most of them are implemented on Arduino using Atmel Ice debugger in between.
```

## Exercise descriptions
**Exercise 1:**  
Connect 3 LEDs (red, yellow and green) to Arduino's digital pins (USE 220 OHM RESISTORS!)  
Code traffic lights (red -> red & yellow -> green -> yellow -> red), use delays wisely  
  
**Exercise 2:**  
**1.**  
Find the datasheet of the 7-segment display (part number MAN3920A)  
Notice that all segments (including decimal point) in the display are LEDs (so remember 220 ohm resistors!)  
7-segment displays have either common anode or common cathode, find out what this means and how to connect the component to Arduino and breadboard. Also: what do you write to LED to turn it on if it is an anode or cathode?  
**2.**  
Test first that you can get all LEDs of the 7-segment display on and off  
**3.**  
Use the following pin settings (any other pin settings -> 0 points), A-G means segments, 2-8 Arduino's digital pins:
A - 2  
F - 3  
E - 4  
D - 5  
C - 6  
G - 7  
B - 8  
**5.**  
Do not use any 7-segment libraries that may exist in Internet (if used -> 0 points)  
**6.**  
Make 7-segment display to repeat the following functionality (remember modularity!):  
- blink number 3 and letter E like this (3-E-3-E-3-E), so three times sequence 3-E
- make a circle counterclockwise three times (so LED's light up smoothly in order A-F-E-D-C-B…)
- turn all LEDs on at once and then off one by one (whichever order you like) until all LEDs are off; repeat this for three times
- make a circle clockwise three times  

**Exercise 3:**  
**1.**  
Measure room temperature with the thermistor (present in Celsius, use a look-up table (look-up table not used -> 0 points))
How do you show the room tempereature, when you have no display (please do not use any serial monitors)? Read Exercise 2 again to figure out the answer.  
**2.**  
Do not use any thermistor libraries that may exist in Internet (if used -> 0 points)  
**3.**  
Warm the thermistor between your fingers and see that the temperature reading changes  


**Exercise 4:**  
**1.**  
Implement a program that has four LEDs (2 x red, yellow, green)  
**2.**  
Green LED blinks: 1 second on 1 second off (inside loop())  
**3.**  
Changes in green LED's state triggers an interrupt (in Arduino pin 2)  
ISR controls one of the red LEDs  
Red LED number one changes its state so that **it is off when green LED is on and on when green LED is off**  
**4.**  
Yellow LED blinks: 0,5 second on and 0,5 second off (inside loop())  
**5.**  
Ghanges in yellow LED's state triggers another interrupt (in Arduino pin 3)  
Second ISR controls the other red LED  
Red LED number two changes its state so that **it is on when yellow LED is on and off when yellow LED is off**  
**6.**  
Re-use the [traffic lights code](https://github.com/jonneroni/embeddedSWExercises/blob/master/Exercise1a3/Exercise1a3_Trafficlights/Exercise1a3_Trafficlights/Exercise1a3/Sketch.cpp) (from exercise1) and use the [interrupts code](https://github.com/jonneroni/embeddedSWExercises/blob/master/Exercise4a2/Exercise4a2/exercise4a2/Sketch.cpp) (you did above). some way (you can decide, what your project does, but keep the traffic lights in your project).


**Exercise 5:**  
**1.**  
First, implement this [sequence diagram.](https://github.com/jonneroni/embeddedSWExercises/blob/master/Exercise5a2/sequenceDiagram.jpg)  
**2.**  
Divide code in 7 different files (Sketch.cpp, Led.h, Led.cpp, Thermistor.h, Thermistor.cpp, Math.h and Math.cpp)  
Right click the folder in Atmel Studio where your Sketch.cpp is -> Add -> New Item (add CPP file and Include File, remember to name them properly!)  
Note:  
you can (and have to) add parameters in some functions  
getVoltage() returns the ADC reading from thermistor (0-1024)  
returnBit(), you can decide bit type (int, byte, bool, etc.)  
Make sure you understand the bit checking operation: be  prepared to prove its correct operation on paper  
Do the math and conversions yourself (no copy-paste from Internet). Only use bitwise operations, mod and + in Math.cpp (so you need to figure out how to make e.g. bit checking and 2's complement using those operators only).  
**3.**  
Then, add a timer interrupt.  
Timer interrupt shall do something short (but noticable); you can choose what it does and at which time intervals  
This functionality shall be clearly documented in the code (as comments)  
It is up to you to decide how easy/difficult this added functionality is  


**Exercise 6:**  
You were given a [state diagram](https://github.com/jonneroni/embeddedSWExercises/blob/master/Exercise6_state5/State5.png) (see Files in your Redmine). Implement it. Commit to Git (when your code works and follows style guide), push to Redmine and demonstrate to teacher.  
Remember to comment your code properly (so that the comments say what the code does).  
