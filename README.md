# Sistema de Control por Niveles con Arduino

Sistema de control automatizado desarrollado con **Arduino Uno R3**, capaz de controlar diferentes cargas eléctricas de acuerdo con el nivel de una entrada analógica.

El sistema utiliza un potenciómetro como entrada, un display de 7 segmentos para mostrar el nivel actual y diferentes salidas para controlar un LED, un ventilador y un foco.

## 📌 Descripción

El sistema divide la lectura del potenciómetro en cuatro niveles de operación:

- Nivel 0
- Nivel 1
- Nivel 2
- Nivel 3

Dependiendo del nivel detectado, se activan progresivamente las diferentes salidas del sistema.

Además, se implementó un mecanismo de seguridad mediante una entrada de habilitación que permite activar o desactivar todas las cargas.

## ⚙️ Funcionamiento

El potenciómetro conectado a la entrada analógica `A0` proporciona un valor entre 0 y 1023.

El valor se divide en cuatro niveles:

| Valor del potenciómetro | Nivel |
|---|---|
| 0 - 250 | 0 |
| 251 - 500 | 1 |
| 501 - 750 | 2 |
| 751 - 1023 | 3 |

Cuando el sistema está habilitado:

- **Nivel 0:** ninguna carga activa.
- **Nivel 1:** se activa el LED.
- **Nivel 2:** se activa el LED y el ventilador.
- **Nivel 3:** se activan el LED, el ventilador y el foco.

El nivel actual se muestra mediante un **display de 7 segmentos de ánodo común**.

Si el sistema no está habilitado, todas las salidas se apagan y el display permanece apagado.

## 🔌 Componentes

- Arduino Uno R3
- Potenciómetro
- Display de 7 segmentos 5161BS de ánodo común
- LED
- Ventilador DC
- Foco
- Transistores NPN
- Resistencias
- Interruptor
- Compuerta lógica AND 74LS08
- Protoboard
- Cables de conexión

## 💻 Tecnologías

- Arduino
- C/C++
- Electrónica digital
- Lectura de entradas analógicas
- Control de salidas digitales
- Display de 7 segmentos
- Lógica booleana

## 🔐 Sistema de seguridad

El proyecto incorpora una condición de habilitación que controla el funcionamiento de las cargas.

Cuando la señal de habilitación se encuentra activa, el sistema puede controlar las salidas de acuerdo con el nivel detectado.

Cuando la señal está desactivada:

- LED: apagado
- Ventilador: apagado
- Foco: apagado
- Display: apagado

Esto evita que las cargas sean activadas mientras el sistema no se encuentra habilitado.

## 📁 Estructura del proyecto

```text
Electronica-Arduino-Sem6/
│
├── Codigo/
│   └── sketch_jun9a/
│       └── sketch_jun9a.ino
│
├── ProyectoFinalElectronica.pdf
│
└── README.md