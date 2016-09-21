#include <Servo.h>
#include <Arduino.h>

Servo servoLid;
Servo servoArm;
Sleep sleep;

int switchPin = 2;       // the number of the switch pin
int ledPin = 13;         // the number of the led pin
int servoPinLid = 8;     // the servo pin
int servoPinArm = 9;     // the servo pin
int ARMLOW = 75;
int ARMHIGH = 180;
int LIDHIGH = 35;
int LIDLOW = 0;

int state = LOW;      // the current state of the output pin
int reading;           // the current reading from the input pin
int servoState = 0;    // the position in degrees of the servo
int counter = 0;       // How often did we do this already?

long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void setup() {
	pinMode(switchPin, INPUT);
	pinMode(ledPin, OUTPUT);
	attachServos();
	setLow();
	saveTime();
}

void loop() {

	boolean canflip = (millis() - time > debounce); // debounce
	if (canflip) {
		reading = digitalRead(switchPin);
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

void attachServos() {
	servoLid.attach(servoPinLid);
	servoLid.write(LIDLOW);
	servoArm.attach(servoPinArm);
	servoArm.write(ARMLOW);
}

void detachServos() {
	servoLid.detach();
	servoArm.detach();
}

void setHigh() {
	state = HIGH;
	doDelay();
	digitalWrite(ledPin, HIGH);
	for (int i = LIDLOW; i <= LIDHIGH; i++) {
		servoLid.write(i);
		delay(5);
	}
	servoArm.write(ARMHIGH);
}

void setLow() {
	state = LOW;
	digitalWrite(ledPin, LOW);
	servoArm.write(ARMLOW);
	int armpos = servoLid.read();
	delay(100);
	for (int i = armpos; i > LIDLOW; i--) {
		servoLid.write(i);
		delay(5);
	}
}

void doDelay() {
	if (counter < 5) {
		counter++;
		delay(1000);
	} else if (counter < 7) {
		counter++;
		delay(500);
	} else {
		int rand = random(100, 1000);
		delay(rand);
	}
}
