# Sistema de Iluminação Pública Inteligente baseado em IoT

## Descrição do Projeto

Este repositório apresenta o desenvolvimento de um protótipo de Sistema de Iluminação Pública Inteligente baseado em Internet das Coisas, utilizando Arduino UNO R3, sensor de presença PIR, LEDs e buzzer.

O objetivo do projeto é simular uma solução de iluminação pública capaz de identificar presença ou movimento em determinado ambiente e acionar sinais luminosos e sonoros. A proposta está alinhada ao ODS 11, que trata de cidades e comunidades sustentáveis.

## Objetivo Geral

Desenvolver um protótipo funcional de iluminação pública inteligente com sensor de presença, capaz de alternar estados de funcionamento conforme a detecção de movimento.

## Objetivos Específicos

- Utilizar sensor PIR para identificar presença ou movimento.
- Acionar LED verde no estado de repouso.
- Acionar LED vermelho e buzzer quando houver presença detectada.
- Simular o funcionamento de um sistema inteligente aplicado à iluminação pública.
- Documentar o projeto com código, imagens, prints e diagramas.
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
├── imagens/
│   ├── montagem-circuito.jpg
│   ├── estado-repouso.jpg
│   └── presenca-detectada.jpg
├── diagramas/
│   ├── arquitetura-iot.png
│   ├── fluxograma-funcionamento.png
│   └── esquema-ligacoes.png
└── resultados/
    └── evidencias-testes.md
```

## Etapas do Projeto

| Etapa | Descrição | Status |
|---|---|---|
| Levantamento dos componentes | Definição dos materiais utilizados | Concluído |
| Montagem do circuito | Conexão do Arduino, PIR, LEDs e buzzer | Concluído |
| Programação do Arduino | Desenvolvimento do código de funcionamento | Concluído |
| Teste local | Validação dos estados de repouso e presença | Concluído |
| Documentação no GitHub | Organização do repositório com código e evidências | Em andamento |
| Integração MQTT | Comunicação com plataforma IoT | Previsto |

## Evidências do Projeto

As evidências do projeto serão adicionadas nas pastas de imagens, diagramas e resultados, incluindo:

- Print do código na Arduino IDE.
- Print do Monitor Serial.
- Foto da montagem física.
- Foto do LED verde ligado em repouso.
- Foto do LED vermelho e buzzer acionados.
- Diagrama da arquitetura do sistema.
- Fluxograma de funcionamento.
- Esquema de ligação dos componentes.

## Situação Atual

O protótipo local com Arduino, sensor PIR, LEDs e buzzer foi desenvolvido e testado. A documentação do projeto está sendo organizada neste repositório para apresentação acadêmica.

## Autor

Leonardo Silva Silveira
