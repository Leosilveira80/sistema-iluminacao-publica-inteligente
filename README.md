# Sistema de Iluminação Pública Inteligente baseado em IoT

Este repositório apresenta o desenvolvimento de um protótipo de Sistema de Iluminação Pública Inteligente baseado em Internet das Coisas (IoT), utilizando Arduino UNO R3, sensor de presença PIR HC-SR501, LEDs, buzzer ativo, comunicação USB/Serial, Node-RED, broker MQTT e dashboard de monitoramento.

A proposta simula uma solução capaz de identificar presença ou movimento em determinado ambiente e acionar sinais luminosos e sonoros automaticamente. O projeto está alinhado ao ODS 11, que trata de cidades e comunidades sustentáveis.

## Vídeo demonstrativo

A apresentação do projeto pode ser acessada pelo link abaixo:

https://www.youtube.com/watch?v=jO-FvlTTFa4

## Objetivo Geral

Desenvolver um protótipo funcional de iluminação pública inteligente com sensor de presença, capaz de alternar estados de funcionamento conforme a detecção de movimento.

## Objetivos Específicos

- Utilizar sensor PIR HC-SR501 para identificar presença ou movimento.
- Acionar LED verde no estado de repouso.
- Acionar LED vermelho e buzzer quando houver presença detectada.
- Documentar o projeto com código, imagens, prints, diagramas e evidências.
- Integrar o protótipo à camada IoT por meio de comunicação USB/Serial, Node-RED, broker MQTT e dashboard de monitoramento.

## Componentes Utilizados

| Componente | Quantidade | Função |
|---|---:|---|
| Arduino UNO R3 | 1 | Microcontrolador responsável pela leitura do sensor e acionamento dos atuadores |
| Sensor PIR HC-SR501 | 1 | Detecção de presença ou movimento |
| LED verde 3 mm | 1 | Indicação visual do estado de repouso |
| LED vermelho 3 mm | 1 | Indicação visual de presença detectada |
| Buzzer ativo 5 V | 1 | Atuador sonoro utilizado no estado de alerta |
| Resistores de 220 Ω | 2 | Limitação de corrente elétrica dos LEDs |
| Protoboard de 400 pontos | 1 | Base para montagem temporária do circuito |
| Jumpers Dupont | Diversos | Conexões elétricas entre os componentes |
| Computador com Arduino IDE e Node-RED | 1 | Programação, leitura serial e gateway USB/Serial-MQTT |
| Broker MQTT | 1 | Recebimento e distribuição das mensagens publicadas pelo Node-RED |

## Ligações do Circuito

| Dispositivo | Pino no Arduino |
|---|---|
| Sensor PIR HC-SR501 | D2 |
| LED verde | D12 |
| LED vermelho | D11 |
| Buzzer ativo 5 V | A0 |

## Funcionamento do Sistema

Em estado normal, o sistema permanece em repouso com o LED verde ligado. Quando o sensor PIR HC-SR501 detecta movimento, o LED verde é desligado, o LED vermelho é acionado e o buzzer emite alerta sonoro por aproximadamente 10 segundos. Após esse intervalo, caso não haja nova detecção de movimento, o sistema retorna automaticamente ao estado de repouso.

Durante a inicialização, o sensor PIR passa por um período de estabilização de aproximadamente 60 segundos antes do início efetivo do monitoramento.

## Comunicação IoT

A comunicação entre o Arduino UNO R3 e o computador é realizada por meio de conexão USB/Serial, configurada com taxa de transmissão de 9600 baud.

O computador atua como gateway entre o protótipo físico e a camada IoT. Por meio do Node-RED, as mensagens enviadas pelo Arduino são recebidas pela porta serial, tratadas e publicadas em tópicos MQTT. Essas informações podem ser acompanhadas em um dashboard de monitoramento ou por outro cliente assinante MQTT.

Arquitetura utilizada:

```txt
Sensor PIR HC-SR501
        ↓
Arduino UNO R3
        ↓ USB/Serial
Computador com Node-RED
        ↓ MQTT
Broker MQTT
        ↓
Dashboard / Cliente MQTT
```

## Tecnologias Utilizadas

- Arduino IDE
- Linguagem C/C++ para Arduino
- Sensor PIR HC-SR501
- Protoboard e componentes eletrônicos
- Comunicação USB/Serial entre Arduino e computador
- Node-RED para integração com broker MQTT e dashboard
- Protocolo MQTT para publicação e monitoramento dos estados do sistema
- GitHub para documentação do projeto

## Estrutura do Repositório

```txt
sistema-iluminacao-publica-inteligente/
│
├── README.md
│
├── codigo/
│   └── iluminacao_publica_iot.ino
│
├── diagramas/
│   ├── arquitetura-iot.md
│   ├── esquema-ligacoes.md
│   └── fluxograma-funcionamento.md
│
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
│
└── resultados/
    └── evidencias-testes.md
```

## Etapas do Projeto

| Etapa | Descrição | Status |
|---|---|---|
| Levantamento dos componentes | Definição dos materiais utilizados | Concluído |
| Montagem do circuito | Conexão do Arduino, PIR, LEDs, resistores e buzzer | Concluído |
| Programação do Arduino | Desenvolvimento do código de funcionamento | Concluído |
| Teste local | Validação dos estados de repouso e presença detectada | Concluído |
| Integração IoT | Comunicação USB/Serial, Node-RED, broker MQTT e dashboard | Concluído |
| Documentação no GitHub | Organização do repositório com código, imagens, diagramas e evidências | Concluído |

## Resultados dos Testes

Foram realizados testes para validar o funcionamento do protótipo em estado de repouso, presença detectada e acionamento dos atuadores. Também foram registradas medições de tempo de resposta utilizando o Node-RED e o dashboard de monitoramento.

| Sensor/atuador | Medição 1 (ms) | Medição 2 (ms) | Medição 3 (ms) | Medição 4 (ms) | Média (ms) |
|---|---:|---:|---:|---:|---:|
| Tempo MQTT do PIR | 143 | 142 | 143 | 143 | 142,75 |
| LED vermelho ON | 218 | 243 | 226 | 257 | 236,00 |
| Buzzer ON | 220 | 182 | 238 | 192 | 208,00 |
| LED verde ON | 248 | 251 | 214 | 213 | 231,50 |

## Evidências do Projeto

As evidências do desenvolvimento e funcionamento do protótipo estão organizadas nas pastas:

- `codigo/`: código-fonte do Arduino.
- `diagramas/`: arquitetura, esquema de ligações e fluxograma.
- `imagens/`: fotos da montagem física, componentes e prints do sistema.
- `resultados/`: evidências dos testes e medições realizadas.

## Links

- Repositório GitHub: https://github.com/Leosilveira80/sistema-iluminacao-publica-inteligente
- Vídeo demonstrativo no YouTube: inserir link após publicação

## Situação Atual

O protótipo local com Arduino, sensor PIR HC-SR501, LEDs e buzzer foi desenvolvido e testado. A comunicação IoT foi estruturada por meio de comunicação USB/Serial entre Arduino e computador, utilizando Node-RED, broker MQTT e dashboard de monitoramento. A documentação do projeto foi organizada neste repositório para apresentação acadêmica.

## Autores

Leonardo Silva Silveira

## Observação

Este projeto possui finalidade acadêmica e representa um protótipo em escala reduzida de um sistema de iluminação pública inteligente baseado em IoT.
