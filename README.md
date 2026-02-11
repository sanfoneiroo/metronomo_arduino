# Metrônomo com Arduino

Projeto de metrônomo digital desenvolvido com Arduino, com três versões de implementação, voltadas à prática musical e ao ensino de programação embarcada:

Controle analógico com potenciômetro

Controle digital com botões e display LCD

Versão pendular com servo motor

O projeto foi desenvolvido com foco em simplicidade, clareza de código e facilidade de montagem, permitindo que qualquer pessoa consiga reproduzir e modificar o sistema rapidamente.

## Versões do Projeto
### Controle Analógico

Ajuste de BPM por potenciômetro

Buzzer para pulso sonoro

LED indicando a batida

Botão para Play / Pause


### Controle Digital com Display LCD

Ajuste de BPM por botões

Display LCD 16×2 exibindo BPM e estado

Controle fino (+1 / -1 BPM) e grosso (+10 / -10 BPM)

LED integrado ao shield indica o pulso


### Controle Analógico + Pêndulo (Servo Motor)

Ajuste de BPM por potenciômetro

Movimento pendular via servo motor

Feedback sonoro por buzzer


## Lista de Materiais
### Componentes comuns

Arduino Uno R3

Protoboard

Jumpers macho-macho

Buzzer passivo 5V

### Controle Analógico

Potenciômetro linear 10kΩ

LED

Resistor 1kΩ

Push button

### Controle Digital

Display LCD Shield 16×2 com teclado para Arduino

Versão Pendular (Opcional)

Micro servo motor 9g

## Ligações

Os esquemas de ligação estão disponíveis na pasta:

/diagramas


Cada versão possui seu diagrama específico:

Controle analógico

Controle digital

Controle analógico + servo


## Como Usar

Clone o repositório:

git clone https://github.com/seu-usuario/metronomo-arduino.git


Abra o código desejado na Arduino IDE.

Monte o circuito conforme o diagrama correspondente.

Compile e grave o código na placa.

Ajuste o BPM e utilize o metrônomo normalmente.

## Objetivo do Projeto

Este projeto tem como objetivo servir como base prática para estudos de temporização, interfaces físicas e aplicações musicais com microcontroladores, permitindo adaptações simples para outros tipos de metrônomos, controladores rítmicos e projetos musicais interativos.

O desenvolvimento detalhado, explicações técnicas e fundamentação musical do projeto estão disponíveis no artigo publicado no blog da Eletrogate:

[BLOG ELETROGATE](https://blog.eletrogate.com/metronomo-arduino/)

## Autor

Erwin de Mattos Kuchenbecker
Músico e Desenvolvedor em Sistemas Embarcados & Aplicações Musicais
Rio de Janeiro – Brasil