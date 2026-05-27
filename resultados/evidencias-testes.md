# Evidências dos Testes do Protótipo

Este documento reúne as evidências utilizadas para comprovar o funcionamento do protótipo de Sistema de Iluminação Pública Inteligente baseado em IoT.

O protótipo foi testado com Arduino UNO R3, sensor PIR HC-SR501, LED verde, LED vermelho, buzzer ativo 5 V, comunicação USB/Serial, Node-RED, broker MQTT e dashboard de monitoramento.

## Objetivo dos Testes

Validar o comportamento do sistema nos principais estados de funcionamento:

1. Inicialização e estabilização do sensor PIR.
2. Estado de repouso, com LED verde ligado.
3. Estado de presença detectada, com LED vermelho e buzzer acionados.
4. Retorno automático ao estado de repouso.
5. Comunicação USB/Serial entre Arduino e computador.
6. Integração com Node-RED, broker MQTT e dashboard.
7. Teste individual dos atuadores por comandos seriais.

## Configuração Testada

| Item | Configuração |
|---|---|
| Microcontrolador | Arduino UNO R3 |
| Sensor | PIR HC-SR501 |
| LED verde | Pino D12 |
| LED vermelho | Pino D11 |
| Buzzer ativo 5 V | Pino A0 |
| Ambiente de programação | Arduino IDE |
| Comunicação local | USB/Serial |
| Velocidade Serial | 9600 baud |
| Integração IoT | Node-RED, broker MQTT e dashboard |
| Tempo de estabilização do PIR | Aproximadamente 60 segundos |
| Tempo de alerta | Aproximadamente 10 segundos |

## Cenários de Teste

| Cenário | Condição | Resultado Obtido | Evidência | Status |
|---|---|---|---|---|
| Inicialização do sistema | Arduino conectado ao computador | Sistema inicia e aguarda estabilização do sensor PIR | `../imagens/print-monitor-serial-01-inicializacao.png` | Concluído |
| Sistema em repouso | Nenhum movimento detectado | LED verde ligado, LED vermelho desligado e buzzer desligado | `../imagens/estado-repouso.png` e `../imagens/print-monitor-serial-02-repouso.png` | Concluído |
| Presença detectada | Movimento identificado pelo sensor PIR | LED verde desligado, LED vermelho ligado e buzzer acionado | `../imagens/presenca-detectada.png` e `../imagens/print-monitor-serial-03-presenca-detectada.png` | Concluído |
| Montagem física | Componentes conectados ao Arduino e à protoboard | Circuito montado com sensor PIR, LEDs, resistores e buzzer | `../imagens/montagem-circuito.png` | Concluído |
| Código na Arduino IDE | Código carregado no Arduino | Código compilado e utilizado no protótipo | `../imagens/print-arduino-ide-01.png` e `../imagens/print-arduino-ide-02.png` | Concluído |
| Comunicação USB/Serial | Arduino conectado ao computador | Mensagens enviadas pelo Arduino ao Node-RED | `../imagens/print-node-red-fluxo-debug.png` | Concluído |
| Integração MQTT | Node-RED conectado ao broker MQTT | Estados do sistema publicados e monitorados em dashboard | `../imagens/print-dashboard-node-red.png` | Concluído |
| Teste do LED verde | Comando enviado pelo Node-RED | LED verde acionado individualmente | `../imagens/print-dashboard-led-verde.png` | Concluído |
| Teste do LED vermelho | Comando enviado pelo Node-RED | LED vermelho acionado individualmente | `../imagens/print-dashboard-led-vermelho.png` | Concluído |
| Teste do buzzer | Comando enviado pelo Node-RED | Buzzer acionado individualmente | `../imagens/print-dashboard-buzzer.png` | Concluído |

## Evidências Visuais

