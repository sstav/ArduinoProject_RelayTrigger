const int inputPin = A3;
const int outputPin = A10;

const unsigned long debounceDelay = 50;   // זמן סינון ריצודים במילישניות
const unsigned long pulseTime = 3000;     // פולס של 3 שניות

bool alreadyTriggered = false;

void setup() {
  pinMode(inputPin, INPUT);      // אם אין נגד חיצוני, תגיד ואשנה ל-INPUT_PULLUP
  pinMode(outputPin, OUTPUT);

  digitalWrite(outputPin, LOW);
}

void loop() {
  if (digitalRead(inputPin) == HIGH && !alreadyTriggered) {

    delay(debounceDelay); // המתנה קצרה נגד ריצודים

    if (digitalRead(inputPin) == HIGH) {
      digitalWrite(outputPin, HIGH);
      delay(pulseTime);
      digitalWrite(outputPin, LOW);

      alreadyTriggered = true; // מונע טריגר חוזר כל עוד A3 נשאר HIGH
    }
  }

  // מאפשר טריגר חדש רק אחרי שהכניסה חזרה ל-LOW
  if (digitalRead(inputPin) == LOW) {
    alreadyTriggered = false;
  }
}