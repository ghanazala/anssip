/*
Coded by Ghana Nazala, Athina Maria, Achmad Kripton, Muhammad Fadli
*/

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "LiquidCrystal_I2C.h"
#include "Keypad.h"
#include "MFRC522.h"

//Setup the pin for keypad
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte colPins[COLS] = {4, 3, 2}; //connect to the row pinouts of the keypad
byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Set init for the LCD with address 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

MFRC522 nfc(10, A6);

void setup()
{
  //initialize the RFID
  SPI.begin();
  nfc.begin();
	// initialize the LCD
	lcd.begin();
	lcd.print("Hello, test");
}

void loop()
{
	char key = keypad.getKey();

  if (key){
    lcd.print(key);
    delay(5000);
  }
}
