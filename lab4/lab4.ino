#include <LiquidCrystal.h>
int LEDs[] = {2,3,4,5,6,7}; // setup pins of leds
int lenled = sizeof(LEDs)/sizeof(LEDs[0]); // length of leds
int mid = lenled/2; // mid elem of lenled

LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // setup pins of lcd

void setup()
{
  // init of inputs
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  
  for(int i = 0; i <= lenled; i++){ //init of outputs
    pinMode(LEDs[i], OUTPUT);
  }
  
  lcd.begin(16,2); // setup lcd
}

void loop() {
  // read inputs
  int a1 = digitalRead(A1); 
  int a2 = digitalRead(A2);
  int a3 = digitalRead(A3);
 
  if (a3 == 0 && a2 == 0 && a1 == 0){
    turnoff();
  	welcome();
  }
  
  else if (a3 == 0 && a2 == 0 && a1 == 1){
    mode1();
  }

  else if (a3 == 0 && a2 == 1 && a1 == 0){
    pmeter();
  }

  else{
    turnoff();
  	lcd.setCursor(0,0);
    lcd.print("     Invalid    ");
    lcd.setCursor(0,1);
    lcd.print("      Input     ");
  }
}

void turnoff(){
  for (int i=0; i <= lenled; i++) // iterates all over LEDs[] and make it LOW
  {
    digitalWrite(LEDs[i], LOW);
  }
}     

void welcome(){ // shows a welcoming statement on the LCD
    lcd.scrollDisplayLeft(); // scroll one position left:
    lcd.setCursor(0,0);
    lcd.print(" Welcome to CAL ");
    lcd.setCursor(0,1);
    lcd.print("    Klasmeyt    ");
}

void mode1() // running but add 1 led pattern
{
  // shows "running" on the LCD display
  lcd.setCursor(0,0);
  lcd.print("    Running    ");
  lcd.setCursor(0,1);
  lcd.print("    Stay LED   ");
  //

  for (int onLed = 0; onLed <= lenled; onLed++) // nested for loop for the onLed (if 0 <= lenled)
  {
    for (int i=lenled-1; i >= onLed+1; i--) // loop for running towards the onLed
      {
        digitalWrite(LEDs[i], HIGH);
        delay(100);
        digitalWrite(LEDs[i], LOW);
      }
  digitalWrite(LEDs[onLed], HIGH);
  delay(100);
  }
  turnoff();  // turn off function to simultaneously turn off the lights after the loop (no delays)
}

void pmeter(){
  int a4 = analogRead(A4);
  lcd.setCursor(0,0);
  lcd.print("  Potentiometer  ");
  lcd.setCursor(0,1);
  lcd.print("      Input      ");

  for (int l=0,r=lenled; l<mid, r>mid-1; l++, r--){
    digitalWrite(LEDs[l], a4/4);
    digitalWrite(LEDs[r], (1023-a4)/4);
  }
}