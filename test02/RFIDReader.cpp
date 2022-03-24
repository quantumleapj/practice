#include "RFIDReader.h"
// 1) 구성: RFID 리더기/태그, 서보모터, 부저, 녹색 LED, 적색 LED, 버튼
// 2) 버튼을 누르면 5초 안에 태그의 RFID 값을 EEPROM에 저장
// 3) 초기화 될 때 EEPROM에 저장된 값을 읽어 출입 가능 태그값으로 처리
// 4) 태그를 읽었을 때 등록된 태그이면 서보 모터로 문을 열어줌
// 5) 열린 문은 5초 후 자동으로 닫힘
// 6) 태그를 읽을 때 짧게 비프음과 녹색 LED를 켰다 끔
// 7) 등록된 태그가 아닌 경우 2초 동안 적색 LED를 켜고 비프음 울림
// 8) RFIDReader 클래스를 제작해서 제어
// 9) 필요하다 생각하는 정보는 LCD로 출력

RFIDReader::RFIDReader(int SS_PIN, int RST_PIN) : SS_PIN(SS_PIN), RST_PIN(RST_PIN)
{
  mfrc = MFRC522(SS_PIN, RST_PIN);
  total_count = 0;
  overlap_count = 0;
}

void RFIDReader::init()
{
  load();
  SPI.begin();
  mfrc.PCD_Init();
  Serial.print(SS_PIN);
  Serial.print(RST_PIN);
}

void RFIDReader::setCallback(callback_t callback1, callback_t callback2)
{

  this->callback1 = callback1;
  this->callback2 = callback2;
}

void RFIDReader::setInputAlert(callback_t inputAlert)
{
  this->inputAlert = inputAlert;
}

bool RFIDReader::search_tag()
{
  byte count = 0;

  for (byte j = 0; j < total_count; j++)
  {
    for (byte i = 0; i < 4; i++)
    {
      if (saved_uid[j * 4 + i] == uid[i])
      {
        count++;
      }
      if (count == 4)
      {
        Serial.print('searched');
        return true;
      }
    }
  }
  return false;
}

void RFIDReader::register_tag()
{//태그 값 저장
  byte count1 = 0;
  Serial.print("register : ");
  bool t;
  t = search_tag();
  if (!t)
  {
    //25개 이상부터는 기존 주소를 하나씩 지워가며 새로 채워 넣는다. 
    if (total_count >= 25)
    {
      if (overlap_count >= 25)
      {
        overlap_count = 1;
      }
      else{
        overlap_count ++;
      }
    }
    else
    {
      total_count++;
      overlap_count = total_count;
    }
    EEPROM.write(500, total_count);
    EEPROM.write(501, overlap_count);
    for (byte i = 0; i < 4; i++)
    {
      Serial.print(uid[i]);
      EEPROM.write(overlap_count * 4 + i, uid[i]);
    }
  }
  return;
}

bool RFIDReader::is_registered()
{
  bool t;
  t = search_tag();
  if (t)
  {
    callback1();
    return true;
  }
  else
  {
    callback2();
    return false;
  }
  // 4) 태그를 읽었을 때 등록된 태그이면 서보 모터로 문을 열어줌 //callback
}

void RFIDReader::load()
{
  // 초기화시 eefrom 값 읽어오기
  byte temp = EEPROM.read(500);

  // 저장된 숫자 테스트
  if (temp > 25)
  {
    total_count = 0;
    overlap_count = 0;
    EEPROM.write(500, 0);
    EEPROM.write(501, 0);
  }

  else
  {
    total_count = temp;
    overlap_count = EEPROM.read(501);
  }

  Serial.print("total count :");
  Serial.print(total_count);
  Serial.println();

  byte i = 0;
  byte d = 0;
  while (i < 101)
  {
    d = EEPROM.read(i);
    saved_uid[i] = d;

    Serial.print(saved_uid[i]);
    Serial.print(" ");
    Serial.print(i);
    Serial.println();
    i++;

    if (i >= 4 * total_count)
    {
      Serial.print("load end");
      Serial.println();
      return;
    }
  }
  return;
}

void RFIDReader::check()
{
  if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial())
  {
    // 태그 접촉이 되지 않았을때 또는 ID가 읽혀지지 않았을때
    return;
  }

  Serial.print("Card UID:"); // 태그의 ID출력

  // 태그의 ID출력하는 반복문.태그의 ID사이즈(4)까지
  for (byte i = 0; i < 4; i++)
  {
    // mfrc.uid.uidByte[0] ~ mfrc.uid.uidByte[3]까지 출력
    uid[i] = mfrc.uid.uidByte[i];
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" "); // id 사이의 간격 출력
  }
  Serial.println();
  inputAlert();
  is_registered();
}
