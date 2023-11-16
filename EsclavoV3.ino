#define stepPinz 2
#define dirPinz 5

#define stepPiny 3
#define dirPiny 6

#define stepPinr 4
#define dirPinr 7

#define enable 8

#include <Servo.h>

Servo myservo;  

void setup() {

  pinMode(stepPinz,OUTPUT); 
  pinMode(dirPinz,OUTPUT);
  pinMode(stepPiny,OUTPUT); 
  pinMode(dirPiny,OUTPUT);
  pinMode(stepPinr,OUTPUT); 
  pinMode(dirPinr,OUTPUT);
  pinMode(enable,OUTPUT);

  myservo.attach(11); 

  Serial.begin(9600); // Inicializa la comunicación serial
}

void loop() {

  if (Serial.available() > 0) { // Si hay datos disponibles en el puerto serial
    int nivelSeleccionado = Serial.read(); // Lee el byte enviado y lo convierte en un número entero

    // Haz algo con el nivel seleccionado, por ejemplo:
    switch (nivelSeleccionado) {
      case 1: {
        calibrarEscaner();
        EscaneoNivel1();
        break;
      }
      case 2: {
        calibrarEscaner();
        EscaneoNivel2();
        break;
      }
      case 3: {
        calibrarEscaner();
        EscaneoNivel3();
        break;
      }
    }
  }
}

void calibrarEscaner(){
  // Inicio de la calibracion 
  digitalWrite(dirPiny,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 1000; x++) {
    digitalWrite(stepPiny,HIGH); 
    delayMicroseconds(500);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPiny,LOW); 
    delayMicroseconds(500); 
  }
  delay(500);

  digitalWrite(dirPinz,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 600; x++) {
    digitalWrite(stepPinz,HIGH); 
    delayMicroseconds(500);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPinz,LOW); 
    delayMicroseconds(500); 
  }
  delay(500); // One second delay

  digitalWrite(dirPinr,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPinr,HIGH); 
    delayMicroseconds(500);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPinr,LOW); 
    delayMicroseconds(500); 
  }
  delay(500); // One second delay
  
  digitalWrite(dirPinr,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPinr,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPinr,LOW);
    delayMicroseconds(500);
  }
  delay(500);
  
  for (int angle = 0; angle <= 40; angle += 1) {
    myservo.write(angle);  // Move the servo to the current angle
    delay(30);             // Wait for a short time to allow the servo to reach the position
  }

  delay(1000);  // Wait for 1 second at 180 degrees

  for (int angle = 40; angle >= 0; angle -= 1) {
    myservo.write(angle);  // Move the servo to the current angle
    delay(30);             // Wait for a short time to allow the servo to reach the position
  }
  // fin de la calibracion 
}

void EscaneoNivel1(){

}

void EscaneoNivel2(){

}

void EscaneoNivel3(){

  digitalWrite(dirPiny,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 1000; x++) {
    digitalWrite(stepPiny,HIGH); 
    delayMicroseconds(500);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPiny,LOW); 
    delayMicroseconds(500); 
  }
  delay(500);

  for(int x = 0; x<5; x++){

    digitalWrite(dirPinz,LOW); 
    for(int x = 0; x < 1500; x++) {
      digitalWrite(stepPinz,HIGH); 
      delayMicroseconds(500);  
      digitalWrite(stepPinz,LOW); 
      delayMicroseconds(500); 
    }
    delay(500);

    digitalWrite(dirPinz,HIGH); 
    for(int x = 0; x < 1500; x++) {
      digitalWrite(stepPinz,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPinz,LOW);
      delayMicroseconds(500);
    }
    delay(500);

    digitalWrite(dirPinr,HIGH); 
    for(int x = 0; x < 100; x++) {
      digitalWrite(stepPinr,HIGH); 
      delayMicroseconds(500);    
      digitalWrite(stepPinr,LOW); 
      delayMicroseconds(500); 
    }
    delay(500); 
  }

}