const int pu_led_pin=3;
const int pd_led_pin=4;


void setup()
{
  pinMode(pu_led_pin,OUTPUT);
  pinMode(pd_led_pin,OUTPUT);
	
}

void loop()
{
	digitalWrite(pd_led_pin,HIGH);
	digitalWrite(pu_led_pin,HIGH);

	// digitalWrite(pd_led_pin,LOW);
	// digitalWrite(pu_led_pin,LOW);
}
