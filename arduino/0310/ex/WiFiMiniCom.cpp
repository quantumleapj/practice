#include "WifiMiniCom.h"
WifiMiniCom::WifiMiniCom(int serial_bps, int lcd_addr)
    : MiniCom(serial_bps, lcd_addr)
{
}
void WifiMiniCom::init(const char *ssid, const char *password)
{
  MiniCom::init();
  WiFi.begin(ssid, password); // 비밀번호가 없는 경우 NULL
  print(0, "try to connect");
  Serial.println();
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  print(0, "WiFi connected");
  print(1, WiFi.localIP().toString().c_str());
  Serial.println();
  Serial.println(WiFi.localIP());
}
