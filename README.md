# HackUSU2024
This is the Git repository for the hardware competition of Hack USU 2024.

# Description
A method for tracking movement was created using six ESP32 boards configured in a grid pattern within a room. A single master node receives and interprets wifi signals from five slave nodes; these signals are interrupted when a body is placed in the way of the signal. Code is included within the 'Code' folder.

# Resources

| Use | Link | Note |
|----------|----------|----------|
| ESP32   | https://randomnerdtutorials.com/getting-started-with-esp32/   | How to program the esp32   |
| WiFi NAN specs   | https://device.report/m/980bcb4db0863da46c502ee7c16a63f7606467778fe73fac7ffabcd3cfa5d207.pdf   | Nan Specification   |
|  ESP 32 WiFi lib  |  https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/network/esp_wifi.html  | General library for WiFi with esp32 |
| ESP 32 NAN Library   | https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/network/esp_nan.html   | ESP32 Specific docs  |

# Acceptable Signal Strengths

| Signal Strength | Strength |
|------------|---------|
| -30 dBm | Amazing - Max achievable signal strength. Not ordinary or what you really want |
| -67 dBm | Very Good - Minimum signal strength for applications that require very reliable, timely delivery of data packets. |
| -70 dBm | Okay - Minimum signal strength for reliable packet delivery |
| -80 dBm | Not Good - Minimum signal strength for basic connectivity. Packet delivery may be unreliable. |
| -90 dBm | Unusable - Approaching or drowning in the noise floor. Funcionality unlikely |


In order to program the ESP32 you can configure your arduino IDE:
1. Press 'File' then go to 'Preferences'
2. In the Preferences popup, type this in the prompt 'Additional Board Manager URLs:'
    https://dl.espressif.com/dl/package_esp32_index.json
3. Click 'Ok'
4. Press 'Tools' then 'Board: ' and finally 'Boards Manager'
5. This will open up a board manager prompt; you will want to install 'esp32' by Expressif Systems
6. Note to not download the one by Arduino. It will install, and you are ready to use the Arduino IDE to develop!

