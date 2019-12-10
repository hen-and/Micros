/*
   Laguna Ponce Henry Anderson
   Sistemas Microporcesados
   CIERCOM
   Ejercicios de Práctica - Interrupciones
*/


int cond1 = 0;
int cond2 = 0;
String date, val;
int i = 0;
int c, a;
void setup() {
  attachInterrupt(0, Ba, LOW);
  attachInterrupt(1, Bb, LOW);
  Serial.begin(9600);
  Serial.println("Ingrese serie de números del 0 al 9 aleatoriamente");
  Serial.println("El sistema ordenanrá la serie de menor a mayor");
  Serial.println("Siga las instrucciones:");
  Serial.println("");
  Serial.println("B1: Ingresar serie");
  Serial.println("B2: Ordenar numeros");
  Serial.println("...");
}
void loop() {
  if (cond1 == 1 && cond2 == 0) {
    if (Serial.available() > 0) {
      date = Serial.readString();
      Serial.println("Numero ingresado");
      Serial.println(date);
      Serial.println("Resione B2 para ordenar los numeros...");
    }
  }
  else if (cond2 == 1 && date != "") {      
    int num[date.length()];                
    for (i = 0; i < date.length(); i++) {   
      val = date.substring(i, (i + 1));    
      num[i] = val.toInt();                
    }
    do {                                    
      c = 0;
      for (i = 0; i < date.length(); i++) { 
        if (num[i] > num[i + 1]) {          
          c = 1;
          a = num[i];
          num[i] = num[i + 1];
          num[i + 1] = a;
        }
      }
    }
    while (c);
    for (i = 0; i < date.length(); i++) { 
      Serial.println(num[i]);
    }
    Serial.println(" ");
    date = "";
  }
}
void Ba() {
  if (cond1 == 0) {
    Serial.println("Escribir serie");
    cond1++;
  }
}
void Bb() {
  if (cond1 == 1) {
    Serial.println("Numeros Ordenados");
    cond2++;
  }
}