| Evidência | Arquivo |
|---|---|
| Repositório organizado no GitHub | `../imagens/github-repositorio.png` |
| Código na Arduino IDE - parte 1 | `../imagens/print-arduino-ide-01.png` |
| Código na Arduino IDE - parte 2 | `../imagens/print-arduino-ide-02.png` |
| Inicialização no Monitor Serial | `../imagens/print-monitor-serial-01-inicializacao.png` |
| Estado de repouso no Monitor Serial | `../imagens/print-monitor-serial-02-repouso.png` |
| Presença detectada no Monitor Serial | `../imagens/print-monitor-serial-03-presenca-detectada.png` |
| Montagem física do circuito | `../imagens/montagem-circuito.png` |
| Estado de repouso com LED verde ligado | `../imagens/estado-repouso.png` |
| Presença detectada com LED vermelho ligado | `../imagens/presenca-detectada.png` |
| Arduino UNO R3 utilizado | `../imagens/arduino-uno-r3-closeup.png` |
| Sensor PIR HC-SR501 utilizado | `../imagens/sensor-pir-closeup.png` |
| Buzzer ativo 5 V utilizado | `../imagens/buzzer-ativo-5v.png` |
| Dashboard geral do Node-RED | `../imagens/print-dashboard-node-red.png` |
| Teste do LED verde no dashboard | `../imagens/print-dashboard-led-verde.png` |
| Teste do LED vermelho no dashboard | `../imagens/print-dashboard-led-vermelho.png` |
| Teste do buzzer no dashboard | `../imagens/print-dashboard-buzzer.png` |
| Fluxo e debug do Node-RED | `../imagens/print-node-red-fluxo-debug.png` |

## Mensagens Seriais Registradas

Durante os testes, foram utilizadas mensagens seriais para validar a comunicação entre Arduino, computador e Node-RED.

```txt
Sistema iniciando...
Aguardando estabilizacao do sensor PIR por 60 segundos.
Sistema pronto.
Estado inicial: REPOUSO
PRESENCA_DETECTADA
REPOUSO
ACK_LED_VERDE_ON
ACK_LED_VERDE_OFF
ACK_LED_VERMELHO_ON
ACK_LED_VERMELHO_OFF
ACK_BUZZER_ON
ACK_BUZZER_OFF
```

## Medições Realizadas

Foram registradas medições de tempo de resposta por meio do Node-RED e do dashboard de monitoramento.

| Sensor/atuador | Medição 1 (ms) | Medição 2 (ms) | Medição 3 (ms) | Medição 4 (ms) | Média (ms) |
|---|---:|---:|---:|---:|---:|
| Tempo MQTT do PIR | 143 | 142 | 143 | 143 | 142,75 |
| LED vermelho ON | 218 | 243 | 226 | 257 | 236,00 |
| Buzzer ON | 220 | 182 | 238 | 192 | 208,00 |
| LED verde ON | 248 | 251 | 214 | 213 | 231,50 |

## Observações dos Testes

Durante os testes locais, o sensor PIR HC-SR501 foi utilizado para identificar movimento no ambiente. Quando o sistema permaneceu sem detecção de movimento, o LED verde ficou ligado, indicando o estado de repouso.

Quando o sensor PIR detectou presença, o sistema desligou o LED verde, acionou o LED vermelho e ativou o buzzer. Após o tempo definido no código, o sistema retornou automaticamente ao estado de repouso.

A comunicação USB/Serial permitiu o envio das mensagens do Arduino ao computador. O Node-RED recebeu essas mensagens, processou os dados, publicou informações em tópicos MQTT e apresentou os estados do sistema no dashboard.

Os testes individuais dos atuadores também foram realizados pelo dashboard do Node-RED, permitindo verificar o acionamento do LED verde, do LED vermelho e do buzzer por meio de comandos seriais e mensagens de confirmação ACK.

## Resultado Obtido

O protótipo apresentou o comportamento esperado nos testes realizados. As evidências registradas por meio de fotos, prints, Monitor Serial, Node-RED, MQTT e dashboard demonstram a montagem física, o funcionamento do código, a comunicação USB/Serial e a integração com a camada IoT.

As medições realizadas indicaram tempos de resposta compatíveis com o funcionamento esperado do protótipo em escala reduzida, validando tanto a detecção de presença quanto o acionamento dos atuadores e a comunicação com o ambiente de monitoramento.

## Conclusão Parcial

Os testes indicam que o protótipo atende aos objetivos definidos para a etapa acadêmica do projeto. O sistema foi capaz de detectar presença, acionar atuadores luminosos e sonoros, retornar ao estado de repouso e comunicar os estados do protótipo por meio de USB/Serial, Node-RED, broker MQTT e dashboard.

Dessa forma, as evidências registradas neste repositório comprovam o funcionamento físico e lógico do protótipo, bem como sua integração com recursos de Internet das Coisas aplicados ao contexto de iluminação pública inteligente.
