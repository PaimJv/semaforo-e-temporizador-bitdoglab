#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RGB_G 11
#define LED_RGB_B 12
#define LED_RGB_R 13
#define BUTTON_A 5

const int temporizador = 3000;
volatile bool leds_ativos = false;
volatile uint32_t ultimo_estado_a = 0;
const int debounce_ms = 50;

void desligar_leds_callback();
void estado_leds_1();
void estado_leds_2();
void estado_leds_3();

void estado_leds_1() {
    gpio_put(LED_RGB_R, 1);
    gpio_put(LED_RGB_G, 1);
    gpio_put(LED_RGB_B, 1);
    add_alarm_in_ms(temporizador, (alarm_callback_t)estado_leds_2, NULL, false);
}

void estado_leds_2() {
    gpio_put(LED_RGB_B, 0);
    add_alarm_in_ms(temporizador, (alarm_callback_t)estado_leds_3, NULL, false);
}

void estado_leds_3() {
    gpio_put(LED_RGB_G, 0);
    add_alarm_in_ms(temporizador, (alarm_callback_t)desligar_leds_callback, NULL, false);
}

void desligar_leds_callback() {
    gpio_put(LED_RGB_R, 0);
    leds_ativos = false;
}

void gpio_irq_handler(uint gpio, uint32_t events) {
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (gpio == BUTTON_A && !leds_ativos && (current_time - ultimo_estado_a > debounce_ms)) {
        ultimo_estado_a = current_time;
        leds_ativos = true;
        estado_leds_1();
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED_RGB_R); gpio_set_dir(LED_RGB_R, GPIO_OUT);
    gpio_init(LED_RGB_G); gpio_set_dir(LED_RGB_G, GPIO_OUT);
    gpio_init(LED_RGB_B); gpio_set_dir(LED_RGB_B, GPIO_OUT);
    gpio_init(BUTTON_A); gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    
    while (1) {
        tight_loop_contents();
    }
}