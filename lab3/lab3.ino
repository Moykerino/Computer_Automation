// C++ code
int LEDs[] = {13,12,11,10,9,8};
int lenled = sizeof(LEDs)/sizeof(LEDs[0]);
int mid = lenled/2;

void setup()
{
  // init of inputs
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  
  //init of outputs
  for(int i = 0; i <= lenled; i++){
    pinMode(LEDs[i], OUTPUT);
  }
}
      
void loop()
{
  // read inputs
  int a1 = digitalRead(A1);
  int a2 = digitalRead(A2);
  int a3 = digitalRead(A3);
  int a4 = digitalRead(A4);
  
  if ((a1==1) && (a2==0) && (a3==0)&& (a4==0)) // 1000
  {
    mode1(); 
  }
  
  else if ((a1==0) && (a2==1) && (a3==0) && (a4==0)) //0100
  {
    mode2(); 
  }

  else if ((a1==0) && (a2==0) && (a3==1) && (a4==0)) //0010
  {
    mode3(); 
  }

  else if ((a1==0) && (a2==0) && (a3==0) && (a4==1)) //0001
  {
    mode4(); 
  }

  else if ((a1==0) && (a2==0) && (a3==1) && (a4==1)) //0011
  {
    mode5(); 
  }

  else if ((a1==0) && (a2==1) && (a3==1) && (a4==1)) //0111
  {
    mode6(); 
  }

  else if ((a1==1) && (a2==1) && (a3==1) && (a4==1)) //1111
  {
    mode7(); 
  }

   else if ((a1==1) && (a2==0) && (a3==0) && (a4==1)) //1001
  {
    mode8(); 
  }

  else{
    turnoff(); //off leds
  }
}

void turnoff(){
  for (int i=0; i <= lenled; i++) // iterates all over LEDs[] and make it LOW
  {
    digitalWrite(LEDs[i], LOW);
  }
}          

void mode1() // 
{
  // iterates all over LEDs[] up until the mid to make it HIGH
  // starts from left and right 
  for (int l=0, r=lenled; l <= mid, r >= mid; l++, r--)
  {
    digitalWrite(LEDs[l], HIGH);
    digitalWrite(LEDs[r-1], HIGH);
    delay(100);
  }
  
  if (lenled % 2 == 1) // if the no. of outputs are odd, turn on the middle
  {
    delay(100);
    digitalWrite(LEDs[mid], HIGH);
    delay(100);
    digitalWrite(LEDs[mid], LOW);
  }

  for (int l=mid, r=mid ; l >= 0, r <= lenled ;l--, r++) // From the middle, iterate all over LEDs[] to make it LOW
  {
    digitalWrite(LEDs[l-1], LOW);
    digitalWrite(LEDs[r], LOW);
    delay(100);
  }
}

void mode2() // running from right to left
{
  for (int i=lenled-1; i >= 0; i--) // iterates LEDs[] from the right to turn everything HIGH
  { 
    digitalWrite(LEDs[i], HIGH);
    delay(100);
  }

  for (int i=lenled-1; i >= 0; i--) // iterates LEDs[] from the right to turn everything LOW
  {
    digitalWrite(LEDs[i], LOW);
    delay(100);
  }
}

void mode3() // running backtoback
{
  for (int i=0; i <= lenled; i++) // iterates LEDs[] from the left to turn everything HIGH
  { 
    digitalWrite(LEDs[i], HIGH);
    delay(100);
  }

  for (int i=0; i <= lenled; i++) // iterates LEDs[] from the left to turn everything LOW
  {
    digitalWrite(LEDs[i], LOW);
    delay(100);
  }

  for (int i=lenled-1; i >= 0; i--) // iterates LEDs[] from the right to turn everything HIGH
  {
    digitalWrite(LEDs[i], HIGH);
    delay(100);
  }

  for (int i=lenled-1; i >= 0; i--) // iterates LEDs[] from the right to turn everything LOW
  {
    digitalWrite(LEDs[i], LOW);
    delay(100);
  }
}



void mode4() // running but add 1 led pattern
{
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

void mode5(){ // back to back but only 1 led per iteration
  for(int i=0; i <= lenled-1; i++){ 
        digitalWrite(LEDs[i], HIGH);
        delay(150);
        digitalWrite(LEDs[i], LOW);
        delay(150);
  }
  for(int i=lenled-2; i > 0; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(150);
        digitalWrite(LEDs[i], LOW);
        delay(150);
  }
}

void mode6(){
  for (int i=0; i < mid; i++){
    digitalWrite(LEDs[i], HIGH);
  }
  delay(200); //put delay on the outside of the loop to prevent one by one iteration of HIGH leds

  for (int i=0; i < mid; i++){
    digitalWrite(LEDs[i], LOW);
  }
  delay(200); //put delay on the outside of the loop to prevent one by one iteration of LOW leds

  for (int i=lenled-1; i >= mid; i--){
    digitalWrite(LEDs[i], HIGH);
  }
  delay(200); //put delay on the outside of the loop to prevent one by one iteration of HIGH leds

  for (int i=lenled-1; i >= mid; i--){
    digitalWrite(LEDs[i], LOW);
  }
  delay(200); //put delay on the outside of the loop to prevent one by one iteration of LOW leds
}

void mode7(){ // 3 simultaneous left to right pattern
  for(int i=0; i <= lenled-1 ;i++){
    Serial.println(i);
    digitalWrite(LEDs[i-2],HIGH);
    digitalWrite(LEDs[i-1],HIGH);
    digitalWrite(LEDs[i],HIGH);
    delay(100);
    digitalWrite(LEDs[i-2],LOW);
    digitalWrite(LEDs[i-1],LOW);
    digitalWrite(LEDs[i],LOW);
  }
}

void mode8(){
    for(int i=0; i<=lenled; i++) {
      digitalWrite(LEDs[i],HIGH);
    }
    
    for(int i=0; i<=lenled; i++) {
      digitalWrite(LEDs[i],LOW);
      delay(100);  
      digitalWrite(LEDs[i],HIGH);
      }
    
}
  


for (int l=mid, r=mid ; l >= 0, r <= lenled ;l--, r++) // From the middle, iterate all over LEDs[] to make it LOW
  {
    digitalWrite(LEDs[l-1], LOW);
    digitalWrite(LEDs[r], LOW);
    delay(100);
  }