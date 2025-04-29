#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define pedButton 4    // Push button to request crossing signal
#define pedWhite 9     // Walk symbol (white LED)
#define pedTime 20000  // 20 seconds pedestrian has to cross
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
  pinMode(pedButton, INPUT);  // for part C
  pinMode(pedWhite, OUTPUT);  // for part C


  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
  digitalWrite(pedWhite, LOW);  // for part C
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



  if (digitalRead(pedButton) == HIGH) {  // Check if pedestrian pressed the button
    pedestrianCrossing();
  }
  // Condensed program
  // If traffic is east and button is pushed then switches traffic from east to west
  if (digitalRead(westButton) == HIGH && !trafficWest) {
    switchTrafficFrom(eastGreen, eastYellow, eastRed);
    changeYellowLight(westYellow);
    trafficWest = true;
    switchTrafficTo(westYellow, westRed, westGreen);

    // If traffic is west and button is pushed switches traffic from west to east
  } else if (digitalRead(eastButton) == HIGH && trafficWest) {
    switchTrafficFrom(westGreen, westYellow, westRed);
    changeYellowLight(eastYellow);
    switchTrafficTo(eastYellow, eastRed, eastGreen);
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
void switchTrafficFrom(int fromGreen, int fromYellow, int fromRed) {
  delay(flowTime);
  digitalWrite(fromGreen, LOW);
  digitalWrite(fromYellow, HIGH);
  delay(changeDelay);
  digitalWrite(fromYellow, LOW);
  digitalWrite(fromRed, HIGH);
  delay(changeDelay);
}
void switchTrafficTo(int toYellow, int toRed, int toGreen) {

  digitalWrite(toYellow, LOW);
  digitalWrite(toRed, LOW);
  digitalWrite(toGreen, HIGH);
}

void pedestrianCrossing() {  // for part C

  digitalWrite(westGreen, LOW);  // Turn both greens off
  digitalWrite(eastGreen, LOW);
  digitalWrite(westYellow, LOW);  // Turn both yellows off
  digitalWrite(eastYellow, LOW);
  digitalWrite(westRed, HIGH);  // Turn both reds on
  digitalWrite(eastRed, HIGH);

  delay(5000);  // 5 seconds to give dumb drivers time to react

  digitalWrite(pedWhite, HIGH);  // Pedestrian white LED ON
  delay(pedTime);
  digitalWrite(pedWhite, LOW);

  if (trafficWest == true) {  // auto resume traffic after old lady is safely across
    switchTrafficTo(westYellow, westRed, westGreen);
  } else {
    switchTrafficTo(eastYellow, eastRed, eastGreen);
  }
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
  } else {
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
