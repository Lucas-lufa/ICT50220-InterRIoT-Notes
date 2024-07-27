#define RED		    13
#define GREEN       12
#define PB_1	     2
#define PERIOD	  1000

int currentTime = 0;
int previousTime = 0;
int timeDiff = 0;
int ledState = LOW;
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
  if (timeDiff > 1000){
    Serial.println(ledState);
    // ledState = ledState == LOW ? HIGH : LOW;
    ledState = !ledState;
    digitalWrite(RED, ledState);
    previousTime = currentTime;
  }
  
  buttonState = digitalRead(PB_1);
  if (buttonState == HIGH) {
    digitalWrite(GREEN, HIGH);
  } else {
    digitalWrite(GREEN, LOW); 
  }
}