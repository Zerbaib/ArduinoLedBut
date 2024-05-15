const int led1 = 2;
const int led2 = 3;
const int button = 4;
int buttonState;
bool buttonLongPress;
int futureLed;
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
        buttonLongPress = true;
    } else {
        if (buttonLongPress) {
            buttonLongPress = false;
            futureLed = lastLed == led1 ? led2 : led1;
            digitalWrite(lastLed, LOW);
            digitalWrite(futureLed, HIGH);
            lastLed = futureLed;
        }
    }
}