int LEDs[] = {2,3,4,5,6,7,8,9,10,11,12,13};
int lenled = sizeof(LEDs)/sizeof(LEDs[0]);
int mid = lenled/2;

void setup() {
  // put your setup code here, to run once:
    for(int i=0; i<=lenled; i++){
        pinMode(LEDs[i],OUTPUT);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
    for(int l=mid,r=mid ; l>=0, r<=lenled ; l--, r++){
        digitalWrite(LEDs[l-1],HIGH);
        digitalWrite(LEDs[r],HIGH);
        delay(200);
    }
    for(int l=mid,r=mid ; l>=0, r<=lenled ; l--, r++){
        digitalWrite(LEDs[l-1],LOW);
        digitalWrite(LEDs[r],LOW);
        delay(300);
    }
}
