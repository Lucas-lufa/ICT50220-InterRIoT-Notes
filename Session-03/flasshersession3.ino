#define red 13
#define timeOn 50
#define pb 15
#define times 10

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(pb, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int switchStatus = digitalRead(pb);
  Serial.println(switchStatus);

  if (switchStatus == LOW){
    loop(timeOn, times)
  }
  
}

void ledOn(int ledPin){
  digitalWrite(red, HIGH);
  delay(timeOn);
}

void ledOff(int ledPin){
  digitalWrite(red, LOW);
  delay(timeOn);
}

void loop(int times){
  for(int i = 0; i <= times; i++){
    ledOn(red);
  }
}