#include <ESP8266WiFi.h>

const char* ssid = "itpsandbox";
const char* password = "NYU+s0a!+P?";

// sets led pins
const int RED = 12;
const int GRE = 13;
const int WHI = 15;

// sets blink time
const int hightTime = 100;
const int lowTime = 100;

// set wifi indicator
int wifiStatus;
int connectSuccess = 0;


void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Something started!");

  pinMode(RED, OUTPUT);
  pinMode(GRE, OUTPUT);
  pinMode(WHI, OUTPUT);


  Serial.println("\n");
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

}
 
void loop() {
  
  // blinkCycle();

   wifiStatus = WiFi.status();
   
    if(connectSuccess==0){
        // if never connected blink white.
        white();
        Serial.println("Hold your horses! I'm still connecting!!!");
    }
    if(wifiStatus == WL_CONNECTED){
        // if connected blink green
        green();
        connectSuccess ++;
        Serial.println("I'm connected!!!");
    } else if(connectSuccess!=0){
        // if connect lost blink red
        red();        
        Serial.println("Womp Womp. I'm lost\nI was found");
    } 
    Serial.println(connectSuccess);
    delay(1000);    

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