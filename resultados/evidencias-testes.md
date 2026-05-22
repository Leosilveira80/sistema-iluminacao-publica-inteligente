# Evidências dos Testes do Protótipo

Este documento reúne as evidências previstas para comprovar o funcionamento do protótipo de Sistema de Iluminação Pública Inteligente baseado em IoT.

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

## Cenários de Teste

| Cenário | Condição | Resultado Esperado | Status |
|---|---|---|---|
| Sistema em repouso | Nenhum movimento detectado | LED verde ligado, LED vermelho desligado e buzzer desligado | Concluído |
| Presença detectada | Movimento identificado pelo sensor PIR | LED verde desligado, LED vermelho ligado e buzzer acionado | Concluído |
| Retorno ao repouso | Após aproximadamente 10 segundos | LED vermelho e buzzer desligados, LED verde ligado novamente | Concluído |

## Evidências a serem adicionadas

As seguintes evidências serão inseridas no repositório:

- Print do código aberto na Arduino IDE.
- Print do Monitor Serial exibindo os estados do sistema.
- Foto da montagem física com Arduino, sensor PIR, LEDs e buzzer.
- Foto do estado de repouso com LED verde ligado.
- Foto do estado de presença detectada com LED vermelho ligado.
- Diagrama da arquitetura IoT proposta.
- Fluxograma de funcionamento.
- Esquema de ligação dos componentes.

## Observações dos Testes

Durante os testes locais, o sensor PIR foi utilizado para identificar movimento no ambiente. Quando o sensor detectou presença, o sistema acionou o LED vermelho e o buzzer. Após o tempo definido no código, o sistema retornou automaticamente ao estado de repouso com o LED verde ligado.

## Conclusão Parcial

Os testes locais indicam que o protótipo atende ao comportamento esperado para a etapa inicial do projeto. A comunicação MQTT permanece como proposta de evolução para integração com uma plataforma IoT.
