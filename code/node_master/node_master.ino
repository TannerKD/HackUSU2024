/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is based on the Arduino WiFi Shield library, but has significant changes as newer WiFi functions are supported.
 *  E.g. the return value of `encryptionType()` different because more modern encryption is supported.
 */
#include "WiFi.h"

int rssi[5];
int thresh;

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected.
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");
}

void loop()
{
    Serial.println("Scan start");

    // WiFi.scanNetworks will return the number of networks found.
    int n = WiFi.scanNetworks();
    Serial.println("Scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            // Serial.printf("%2d",i + 1);
            // Serial.print(" | ");
            // Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
            // Serial.print(" | ");
            // Serial.printf("%4d", WiFi.RSSI(i));
            // Serial.print(" | ");
            // Serial.printf("%2d", WiFi.channel(i));
            // Serial.print(" | ");
            int node_id=100;
            if(slice(WiFi.SSID(i).c_str(),0,4)=="Node_"){
              Serial.printf("found %-32.32s", WiFi.SSID(i).c_str());
              int node_id = int(WiFi.SSID(i)[5])-48;
              Serial.printf("%d",node_id);
              Serial.println();
              rssi[node_id] = WiFi.RSSI(i);
            }
            delay(10);
        }
    }
    Serial.printf("\n %d,", rssi[0]);
    Serial.printf(" %d,", rssi[1]);
    Serial.printf(" %d,", rssi[2]);
    Serial.printf(" %d,", rssi[3]);
    Serial.printf(" %d,", rssi[4]);


    // Delete the scan result to free memory for code below.
    WiFi.scanDelete();

}

String slice(String myString, int startBit,int endBit){
  int numBits = endBit - startBit + 1;

  String extractedBits;
  for(int i=0;i<=endBit;i++){
    extractedBits = extractedBits + myString[i];
  }
  return extractedBits;
}

int average(int[n] value){
  
}

void turn_led_on_weakest(){

}
