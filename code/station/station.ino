#include <WiFi.h>
#include <WiFiClient.h>

const char *ssid = "YourSSID";     // Change to the same SSID as the AP ESP32
const char *password = "YourPassword"; // Change to the same password as the AP ESP32
const char *host = "192.168.4.1";   // Change to the IP address of the AP ESP32

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Connect to the server on the AP ESP32
  WiFiClient client;
  if (client.connect(host, 80)) {
    Serial.println("Connected to server");

    // Read data from the server
    while (client.available()) {
      Serial.println("test");
      Serial.println(client.read());
    }

    // Close the connection
    client.stop();
    Serial.println("Connection closed");
  }
  else {
    Serial.println("Connection failed");
  }

  // Wait before trying again
  delay(5000);
}
