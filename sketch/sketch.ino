#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[COLS][ROWS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowPins[ROWS] = {5,4,3,2};
byte colPins[COLS] = {9,8,7,6};

Keypad keypad = Keypad(makeKeymap(keys),colPins, rowPins, COLS, ROWS);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if(key){
    Serial.println(key);
  }
}
