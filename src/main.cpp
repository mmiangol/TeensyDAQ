#include <Arduino.h>

class Blinker {
public:
    Blinker(uint8_t pin, unsigned int interval)
        : _pin(pin), _interval(interval), _lastToggle(0), _state(false) {
        pinMode(_pin, OUTPUT);
    }

    void update() {
        if (millis() - _lastToggle >= _interval) {
            _state = !_state;
            digitalWrite(_pin, _state);
            _lastToggle = millis();
        }
    }

private:
    uint8_t _pin;
    unsigned int _interval;
    unsigned long _lastToggle;
    bool _state;
};

Blinker led(13, 500);

void setup() {
    Serial.begin(115200);
}

void loop() {
    led.update();
}