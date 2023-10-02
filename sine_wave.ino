#include "sine_wave.h"

struct sine_wave sine_wave_new(double frequency) {
    struct sine_wave w = {
        .frequency = frequency
    };
    w.time_period=1/w.frequency;
    w.sample_size=w.time_period/DT;

    for(int i=0;i<w.sample_size;i++) {
        w.buf[i] = sin(2*PI*w.frequency*i*DT);
    }
    return w;
}

// Prints only doubles
void print_space_separated(int n, ...) {
    va_list args;
    va_start(args, n);
    for(int i=0;i<n;i++) {
        Serial.print(va_arg(args, double));
        Serial.print(" ");
    }
    Serial.print("\n");
}

void pwm_plot_loop(struct sine_wave *w1, struct sine_wave *w2) {
    int i=0, j=0;
    while(1) {
        if(i==w1->sample_size) i=0;
        if(j==w2->sample_size) j=0;

        print_space_separated(3, w1->buf[i], w2->buf[j], (double)(w1->buf[i]>w2->buf[j]));

        // delay(time) time in ms
        delay(DT*1000);

        i++;j++;
    }
}
