int sensor1 = A0; // Pin for first sensor
int sensor2 = A1; // Pin for second sensor
int laser1 = 6;
int laser2 = 3;
int i = 0; 
int entering =false;
int exiting =false;
#include <Wire.h>
#include <LiquidCrystal_I2C.h> ;
LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  lcd.init();
  
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  Serial.begin(9600); 
  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);
 
}

void loop() {


  if (analogRead(sensor1) >1000) {
  entering =true;}
  
   while ((analogRead(sensor2)<1000)&& (entering==true)) 
    {
      }
   if (entering== true)
   {i++;
   lcd.clear();
  lcd.backlight();
   lcd.setCursor(0,0);
     lcd.print(i);
    Serial.println (i);
     Serial.println ("entering");
     entering =false;
         delay(500);

     }
     
    
     
    
     
   if (analogRead(sensor2) >1000) {
  { exiting =true;}
    while ((analogRead(sensor1) < 1000) && (exiting==true))
    {
    }
    if (exiting == true)
    {i--;
    lcd.clear();
  lcd.backlight();
   lcd.setCursor(0,0);
     lcd.print(i);
    Serial.println (i);
     Serial.println ("exiting");
     exiting = false;
    delay(500); 
    } 
  delay(500); 
  }
}
