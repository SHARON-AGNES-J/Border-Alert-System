#include <LiquidCrystal.h>

#define BORDER_CROSSED 60
#define NEARING_BORDER 200
#define DOWN_KEY 400
#define WITH_IN_BORDER 600

#define GREEN_LED A2
#define ORANGE_LED A1
#define RED_LED A3

#define RELAY_MOTOR A4


//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd( pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(ORANGE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(RELAY_MOTOR, OUTPUT);
  
 lcd.begin(16, 2);
 lcd.setCursor(0,0);
 lcd.print ("BORDER TRACKING");
 lcd.setCursor(0,1); 
 lcd.print ("GIVE EVENT"); 
 
}
void loop() {
 int x;
 x = analogRead (0);
 lcd.setCursor(0,0);
 if (x < BORDER_CROSSED) {
    lcd.setCursor(0,0);
   lcd.print ("BORDER CROSSED");
    lcd.setCursor(0,1);
    lcd.print ("MOTOR OFF RED ON");
    
  digitalWrite(GREEN_LED, LOW); // turn the LED on (HIGH is the voltage level)
  digitalWrite(ORANGE_LED, LOW); // turn the LED on (HIGH is the voltage level)
  digitalWrite(RED_LED, HIGH); // turn the LED on (HIGH is the voltage level)

  digitalWrite(RELAY_MOTOR, LOW); // turn the LED on (HIGH is the voltage level)
 }
 else if (x < NEARING_BORDER) {
   lcd.print ("NEARING BORDER");
   lcd.setCursor(0,1);
    lcd.print ("MOTOR ON ORG ON");

  digitalWrite(GREEN_LED, LOW); // turn the LED on (HIGH is the voltage level)
  digitalWrite(ORANGE_LED, HIGH); // turn the LED on (HIGH is the voltage level)
  digitalWrite(RED_LED, LOW); // turn the LED on (HIGH is the voltage level)

  digitalWrite(RELAY_MOTOR, HIGH);
 }
 else if (x < DOWN_KEY ){
   lcd.print (" ");
 }
 else if (x < WITH_IN_BORDER){
   lcd.print ("WITHIN BORDER");
    lcd.setCursor(0,1);
    lcd.print ("MOTOR ON GRN ON ");

    digitalWrite(GREEN_LED, HIGH); // turn the LED on (HIGH is the voltage level)
  digitalWrite(ORANGE_LED, LOW); // turn the LED on (HIGH is the voltage level)
  digitalWrite(RED_LED, LOW); // turn the LED on (HIGH is the voltage level)

  digitalWrite(RELAY_MOTOR, HIGH);
 }
 else if (x < 800){
   lcd.print ("Select");
 }
}
