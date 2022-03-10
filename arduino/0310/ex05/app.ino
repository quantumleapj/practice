#include <MqttCom.h>
#include <Led.h>

const char *ssid = "SK_WiFiGIGAF51C";
const char *password = "2011028540";
const char *mqtt_server = "192.168.35.251"; // mqtt broker ip address

MqttCom com;
Led led(BUILTIN_LED);
int value = 0;

void callback(char *topic, byte *payload, unsigned int length)
{
  char buf[128];

  memcpy(buf, payload, length);
  buf[length] = '\0';
  com.print(0, topic);
  com.print(1, buf);
  if (buf[0] == '1')
  {
    led.setValue(LOW);
  }
  else
  {
    led.setValue(HIGH);
  }
}

void publish()
{
  char msg[50];
  ++value;
  sprintf(msg, "hello world #%ld", value);
  com.publish("outTopic", msg);
}

void setup()
{
  com.init(ssid, password);
  com.setServer(mqtt_server, "inTopic", callback);
  com.setInterval(2000, publish);
}

void loop()
{
  com.run();
}
