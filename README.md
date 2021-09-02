# Inerfacing-IR-Sensor-with-STM32F407-DISC1

https://www.google.com/imgres?imgurl=https%3A%2F%2F5.imimg.com%2Fdata5%2FCY%2FLS%2FQT%2FSELLER-7726776%2Fir-sensor-500x500.jpg&imgrefurl=https%3A%2F%2Fwww.indiamart.com%2Fproddetail%2Fir-sensor-21495675055.html&tbnid=4coXZz7WDk3HNM&vet=12ahUKEwjo89evtt_yAhVolEsFHThxDQ4QMygAegUIARDdAQ..i&docid=ajWGUJAYZtgbpM&w=500&h=500&q=IR%20Sensor&client=firefox-b-d&ved=2ahUKEwjo89evtt_yAhVolEsFHThxDQ4QMygAegUIARDdAQ

![image](https://user-images.githubusercontent.com/56625259/131780781-91a44542-356f-4deb-b3ec-7a2c8e44bb54.png)

In this project, the Obstacle LED on the IR Sensor module, and an external LED connected to PA7 when an obstacle is detected. This is achieved by configuring an external interrupt for the 'OUT' pin of the IR sensor module. When the IR sensor detects that something is nearby, it's 'OUT' pin goes low. Due to this, the'PA0' pin of the stm32f407 which is configured as an input, is connected to the 'OUT' pin of the sensor module. Whe he IR sensor module goes low, an external interrupt is generated, and the external LED connected to PA7 glows.


The connections made here are as follows,
| IR Sensor | STM32F407 |
|---|---|
| VCC | 5V |
| OUT | PA0 |
| GND | GND |

| LED | STM32F407 |
|---|---|
| Anode | PA7 |
| Cathode | To GND through a resistor |
