//Nombre: Henry Lema
//Asignatura: Sistemas Embebidos
#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8); // pines lcd 16x2
int conversor; // declaracion de variables
int velocidad;
int dutty;
const int motor=6;// declaracion pin de salida motor
String dato;// variable de tipo string de lectura
float vol;
void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  Serial.println("Ingrese Valor 0---255  0=Min 255=Max");
}
void loop() {
  conversor=analogRead(0);
  if(Serial.available()>0){
    dato=Serial.readString();
    velocidad=dato.toInt();
    if(velocidad <=255){
      conversor=map(conversor,0,1023,0,velocidad);
      analogWrite (motor,velocidad);
      lcd.setCursor(0,0);
      lcd.print("Velocidad motor:");
      lcd.setCursor(0,1);
      lcd.print(velocidad);
      delay(6000);
      lcd.clear();
    }
    else{
      Serial.println ("Ingrese solo numero del 0 al 255");
      lcd.setCursor(0,0);
      lcd.print("ERROR");
      lcd.setCursor(0,1);
      lcd.print("Solo 0 a 255 ");
      delay(6000);
      lcd.clear(); 
    }
  }
  vol=(conversor*5.0)/1023.0;
  dutty=conversor/4;
  analogWrite(motor,dutty);
  lcd.setCursor(0,0);
  lcd.print("Velocidad Pot:");
  lcd.setCursor(0,1);
  lcd.print(dutty);
  delay(6000);
  lcd.clear();
}
