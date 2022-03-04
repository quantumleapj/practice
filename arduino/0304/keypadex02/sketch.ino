

#include <MiniCom.h>
#include <Numberpad.h>
#include <Servo.h>
MiniCom com;
NumberPad keypad;
Servo servo;

string input = "";
string dumy_input = "";
bool b_input = false;

int timer_id = -1;
const String PASSWORD = "1234";

void open_door(){
servo.write(90);
}
void close_door(){
servo.write(0);
}
void cancle_input(){
b_input = true;
}

void start_input(){
b_input = true;
input = "";
dumy_input = "";
timer_id = com.getTimer().setTimeout(3000,cancle_input);
// com.onLcd();

}
void end_input(){

 b_input= false;
 Serial.print("입력완료");
 Serial.println(input);
 if (input == PASSWORD)
 {//열렸을때
 //서보모터



 }

else{
  //경고음
}


 com.print(1,"");
 com.getTimer().deleteTimer(); 
 timer_id=-1;
}

void key_process(char key){
  if (key == '*')
  {
    start_input();
  }
}

void setup()
{
  com.init();
  com.print(0,"[[keypad test]]");
  com.offLcd();
  servo.attach(3);
  servo.write(0);
}

void loop()
{
  timer.run();
}