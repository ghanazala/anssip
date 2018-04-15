/*
Coded by Ghana Nazala, Athina Maria, Achmad Kripton, Muhammad Fadli
*/

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "LiquidCrystal_I2C.h"
#include "Keypad.h"
#include "MFRC522.h"
#include "SoftwareSerial.h"

int flag;
//Setup the pin for keypad
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte colPins[COLS] = {6, 7, 8}; //connect to the row pinouts of the keypad
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Set init for the LCD with address 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

MFRC522 nfc(10, A6);

// SoftwareSerial esp(A3, A2);
SoftwareSerial esp(A3, A2);

void displayMenu(uint8_t key)
{
  switch (key) {
    case '1': lcd.clear();
            lcd.setCursor(0, 0);
            lcd.printstr("1. Input Data");
            lcd.setCursor(0, 1);
            lcd.printstr("2. Check Data");
            break;
    case '2': lcd.clear();
            lcd.setCursor(0, 0);
            lcd.printstr("2. Check Data");
            lcd.setCursor(0, 1);
            lcd.printstr("3. Mulai Absen");
            break;
    case '3': lcd.clear();
            lcd.setCursor(0, 0);
            lcd.printstr("3. Mulai Absen");
            lcd.setCursor(0, 1);
            lcd.printstr("uda ga ada haha");
            break;
  }
  flag=1;
}

void pilihMenu()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.printstr("Pilih Menu :");
  lcd.setCursor(0,1);
  lcd.printstr("Pencet 1-3");
}

void setup()
{
  Serial.begin(9600);
  esp.begin(9600);
  //initialize the RFID
  SPI.begin();
  nfc.PCD_Init();
	// initialize the LCD
	lcd.begin();
  lcd.setCursor(0, 0);
	lcd.printstr("Front Page");
  lcd.setCursor(0, 1);
  lcd.printstr("Nyam");
  esp.print("AT\r");
}

void loop()
{

  /*
  char key = keypad.getKey();
  if (flag==0) {
    pilihMenu();
  }
	displayMenu(key);
  if (key=='*') {
    flag--;
  }*/

  // read from port 1, send to port 0:
    if (esp.available()) {
      int inByte = esp.read();
      Serial.write(inByte);
    }

    // read from port 0, send to port 1:
    if (Serial.available()) {
      int inByte = Serial.read();
      esp.write(inByte);
    }

}
