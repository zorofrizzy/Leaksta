# Leaksta
Water Leakage Detection for household pipes.

#Equipment used
1. Arduino Uno Microcontroller Board
2. YF-S201  

#METHODOLOGY
The project uses two water flow ensors that work on the principle of Hall Effect.
An EMF is generated whenever water flows through the pipe and that voltage is read in the microcontroller.
The difference of the voltages tells us if there is any leakage or not.

difference = 0 (or minimal change means no leakage)
difference !=  0 (There is leakage)

#Future Scope

We shall try to pinpoint the exact point of leakage in the pipe. 
Adjustments for altitude difference would be added.
