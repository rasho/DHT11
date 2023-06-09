/*
  DHTSensor.cpp - Biblioteka za čitanje temperature i vlage s DHT senzora.
  Autor: Radenko Bogdanovic
  Datum: 09.06.2023
  Verzija: 1.0
  Opis: Ova biblioteka omogućuje čitanje temperature i vlage s' DHT senzora na Arduino platformi.
  Licenca: MIT Licenca
*/

#include "DHTSensor.h"

DHTSensor::DHTSensor(int pin) : _pin(pin) {}

void DHTSensor::begin() {
  // Inicijalizacija senzora
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, HIGH);
}

float DHTSensor::readTemperature() {
  // Čitanje temperature s DHT11 senzora
  uint8_t data[5] = {0};

  // Inicijalizacija komunikacije s senzorom
  digitalWrite(_pin, LOW);
  delay(18);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(40);
  pinMode(_pin, INPUT_PULLUP);

  // Očekivanje odgovora senzora
  unsigned long timeout = micros() + 1000;
  while (digitalRead(_pin) == LOW) {
    if (micros() > timeout) {
      return -1.0; // Povratna vrijednost u slučaju greške
    }
  }

  timeout = micros() + 1000;
  while (digitalRead(_pin) == HIGH) {
    if (micros() > timeout) {
      return -1.0; // Povratna vrijednost u slučaju greške
    }
  }

  // Čitanje podataka s senzora
  for (int i = 0; i < 5; i++) {
    uint8_t value = 0;
    for (int j = 0; j < 8; j++) {
      timeout = micros() + 1000;
      while (digitalRead(_pin) == LOW) {
        if (micros() > timeout) {
          return -1.0; // Povratna vrijednost u slučaju greške
        }
      }

      delayMicroseconds(30);

      if (digitalRead(_pin) == HIGH) {
        value |= (1 << (7 - j));
      }

      timeout = micros() + 1000;
      while (digitalRead(_pin) == HIGH) {
        if (micros() > timeout) {
          return -1.0; // Povratna vrijednost u slučaju greške
        }
      }
    }
    data[i] = value;
  }

  // Provjera checksuma
  if (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) {
    return (float)data[2];
  } else {
    return -1.0; // Povratna vrijednost u slučaju greške
  }
}

float DHTSensor::readHumidity() {
  // Čitanje vlage s DHT11 senzora
  uint8_t data[5] = {0};

  // Inicijalizacija komunikacije s senzorom
  digitalWrite(_pin, LOW);
  delay(18);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(40);
  pinMode(_pin, INPUT_PULLUP);

  // Očekivanje odgovora senzora
  unsigned long timeout = micros() + 1000;
  while (digitalRead(_pin) == LOW) {
    if (micros() > timeout) {
      return -1.0; // Povratna vrijednost u slučaju greške
    }
  }

  timeout = micros() + 1000;
  while (digitalRead(_pin) == HIGH) {
    if (micros() > timeout) {
      return -1.0; // Povratna vrijednost u slučaju greške
    }
  }

  // Čitanje podataka s senzora
  for (int i = 0; i < 5; i++) {
    uint8_t value = 0;
    for (int j = 0; j < 8; j++) {
      timeout = micros() + 1000;
      while (digitalRead(_pin) == LOW) {
        if (micros() > timeout) {
          return -1.0; // Povratna vrijednost u slučaju greške
        }
      }

      delayMicroseconds(30);

      if (digitalRead(_pin) == HIGH) {
        value |= (1 << (7 - j));
      }

      timeout = micros() + 1000;
      while (digitalRead(_pin) == HIGH) {
        if (micros() > timeout) {
          return -1.0; // Povratna vrijednost u slučaju greške
        }
      }
    }
    data[i] = value;
  }

  // Provjera checksuma
  if (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) {
    return (float)data[0];
  } else {
    return -1.0; // Povratna vrijednost u slučaju greške
  }
}
