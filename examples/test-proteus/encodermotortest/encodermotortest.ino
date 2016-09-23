#include <Event.h>
#include <Timer.h>
#include <LiquidCrystal.h>
#include <Speedcontrolmotor.h>


#define MOTOR_PIN 11
#define ENCODER_PIN 13

LiquidCrystal lcd(0,1,2,3,4,5);
Timer t;


void mostrar_rpm(void)
{
  //lcd.print(Motor.getRevoluciones());
}

void setup() {
  t.every(100,mostrar_rpm);
  pinMode(ENCODER_PIN,INPUT);
  lcd.begin(16,4);
  lcd.print("hola mundo");
  Speedcontrolmotor Motor(MOTOR_PIN,1024);
}

int valor_anterior;

void loop() {

int valor = digitalRead(ENCODER_PIN);
if (valor!= valor_anterior){
  //Motor.revolucion();
  valor_anterior = valor;
  }
t.update();

}
