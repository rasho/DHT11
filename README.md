# DHT11
Ova biblioteka, nazvana "DHTSensor", omogućuje čitanje temperature i vlage s DHT11 senzora koristeći Arduino. Evo objašnjenja o tome kako koristiti ovu biblioteku:

#### 1. Prvo morate uključiti biblioteku u vaš Arduino projekt dodavanjem sljedeće linije na vrh vašeg programa:

```
#include <DHTSensor.h>
```
#### 2. Zatim, unutar vaše glavne petlje (loop funkcije), možete stvoriti objekt DHTSensor s odgovarajućim pinom na kojem je priključen senzor. Na primjer:
```
DHTSensor dhtSensor(D2);  // Kreiranje objekta DHTSensor s pinom D2
```
#### 3. U setup funkciji, morate pozvati metodu begin kako biste inicijalizirali senzor. Na primjer:
```
void setup() {
  Serial.begin(9600);
  dhtSensor.begin();  // Inicijalizacija senzora
}
```
#### 4. Sada možete koristiti objekt dhtSensor za čitanje temperature i vlage u glavnoj petlji (loop funkciji). Na primjer:
```
void loop() {
  float temperature = dhtSensor.readTemperature();  // Čitanje temperature
  float humidity = dhtSensor.readHumidity();  // Čitanje vlage
  
  // Ispis temperature i vlage na serijski monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  delay(2000);
}
```
Ovaj primjer će čitati temperaturu i vlagu s DHT11 senzora povezanog na odabrani pin (u ovom slučaju, pin D2) i ispisivati ih na serijski monitor svake 2 sekunde. Naravno, možete prilagoditi kod prema vašim potrebama, na primjer, dodavanjem dodatne logike ili integracijom s drugim dijelovima vašeg Arduino projekta.

Molim vas da provjerite da su sve veze senzora ispravne i da je odabran ispravan pin u skladu s vašim vezanjem.
