// Reconstructed 2026-10-23. New pin map; not the lost original firmware.
#include <Arduino.h>
#if defined(ESP32)
const int SENSOR=34, INPUT_A=27, INPUT_B=14, OUT=26, AUX=25;
const int ADC_MAXIMUM=4095;
#else
const int SENSOR=A0, INPUT_A=2, INPUT_B=3, OUT=8, AUX=9;
const int ADC_MAXIMUM=1023;
#endif
// OUT/AUX drive a transistor/module input, never an inductive load directly.
// Default OFF = LOW. Use a compatible active-HIGH driver for this reconstruction.

// INPUT_A is trigger; INPUT_B is echo. Limit ESP32 echo to 3.3 V.
float distanceCM(){digitalWrite(INPUT_A,LOW);delayMicroseconds(2);digitalWrite(INPUT_A,HIGH);delayMicroseconds(10);digitalWrite(INPUT_A,LOW);unsigned long t=pulseIn(INPUT_B,HIGH,25000UL);return t? t*0.0343f/2.0f:-1.0f;}

unsigned long last=0;float distance=-1;
void setup(){Serial.begin(115200);pinMode(INPUT_A,OUTPUT);pinMode(INPUT_B,INPUT);pinMode(OUT,OUTPUT);pinMode(AUX,OUTPUT);digitalWrite(OUT,LOW);}
void loop(){unsigned long now=millis();if(now-last>=80){last=now;distance=distanceCM();Serial.println(distance);}
 bool valid=distance>=2&&distance<=400;unsigned long period=distance<40?200:distance<80?600:1000;
 bool pulse=valid&&distance<=120&&(now%period<period/3);
 digitalWrite(OUT,pulse?HIGH:LOW);digitalWrite(AUX,valid?LOW:HIGH);
}
