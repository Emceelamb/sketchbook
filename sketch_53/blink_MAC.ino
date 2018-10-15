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
void setup() {
  Serial.begin(9600);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
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
    Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
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
 
}