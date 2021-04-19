  #include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include <Arduino_JSON.h>

#include <ESP8266WiFi.h>


#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE);
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""

#define ssid ""
#define password ""
 
void setup()
{ 
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(500);
  WiFi.disconnect();
  WiFi.begin(ssid , password);
  Serial.println("connecting....");
while( WiFi.status() != WL_CONNECTED){
delay (50);
Serial.println("."); }
Serial.println(".");
Serial.println("connected"); 
Serial.println(WiFi.localIP());

Firebase.begin(FIREBASE_HOST ,FIREBASE_AUTH );
Firebase.setString ( "DHT_Sensor/Humidity", "Malak");
Firebase.setString ("DHT_Sensor/Temperature", "Malak");
  }
  
void loop()
{
    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");

   String  h_FB = String (h);
   String  t_FB = String (t);

   Firebase.setString ( "DHT_Sensor/Humidity" ,h_FB );
   Firebase.setString ( "DHT_Sensor/Temperature" ,t_FB );

  delay(1000);
} 
