//Author: projedefteri.com
// With LDR and virtual terminal, show the value.

void setup() { // put your setup code here, to run once:
  Serial.begin(9600); // Serial port is opened at 9600 baud rate
  pinMode(A0, INPUT); // A0 pin is set as input
}

void loop() { // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0)); // The value of the LDR is printed on the serial monitor
  delay(1000); // 1 second delay
}
