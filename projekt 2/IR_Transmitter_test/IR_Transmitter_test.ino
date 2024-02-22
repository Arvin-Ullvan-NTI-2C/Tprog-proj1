#include <IRremote.h> // >v3.0.0
                                            
#define PIN_SEND 3

const int buttonPin = 7;
int buttonState = 0;
const int LaserPin = 10;




void setup()  
{  
  IrSender.begin(PIN_SEND); // Initializes IR sender
  pinMode(buttonPin, INPUT);
  pinMode(LaserPin, OUTPUT);
 
}  
                               
void loop()  
{  
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    IrSender.sendNEC(0x0102, 0x34, true, 0); // the address 0x0102 with the command 0x34 is sent
    digitalWrite(LaserPin, HIGH);
  } else {
    digitalWrite(LaserPin, LOW);
  }
  
}  
