# Sistema de Iluminação Pública Inteligente baseado em IoT

Este repositório apresenta o desenvolvimento de um protótipo de Sistema de Iluminação Pública Inteligente baseado em Internet das Coisas, utilizando Arduino UNO R3, sensor de presença PIR HC-SR501, LEDs e buzzer.

A proposta simula uma solução capaz de identificar presença ou movimento em determinado ambiente e acionar sinais luminosos e sonoros automaticamente. O projeto está alinhado ao ODS 11, que trata de cidades e comunidades sustentáveis.

## Objetivo Geral

Desenvolver um protótipo funcional de iluminação pública inteligente com sensor de presença, capaz de alternar estados de funcionamento conforme a detecção de movimento.

## Objetivos Específicos

- Utilizar sensor PIR para identificar presença ou movimento.
- Acionar LED verde no estado de repouso.
- Acionar LED vermelho e buzzer quando houver presença detectada.
- Documentar o projeto com código, imagens, prints, diagramas e evidências.
- Prever futura integração com comunicação MQTT para aplicações IoT.

## Componentes Utilizados

| Componente | Quantidade | Função |
|---|---:|---|
| Arduino UNO R3 | 1 | Microcontrolador principal |
| Sensor PIR HC-SR501 | 1 | Detecção de presença/movimento |
| LED verde | 1 | Indicação de estado normal |
| LED vermelho | 1 | Indicação de presença detectada |
| Buzzer ativo 5V | 1 | Alerta sonoro |
| Resistores 220 ohms | 2 | Proteção dos LEDs |
| Protoboard | 1 | Montagem do circuito |
| Jumpers Dupont | Diversos | Conexões elétricas |

## Ligações do Circuito

| Dispositivo | Pino no Arduino |
|---|---|
| Sensor PIR | D2 |
| LED verde | D12 |
| LED vermelho | D11 |
| Buzzer | A0 |

## Funcionamento do Sistema

Em estado normal, o sistema permanece em repouso com o LED verde ligado. Quando o sensor PIR detecta movimento, o LED verde é desligado, o LED vermelho é acionado e o buzzer emite alerta sonoro por aproximadamente 10 segundos. Após esse intervalo, o sistema retorna automaticamente ao estado de repouso.

## Tecnologias Utilizadas

- Arduino IDE
- Linguagem C/C++ para Arduino
- Sensor PIR HC-SR501
- Prototipagem eletrônica em protoboard
- GitHub para documentação do projeto
- MQTT como proposta de evolução para comunicação IoT

## Estrutura do Repositório

```text
sistema-iluminacao-publica-inteligente/
├── README.md
├── codigo/
│   └── iluminacao_publica_iot.ino
├── diagramas/
│   ├── arquitetura-iot.md
│   ├── esquema-ligacoes.md
│   └── fluxograma-funcionamento.md
├── imagens/
│   ├── README.md
│   ├── montagem-circuito.png
│   ├── estado-repouso.png
│   ├── presenca-detectada.png
│   ├── arduino-uno-r3-closeup.png
│   ├── sensor-pir-closeup.png
│   ├── buzzer-ativo-5v.png
│   ├── github-repositorio.png
│   ├── print-arduino-ide-01.png
│   ├── print-arduino-ide-02.png
│   ├── print-monitor-serial-01-inicializacao.png
│   ├── print-monitor-serial-02-repouso.png
│   └── print-monitor-serial-03-presenca-detectada.png
└── resultados/
    └── evidencias-testes.md
