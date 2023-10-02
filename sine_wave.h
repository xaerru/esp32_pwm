#ifndef CONFIG_H
#define CONFIG_H

#include "config.h"

struct sine_wave {
    float frequency;
    float time_period;
    int sample_size;
    float buf[SINE_BUF_SIZE];
};

struct sine_wave sine_wave_new(double frequency);
void print_space_separated(int n, ...);
void pwm_plot_loop(struct sine_wave *w1, struct sine_wave *w2);

#endif
