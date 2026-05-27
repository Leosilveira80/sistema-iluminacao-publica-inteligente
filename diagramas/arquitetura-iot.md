# Arquitetura IoT do Projeto

Este arquivo apresenta a arquitetura utilizada no protótipo de Sistema de Iluminação Pública Inteligente baseado em IoT.

A comunicação do projeto foi estruturada por meio da conexão USB/Serial entre o Arduino UNO R3 e o computador. O computador atua como gateway entre o protótipo físico e a camada IoT, utilizando o Node-RED para receber as mensagens seriais, tratar os dados e publicá-los em tópicos MQTT.

## Diagrama da Arquitetura

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

## Descrição da Arquitetura

O sensor PIR HC-SR501 realiza a detecção de presença ou movimento no ambiente monitorado. O sinal do sensor é enviado ao Arduino UNO R3, que processa a leitura e aciona os atuadores locais do protótipo.

Em estado de repouso, o LED verde permanece ligado. Quando há presença detectada, o Arduino desliga o LED verde, aciona o LED vermelho e liga o buzzer ativo por aproximadamente 10 segundos. Após esse intervalo, o sistema retorna automaticamente ao estado de repouso.

A comunicação IoT ocorre por meio da porta USB/Serial do Arduino. As mensagens enviadas pelo Arduino são recebidas pelo Node-RED no computador. O Node-RED interpreta essas mensagens e publica os estados do sistema em tópicos MQTT, permitindo o acompanhamento por dashboard ou por outro cliente assinante MQTT.

## Elementos da Arquitetura

| Elemento | Função |
|---|---|
| Sensor PIR HC-SR501 | Detectar presença ou movimento |
| Arduino UNO R3 | Processar os sinais do sensor e controlar os atuadores |
| LED verde | Indicar estado de repouso |
| LED vermelho | Indicar presença detectada |
| Buzzer ativo 5 V | Emitir alerta sonoro |
| Comunicação USB/Serial | Enviar mensagens do Arduino para o computador |
| Computador com Node-RED | Atuar como gateway entre Arduino e MQTT |
| Broker MQTT | Intermediar a publicação e assinatura das mensagens |
| Dashboard / Cliente MQTT | Visualizar os estados do sistema |

## Tópicos MQTT Utilizados

O sistema pode publicar e monitorar mensagens em tópicos MQTT, como:

```txt
cidade/iluminacao/poste01/status
cidade/iluminacao/poste01/presenca
cidade/iluminacao/poste01/comando
```

Esses tópicos permitem informar se o sistema está em repouso, se houve presença detectada e também possibilitam o envio de comandos para testes dos atuadores pelo Node-RED.

## Mensagens Seriais Utilizadas

Durante os testes, o Arduino envia mensagens pela comunicação USB/Serial, como:

```txt
PRESENCA_DETECTADA
REPOUSO
ACK_LED_VERDE_ON
ACK_LED_VERDE_OFF
ACK_LED_VERMELHO_ON
ACK_LED_VERMELHO_OFF
ACK_BUZZER_ON
ACK_BUZZER_OFF
```

Essas mensagens são utilizadas pelo Node-RED para validação do funcionamento do protótipo, acionamento do dashboard e integração com o broker MQTT.

## Observação

Nesta versão do protótipo, não foi utilizado módulo Wi-Fi adicional no circuito físico. A integração IoT foi realizada por meio do computador, que recebe os dados do Arduino pela porta USB/Serial e os encaminha para a camada MQTT utilizando o Node-RED.
