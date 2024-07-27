/* ------------------------------------------ *
 *
 * Traffic Light Simulator 1
 * 
 * SUMMARY TEXT
 * 
 * Name: 	 YOUR NAME
 *
 * Year: 	 2024
 * Semester: 2
 *
 * ------------------------------------------ */
// Imports

// Macros

#define RED_LED_1   13
#define RED_LED_2    7
#define AMBER_LED_1 12
#define GREEN_LED_1  8
#define GREEN_LED_2  4

#define PB_1		 2

// Variables

int buttonState = LOW;

// Set up device
void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(RED_LED_2, OUTPUT);
  pinMode(AMBER_LED_1, OUTPUT);
  pinMode(GREEN_LED_1, OUTPUT);
  pinMode(GREEN_LED_2, OUTPUT);
  
  pinMode(PB_1, INPUT);
  
  ledOn(RED);
  ledOn(RED_LED_2);
  ledOff(AMBER_LED_1);
  ledOff(GREEN_LED_1);
  ledOff(GREEN_LED_2);
}

// Run loop
void loop()
{
  stop(5);
  prepareToGo(1);
  go(8);
  prepareToStop(2);
  buttonState = digitalRead(PB_1);
  if (buttonState == HIGH) {
    ledOn(RED);
    ledOff(_LED_1);
    ledOff(RED_LED_2);
    ledOn(GREEN_LED_2);
    delay(5000);
    ledOn(RED_LED_2);
    ledOff(GREEN_LED_2);
  }
}

void stop(int seconds) {
  ledOn(RED);
  ledOff(AMBER_LED_1);
  delay(seconds*1000);
}

void prepareToGo(int seconds)
{
  ledOn(AMBER_LED_1);
  delay(seconds * 1000);
}

void prepareToStop(int seconds)
{
  ledOn(AMBER_LED_1);
  ledOff(GREEN_LED_1);
  delay(seconds * 1000);
}

void go(int seconds) 
{
  ledOn(GREEN_LED_1);
  ledOff(RED);
  ledOff(AMBER_LED_1);
  delay(seconds * 1000);
}

void ledOff(int ledPin){
  digitalWrite(ledPin, LOW);
}


void ledOn(int ledPin){
  digitalWrite(ledPin, HIGH);
}