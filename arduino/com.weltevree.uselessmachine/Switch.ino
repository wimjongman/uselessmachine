#include <Servo.h>
#include <Arduino.h>

Servo servo;

int inPin = 2;         // the number of the input pin
int outPin = 13;       // the number of the output pin
int servoPin = 9;       // the servo pin

int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int servoState = 0;    // the position in degrees of the servo

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void setup() {
	pinMode(inPin, INPUT);
	pinMode(outPin, OUTPUT);
	Serial.begin(9600);
	servo.attach(servoPin);
}

void loop() {

	reading = digitalRead(inPin);
	boolean canflip = (millis() - time > debounce); // debounce
	Serial.println(canflip);
	if (canflip) {
		if (state == HIGH && reading == LOW)
			setLow();
		else if (state == LOW && reading == HIGH)
			setHigh();

		time = millis();
	}
}

void setHigh() {
	state = HIGH;
	digitalWrite(outPin, HIGH);
	servo.write(90);
}

void setLow() {
	state = LOW;
	digitalWrite(outPin, LOW);
	servo.write(0);
}
