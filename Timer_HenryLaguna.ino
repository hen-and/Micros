#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <TimerOne.h>
#include <EEPROM.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int nturno = 0;
int nturno1 = 0;
int pul8 = 8;
int pul9 = 9;
int pul10 = 10;
int led13 = 13;
int t = 2000;
int v1 ;
int v2 ;
int v3 ;
int at = 0;
int c = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(attiempo);
  attachInterrupt(0, turno, LOW);
  MsTimer2::set(1000, conteo);       //sistema trabajara con 1 segundo

  pinMode(pul8, INPUT);
  pinMode(pul9, INPUT);
  pinMode(pul10, INPUT);
  pinMode(led13, OUTPUT);
  lcd.setCursor(2, 0);
  lcd.print("BIENVENIDO");
  delay(t);
  lcd.clear();

  if (EEPROM.read(0) != 255) {
    nturno = EEPROM.read(0);
  }


}

void loop() {

  cnt();
  tiempoturno ();
}
void turno() {
  nturno1++;
  Serial.println(nturno1);
}
void attiempo() {
  at++;
}

void cnt() {

  v1 = digitalRead(pul8);

  if (v1 == LOW) {
    lcd.setCursor(2, 0);
    lcd.println("CUBICULO: 1  ");
    lcd.setCursor(2, 1);
    lcd.println("TURNO: ");
    lcd.print(nturno);
    nturno++;

  }
  delay(100);
  v2 = digitalRead(pul9);  //lectura digital de pin
  if (v2 == LOW) {

    lcd.setCursor(2, 0);
    lcd.println("CUBICULO: 2 ");
    lcd.setCursor(2, 1);
    lcd.println("TURNO: ");
    lcd.print(nturno);
    nturno++;
  }
  delay(100);
  v3 = digitalRead(pul10);
  if (v3 == LOW) {
    lcd.setCursor(2, 0);
    lcd.println("CUNICULO: 3");
    lcd.setCursor(2, 1);
    lcd.println("TURNO: ");
    lcd.print(nturno);
    nturno++;

  }
  EEPROM.write(0, nturno);

}
void tiempoturno () {
  if (at == 10) {
    digitalWrite(13, HIGH);
    delay(5000);
    digitalWrite(13, LOW);
    nturno++;
    at = 0;
  }
}
void conteo() {
  MsTimer2::start();
  c++;
  Serial.println(c);
  if (c == 40) {
    lcd.setCursor(2, 0);
    lcd.print("es un nuevo dia");
    delay(t);
    lcd.clear();
    c=0;
  }
}
