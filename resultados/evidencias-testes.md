# Evidências dos Testes do Protótipo

Este documento reúne as evidências utilizadas para comprovar o funcionamento do protótipo de Sistema de Iluminação Pública Inteligente baseado em IoT.

## Objetivo dos Testes

Validar o comportamento do sistema em dois estados principais:

1. Estado de repouso, com LED verde ligado.
2. Estado de presença detectada, com LED vermelho e buzzer acionados.

## Configuração Testada

| Item | Configuração |
|---|---|
| Microcontrolador | Arduino UNO R3 |
| Sensor | PIR HC-SR501 |
| LED verde | Pino D12 |
| LED vermelho | Pino D11 |
| Buzzer | Pino A0 |
| Ambiente de programação | Arduino IDE |
| Comunicação local | Monitor Serial |
| Porta utilizada | COM5 |
| Velocidade Serial | 9600 baud |

## Cenários de Teste

| Cenário | Condição | Resultado Esperado | Evidência | Status |
|---|---|---|---|---|
| Inicialização do sistema | Arduino conectado ao computador | Sistema inicia e estabiliza o sensor PIR | `print-monitor-serial-01-inicializacao.png` | Concluído |
| Sistema em repouso | Nenhum movimento detectado | LED verde ligado, LED vermelho desligado e buzzer desligado | `estado-repouso.png` e `print-monitor-serial-02-repouso.png` | Concluído |
| Presença detectada | Movimento identificado pelo sensor PIR | LED verde desligado, LED vermelho ligado e buzzer acionado | `presenca-detectada.png` e `print-monitor-serial-03-presenca-detectada.png` | Concluído |
| Montagem física | Componentes conectados ao Arduino e protoboard | Circuito montado com sensor PIR, LEDs e buzzer | `montagem-circuito.png` | Concluído |

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
| Sensor PIR HC-SR501 | `../imagens/sensor-pir-closeup.png` |
| Buzzer ativo 5V | `../imagens/buzzer-ativo-5v.png` |

## Observações dos Testes

Durante os testes locais, o sensor PIR HC-SR501 foi utilizado para identificar movimento no ambiente. Quando o sistema permaneceu sem detecção de movimento, o LED verde ficou ligado, indicando o estado de repouso.

Quando o sensor PIR detectou presença, o sistema desligou o LED verde, acionou o LED vermelho e ativou o buzzer. Após o tempo definido no código, o sistema retornou automaticamente ao estado de repouso.

## Resultado Obtido

O protótipo apresentou o comportamento esperado nos testes realizados. As evidências registradas por meio de fotos e prints demonstram a montagem física, o funcionamento do código, a comunicação pelo Monitor Serial e a organização do projeto no GitHub.

## Conclusão Parcial

Os testes locais indicam que o protótipo atende aos objetivos da etapa inicial do projeto. A comunicação MQTT permanece como proposta de evolução para uma etapa futura de integração com plataforma IoT.
