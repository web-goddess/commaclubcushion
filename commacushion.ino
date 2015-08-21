/* constants won't change */
const int comma3Pin = 12;   // comma 3
const int comma32gPin = 11; // ground for comma 3 and comma 2
const int comma2Pin = 9;    // comma 2
const int comma1Pin = 7;     // comma 1
const int comma1gPin = 6;    // ground for comma 1
const int buttonPin = 3;    // button

/* variables will change */
int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;        // current state of the button
int lastButtonState = 0;     // previous state of the button
   
void setup()   
{
      /* set up outputs */
      pinMode(comma3Pin, OUTPUT);
      pinMode(comma32gPin, OUTPUT);
      pinMode(comma2Pin, OUTPUT);
      pinMode(comma1Pin, OUTPUT);
      pinMode(comma1gPin, OUTPUT);

      /* set up inputs */
      pinMode(buttonPin, INPUT);
      
      /* initialise ground pins */
      digitalWrite(comma32gPin, LOW);
      digitalWrite(comma1gPin, LOW);

      /* initialise button */
      digitalWrite(buttonPin, HIGH);

}  
   
void loop() // run over and over again
{

      // read the pushbutton input pin:
      buttonState = digitalRead(buttonPin);

      // compare the buttonState to its previous state
      if (buttonState != lastButtonState) {
      
        // if the state has changed, increment the counter
        if (buttonState == LOW) {
          buttonPushCounter = (buttonPushCounter + 1) % 5;
        }
        // Delay a little bit to avoid bouncing
        delay(50);
      }
      lastButtonState = buttonState;

      switch (buttonPushCounter) {
        case 0:
          // all turn off
          digitalWrite(comma1Pin, LOW);
          digitalWrite(comma2Pin, LOW);
          digitalWrite(comma3Pin, LOW);
          break;
        case 1:
          // UNA COMMA
          digitalWrite(comma1Pin, HIGH);
          break;
        case 2:
          // DOS COMMAS
          digitalWrite(comma2Pin, HIGH);
          break;
        case 3:
          // TRES COMMAS
          digitalWrite(comma3Pin, HIGH);
          break;
        case 4:
          // PARTY!
          digitalWrite(comma1Pin, LOW);
          digitalWrite(comma2Pin, LOW);
          digitalWrite(comma3Pin, LOW);
          delay(500);
          digitalWrite(comma1Pin, HIGH);
          digitalWrite(comma2Pin, HIGH);
          digitalWrite(comma3Pin, HIGH);
          delay(500);
          break;
      }
}
