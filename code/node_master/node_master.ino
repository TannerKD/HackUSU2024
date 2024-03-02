/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is based on the Arduino WiFi Shield library, but has significant changes as newer WiFi functions are supported.
 *  E.g. the return value of `encryptionType()` different because more modern encryption is supported.
 */
#include "WiFi.h"

int rssi[5];
int thresh;

int avg[5];
int count;
// how many cycles to setup baseline
int setup_time=10;
// how often to reset average
int reset_time=200;

WiFiClient localClient;

const uint port = 80;
const char* ip = "192.168.4.1";
const char* password = "HACKUSU1";

void setup()
{
    Serial.begin(115200);
    count = 0;

    // Set WiFi to station mode and disconnect from an AP if it was previously connected.
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");
}

void loop()
{
    delay(100);
    Serial.println("Scan start");

    // WiFi.scanNetworks will return the number of networks found.
    int n = WiFi.scanNetworks();
    Serial.printf("Scan %d done \n", count);
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
        for (int i = 0; i < n; ++i) {
            //helps avoid false positives
            int node_id=100;
            if(slice(WiFi.SSID(i).c_str(),0,4)=="Node_"){
              Serial.printf("found %-32.32s", WiFi.SSID(i).c_str());
              int node_id = int(WiFi.SSID(i)[5])-48;
              Serial.printf("%d",node_id);
              Serial.println();
              rssi[node_id] = WiFi.RSSI(i);
              if(count<setup_time){
                avg[node_id] += rssi[node_id];
              }
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
    if(count == setup_time-1){
      for(int i=0;i<5;i++){
        avg[i]=avg[i]/setup_time;
        Serial.printf("Avg %d: ", i);
        Serial.printf("%d ", avg[i]);
      }
    }
     weakest();
    count == reset_time ? count=0: count++;
}

String slice(String myString, int startBit,int endBit){
  int numBits = endBit - startBit + 1;

  String extractedBits;
  for(int i=0;i<=endBit;i++){
    extractedBits = extractedBits + myString[i];
  }
  return extractedBits;
}

void weakest(){
  int low=0;
  for(int i=0;i<5;i++){
      if(rssi[i]<rssi[low]){low=i;}
  }
  Serial.printf("lowest: %d", low);
  turn_led_on_weakest(low);
}

void turn_led_on_weakest(int id){
    char* ssid;
    if(id==0){
      ssid = "Node_0";
    }
    else if(id==1){
      ssid = "Node_1";
    }
    else if(id==2){
      ssid = "Node_2";
    }
    else if(id==3){
      ssid = "Node_3";
    }
    else if(id==4){
      ssid = "Node_4";
    }
    else{
      return;
    }
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    Serial.println(WiFi.localIP());
    sendRequest();
}

void sendRequest() {

  for(int a=0; a<5;a++){
    if (localClient.connect(ip, port)) {                 // Establish a connection
      if (localClient.connected()) {
        localClient.println("GET /H");                      // send data
        Serial.println("[Tx] GET /H");
        delay(5000);
        localClient.println("GET /L");
        Serial.println("[Tx] GET /L");
        delay(3000);
        WiFi.disconnect();
        Serial.println("Disconnecting from wifi");
        return;
      }
    }
    else{
      Serial.printf("failed attepmt %d \n", a);
    }
 
  }
  
}
