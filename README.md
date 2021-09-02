# Inerfacing-IR-Sensor-with-STM32F407-DISC1

![image](https://user-images.githubusercontent.com/56625259/131781905-5f1c9c67-c7d4-485c-b4bf-7f9ad38e8f54.png)


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
