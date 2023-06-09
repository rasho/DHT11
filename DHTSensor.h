/*
  DHTSensor.h - Biblioteka za čitanje temperature i vlage s DHT senzora.
  Autor: Radenko Bogdanovic
  Datum: 09.06.2023
  Verzija: 1.0
  Opis: Ova biblioteka omogućuje čitanje temperature i vlage s' DHT11 senzora na Arduino platformi.
  Licenca: MIT Licenca
*/
#ifndef DHTSensor_h
#define DHTSensor_h

#include <Arduino.h>

class DHTSensor {
  public:
    DHTSensor(int pin);
    void begin();
    float readTemperature();
    float readHumidity();
    
  private:
    int _pin;
};

#endif