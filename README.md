HackOnHills_4.0_Enigma
#Team-Enigma
Theme : Making Life easier

Project based on Earthquake detector and landsliding detection : 


Steps to follow :-
1.	Connect MPU-6050 with Arduino Uno according to specified pin diagram. Connect analog pins A4 and A5 of Arduino with SDA and SCL pins respectively of MPU-6050. Now output is taken from digital pins 12 and 13. Pin 12 corresponds to earthquake and Pin 13 corresponds to landslide readings. 
2.	Upload the code for the same on the Arduino board. Set the threshold for both the cases. 
3.	Connect the D6 and D7 pins of NodeMCU ESP8266 WiFi Module with the digital pin 12 and 13 of Arduino respectively.
4.	Send the data to the server. We have built Adafruit server to show the prototype. The data will show the possibility of landslide or earthquake in the location if the sensor reading exceeds threshold. It will also give warning messages to local residents.
