#define BLYNK_TEMPLATE_ID "TMPL3EJqR1VHx"
#define BLYNK_TEMPLATE_NAME "synus"
#define BLYNK_AUTH_TOKEN "dlrNk_KJT6Bminur7HF-A3jS7ah7ZfrC"

#include<DHT.h>
#include<BlynkSimpleEsp32.h>

const char* ssid="AndroidShare_1985";
const char* password ="sreeja@123";
const char auth[]= BLYNK_AUTH_TOKEN  ;

DHT dht(5,DHT11);
int pressure=34;
void setup() {
  // put your setup code here, to run once:
  pinMode(pressure,INPUT);
  dht.begin();
  Serial.begin(9600);
  Blynk.begin(auth,ssid,password);
}

void loop() {
  // put your main code here, to run repeatedly:
  int p=analogRead(pressure);
  int h=dht.readHumidity();
  Blynk.virtualWrite(V0,p);
  Blynk.virtualWrite(V1,h);
  if(p<2000 || h>90){
    Blynk.logEvent("high","Pressure and humidity values are Extreme.Take care!");
  }
  else if(p<2500 || h>80){
     Blynk.logEvent("medium","Pressure and humidity values are abnormal.Take care!");
  }
  else{
    Blynk.logEvent("low","Humidity and pressure levels are abnormal.Be cautious.");
  }
  Serial.println(h);
  Serial.println(p);
  Blynk.run();
  delay(2000);
}

