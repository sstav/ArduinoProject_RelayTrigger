const int inputPin = A3;
const int outputPin = A10;

const unsigned long debounceDelay = 50;
const unsigned long pulseTime = 3000;

bool alreadyTriggered = false;

void setup() {
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(outputPin, OUTPUT);

  digitalWrite(outputPin, HIGH);
}

void loop() {
  bool trigger = (digitalRead(inputPin) == LOW); 

  if (trigger && !alreadyTriggered) {

    delay(debounceDelay);

    if (digitalRead(inputPin) == LOW) {
      digitalWrite(outputPin, LOW);
      delay(pulseTime);
      digitalWrite(outputPin, HIGH);

      alreadyTriggered = true;
    }
  }

  if (!trigger) {
    alreadyTriggered = false;
  }
}