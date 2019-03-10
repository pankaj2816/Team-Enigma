#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#define WLAN_SSID       "enigma"
#define WLAN_PASS       "enigma12"
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "anshul2498"
#define AIO_KEY         "0cdb29698e494b9d86ce0129b13ee767"
int earthquake,landslide;
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feed called 'photocell' for publishing.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish onn = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/ax");

// Setup a feed called 'onoff' for subscribing to changes.
Adafruit_MQTT_Publish off = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/bx");
void MQTT_connect();

void setup() {
  pinMode(13,INPUT);
  pinMode(12,INPUT);
    Serial.begin(9600);

  Serial.println(WLAN_SSID);
  Serial.print("Connecting to ");
  
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

MQTT_connect();

   }
uint32_t x=0;


void loop() {
earthquake=digitalRead(13);
 if(earthquake== HIGH)
    {    
  onn.publish(1);
  Serial.println("earthquake");
  delay(1000);
   }
   landslide= digitalRead(12);
   if(landslide== HIGH)
    {    
  off.publish(1);
  Serial.println("landslide");
  delay(1000);
   }
}

   void MQTT_connect() {
  int8_t ret;
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
   }
