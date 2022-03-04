#include <MiniCom.h>
#include <Keypad.h>
MiniCom com;
const byte ROWS = 4; // 행(rows) 개수
const byte COLS = 4; // 열(columns) 개수
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {7, 6, 5, 4};   // R1, R2, R3, R4 단자가 연결된 핀 번호
byte colPins[COLS] = {8, 9, 10, 11}; // C1, C2, C3, C4 단자가 연결된 핀 번호
// Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup()
{
  com.init();
  com.print(0, "[[Keypad Test]]");
}
void loop()
{
  char key = keypad.getKey();
  if (key)
  {
    String str(key);
    com.print(1, str.c_str());
  }
}
