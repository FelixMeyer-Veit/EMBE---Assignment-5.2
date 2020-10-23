
#include <Arduino.h>
/* Arduino Serial Command Program - Derek Molloy (www.derekmolloy.ie)
*   for the book Exploring Raspberry Pi */
int ledPin = 13;          // LED with PWM brightness control

void setup() {            // called once on start up
   // A baud rate of 115200 (8-bit with No parity and 1 stop bit)
   Serial.begin(115200, SERIAL_8N1);
   pinMode(ledPin, OUTPUT);         // the LED is an output
}

void loop() {              // loops forever
   char buffer[100];       // stores the return buffer on each loop
   uint8_t value; 

   if (Serial.available()>0){                 // bytes received
      value = Serial.read();
      if(value>=0 && value<=255){          // is it in range?
        analogWrite(ledPin, value);       // yes, write out
        sprintf(buffer, "Set brightness to %d", value);
      }
      else{                                // no, error message back
        sprintf(buffer, "Error: %d is out of range", value);
      }
      Serial.print(buffer); 
   }
}