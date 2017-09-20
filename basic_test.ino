/* ISD 1820 Voice Recording Module (ISD1820) [S082] : http://rdiot.tistory.com/153 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

int Rec = 11;
int Play = 13;

void setup()
{ 
  pinMode(Rec, OUTPUT); 
  pinMode(Play, OUTPUT);

  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  delay(1000);

  lcd.clear();
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("S082:ISD1820 Module");

  digitalWrite(Rec, HIGH); // record 10sec
  lcd.setCursor(0,1);
  lcd.print("Rec: HIGH ");

  delay(10000);
  digitalWrite(Rec, LOW); // end record 
  lcd.setCursor(0,1);
  lcd.print("Rec: LOW  ");
  delay(5000);

  digitalWrite(Play, HIGH); // play 
  lcd.setCursor(0,1);
  lcd.print("Play: HIGH");
  delay(100);

  digitalWrite(Play, LOW); // stop play
  lcd.setCursor(0,1);
  delay(10000);
  lcd.print("Play: LOW ");      
}
