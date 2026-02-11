// Configurações do Display LCD Shield 16x2 com Teclado para Arduino
#include <LiquidCrystal.h> 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const int LEDdisplay = 10;    
const int botaoAnalogico = A0;

// Definição de Pinos
const int buzzerPin = 3; // Buzzer passivo

// Configurações do Metrônomo
int bpm = 60;
int bpmMaximo = 120;
int bpmMinimo = 30;
bool tocando = false;

unsigned long ultimaBatida = 0;
unsigned long intervalo = 60000 / 60;

// Controle do LED
bool ledApagadoNaBatida = false;
unsigned long tempoLed = 0;

// Atualização do LCD
void atualizarLCD() {
  lcd.setCursor(0, 1);
  lcd.print("BPM:");
  if (bpm < 100) lcd.print(" ");
  lcd.print(bpm);
  lcd.print(tocando ? " PLAY " : " PAUSE");
}

// Controle de Play e Pause
bool ultimoEstadoSelect = HIGH;

// ----- SETUP -----
void setup() {
  lcd.begin(16, 2);

  pinMode(buzzerPin, OUTPUT);
  pinMode(botaoAnalogico, INPUT);
  pinMode(LEDdisplay, OUTPUT);

  digitalWrite(LEDdisplay, HIGH); // LED começa aceso

  lcd.setCursor(0, 0);
  lcd.print("Metronomo");
  lcd.setCursor(0, 1);
  lcd.print("BPM:");
  lcd.print(bpm);
  lcd.print(" PAUSE");
}

// ------ LOOP -----
void loop() {
  // Leitura dos botões
  int leitura = analogRead(botaoAnalogico);

  bool botaoCima     = (leitura >= 100 && leitura < 200);
  bool botaoBaixo    = (leitura >= 200 && leitura < 400);
  bool botaoDireita  = (leitura >= 0   && leitura < 100);
  bool botaoEsquerda = (leitura >= 400 && leitura < 600);
  bool botaoSelect   = (leitura >= 600 && leitura < 800);

  // Ajuste de BPM
  if (botaoCima) {
    bpm += 10;
    if (bpm > bpmMaximo) bpm = bpmMaximo;
    atualizarLCD();
    delay(150); //debounce
  }
  else if (botaoBaixo) {
    bpm -= 10;
    if (bpm < bpmMinimo) bpm = bpmMinimo;
    atualizarLCD();
    delay(150); //debounce
  }
  else if (botaoDireita) {
    bpm += 1;
    if (bpm > bpmMaximo) bpm = bpmMaximo;
    atualizarLCD();
    delay(150); //debounce
  }
  else if (botaoEsquerda) {
    bpm -= 1;
    if (bpm < bpmMinimo) bpm = bpmMinimo;
    atualizarLCD();
    delay(150); //debounce
  }

  // Play / Pause
  if (botaoSelect && !ultimoEstadoSelect) {
    tocando = !tocando;
    atualizarLCD();

    if (!tocando) {
      digitalWrite(LEDdisplay, HIGH); // no pause, LED fica aceso
    }

    delay(150); //debounce
  }
  ultimoEstadoSelect = botaoSelect;

  // Lógica do metrônomo
  unsigned long agora = millis();
  intervalo = 60000 / bpm;

  if (tocando) {
    if (agora - ultimaBatida >= intervalo) {
      ultimaBatida = agora;

      tone(buzzerPin, 1000, 100);

      // LED apaga na batida
      digitalWrite(LEDdisplay, LOW);
      ledApagadoNaBatida = true;
      tempoLed = agora;
    }
  }

  // LED acende após a batida
  if (ledApagadoNaBatida && (agora - tempoLed >= 100)) {
    digitalWrite(LEDdisplay, HIGH);
    ledApagadoNaBatida = false;
  }
}
