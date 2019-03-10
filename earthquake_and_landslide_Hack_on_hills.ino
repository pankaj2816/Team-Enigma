#include "I2Cdev.h"
#include "MPU6050.h"


#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
float a,b,c,d,e,f;

MPU6050 accelgyro;
//MPU6050 accelgyro(0x69); // <-- use for AD0 high

int16_t ax, ay, az;
int16_t gx, gy, gz;


#define OUTPUT_READABLE_ACCELGYRO




int sensor_pin = 2;

int output_value;



void setup() {


   Serial.begin(115200);

   #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");


   Serial.println("Reading From the Sensor ...");

   }



void loop() {
  
   accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // these methods (and a few others) are also available
    //accelgyro.getAcceleration(&ax, &ay, &az);
    //accelgyro.getRotation(&gx, &gy, &gz);

    #ifdef OUTPUT_READABLE_ACCELGYRO
        // display tab-separated accel/gyro x/y/z values
//        Serial.print("a/g:\t");
        Serial.print(ax); Serial.print("\t");
        Serial.print(ay); Serial.print("\t");
        Serial.print(az); Serial.print("\t");
        Serial.print(gx); Serial.print("\t");
        Serial.print(gy); Serial.print("\t");
        Serial.print(gz); Serial.print("\t");
    #endif
a=ax;
b=ay;
c=az;
d=gx;
e=gy;
f=gz;
    output_value = analogRead(sensor_pin);

    Serial.println(output_value);
   if(a>2500 || a<-2500 || b>2500 || b<-2500)     //landslide
    {
      digitalWrite(13, 1);
      delay(1000);
    }
    if(d>400 || d<-400 || e>150 || e<-150 ||f>150||f<-150) //Earthquake
    {
       digitalWrite(12, 1);
       delay(1000);
    }
     digitalWrite(12, 0);
    digitalWrite(13, 0);
//    delay (1);

   }
