#include <Servo.h>
#include <Arduino.h>

Servo servoLid;
Servo servoArm;

int inPin = 2;         // the number of the input pin
int outPin = 13;       // the number of the output pin
int servoPinLid = 9;       // the servo pin
int servoPinArm = 7;       // the servo pin
int ARMLOW = 75;
int ARMHIGH = 180;
int LIDHIGH = 70;
int LIDLOW = 0;


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
	servoLid.attach(servoPinLid);
	servoArm.attach(servoPinArm);
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

void setLow() {
	Serial.println("setLow");
	state = LOW;
	digitalWrite(outPin, LOW);
	servoArm.write(ARMLOW);
	delay(100);
	servoLid.write(LIDLOW);
}

void setHigh() {
	state = HIGH;
	digitalWrite(outPin, HIGH);
	servoLid.write(LIDHIGH);
	delay(300);
	servoArm.write(ARMHIGH);
}
