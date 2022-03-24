#include <Analog.h>
#include <Servo.h>
#include <Button.h>
#include <Buzzer.h>
#include <Led.h>
#include <MiniCom.h>
#include <SPI.h>
#include <MFRC522.h>
#include <SimpleTimer.h>
#include <EEPROM.h>

#include "RFIDReader.h"

#define RST_PIN 9 // reset핀은 9번으로 설정
#define SS_PIN 10 // SS핀은 10번으로 설정
// SS핀은 데이터를 주고받는 역할의 핀( SS = Slave Selector )
// MFRC522 mfrc(SS_PIN, RST_PIN); // MFR522 객체 생성

Button Btn(1);
Led ledG(2);
Led ledR(3);
Buzzer Bz(4);
MiniCom com(9600, 0x27);
Servo servo;

RFIDReader rf(SS_PIN, RST_PIN);

int t_rf;
int t_bt;

SimpleTimer timer;
SimpleTimer timer_rf;

void closeDoor()
{
  servo.write(90);
  com.print(0, "Goodbye!");
  com.print(1, "close door");
}
void openDoor()
{
  servo.write(20);
  com.print(0, "WellCome!");
  com.print(1, "open door");
  timer.setTimeout(5000, closeDoor);
}

void check()
{
  rf.check();
}
void read_off()
{
  ledG.off();
  Bz.off();
}

void read_mark()
{
  com.print(0, "hi!");
  com.print(1, "rfid input alert");
  ledG.on();
  Bz.on();
  timer.setTimeout(500, read_off);
}

void red_alert_off()
{
  ledR.off();
  Bz.off();
}
void red_alert()
{
  com.print(0, "his rfid is");
  com.print(1, "not registered");
  ledR.on();
  Bz.on();
  timer.setTimeout(2000, red_alert_off);
}

void click(){
  // EEPROM.write(500,1);
  timer_rf.disable(t_bt);
  ledG.on();
  ledR.on();
  timer.setTimeout(5000,register_tag);
}

void register_tag(){
  timer_rf.disable(t_rf);
  ledR.off();
  ledG.off();
  rf.register_tag();
  rf.load();
  timer_rf.enable(t_rf);
  timer_rf.enable(t_bt);
}

void reset(){
  Serial.print("reset");
EEPROM.write(500,0);
rf.load();

}

void run_button(){
  Btn.run();
}
// 1) 구성: RFID 리더기/태그, 서보모터, 부저, 녹색 LED, 적색 LED, 버튼
// 2) 버튼을 누르면 5초 안에 태그의 RFID 값을 EEPROM에 저장
// 3) 초기화 될 때 EEPROM에 저장된 값을 읽어 출입 가능 태그값으로 처리
// 4) 태그를 읽었을 때 등록된 태그이면 서보 모터로 문을 열어줌
// 5) 열린 문은 5초 후 자동으로 닫힘
// 6) 태그를 읽을 때 짧게 비프음과 녹색 LED를 켰다 끔
// 7) 등록된 태그가 아닌 경우 2초 동안 적색 LED를 켜고 비프음 울림
// 8) RFIDReader 클래스를 제작해서 제어
// 9) 필요하다 생각하는 정보는 LCD로 출력

void setup()
{
  servo.attach(6);
  Serial.begin(9600);

  com.init();
  com.print(0, "[[MiniCom]]");

  rf.init();
  rf.setCallback(openDoor,red_alert);
  rf.setInputAlert(read_mark);

  Btn.setCallback(click);
  // Btn.init();
  t_rf = timer_rf.setInterval(500, check);
  t_bt=timer_rf.setInterval(200,run_button);
}

void loop()
{
  com.run();
  timer.run();
  timer_rf.run();
}