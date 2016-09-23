/*
Speedcontrolmotor.cpp - codigo Libreria para controlar velocidad de motor DC.
Creado por Gustavo David Ferreyra, Setiembre, 2016. Versión de dominio público.
*/
#include "Arduino.h"
#include "Speedcontrolmotor.h"
/* Inicia el funcionamiento de un motor DC, pinMotor es una salida
PWM de arduino que permite controlar la potencia del motor.
*/
Speedcontrolmotor::Speedcontrolmotor(int pinMotor, int init_voltage)
{
   _tension_motor= init_voltage;
   _pinMotor = pinMotor;
    pinMode(_pinMotor, OUTPUT);
    analogWrite(_pinMotor,_tension_motor);
}

void Speedcontrolmotor::setVoltageMotor(int valor){
_tension_motor= valor;
analogWrite(_pinMotor,_tension_motor);
}
void Speedcontrolmotor::check_sensors()
{
   _sensorValue = analogRead(_pinSensor);
}

void Speedcontrolmotor::setSensorMAX(int valor)
{
	_sensorMaximo =valor;
}

void Speedcontrolmotor::setTiempoIntervalo(int valor)
{
	_tiempo_intervalo = valor;

}
void Speedcontrolmotor::revolucion(void)
{
	_revoluciones++;
}


int Speedcontrolmotor::getRevoluciones(void){
return _revoluciones;
}
void Speedcontrolmotor::setRevObj(int valor){
_obj_rev = valor;
}
int Speedcontrolmotor::get_rps(void)
{
  unsigned long tiempo_actual = millis();
  if (tiempo_actual>_tiempo_proximo)
  {
  _tiempo_proximo = tiempo_actual + _tiempo_intervalo;
  _rps = (_revoluciones - _rev_anterior);
  _rev_anterior = _revoluciones;
  }
  return _rps;
  }

  void Speedcontrolmotor::setVelocidadCambio(int valor)
  {
  _velocidad_cambio = valor;
  }

  void Speedcontrolmotor::adaptVoltage(void){
  if ( _rps < _obj_rev) {
      if (_tension_motor < (255-_velocidad_cambio)) _tension_motor+=_velocidad_cambio;
  }else
   if (_rps == _obj_rev);
   else  _tension_motor-=_velocidad_cambio;

   analogWrite(_pinMotor,_tension_motor);
  }

void Speedcontrolmotor::count_revolutions(void)
{
	if ( _sensorValue>_sensorMaximo)
  {
		if (_estado_del_sensor==HIGH);
		else _revoluciones++;
		_estado_del_sensor = HIGH;
  }
	else
  {
		_estado_del_sensor = LOW;
  }

}
