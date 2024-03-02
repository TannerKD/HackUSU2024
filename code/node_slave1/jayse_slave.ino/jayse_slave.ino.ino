#include "WiFi.h"

const char* master_ssid = "node0";
const char* ssid        = "node2";
const char* password    = "1234567";
const int   id          = 3;
const int monitor_ids[1]= {5};
const int key[15]       = {6,10,14,15,21,22,26,33,35,39,55,65,77,91,143};
const int list[15][3]   = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18},
        {19, 20, 21},
        {22, 23, 24},
        {25, 26, 27},
        {28, 29, 30},
        {31, 32, 33},
        {34, 35, 36},
        {37, 38, 39},
        {40, 41, 42},
        {43, 44, 45}
    };
const int thresh = -65;

int out[19] = {0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_AP_STA);

  // connect to master
  Serial.println();
    Serial.print("[WiFi] Connecting to ");
    Serial.println(ssid);
  WiFi.begin(master_ssid,password);

  // start broadcasting
  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while(1);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int n=0;n<3;n++){
    char search_ssid = "node"+String(monitor_ids[n]);
    WiFi.scanNetworks(search_ssid);
    Serial.print(WiFi.SSID(n).c_str() + "\n");
    Serial.print(WiFi.RSSI(n));
    if(WiFi.RSSI(n)<thresh){
      int vtx[3] = list[index(key, id*n)];
      for(int v=0;v<4;v++){
        if(vtx[v]<19){
          out[v]++;
        }
      }
    }
  }

  client.write(out);
}

int index(int array[], int element) {
 for (int i = 0; i < 15; i++) {
      if (array[i] == element) {
          return i;
      }
    }
  return -1;
 }