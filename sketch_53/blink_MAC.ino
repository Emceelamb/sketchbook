#include <ESP8266WiFi.h>
#include <Servo.h>

Servo servo; 
// void setup(){
 
//    Serial.begin(9600);
//    delay(500);
 
//    Serial.println();
//    Serial.print("MAC: ");
//    Serial.println(WiFi.macAddress());
//     pinMode(13, OUTPUT);
// }
 
// void loop(){
//      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
//   delay(1000);              // wait for a second
//   digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
//   delay(1000);    
//   Serial.println("sup");
// }


const char* ssid = "itpsandbox";
const char* password = "NYU+s0a!+P?";
// const char* ssid = "iPhone";
// const char* password = "guest123";
 
int ledPin = 13; // GPIO13
WiFiServer server(80);
 int servoPos=90;


/* SOMETHING */
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

// nothing


void setup() {
  Serial.begin(9600);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
   pinMode(RED, OUTPUT);
    pinMode(GRE, OUTPUT);
    pinMode(WHI, OUTPUT);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  
  servo.attach(2); //D4

  servo.write(servoPos);

  delay(2000);

 
}
 
void loop() {
  // Check if a client has connected
  //   Serial.print("Use this URL to connect: ");
  // Serial.print("http://");
  // Serial.print(WiFi.localIP());
  // Serial.println("/");
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }

    if (request.indexOf("/SERVO=UP") != -1)  {
    servoPos += 10;  
    servo.write(servoPos);
 
  }

      if (request.indexOf("/SERVO=DOWN") != -1)  {
    servoPos -= 10;  
    servo.write(servoPos);
 
  }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");  


  client.println("<a href=\"/SERVO=UP\"\"><button>Servo UP </button></a>");
  client.println("<a href=\"/SERVO=DOWN\"\"><button>Servo DOWN </button></a><br />");  

  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
 // loop end
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