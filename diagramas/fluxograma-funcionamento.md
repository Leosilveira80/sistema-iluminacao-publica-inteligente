# Fluxograma de Funcionamento do Sistema

Este arquivo apresenta o fluxo de funcionamento do protótipo de Sistema de Iluminação Pública Inteligente baseado em IoT, considerando o comportamento do Arduino, do sensor PIR HC-SR501, dos atuadores e da comunicação USB/Serial com o Node-RED.

## Fluxograma Principal

```txt
Início do sistema
        ↓
Configura pinos do Arduino
        ↓
Inicializa comunicação Serial em 9600 baud
        ↓
Desliga LED verde, LED vermelho e buzzer
        ↓
Aguarda estabilização do sensor PIR por 60 segundos
        ↓
Sistema pronto
        ↓
LED verde ligado
LED vermelho desligado
Buzzer desligado
        ↓
Estado inicial: REPOUSO
        ↓
Loop principal
        ↓
Verifica comandos seriais recebidos do Node-RED
        ↓
Lê o sensor PIR HC-SR501
        ↓
Sensor PIR detectou movimento?
        ↓
 ┌───────────────┬────────────────┐
 │ Não           │ Sim            │
 ↓               ↓
Mantém repouso   Envia PRESENCA_DETECTADA pela Serial
LED verde ON     ↓
LED vermelho OFF LED verde desligado
Buzzer OFF       ↓
        ↑        LED vermelho ligado
        │        ↓
        │        Buzzer ligado
        │        ↓
        │        Aguarda aproximadamente 10 segundos
        │        ↓
        │        LED vermelho desligado
        │        ↓
        │        Buzzer desligado
        │        ↓
        │        LED verde ligado novamente
        │        ↓
        │        Envia REPOUSO pela Serial
        └────────┴───────────────→ Retorna ao loop principal
```

## Fluxo dos Comandos Seriais

Além da leitura automática do sensor PIR, o sistema também permite o recebimento de comandos pela comunicação USB/Serial. Esses comandos são utilizados pelo Node-RED para testar individualmente os atuadores e validar o funcionamento do dashboard.

```txt
Node-RED envia comando pela Serial
        ↓
Arduino recebe o comando
        ↓
Comando identificado?
        ↓
 ┌───────────────────────┬────────────────────────┐
 │ LED_VERDE_ON          │ Liga LED verde          │
 │ LED_VERDE_OFF         │ Desliga LED verde       │
 │ LED_VERMELHO_ON       │ Liga LED vermelho       │
 │ LED_VERMELHO_OFF      │ Desliga LED vermelho    │
 │ BUZZER_ON             │ Liga buzzer             │
 │ BUZZER_OFF            │ Desliga buzzer          │
 └───────────────────────┴────────────────────────┘
        ↓
Arduino envia mensagem de confirmação ACK pela Serial
```

## Descrição do Fluxo

O sistema inicia configurando os pinos do Arduino UNO R3, do sensor PIR HC-SR501, dos LEDs e do buzzer. Em seguida, a comunicação Serial é inicializada em 9600 baud, permitindo a troca de mensagens entre o Arduino e o computador.

Durante a inicialização, o sistema mantém os atuadores desligados e aguarda aproximadamente 60 segundos para estabilização inicial do sensor PIR. Após esse período, o sistema informa que está pronto, aciona o LED verde e entra no estado inicial de repouso.

No estado de repouso, o LED verde permanece ligado, enquanto o LED vermelho e o buzzer permanecem desligados. O Arduino realiza continuamente a leitura do sensor PIR e também verifica se há comandos seriais recebidos do Node-RED.

Quando o sensor PIR detecta movimento, o Arduino altera o estado do sistema para alerta, envia a mensagem `PRESENCA_DETECTADA` pela comunicação USB/Serial, desliga o LED verde, liga o LED vermelho e aciona o buzzer. Esse estado permanece ativo por aproximadamente 10 segundos.

Após o tempo programado, o LED vermelho e o buzzer são desligados, o LED verde volta a ser ligado e o Arduino envia a mensagem `REPOUSO` pela comunicação USB/Serial. Em seguida, o sistema retorna ao loop principal de monitoramento.

## Estados Representados

| Estado | Condição | Ação do Sistema | Mensagem Serial |
|---|---|---|---|
| Inicialização | Sistema energizado | Configura pinos e inicia Serial | Sistema iniciando |
| Estabilização | Sensor PIR em aquecimento | Aguarda aproximadamente 60 segundos | Aguardando estabilizacao do sensor PIR |
| Repouso | Nenhum movimento detectado | LED verde ligado, LED vermelho e buzzer desligados | REPOUSO |
| Presença detectada | Movimento identificado pelo PIR | LED verde desligado, LED vermelho e buzzer acionados | PRESENCA_DETECTADA |
| Retorno ao repouso | Após aproximadamente 10 segundos | LED verde ligado novamente, LED vermelho e buzzer desligados | REPOUSO |
| Teste de atuadores | Comando recebido do Node-RED | Liga ou desliga LED verde, LED vermelho ou buzzer | ACK do comando recebido |

## Comandos Seriais Utilizados

| Comando recebido | Ação executada | Resposta do Arduino |
|---|---|---|
| LED_VERDE_ON | Liga o LED verde | ACK_LED_VERDE_ON |
| LED_VERDE_OFF | Desliga o LED verde | ACK_LED_VERDE_OFF |
| LED_VERMELHO_ON | Liga o LED vermelho | ACK_LED_VERMELHO_ON |
| LED_VERMELHO_OFF | Desliga o LED vermelho | ACK_LED_VERMELHO_OFF |
| BUZZER_ON | Liga o buzzer | ACK_BUZZER_ON |
| BUZZER_OFF | Desliga o buzzer | ACK_BUZZER_OFF |

## Integração com Node-RED e MQTT

As mensagens enviadas pelo Arduino pela porta USB/Serial são recebidas pelo Node-RED no computador. O Node-RED interpreta essas mensagens e pode publicá-las em tópicos MQTT, permitindo o monitoramento do estado do sistema em um dashboard.

Dessa forma, o fluxo de funcionamento do protótipo contempla tanto a resposta local aos eventos detectados pelo sensor PIR quanto a comunicação com a camada IoT por meio do computador, Node-RED, broker MQTT e dashboard.
