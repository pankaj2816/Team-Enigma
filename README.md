HackOnHills_4.0_Enigma
#Team-Enigma
Theme : Making Life easier

Project based on Earthquake detector and landsliding detection :
Natural calamities like earthquake and landslide have been frequent in the recent times. They cause a great harm to life and property. Resettlement of population and recovering the damage takes a lot of time. We have designed a system which detects earthquake in their initial stage and issues alert to the public and authorities on time. Hence the damage caused can be reduced to a greater extent and a number of lives can be saved.
The detector used is MPU6050. The MPU-6050 devices combine a 3-axis gyroscope and a 3-axis accelerometer on the same silicon die, together with an onboard Digital Motion Processor, which processes complex 6-axis Motion Fusion algorithms. The MPU 6050 is a 6 DOF (degrees of freedom) or a six-axis IMU sensor which means that it gives six values as output: three values from the accelerometer and three from the gyroscope. Here accelerometer readings will tell about the vibrations in tectonic plates while, on the other hand, gyroscope readings give the measure of inclination of hills.

Steps to follow :-
1.	Connect MPU-6050 with Arduino Uno according to specified pin diagram. Connect analog pins A4 and A5 of Arduino with SDA and SCL pins respectively of MPU-6050. Now output is taken from digital pins 12 and 13. Pin 12 corresponds to earthquake and Pin 13 corresponds to landslide readings. 
2.	Upload the code for the same on the Arduino board. Set the threshold for both the cases. 
3.	Connect the D6 and D7 pins of NodeMCU ESP8266 WiFi Module with the digital pin 12 and 13 of Arduino respectively.
4.	Send the data to the server. We have built Adafruit server to show the prototype. The data will show the possibility of landslide or earthquake in the location if the sensor reading exceeds threshold. It will also give warning messages to local residents.
