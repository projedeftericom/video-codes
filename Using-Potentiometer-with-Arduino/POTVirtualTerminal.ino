// Author: projedefteri.com
// With potentiometer and virtual terminal, show the value.

int pot = A0; // potentiometer connected to analog pin 0
int PotDeger; // value read from the pot

void setup() {
    pinMode(2, OUTPUT); // sets the digital pin as output
    pinMode(3, OUTPUT); // sets the digital pin as output
}

void loop () {
    PotDeger = analogRead(pot); // reads the value of the pot (value between 0 and 1023)
    PotDeger = map(PotDeger, 0, 1023, 0, 255); // scale it to use it with the analogWrite:

    if (PotDeger == 2) { // if the potentiometer is turned all the way to the left:
        digitalWrite(2, HIGH); // turn the LED on (HIGH is the voltage level)   
        digitalWrite(3, LOW); // turn the LED on (HIGH is the voltage level)
    } else if (PotDeger == 5) { // if the potentiometer is turned all the way to the right:
        digitalWrite(2, HIGH); // turn the LED on (HIGH is the voltage level)
        digitalWrite(3, HIGH); // turn the LED on (HIGH is the voltage level)
    } else if (PotDeger == 7) { // if the potentiometer is turned all the way to the left:
        digitalWrite(2, LOW); // turn the LED off by making the voltage LOW
        digitalWrite(3, LOW); // turn the LED off by making the voltage LOW
    }
}