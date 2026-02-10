#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 2
#define ENA 9       
#define IN1 7
#define IN2 8

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float temperatureC;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  sensors.begin();
  Serial.begin(9600);
}

void loop() {
  sensors.requestTemperatures();
  temperatureC = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.println(temperatureC);

  int pwmValue = 0;

  if (temperatureC < 23) {
    pwmValue = 80;
  } 
  else if (temperatureC >= 23 && temperatureC < 30) {
    pwmValue = 150;
  } 
  else {
    pwmValue = 255;
  }

  analogWrite(ENA, pwmValue);
  delay(1000);
}
