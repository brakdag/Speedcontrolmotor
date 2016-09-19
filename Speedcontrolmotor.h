
/*
speedcontrolmotor.h - Código Libreria para controlar velocidad de motor DC.
Creado por Gustavo David Ferreyra, Septiembre, 2017. Versión de dominio público.
*/

#ifndef Speedcontrolmotor_h
#define Speedcontrolmotor_h
#include "Arduino.h"

class Speedcontrolmotor
{
   public:
   Speedcontrolmotor(int pinMotor,int pinSensor, int init_voltage);
   void check_sensors();
   void count_revolutions();
   void setSensorMAX(int valor);
   void setTiempoIntervalo(int valor);
   void setRevObj(int valor);
   void setVelocidadCambio(int valor);
   void setVoltageMotor(int valor);
   int  getRevoluciones();
   int  get_rps();
   void Iniciar();
   void adaptVoltage();


   private:

   int _pinMotor;
   int _pinSensor;
   int _tension_motor;
   int _velocidad_cambio;
   int _sensorValue;
   int _sensorMaximo;
   int _revoluciones;
   int _rev_anterior;
   int _rps;
   int _obj_rev;
   bool _estado_del_sensor;
   unsigned long _tiempo_proximo;
   int _tiempo_intervalo;
};

#endif
