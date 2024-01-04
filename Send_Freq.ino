// Pour l'envoi de données 
#include <TheThingsNetwork.h>
#include <TheThingsMessage.h>

// Set your AppEUI and AppKey
const char *appEui = "0101010101010101";
const char *appKey = "FFC02004B8509288E5A3B5C468436428";

#define loraSerial Serial1
#define debugSerial Serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

devicedata_t data = api_DeviceData_init_default;

// Pour le calcul cardiaque 

long instance1=0, timer;

double hrv =0, hr = 72, interval = 0;

int value = 0, count = 0;  

bool flag = 0;

#define shutdown_pin 10 

#define threshold 100 // to identify R peak

#define timer_value 10000 // 10 seconds timer to calculate hr

byte payload[1] ;

void setup()
{
  // setup pour l'envoi 
  loraSerial.begin(57600);
  debugSerial.begin(9600);

  // Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000)
    ;

  ttn.join(appEui, appKey);

  // setup pour le calcul cardiaque 

  Serial.begin(9600);

  pinMode(8, INPUT); // Setup for leads off detection LO +

  pinMode(9, INPUT); // Setup for leads off detection LO -

}

void loop()
{


  if((digitalRead(8) == 1)||(digitalRead(9) == 1)){

    digitalWrite(shutdown_pin, LOW); //standby mode

    instance1 = micros();

    timer = millis();

  }

  else {

    digitalWrite(shutdown_pin, HIGH); //normal mode

    value = analogRead(A0);

    value = map(value, 250, 400, 0, 100); //to flatten the ecg values a bit

    if((value > threshold) && (!flag)) {

      count++;  


      flag = 1;

      interval = micros() - instance1; //RR interval

      instance1 = micros(); 

    }

    else if((value < threshold)) {

      flag = 0;

    }
    
    if ((millis() - timer) > 60000) {

      hr = count;

      timer = millis();

      count = 0; 

      payload[0] = hr ;

      Serial.println(hr);

      ttn.sendBytes(payload, sizeof(payload));
    }

    hrv = hr/60 - interval/1000000;

    delay(10);

  }

}
