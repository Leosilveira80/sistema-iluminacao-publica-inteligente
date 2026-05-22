// Projeto: Sistema de Iluminacao Publica Inteligente baseado em IoT
// Etapa 1: Teste local com Arduino, PIR, LEDs e buzzer
// Autor: Leonardo Silva Silveira
//
// Ligacoes:
// Sensor PIR no D2
// LED verde no D12
// LED vermelho no D11
// Buzzer no A0

const int pinoPIR = 2;
const int ledVerde = 12;
const int ledVermelho = 11;
const int buzzer = A0;

void setup() {
  pinMode(pinoPIR, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(buzzer, LOW);

  Serial.println("Sistema de Iluminacao Publica Inteligente iniciado.");
  Serial.println("Aguardando leitura do sensor PIR...");
}

void loop() {
  int movimento = digitalRead(pinoPIR);

  if (movimento == HIGH) {
    Serial.println("Presenca detectada.");

    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH);

    delay(10000);

    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledVerde, HIGH);

    Serial.println("Sistema retornou ao estado de repouso.");
  } else {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);

    Serial.println("Estado de repouso.");
    delay(1000);
  }
}
