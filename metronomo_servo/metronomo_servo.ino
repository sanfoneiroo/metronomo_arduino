// Config do Servo Motor
#include <Servo.h>
const int servo = 9;
Servo myservo; 
int direita = 100;
int esquerda = 80;
bool servoNaDireita = false;

void servo_direita(){
  myservo.write(direita);
}
void servo_esquerda(){
  myservo.write(esquerda);
}

// Definição de Pinos
const int buzzerPin = 12;       // buzzer passivo
const int botaoPlayPause = 10; // switch
const int potPin = A0;         // potenciômetro

// Config do Metrônomo
int bpm = 60;
int bpmMaximo = 120;
int bpmMinimo = 30;
bool tocando = false;
unsigned long ultimaBatida = 0;
unsigned long intervalo = 60000 / 60;

// --------- SETUP ---------
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(botaoPlayPause, INPUT_PULLUP);
  pinMode(potPin, INPUT);
  myservo.attach(servo);
}

// --------- LOOP ---------
void loop() {
  // Leitura do potenciômetro e mapeamento para BPM
  int leituraPot = analogRead(potPin);
  bpm = map(leituraPot, 0, 1023, bpmMinimo, bpmMaximo);
  intervalo = 60000 / bpm;;
  unsigned long agora = millis();

  // Acionamento por switch
  bool estadoPlayPause = digitalRead(botaoPlayPause);
  if (estadoPlayPause == LOW) {
    if (agora - ultimaBatida >= intervalo) {
      ultimaBatida = agora;

      tone(buzzerPin, 1000, 100); // bip

      // Movimento tipo pêndulo
      if (servoNaDireita) {
        servo_esquerda();
        servoNaDireita = false;
      } 
      else {
        servo_direita();
        servoNaDireita = true;
      }
    }
  }
  
}

