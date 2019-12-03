char entrada;
int i = 2;
int posInicial=2;  
int posFinal=7;     
int tiempo=70;    
int repeticiones=5; 
int secuencia=1;
int led;
int j;


void setup() {
  Serial.begin(9600);
  pinMode( 6, OUTPUT) ;
  pinMode( 5, OUTPUT) ;
  pinMode( 4, OUTPUT) ;
  pinMode( 3, OUTPUT) ;
  pinMode( 2, OUTPUT) ;

}

void loop() {
 if(Serial.available()>0){
    entrada=Serial.read();

    if(entrada = "ACBF"){
              for ( int i = 2 ; i < 7 ; i++)
                    {
                       digitalWrite( i , HIGH) ;
                       delay (100) ;
                       digitalWrite( i , LOW);
                       delay (100) ;

                    }
  
        }
    if(entrada = "ACGF"){
      for ( i ; i < 7 ; i++){
               if( i%2 == 0){
                digitalWrite( i , HIGH);
                delay (100);
                digitalWrite( i , LOW);
                delay (100);

      
                }

               if( i%2 == 1){
                digitalWrite( i , HIGH);
                delay (100);
                digitalWrite( i , LOW);
                delay (100);
                }
      }
    }

      if(entrada = "ADBF"){
     for(j=0;j<repeticiones;j++)
  {
    //Secuencia de izquierda a derecha
    for(led=posInicial;led<=posFinal;led++)
    {
      switch(secuencia)
      {
        case 1:
          digitalWrite(led,HIGH);
          delay(tiempo);
          digitalWrite(led,LOW);
        break;
        case 2:
          digitalWrite(led,HIGH);
          delay(tiempo);
        break;
        case 3:
          digitalWrite(led,HIGH);
          delay(tiempo);
        break;
        case 4:
          digitalWrite(led,LOW);
          delay(tiempo);
          delay(tiempo);
          digitalWrite(led,HIGH);
        break;
        case 5:
          digitalWrite(led,LOW);
          delay(tiempo);
        break;
        case 6:
          digitalWrite(led,HIGH);
        break;
      }
    }
    if(secuencia==3)
    { i=repeticiones; }
    if(secuencia==6)
    { delay(tiempo); 
      delay(tiempo);
    } 
    //secuencia de derecha a izquierda
    for(led=posFinal;led>=posInicial;led--)
    {
      switch(secuencia)
      {
        case 1:
          if(led>posInicial && led<posFinal)
          {
            digitalWrite(led,HIGH);
            delay(tiempo);
            digitalWrite(led,LOW);
          }
        break;
        case 2:
          digitalWrite(led,LOW);
          delay(tiempo);
        break;
        case 3:
          digitalWrite(led,HIGH);
        break;
        case 4:
          if(led>posInicial && led<posFinal)
          {
            digitalWrite(led,LOW);
            delay(tiempo);
            digitalWrite(led,HIGH);
          }
        break;
        case 5:
          digitalWrite(led,HIGH);
          delay(tiempo);
        break;
        case 6:
          digitalWrite(led,LOW);
        break;
      }
    }
    if(secuencia==6)
    { delay(tiempo);
      delay(tiempo);
    } 
  }
  secuencia++;
  if(secuencia==7)
  { secuencia=1; }
      }

      if(entrada = "ADBH"){
      for(i = 2; i < 7; i ++){
    //En el mismo for, colocamos como estado alto al pin
    digitalWrite(i, HIGH);     
    delay(500);
  }

  for(i =2; i < 7; i ++){
    //En el mismo for, colocamos como estado bajo al pin
    digitalWrite(i, LOW);     
    delay(200);
  }
      }
      
    }
              
      
    }





  
  
 
