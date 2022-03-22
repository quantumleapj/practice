#include <Analog.h>
#include <Servo.h>
#include <Button.h>
#include <Buzzer.h>
#include <Led.h>
#include <MiniCom.h>
#include <SPI.h>
#include <MFRC522.h>

#include "RFIDReader.h"

#define RST_PIN 9 // reset핀은 9번으로 설정
#define SS_PIN 10 // SS핀은 10번으로 설정
// SS핀은 데이터를 주고받는 역할의 핀( SS = Slave Selector )
MFRC522 mfrc(SS_PIN, RST_PIN); // MFR522 객체 생성

Button Btn(1);
Led ledG(2);
Led ledR(3);
Buzzer Bz(4);
MiniCom com(9600,0x27);
Servo servo;

RFIDReader rf;

// bool bo;

void setup()
{

  servo.attach(6);
  Serial.begin(9600);

  com.init();
  com.print(0, "[[MiniCom]]");
  com.setInterval(1000, check); // 1초 간격으로

  SPI.begin();
  mfrc.PCD_Init();
  // Btn.setCallback(callback);
  // bo = false;
}
void loop()
{
  // ledG.blink();
  // ledR.blink();
  // Bz.beep();
  // Btn.check();
  // bo = Btn.read( );
  // if(bo){
  //   ledG.on();
  // }
  // else{
  //   ledG.off();
  // }
  com.run();

  if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial())
  {
    // 태그 접촉이 되지 않았을때 또는 ID가 읽혀지지 않았을때
    delay(500);
    return;
  }

  Serial.print("Card UID:"); // 태그의 ID출력
  // 태그의 ID출력하는 반복문.태그의 ID사이즈(4)까지
  for (byte i = 0; i < 4; i++)
  {
    // mfrc.uid.uidByte[0] ~ mfrc.uid.uidByte[3]까지 출력
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" "); // id 사이의 간격 출력
  }
  Serial.println();
}


void check()
{
  int on = Btn.read();
  if (on)
  {
    servo.write(30);
    com.print(1, "button on");
  }
  else
  {
    servo.write(90);
    com.print(1, "button off");
  }
}


void buttonCallback()
{
}

void openDoor()
{

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