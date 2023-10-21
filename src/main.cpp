#include <Arduino.h>

int sumar(int);

int nElementos;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    // Espera a que la comunicación serial esté disponible.
  }

  do {
    Serial.print("Digite el número de elementos: ");
    while (!Serial.available()) {
      // Espera a que el usuario ingrese datos por el puerto serie.
    }
    nElementos = Serial.parseInt();
  } while (nElementos <= 0);

  Serial.print("\nLa suma es: ");
  Serial.println(sumar(nElementos));
}

void loop() {
  // Tu código de loop, si es necesario.
}

int sumar(int n) {
  int suma = 0;

  if (n == 1) {
    suma = 1;
  } else {
    suma = n + sumar(n - 1);
  }
  return suma;
}
