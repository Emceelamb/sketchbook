# 1 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
# 1 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino"
# 2 "/home/mark/code/sketch/sketchbook/sketch_54/sketch_54.ino" 2

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

void setup(){
    pinMode(RED, 0x01);
    pinMode(GRE, 0x01);
    pinMode(WHI, 0x01);

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
