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

char correctPin[4] = {'1','2','3','4'};
char enteredPin[4] = {'0','0','0','0'};
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
      bool yes = true;
      for(int i = 0;i<4;i++){
        if( strcmp(enteredPin[i], correctPin[i]) ){
          yes = false;
        }
      }
      if(yes){
        Serial.println("correct!");
      }else{
        Serial.println("wrong!");
      }
      currentSpot = 0;
    }
  }
}
