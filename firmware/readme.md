
## Pre-requisites

### 1. Arduno IDE

Download from https://www.arduino.cc/download_handler.php

#### 2. ESP8266 Addon
1. In your Arduino IDE, go to `File > Preferences`
2. Enter `https://arduino.esp8266.com/stable/package_esp8266com_index.json` into the `Additional Boards Manager URLs` field. Then, click the `OK` button
3. Open the Boards Manager. Go to `Tools > Board > Boards Manager`
4. Search for `ESP8266` and press install button for the `ESP8266 by ESP8266 Community`
5. It should be installed after a few seconds.
6. Choose board as `NodeMCU 1.0` and set erase to `ALL FLASH CONTENTS`. That’s it.

#### 3. Sensors
1. Open the Libraries Manager. Go to `Sketch -> Include Library -> Add .ZIP Library`
2. Choose `smart-pole/firmware/lib/Sensors`
