TARS_MorseCode
📡 Morse Code IoT Project with Blynk & ESP8266
This project converts text messages into Morse code using an ESP8266 microcontroller, displays the original and Morse text on an I2C LCD, and blinks an LED according to Morse patterns. The text input is sent through the Blynk IoT app.

🔧 Hardware Components
ESP8266 (e.g., NodeMCU)
I2C 16x2 LCD Display
LED
Jumper wires
Breadboard
Wi-Fi Connection
Buzzer
📱 Features
Enter text remotely using Blynk App (Virtual Pin V2)
Convert the text into Morse Code
Blink an LED for dots and dashes
Display both original text and Morse code on an LCD
📂 Code Highlights
Uses LiquidCrystal_I2C for LCD display
Uses BlynkSimpleEsp8266 to connect with Blynk cloud
Each character is translated using a function morseCode(char)
LED blinks . as short and - as long
LCD scrolls the Morse message if it overflows
💻 How It Works
Connect ESP8266 to Wi-Fi using your credentials.
Send any message from the Blynk app to Virtual Pin V2.
The message is displayed on the LCD's first row.
Corresponding Morse code is:
Shown on the second row of the LCD.
Represented with LED blinks (dot = short flash, dash = long flash).
📲 Blynk Setup
Template ID
Template Name
Auth Token
Add a Text Input Widget and link it to V2
📡 Network Setup
char ssid[] = "Prince Eeppakayal";
char pass[] = "1232Tars";

🧠 Author
Arnav Nair
Prince Eppakayal
Prithvi

