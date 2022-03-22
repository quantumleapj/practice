#pragma once
#include <Arduino.h>
// 1) 구성: RFID 리더기/태그, 서보모터, 부저, 녹색 LED, 적색 LED, 버튼
// 2) 버튼을 누르면 5초 안에 태그의 RFID 값을 EEPROM에 저장
// 3) 초기화 될 때 EEPROM에 저장된 값을 읽어 출입 가능 태그값으로 처리
// 4) 태그를 읽었을 때 등록된 태그이면 서보 모터로 문을 열어줌
// 5) 열린 문은 5초 후 자동으로 닫힘
// 6) 태그를 읽을 때 짧게 비프음과 녹색 LED를 켰다 끔
// 7) 등록된 태그가 아닌 경우 2초 동안 적색 LED를 켜고 비프음 울림
// 8) RFIDReader 클래스를 제작해서 제어
// 9) 필요하다 생각하는 정보는 LCD로 출력

class RFIDReader{
  protected:
  public:
  void register_tag();
  void read_tag();
  void is_registered();
  void is_not_registered();
  void load();
};