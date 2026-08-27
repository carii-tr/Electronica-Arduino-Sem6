// ===============================
// SISTEMA DE CONTROL POR NIVELES
// Display 5161BS ÁNODO COMÚN
// ===============================

// Entradas
const int pot = A0;
const int enable = 5;

// Salidas
const int led = 2;
const int ventilador = 3;
const int foco = 4;

// Display 7 segmentos
const int segA = 6;
const int segB = 7;
const int segC = 8;
const int segD = 9;
const int segE = 10;
const int segF = 11;
const int segG = 12;

void setup() {

  pinMode(led, OUTPUT);
  pinMode(ventilador, OUTPUT);
  pinMode(foco, OUTPUT);

  pinMode(enable, INPUT);

  for (int i = 6; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }

  apagarDisplay();
}

void loop() {

  int valor = analogRead(pot);

  int nivel = 0;

  if (valor <= 250) {
    nivel = 0;
  }
  else if (valor <= 500) {
    nivel = 1;
  }
  else if (valor <= 750) {
    nivel = 2;
  }
  else {
    nivel = 3;
  }

  int seguro = digitalRead(enable);

  if (seguro == HIGH) {

    mostrarNumero(nivel);

    // LED indicador
    if (nivel >= 1)
      digitalWrite(led, HIGH);
    else
      digitalWrite(led, LOW);

    // Ventilador
    if (nivel >= 2)
      digitalWrite(ventilador, HIGH);
    else
      digitalWrite(ventilador, LOW);

    // Foco
    if (nivel >= 3)
      digitalWrite(foco, HIGH);
    else
      digitalWrite(foco, LOW);

  }
  else {

    digitalWrite(led, LOW);
    digitalWrite(ventilador, LOW);
    digitalWrite(foco, LOW);

    apagarDisplay();
  }

  delay(100);
}

// ===============================
// DISPLAY ÁNODO COMÚN
// LOW = ENCENDIDO
// HIGH = APAGADO
// ===============================

void apagarDisplay() {

  for (int i = 6; i <= 12; i++) {
    digitalWrite(i, HIGH);
  }
}

void mostrarNumero(int n) {

  apagarDisplay();

  switch (n) {

    case 0:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      break;

    case 1:
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      break;

    case 2:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segG, LOW);
      break;

    case 3:
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segG, LOW);
      break;
  }
}