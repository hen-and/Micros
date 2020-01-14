//Laguna Ponce Henry Anderson
//Sistemas Microprocesados
//Deber: Realice un programa que ingrese una palabra por comunicación serial y genere una rotación de caracteres en la LCD.

#include <LiquidCrystal.h>
const int rs =10 , en =9 , d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String palabraf;
int t=150;
  int on=0;
 int i=0;
void setup() {
  attachInterrupt(0, encendido, FALLING);
  Serial.begin(9600);
  lcd.begin(16,2);
 }
 
void loop() {

  if(on==1){
     
     if(Serial.available()>0){
   palabraf = Serial.readString();
     }
     for(; i<=16;i++)
  {
    lcd.clear(); 
    lcd.setCursor(i, 0);    
    lcd.print(palabraf);
    delay(t);
  }
  
i=0;
}}
 void encendido() {

    on = 1 - on;
    if (on == 1) {//Si presionamos el pulsaro ingresamos el sistema
      lcd.setCursor(0, 0);
      lcd.println("ON/ IN PALABRA   ");//imprimos en el LCD
       lcd.setCursor(3, 1);
      lcd.println("                      ");//imprimos en el LCD
       digitalWrite(5,1);  
       
    }
    else {
      digitalWrite(5,0);
      lcd.setCursor(0, 0);
       lcd.println("SYSTEM OFF        ");
        lcd.setCursor(0, 1);
       lcd.println("                         ");
      
    }
    
  }
