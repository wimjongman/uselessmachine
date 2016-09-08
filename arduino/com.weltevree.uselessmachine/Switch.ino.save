#include <Servo.h>
#include <Arduino.h>

Servo servo;

int inPin = 2;         // the number of the input pin
int outPin = 13;       // the number of the output pin
int servoPin = 9;       // the servo pin
int gedrag = 0;       // the servo pin

int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int servoState = 0;    // the position in degrees of the servo
int randomGedrag = random(1, 4);

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

	boolean canflip = (millis() - time > debounce); // debounce
	if (canflip) {
		reading = digitalRead(inPin);
		if (state == HIGH && reading == LOW) {
			setLow();
			saveTime();
		} else if (state == LOW && reading == HIGH) {
			setHigh();
			saveTime();
		}
	}
}

void saveTime() {
	time = millis();
}

void setHigh() {
	int randomGedrag = random(1, 4);
	state = HIGH;
	digitalWrite(outPin, HIGH);
	if (randomGedrag == 1) {
		gedrag1();
		return;
	} else if (randomGedrag == 2) {
		gedrag2();
		return;
	} else if (randomGedrag == 3) {
		gedrag3();
		return;
	}
}

void setLow() {
	Serial.println("setLow");
	state = LOW;
	digitalWrite(outPin, LOW);
	servo.write(0);
}

void gedrag1() {
	servo.write(90);
}

void gedrag2() {
	servo.write(50);
	delay(1000);
	servo.write(90);
}

void gedrag3() {
	servo.write(60);
	delay(1000);
	servo.write(0);
	delay(1000);
	servo.write(90);
}
