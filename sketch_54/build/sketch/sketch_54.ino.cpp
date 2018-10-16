#include <Arduino.h>
#line 1 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
#line 1 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
#include <ESP8266WiFi.h>

// sets led pins
const int RED = 12;
const int GRE = 13;
const int WHI = 15;

// sets blink time
const int hightTime = 100;
const int lowTime = 100;

// set wifi credentials
const char* ssid = "itpsandbox";
const char* password = "NYU+s0a!+P?";

// set wifi indicator
int wifiStatus;
int connectSuccess = 0;

#line 20 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
void setup();
#line 36 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
void loop();
#line 58 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
void red();
#line 63 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
void green();
#line 67 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
void white();
#line 72 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
void blinkCycle();
#line 20 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
void setup(){
    pinMode(RED, OUTPUT);
    pinMode(GRE, OUTPUT);
    pinMode(WHI, OUTPUT);

    Serial.begin(9600);
    Serial.print("somethingstarted");
    delay(10);

    Serial.println("\n");
    Serial.println(ssid);
    WiFi.begin(ssid, password);


}

void loop(){
    wifiStatus = WiFi.status();
    if(connectSuccess==0){
        // if never connected blink white.
        white();
        Serial.println("Hold your horses! I'm still connecting!!!");
    }
    if(connectSuccess == WL_CONNECTED){
        // if connected blink green
        green();
        connectSuccess ++;
        Serial.println("I'm connected!!!");
    } 
    else if(connectSuccess!=0){
        // if connect lost blink red
        red();        
        Serial.println("Womp Womp. I'm lost\nI was found");
    } 

    delay(10000);    
}

void red(){
    digitalWrite(RED, HIGH), delay(hightTime), digitalWrite(RED, LOW), delay(lowTime);
}


void green(){
    digitalWrite(GRE, HIGH), delay(hightTime), digitalWrite(GRE, LOW), delay(lowTime);
}

void white(){
    digitalWrite(WHI, HIGH), delay(hightTime), digitalWrite(WHI, LOW), delay(lowTime);
}


void blinkCycle(){
    red();
    green();
    white();
    delay(100);
}
