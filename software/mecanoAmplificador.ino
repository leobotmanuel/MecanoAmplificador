//Proyecto Amplificacion Mecanoceptiva
//Dispositivo Mecano-Amplificador
//Autores:
//        Maite Aliaga
//        Manuel Hidalgo
//Fecha: Junio 2017
//Fecha: Abril 2018. Modificacion del ciclo de trabajo 25%
//Código con licencia Creative Commons (by-nc-sa)

//declaracion de variables y pines
int sensorPinA2 = A2;   // Sensor conectado a Analog 2
int motorPinD3 = 3;     // LED conectado a Pin 3 (PWM)
int resRead;            // La Lectura de la Resistencia por División de Tensión
int umbral;             // Umbral de activacion
int potPinA0 = A0;      // Marca el umbral conectado a Analog 0

//programa
void setup()
{
  Serial.begin(9600); // Enviaremos la información de depuración a través del Monitor de Serial
  pinMode(motorPinD3, OUTPUT);
}
//programa principal
void loop()
{
  resRead = analogRead(sensorPinA2); // lectura del sensor (A2)
  //escribe el valor de la lectura del sensor de fuerza
  Serial.print("Lectura sensor de fuerza = ");
  Serial.print(resRead);

  umbral = analogRead(potPinA0); // umbral (A0) es igual a la lectura del sensor (A2)
  //escribe el valor de la lectura del umbral
  Serial.print("\tLectura del umbral = ");
  Serial.println(umbral);

  //activa el motor-vibrador si cumple la condicion
  //el ciclo de trabajo del motor-vibrador 25%
  if (resRead > umbral) {
    digitalWrite(motorPinD3, 1);
    delay(750);
  }

  //desactiva el motor-vibrador
  digitalWrite(motorPinD3, 0);
  delay(250);
  
}
