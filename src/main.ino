const int led1 = 2;
const int led2 = 3;
const int button = 4;
int buttonState;
inf buttonLongPress;
int lastLed = led1;

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(button, INPUT);

    digitalWrite(led1, HIGH);
}

void loop() {
    buttonState = digitalRead(button);
    if (buttonState != HIGH) {
        buttonLongPress = 1;
    } else {
        buttonLongPress = 0;
    }
    if (buttonLongPress == 1) {
        if (lastLed == led1) {
            digitalWrite(led1, LOW);
            digitalWrite(led2, HIGH);
            lastLed = led2;
        } else {
            digitalWrite(led2, LOW);
            digitalWrite(led1, HIGH);
            lastLed = led1;
        }
    }
}