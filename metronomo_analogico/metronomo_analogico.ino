// Definição de Pinos

const int buzzerPin = 11;       // buzzer passivo
const int botaoPlayPause = 10; // botão
const int potPin = A0;         // potenciômetro
const int ledPin = 12;         // LED + resistor

// Configurações do Metrônomo
int bpm = 60;
int bpmMaximo = 120;
int bpmMinimo = 30;
bool tocando = false;

unsigned long ultimaBatida = 0;
unsigned long intervalo = 60000 / 60;

// Controle do LED
bool ledAtivo = false;
unsigned long tempoLed = 0;
const unsigned long duracaoLed = 50;

// Atualização do Intervalo
void atualizarIntervalo() { 
  intervalo = 60000 / bpm;
}

// Controle de Play e Pause
bool ultimoEstadoPlayPause = HIGH;

// ----- SETUP -----
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(botaoPlayPause, INPUT_PULLUP);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW); // LED começa apagado
}

// ------ LOOP -----
void loop() {
  // Leitura do potenciômetro e mapeamento para BPM
  int leituraPot = analogRead(potPin);
  bpm = map(leituraPot, 0, 1023, bpmMinimo, bpmMaximo);
  atualizarIntervalo();

  // Botão PLAY / PAUSE
  bool estadoPlayPause = digitalRead(botaoPlayPause);
  if (estadoPlayPause == LOW && ultimoEstadoPlayPause == HIGH) {
    tocando = !tocando;
    delay(300); // debounce simples
  }
  ultimoEstadoPlayPause = estadoPlayPause;

  // Lógica do metrônomo
  unsigned long agora = millis();
  
  if (tocando) {
    if (agora - ultimaBatida >= intervalo) {
      ultimaBatida = agora;

      tone(buzzerPin, 1000, 100); // bip de 100 ms

      // LED pisca na batida
      digitalWrite(ledPin, HIGH);
      ledAtivo = true;
      tempoLed = agora;
    }
  }

  // Desliga o LED após o pulso
  if (ledAtivo && (agora - tempoLed >= duracaoLed)) {
    digitalWrite(ledPin, LOW);
    ledAtivo = false;
  }
}
