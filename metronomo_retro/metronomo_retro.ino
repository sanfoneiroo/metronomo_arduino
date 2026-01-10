#include <Servo.h>

// --------- Definição de Pinos ---------
const int buzzerPin = 12;       // buzzer passivo
const int botaoPlayPause = 10; // botão
const int potPin = A0;         // potenciômetro
const int servo = 9;

Servo myservo;  // cria objeto Servo

int val;
int  val1=0;
int  val2=90;     // variable to read the value from the analog pin


// --------- Config do Metrônomo ---------
int bpm = 60;
int bpmMaximo = 120;
int bpmMinimo = 30;
bool tocando = false;
unsigned long ultimaBatida = 0;
unsigned long intervalo = 60000 / 60;

// --------- Controle do servo (evento de batida) ---------
bool servoNaDireita = false;
void servo_direita(){
  myservo.write(100);
}
void servo_esquerda(){
  myservo.write(80);
}


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

  // Acionamento por switch
  unsigned long agora = millis();

  bool estadoPlayPause = digitalRead(botaoPlayPause);
  if (estadoPlayPause == LOW) {
    if (agora - ultimaBatida >= intervalo) {
      ultimaBatida = agora;

      tone(buzzerPin, 1000, 100); // bip

      // --------- Movimento tipo pêndulo ---------
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

