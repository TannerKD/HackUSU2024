# HackUSU2024
This is the Git repository for the hardware competition of Hack USU 2024.

Useful article to learn the implementation of the ESP32:
    https://randomnerdtutorials.com/getting-started-with-esp32/

# Useful Links

| Use | Link | Note |
|----------|----------|----------|
| ESP32   | https://randomnerdtutorials.com/getting-started-with-esp32/   | How to program the esp32   |
| WiFi NAN specs   | https://device.report/m/980bcb4db0863da46c502ee7c16a63f7606467778fe73fac7ffabcd3cfa5d207.pdf   | Nan Specification   |
| ESP 32 NAN Library   | https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/network/esp_nan.html   | ESP32 Specific docs  |




In order to program the ESP32 you can configure your arduino IDE:
1. Press 'File' then go to 'Preferences'
2. In the Preferences popup, type this in the prompt 'Additional Board Manager URLs:'
    https://dl.espressif.com/dl/package_esp32_index.json
3. Click 'Ok'
4. Press 'Tools' then 'Board: ' and finally 'Boards Manager'
5. This will open up a board manager prompt; you will want to install 'esp32' by Expressif Systems
6. Note to not download the one by Arduino. It will install, and you are ready to use the Arduino IDE to develop!

