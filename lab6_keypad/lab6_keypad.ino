#include <LiquidCrystal.h>
#include <Keypad.h>

const int bulb = 13; // pin of lightbulb
const int temperature = A5; // pin of temperature sensor

const String password_1 = "1A2B3C"; // change your password here
const String password_2 = "ABCD1234"; // change your password here
String input_password;

// FOR LCD
LiquidCrystal lcd(A0,A1,A2,A3,A4,2); // setup pins of lcd

//FOR KEYPAD
const byte rows = 4; //four rows
const byte cols = 4; //four columns
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[rows] = {11,10,9,8}; //connect to the row pinouts of the keypad
byte colPins[cols] = {7,6,5,4}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols );
//

void setup()
{
    pinMode(bulb, OUTPUT); // setup light bulb
    lcd.begin(16,2); // setup lcd
    Serial.begin(9600); // setup serial
}

void loop() {
    char key = keypad.getKey(); //gets the input from the keypad
    if (key != NO_KEY){ 
        DefaultLCD(); // prints enter your mode into the LCD
        lcd.print(key); // prints the keypad input into the LCD
        // Serial.println(key); // prints keypad inputs to serial monitor
        if (key == '*'){ // * clears the input of kepayd 
           String input_password = ""; // reset the inputted password
        }
        else if (key == '#'){ // # is like the submit button
            if(input_password == password_1){ // mode 1
                Lightbulb();
            }
            else if(input_password == password_2){ // mode 2
                Off_Bulb();
              	Celcius();
            }
            else{
              	Off_Bulb();
                Invalid_Input();
            }
            input_password = ""; // reset the input password
        }
        else {
            input_password += key; // append new character to input password string
        }
    }
}

void DefaultLCD(){ // shows "Enter Your Mode" to LCD
    lcd.setCursor(0,0);
    lcd.print("   Enter Your    ");
    lcd.setCursor(0,1);
    lcd.print("      Mode     ");
}

void Invalid_Input(){ // shows "invalid input" to LCD
    lcd.setCursor(0,0);
    lcd.print("     Invalid    ");
    lcd.setCursor(0,1);
    lcd.print("      Input     ");
}

void Lightbulb(){
    digitalWrite(bulb, 1); // turns on the bulb
    lcd.setCursor(0,0);
    lcd.print("Turn on       ");
    lcd.setCursor(0,1);
    lcd.print("Light Bulb    ");
}

void Off_Bulb(){
    digitalWrite(bulb, 0); // turns off the bulb
}

void Celcius(){
    int Temp = analogRead(temperature); // gets value from temp sensor
    float volts = (Temp / 965.0) * 5;  // https://www.javatpoint.com/arduino-temperature-sensor
    float celcius = (volts - 0.5) * 100;  // https://www.javatpoint.com/arduino-temperature-sensor
    lcd.setCursor(0,0);
    lcd.print("    Celcius   ");
    lcd.setCursor(0,1);
    lcd.print("              "); // clears the LCD
    lcd.setCursor(5,1);
    lcd.print(celcius);
}