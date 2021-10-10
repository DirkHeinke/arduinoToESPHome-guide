#define LED_PIN 2

unsigned long last_led_change;
bool enable = false;
float frequency = 1;


void setup()
{
  pinMode(LED_PIN, OUTPUT);
  last_led_change = millis();
}

void loop()
{
  if (enable == false)
  {
    return;
  }

  unsigned long now = millis();
  
  if (last_led_change + 1000 / frequency  < now)
  {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    last_led_change = now;
  }
}
