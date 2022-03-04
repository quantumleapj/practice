#include <SimpleTimer.h>
#include <Servo.h>
#include <MiniCom.h>
#include <Button.h>


MiniCom com;
Button btn(2);
Servo servo;

const int OPEN = true;
const int CLOSE = false;

bool door_state = CLOSE;
int timer_id = -1;

void close_door(){
  servo.write(0);
  door_state = CLOSE;
  com.print(1,'CLOSE');
}

void open_door(){
  SimpleTimer &timer = com.getTimer();

  if(door_state == OPEN){
    timer.restartTimer(timer_id);
  }
  else{
    //닫혀있을경우
    servo.write(90);
    timer_id = timer.setTimerout(3000,close_door);
  }
  door_state = OPEN;
  com.print(1,"OPEN");
}

void setup(){
  com.init();
  servo.attach(5);
  com.print(0,"[[Minicom]]");
  btn.setCallback(open_door);
  close_door();
}
void loop(){
  btn.check();
  com.run();
}