#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

const char *ssid = "YourSSID";     // Change to your desired SSID
const char *password = "YourPassword"; // Change to your desired password
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  
  // Initialize Wi-Fi in access point mode
  WiFi.softAP(ssid, password);
  
  Serial.println("Access Point started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loop() {
  // Wait for a client to connect
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");

    // Send data to the client
    client.print("Hello from ESP32 AP");

    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}
