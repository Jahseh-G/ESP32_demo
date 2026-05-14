#include <Arduino.h>
#include <WiFi.h>

// put function declarations here:
const char* ssid = "iPhone";            // WiFi name
const char* password = "ggg0070312";    // WiFi password

void connectWiFi();                     // WiFi connection function


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);   // enable serial communication
  connectWiFi();          // call the WiFi connection function
}

void loop() {
  // put your main code here, to run repeatedly:

  // If the WiFi connection "drops"
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Reconnecting WiFi...");
    WiFi.disconnect();    // disconnect previous connections first
    connectWiFi();        // reconnect
    delay(3000);          // retry after 3 seconds
  }

  delay(1000);            // check WiFi status every second
}

// put function definitions here:
void connectWiFi() {
  WiFi.begin(ssid, password);         // Start attempting WiFi connection
  Serial.println("Connecting WiFi...");

  // "safe connection mode": wait for a maximum of 10 seconds,
  //           exit if connection fails to avoid system freeze
  int timeout = 20;     // 20 * 500ms = 10s
  
  // Wait for successful WiFi connection 
  // (print dots continuously until timeout if not connected)
  while (WiFi.status() != WL_CONNECTED && timeout > 0) {
    delay(500);
    Serial.print(".");
    timeout--;
  }
  Serial.println();

  // Print connection information after successful connection
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("-- WiFi Connected --");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());     // output the IP address of ESP32
  } else {
    Serial.println("-- WiFi Connect Timeout --");
  }

}