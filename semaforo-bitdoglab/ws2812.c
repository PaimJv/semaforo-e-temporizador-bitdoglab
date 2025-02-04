#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RGB_G 11
#define LED_RGB_B 12
#define LED_RGB_R 13

const int temporizador = 3000;

int led_atual = 0;

void led_amarelo() {
    gpio_put(LED_RGB_R, 1);
    gpio_put(LED_RGB_G, 1);
    gpio_put(LED_RGB_B, 0);
}

bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(LED_RGB_R, 0);
    gpio_put(LED_RGB_G, 0);
    gpio_put(LED_RGB_B, 0);
    
    if (led_atual == 0) {
        // led_amarelo(); // utilizar somente na bitdoglab
        gpio_put(LED_RGB_B, 1); // utilizar somente na simulação
        led_atual = 1;
    } 
    else if (led_atual == 1) {
        gpio_put(LED_RGB_R, 0);
        gpio_put(LED_RGB_G, 1);
        led_atual = 2;
    }
    else {
        gpio_put(LED_RGB_R, 1); 
        led_atual = 0;
    }
    return true;
}

int main() {
    int contagem = 0;
    stdio_init_all();

    gpio_init(LED_RGB_R); gpio_set_dir(LED_RGB_R, GPIO_OUT);
    gpio_init(LED_RGB_G); gpio_set_dir(LED_RGB_G, GPIO_OUT);
    gpio_init(LED_RGB_B); gpio_set_dir(LED_RGB_B, GPIO_OUT);

    gpio_put(LED_RGB_R, 1);

    struct repeating_timer timer;
    add_repeating_timer_ms(temporizador, repeating_timer_callback, NULL, &timer);

    while (1) {
        printf("Executando rotina...\n");
        sleep_ms(1000);
    }

    return 0;
}