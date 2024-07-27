/*
Create a circuit that has two LEDs (You choose the colours), and two 330 Ohm resistors. It also has a pushbutton switch and a resistor configured to 'pull down' the switch input to LOW by default.

Wire up the circuit, and write the code, using an Arduino and a small breadboard so that:

- The code is NON blocking
- The first LED starts flashing by default
- When the button is pressed (and released) again the other LED will flash, and the currently flashing LED will stop
- The LEDs will flash at a rate of on for 500ms and off for 750ms

> **Hint 1:** Start by solving the different on/off periods for the on and off for ONE of the LEDs.

> **Hint 2:** Add switch detection to check if button pressed, and to toggle a value to enable the correct LED to flash.
*/

#define RED		    13
#define GREEN       12
#define PB_1	     2
#define PERIOD	  1000

int currentTime = 0;
int previousTime = 0;
int timeDiff = 0;
int ledState = HIGH;
int buttonState = LOW;
int ledSelected = RED;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PB_1, INPUT);
  digitalWrite(RED, ledState);
}

void loop()
{
  currentTime = millis();
  
  timeDiff = currentTime - previousTime;
  if (ledState == HIGH && timeDiff > 500){
    ledState = !ledState;
    digitalWrite(ledSelected, ledState);
    previousTime = currentTime;    
  }

  if (ledState == LOW && timeDiff > 750){
    ledState = !ledState;
    digitalWrite(ledSelected, ledState);
    previousTime = currentTime;    
  }
  
  buttonState = digitalRead(PB_1);
  if (buttonState == HIGH) {
    if (ledSelected == RED) {
        ledSelected = GREEN;
    } else {
        ledSelected = RED;
    }
  }
}