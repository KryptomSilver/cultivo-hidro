/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
////lIBRERÍAS/////
#include <LiquidCrystal.h>

// VARIABLES DE LA LCD 16x4
int rs = 13,
          en = 12,
          d4 = 11,
          d5 = 10,
          d6 = 9,
          d7 = 8,
          ldr = 0,
          valor  = 0;  // valor analogico sensor de temperatura;
int analogPin = A3;
// VARIABLES
float Echo = 6,         // pin de entrada.
      Trig = 7,         // pin de salida.
      temp = 0;  // temperatura LM35.
      

long duracion, distancia;  

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup ( ) {
  
  Serial.begin(9600);
  
  pinMode(Echo, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Trig, OUTPUT);    // define el pin 7 como salida  (triger)
  // declaramos el tipo de pantalla LCD 16X4
  lcd.begin(16, 4);
  
}


void loop() {

  // Obtener temperatura
  temperatura ( );
  lcd.setCursor(0, 0);
    lcd.print ( "TEMP: " );
    lcd.print ( temp );
    lcd.print ( "C" );

  ultrasonico ( );
  lcd.setCursor(0, 1);
    lcd.print ( "DIST: " );
    lcd.print ( distancia );
    lcd.print ( "cm" );

  fotoresistencia ( );
  lcd.setCursor(0, 2);
    lcd.print ( "LUM: " );
    lcd.print ( ldr );
    lcd.print ( ":)" );
    
}

void temperatura () {

  valor = analogRead(analogPin);
  temp = (5.0 * valor * 100.0)/1024.0;
  
}

void fotoresistencia ( )  {

  ldr = analogRead(A2);
}

void ultrasonico ( ){
  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  duracion = pulseIn(Echo, HIGH);
  distancia = duracion*0.034/2;            // calcula la distancia en centimetros

  if (distancia >= 500 || distancia <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
    Serial.println("No presencia");                  // no mide nada
  }
  else {
    Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"  
    digitalWrite(13,LOW);           
  }
  
  if (distancia <= 10 && distancia >= 1){
    digitalWrite(13,HIGH);
}
}
