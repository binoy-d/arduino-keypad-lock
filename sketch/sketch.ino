#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'},
};

byte rowPins[ROWS] = {5,4,3,2};
byte colPins[COLS] = {9,8,7,6};

char correctPin[] = "1234";
char enteredPin[] = "0000";
int currentSpot = 0;

Keypad keypad = Keypad(makeKeymap(keys),rowPins, colPins, ROWS, COLS);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if(key){
    enteredPin[currentSpot] = key;
    currentSpot = currentSpot+1;
    if(currentSpot == 4){
      Serial.println(enteredPin);
      if(strcmp(enteredPin,correctPin) == 0){
        Serial.println("correct!");
      }else{
        Serial.println("wrong!");
      }
      currentSpot = 0;
    }
  }
}
