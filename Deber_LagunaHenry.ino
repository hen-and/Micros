int date;
float dato; 

void setup() {
  Serial.begin(9600);
  pinMode (8, OUTPUT);
}

void loop() {
dato = (analogRead(0) * 2000.0) / 1023.0;
 if (dato > 1024.0) {
        digitalWrite(8, HIGH);
      }
      else{
        digitalWrite(8, LOW);
        }
 Serial.print(String(analogRead(0))+ ": ");
 Serial.println(dato, 3);
 delay(200);
}
