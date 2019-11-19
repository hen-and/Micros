String inputString = "";         
bool stringComplete = false;     

char cedula[11],op;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 inputString.reserve(200);
}

void loop() {
  // put your main code here, to run repeatedly:
if (stringComplete) {
    Serial.println(inputString);
    Serial.println(inputString.length());
    for(int i=0;i<(inputString.length()-2);i++){

      cedula[i]=inputString.charAt(i);
    }

            extraer(cedula);
    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

}
 void serialEvent() {
  while (Serial.available()) {
    borrar(cedula);
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}




void borrar(char a[]){
  for(int i=0; i<11;i++){
    if (a[i] == '\n')
      a[i] = '\0';
  }
}

void extraer(char b[]){
  int v[10], num, limite;

   limite = strlen(b);

   if (limite != 10)
    Serial.print("Cedula No Valida");

   if (limite == 10){

    for (int i=0;i<10;i++){
      num = b[i]-48;
          v[i] = num; }

//VALIDACION CEDULA PROCESO

  int vec[10], suma, ultimo, ultimon; 
  if (v[0] == 1 || v[0] == 2){
    if (v[2] > 0 && v[2] < 6 ){
  
      for (int i=0; i<9; i+=2){
        vec[i] = v[i] *2;
        if (vec[i] >= 10)
          vec[i] -= 9; 
      }
    
      for (int i=1; i<9; i+=2){
        vec[i] = v[i];
        
      }
      
      suma= 0;
      for(int i=0; i<10; i++){
        suma = suma + vec[i];
      }
      
      if (suma == 10)
        ultimo = 0;
      else if(suma >10 && suma<20)
        ultimo = 20;
      else if (suma >20 && suma<30)
        ultimo = 30;
      else if (suma >30 && suma<40)
        ultimo = 40;
      else Serial.print("Cedula Incorrecta");
      
      
      ultimon = ultimo - suma;
      
      if (ultimon == v[9])
        Serial.print("Cedula VERIFICADA");
      else
        Serial.print("Cedula NO VERIFICADA");  
    
      
    }   
    
    else
      Serial.print("Cedula incorrecta");    
  
   }
}
}
