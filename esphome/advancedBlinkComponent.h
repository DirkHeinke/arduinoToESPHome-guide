#include "esphome.h"

#define LED_PIN 2

class AdvancedBlinkComponent : public Component
{
public:
  unsigned long last_led_change;
  bool enable = false;
  float frequency = 1;

  AdvancedBlinkComponent(esphome::template_::TemplateSwitch *&_enable, esphome::template_::TemplateNumber *&_frequency)
  {
    _enable->add_on_state_callback([this](bool newState)
                                   { enable = newState; });
    _frequency->add_on_state_callback([this](float newFrequency)
                                      { frequency = newFrequency; });
  }

  void setup() override
  {
    pinMode(LED_PIN, OUTPUT);
    last_led_change = millis();
  }

  void loop() override
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
};