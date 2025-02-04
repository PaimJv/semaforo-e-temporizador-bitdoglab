# Projetos BitDogLab - Semáforo (Temporizador periódico) e Temporizador de um disparo (One Shot)

Este repositório contém dois projetos distintos desenvolvidos para a BitDogLab utilizando o Raspberry Pi Pico W. Ambos foram implementados na linguagem C e utilizam o SDK do Raspberry Pi Pico para controle de GPIOs e temporizadores.

## Atividade 1: Semáforo (Pasta `semaforo-bitdoglab`)
### Descrição
Este projeto implementa um semáforo utilizando três LEDs (vermelho, amarelo e verde) controlados por um temporizador periódico. O tempo de troca de estado do semáforo é de 3 segundos, seguindo a sequência:
1. **Vermelho aceso** (início do ciclo)
2. **Amarelo aceso**
3. **Verde aceso**
4. **Reinício do ciclo**

A transição dos estados é controlada pela função `repeating_timer_callback()` e ocorre a cada 3 segundos.

### Componentes Utilizados
- **Microcontrolador**: Raspberry Pi Pico W
- **LEDs**:
  - Vermelho (GPIO 13)
  - Amarelo (GPIO 12)
  - Verde (GPIO 11)
- **Resistores**: 3x 330Ω

### Dependências
- `pico/stdlib.h`
- `hardware/timer.h`

### Como Compilar e Executar
1. Navegue até a pasta `semaforo-bitdoglab`
2. Compile o código utilizando o SDK do Pico
3. Faça o upload do arquivo `.uf2` para a placa
4. O semáforo iniciará automaticamente

### Como Simular
1. Navegue até a pasta `semaforo-bitdoglab`
2. Compile o código utilizando o SDK do Pico
3. Abra o `diagram.json` e execute
4. O sistema iniciará automaticamente

## Atividade 2: Temporizador de um disparo (Pasta `temporizador-bitdoglab`)
### Descrição
Este projeto implementa um temporizador com controle de LEDs via botão. O botão inicia um ciclo de acionamento dos LEDs RGB, respeitando um intervalo de 3 segundos entre os estados. A sequência segue:
1. **Todos os LEDs acesos**
2. **Apenas o LED azul desligado**
3. **Apenas o LED verde desligado**
4. **Todos os LEDs desligados (fim do ciclo, pode ser reiniciado)**

Durante o ciclo, o botão não pode ser pressionado novamente até que os LEDs sejam desligados. Além disso, um debounce por software de 50ms é aplicado para evitar leituras falsas.

### Componentes Utilizados
- **Microcontrolador**: Raspberry Pi Pico W
- **LED RGB**:
  - Vermelho (GPIO 13)
  - Verde (GPIO 11)
  - Azul (GPIO 12)
- **Botão**: GPIO 5

### Dependências
- `pico/stdlib.h`
- `hardware/timer.h`

### Como Compilar e Executar
1. Navegue até a pasta `temporizador-bitdoglab`
2. Compile o código utilizando o SDK do Pico
3. Faça o upload do arquivo `.uf2` para a placa
4. Pressione o botão para iniciar a sequência dos LEDs

### Como Simular
1. Navegue até a pasta `semaforo-bitdoglab`
2. Compile o código utilizando o SDK do Pico
3. Abra o `diagram.json` e execute
4. O sistema iniciará automaticamente