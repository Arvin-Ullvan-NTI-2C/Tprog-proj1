#include <IRremote.h> // >v3.0.0
                                           
#define PIN_RECV 11
const int buzzerPin = 7;
bool ShouldBuzzerBeOn = false;
const int LEDPin = 13;


void setup()  
{  
  Serial.begin(9600); //initialize serial connection to print on the Serial Monitor of the Arduino IDE
  IrReceiver.begin(PIN_RECV); // Initializes the IR receiver object
  pinMode(buzzerPin, OUTPUT);
  pinMode(LEDPin, OUTPUT);
  
}  
                               
void loop()  {
  if (IrReceiver.decode()) {
    Serial.println("Received something..."); 
    tone(buzzerPin, 50);
    digitalWrite(LEDPin, LOW);
    delay(500);
    noTone(buzzerPin); 
    IrReceiver.printIRResultShort(&Serial); // Prints a summary of the received data
    Serial.println();
    IrReceiver.resume(); // Important, enables to receive the next IR signal
  } else {
    digitalWrite(LEDPin, HIGH);
  }
}
