
#include <Servo.h>
#include <MiniCom.h>


MiniCom com;
Servo myServo;           // 사용할 서보 모터명 선언
const int servo_pin = 5; // 서보 모터 연결핀
void setup()
{
  com.init();
  com.print(0, "Servo Test");
  myServo.attach(servo_pin); // 사용할 서보명에 핀 할당
}
void move_angle(int angle, int delay_time)
{
  myServo.write(angle);
  com.print(1, "Angle:", angle);
  delay(delay_time);
}
void loop()
{
  move_angle(0, 1000);
  move_angle(90, 1000);
  move_angle(180, 1000);
  move_angle(90, 1000);
}
