#include <ESP8266WiFi.h>

const char* ssid = "itpsandbox";
const char* password = "NYU+s0a!+P?";
WiFiServer server =(80);
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
  while(WiFi.status()!=WL_CONNECTED){
        // if never connected blink white.
        delay(1000);
        blinkCycle();
        Serial.println("Hold your horses! I'm still connecting!!!");
    }
    Serial.print("Connected to WiFi. IP: http://");
    Serial.print(WiFi.localIP());
    Serial.print("/\n");
    server.begin();

}
 
void loop() {

    wifiStatus = WiFi.status();    
    
    if(wifiStatus == WL_CONNECTED){
        // if connected blink green
        green();
        connectSuccess ++;

        checkClient();
        // Serial.println("I'm connected!!!");
    } else if(connectSuccess!=0){
        // if connect lost blink red
        red();        
        Serial.println("Womp Womp. I'm lost\nI was found");
    } 
    // print number of times it connected
    // Serial.println(connectSuccess); 
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

void checkClient(){
        WiFiClient client = server.available();
    if (client){
        digitalWrite(12,HIGH);
        while(client.connected()){
            while(client.available()>0){
                char c = client.read();
                Serial.write(c);
               
                
                client.println("Welcome to my server. :) ");
                
                delay(1);
            }
            delay(10);
        }
        digitalWrite(12,LOW);
        client.stop();
        Serial.println("Client disconnected");
    } 
}