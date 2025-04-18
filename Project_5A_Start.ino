#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10

#define yellowBlinkTime 500

boolean trafficWest = true;  // west = true, east = false
int flowTime = 10000;
int changeDelay = 2000;

void setup() {
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}

void loop() {
  /*  if (digitalRead(westButton) == HIGH) {
    if (trafficWest != true) {
      trafficWest = true;
      delay(flowTime);
      digitalWrite(eastGreen, LOW);
      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
      delay(changeDelay);
      for (int a = 0; a < 5; a++) {
        digitalWrite(westYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(westYellow, HIGH);
        delay(yellowBlinkTime);
      }
      // changeYellowLight(westYellow);

      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW);
      digitalWrite(westGreen, HIGH);
    }
  }
  if (digitalRead(eastButton) == HIGH) {
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);
      digitalWrite(westGreen, LOW);
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay);
      for (int a = 0; a < 5; a++) {
        digitalWrite(eastYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(eastYellow, HIGH);
        delay(yellowBlinkTime);
      }
      // changeYellowLight(eastYellow);

      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW);
      digitalWrite(eastGreen, HIGH);
    }
  }
  if (digitalRead(westButton) == HIGH && !trafficWest) {  
    switchTraffic(true);
  } 
  else if (digitalRead(eastButton) == HIGH && trafficWest) {
    switchTraffic(false);
  } */

  // Condensed program
  if (digitalRead(westButton) == HIGH && !trafficWest) {
    switchTrafficAll(eastGreen, eastYellow, eastRed, westYellow, westRed, westGreen);
    trafficWest = true;
  } 
  else if (digitalRead(eastButton) == HIGH && trafficWest) {
    switchTrafficAll(westGreen, westYellow, westRed, eastYellow, eastRed, eastGreen);
    trafficWest = false;
  }
}

// Blink yellow light 5x
void changeYellowLight(int yellowPin) {
  for (int a = 0; a < 5; a++) {
    digitalWrite(yellowPin, LOW);
    delay(yellowBlinkTime);
    digitalWrite(yellowPin, HIGH);
    delay(yellowBlinkTime);
  }
}

// Switch traffic flow either direction
void switchTrafficAll(int fromGreen, int fromYellow, int fromRed, int toYellow, int toRed, int toGreen) {
  delay(flowTime);

  digitalWrite(fromGreen, LOW);
  digitalWrite(fromYellow, HIGH);
  delay(changeDelay);
  digitalWrite(fromYellow, LOW);
  digitalWrite(fromRed, HIGH);
  delay(changeDelay);

  changeYellowLight(toYellow);
  digitalWrite(toYellow, LOW);
  digitalWrite(toRed, LOW);
  digitalWrite(toGreen, HIGH);
}

/*
void switchTraffic(bool toWest) {
  if (toWest) {
    delay(flowTime);
    digitalWrite(eastGreen, LOW);
    digitalWrite(eastYellow, HIGH);
    delay(changeDelay);
    digitalWrite(eastYellow, LOW);
    digitalWrite(eastRed, HIGH);
    delay(changeDelay);
    changeYellowLight(westYellow);
    digitalWrite(westYellow, LOW);
    digitalWrite(westRed, LOW);
    digitalWrite(westGreen, HIGH);
    trafficWest = true;
  } 
  else {
    delay(flowTime);
    digitalWrite(westGreen, LOW);
    digitalWrite(westYellow, HIGH);
    delay(changeDelay);
    digitalWrite(westYellow, LOW);
    digitalWrite(westRed, HIGH);
    delay(changeDelay);
    changeYellowLight(eastYellow);
    digitalWrite(eastYellow, LOW);
    digitalWrite(eastRed, LOW);
    digitalWrite(eastGreen, HIGH);
    trafficWest = false;
  }
}
*/
