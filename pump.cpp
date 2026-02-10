#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>

#define ONE_WIRE_BUS 2
#define SERVO_PIN 6
#define PUMP_PIN 10

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

Servo valveServo;
float temperatureC;

void setup() {
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);

  valveServo.attach(SERVO_PIN);
  valveServo.write(0);

  sensors.begin();
  Serial.begin(9600);
}

void loop() {
  sensors.requestTemperatures();
  temperatureC = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.println(temperatureC);

  if (temperatureC > 23) {
    valveServo.write(90);      
    digitalWrite(PUMP_PIN, HIGH);
  } 
  else {
    valveServo.write(0);      
    digitalWrite(PUMP_PIN, LOW);
  }

  delay(1500);
}
