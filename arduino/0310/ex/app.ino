// #include <ESP8266WiFi.h>
// #include <MiniCom.h>
// const char *ssid = "SK_WiFiGIGAF51C";
// const char *password = "2011028540";
// MiniCom com;
// void wifi_connect()
// {
//   WiFi.begin(ssid, password); // 비밀번호가 없는 경우 NULL
//   com.print(0, "try to connect");
//   Serial.println();
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print(".");
//   }
//   com.print(0, "WiFi connected");
//   com.print(1, WiFi.localIP().toString().c_str());
//   Serial.println();
//   Serial.println(WiFi.localIP());
// }
// void setup()
// {
//   com.init();
//   wifi_connect();
// }
// void loop()
// {
//   com.run();
// }

#include "WifiMiniCom.h"
const char *ssid = "SK_WiFiGIGAF51C";
const char *password = "2011028540";
WifiMiniCom com;
WiFiServer server(80); // 80: Web Server 표준 포트
void setup()
{
  com.init(ssid, password);
  server.begin();
}

void loop()
{
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available())
  {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

      // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print("HELLO WORLD!");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}