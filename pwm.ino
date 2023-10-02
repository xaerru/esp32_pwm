#include "config.h"
#include "sine_wave.h"

struct sine_wave w1 = sine_wave_new(FREQ_1);
struct sine_wave w2 = sine_wave_new(FREQ_2);

void setup() {
    Serial.begin(BAUD_RATE);
    pwm_plot_loop(&w1, &w2);
}

void loop() {}
