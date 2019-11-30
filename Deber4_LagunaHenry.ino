int Datos[] = {2, 3, 4, 5, 6};
float a;
int num;
void setup() {

  for (int i = 0; i < 5; i++) {
    pinMode(Datos[i], OUTPUT);
    
  }
  Serial.begin(9600);
}
void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(Datos[i], LOW);
  }
  Serial.println("Ingrese un numero");
  while (Serial.available() == 0) {}
  a = Serial.parseFloat();
  Serial.println(a);

  if (int(a) == a) {
    if (a >= 0 && a <= 16) {
      num = int(a);
      for (int i = 0; i < 5; i++) {
        if (num % 2 == 1) {
          digitalWrite(Datos[i], HIGH);
        }
        else {
          digitalWrite(Datos[i], LOW);
        }
        num = num / 2;
      }
    }
    else {
      Serial.println("Ingrese un número menor a 16");
    }
  }
  delay(3000);
}
