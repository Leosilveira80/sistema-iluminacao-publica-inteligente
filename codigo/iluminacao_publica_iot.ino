// Projeto: Iluminacao Publica Inteligente
// Etapa: Arduino + PIR + LEDs + buzzer + comandos seriais para Node-RED
// PIR no D2
// LED verde no D12
// LED vermelho no D11
// Buzzer no A0

const int pinoPIR = 2;
const int ledVerde = 12;
const int ledVermelho = 11;
const int buzzer = A0;

const unsigned long tempoAlerta = 10000; // 10 segundos

bool emAlerta = false;
bool aguardandoPIRBaixar = false;
unsigned long inicioAlerta = 0;

void setup() {
  pinMode(pinoPIR, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(buzzer, LOW);

  Serial.println("Sistema iniciando...");
  Serial.println("Aguardando estabilizacao do sensor PIR por 60 segundos.");

  delay(60000);

  Serial.println("Sistema pronto.");
  Serial.println("Estado inicial: REPOUSO");

  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {
  verificarComandosSeriais();

  int leituraPIR = digitalRead(pinoPIR);

  if (leituraPIR == LOW) {
    aguardandoPIRBaixar = false;
  }

  if (leituraPIR == HIGH && emAlerta == false && aguardandoPIRBaixar == false) {
    emAlerta = true;
    aguardandoPIRBaixar = true;
    inicioAlerta = millis();

    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH);

    Serial.println("PRESENCA_DETECTADA");
  }

  if (emAlerta == true && millis() - inicioAlerta >= tempoAlerta) {
    emAlerta = false;

    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);

    Serial.println("REPOUSO");
  }

  delay(100);
}

void verificarComandosSeriais() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "LED_VERDE_ON") {
      digitalWrite(ledVerde, HIGH);
      Serial.println("ACK_LED_VERDE_ON");
    }

    else if (comando == "LED_VERDE_OFF") {
      digitalWrite(ledVerde, LOW);
      Serial.println("ACK_LED_VERDE_OFF");
    }

    else if (comando == "LED_VERMELHO_ON") {
      digitalWrite(ledVermelho, HIGH);
      Serial.println("ACK_LED_VERMELHO_ON");
    }

    else if (comando == "LED_VERMELHO_OFF") {
      digitalWrite(ledVermelho, LOW);
      Serial.println("ACK_LED_VERMELHO_OFF");
    }

    else if (comando == "BUZZER_ON") {
      digitalWrite(buzzer, HIGH);
      Serial.println("ACK_BUZZER_ON");
    }

    else if (comando == "BUZZER_OFF") {
      digitalWrite(buzzer, LOW);
      Serial.println("ACK_BUZZER_OFF");
    }
  }
}
