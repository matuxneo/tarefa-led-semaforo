#include <stdio.h>
#include "pico/stdlib.h"

// Configuração dos GPIOs para o LED RGB
#define LED_R 11  
#define LED_Y 12  
#define LED_G 13  

// Estados do semáforo
typedef enum { VERMELHO, AMARELO, VERDE } EstadoSemaforo;
EstadoSemaforo estado_atual = VERMELHO;

// Função de callback do temporizador (3 segundos)
bool timer_callback(struct repeating_timer *t) {
    switch (estado_atual) {
        case VERMELHO:
            gpio_put(LED_R, 0);
            gpio_put(LED_Y, 1);
            estado_atual = AMARELO;
            printf("\n🟡 LED AMARELO LIGADO\n");
            break;
        case AMARELO:
            gpio_put(LED_Y, 0);
            gpio_put(LED_G, 1);
            estado_atual = VERDE;
            printf("\n🟢 LED VERDE LIGADO\n");
            break;
        case VERDE:
            gpio_put(LED_G, 0);
            gpio_put(LED_R, 1);
            estado_atual = VERMELHO;
            printf("\n🔴 LED VERMELHO LIGADO\n");
            break;
    }
    return true;
}

int main() {
    stdio_init_all();
    sleep_ms(2000);    // Aguarda 2 segundos para o USB inicializar
    printf("🚦 Projeto BitDogLab - Semáforo com Temporizador 🚦\n");

    // Configuração dos LEDs
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_Y);
    gpio_set_dir(LED_Y, GPIO_OUT);
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);

    // Inicializa com LED vermelho ligado
    gpio_put(LED_R, 1);
    gpio_put(LED_Y, 0);
    gpio_put(LED_G, 0);
    printf("\n🔴 LED VERMELHO LIGADO\n");

    // Configura o temporizador (3 segundos)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, timer_callback, NULL, &timer);

    // Loop principal - imprime mensagens a cada 1 segundo
    uint32_t tempo_inicial = to_ms_since_boot(get_absolute_time());
    while (true) {
        uint32_t tempo_atual = to_ms_since_boot(get_absolute_time());
        if (tempo_atual - tempo_inicial >= 1000) {  
            printf("⏳ Tempo decorrido: %d segundos\n", (tempo_atual / 1000));
            tempo_inicial = tempo_atual;
        }
    }

    return 0;
}
