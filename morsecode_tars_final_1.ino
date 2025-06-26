#define BLYNK_TEMPLATE_ID //put yopur own blynk template id
#define BLYNK_TEMPLATE_NAME "Morse Code" //your project name
#define BLYNK_AUTH_TOKEN //your blynk auth token
#define LED_PIN 15

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Prince Eeppakayal"; //you can add your own ssid and password
char pass[] = "1232Tars";

LiquidCrystal_I2C lcd(0x27, 16, 2);
String Text = "";       
String morseArray = ""; 

String morseCode(char c) {
  switch (toupper(c)) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case '0': return "-----";
    default: return " ";
  }
}

void dot() {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(200);
}

void dash() {
  digitalWrite(LED_PIN, HIGH);
  delay(600);
  digitalWrite(LED_PIN, LOW);
  delay(200);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

BLYNK_WRITE(V2) {
  String inputText = param.asStr();
  Text = inputText;
  morseArray = "";

  Serial.print("SANDESHA AAYA HAI!: ");
  Serial.println(Text);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(Text); 

  lcd.setCursor(0, 1); 

  for (int i = 0; i < Text.length(); i++) {
    char c = Text[i];
    String morse = morseCode(c);

    for (int j = 0; j < morse.length(); j++) {
      if (morse[j] == '.') {
        dot();
        morseArray += ".";
      } else if (morse[j] == '-') {
        dash();
        morseArray += "-";
      }
      
      lcd.setCursor(0, 1);
      if (morseArray.length() <= 16) {
        lcd.print(morseArray);
      } else {
        lcd.print(morseArray.substring(morseArray.length() - 16)); 
      }
    }

    morseArray += " "; 
    delay(500);
  }
}

void loop() {
  Blynk.run();
}
