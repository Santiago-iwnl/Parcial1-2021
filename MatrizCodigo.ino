//--------------------------DESCRIPCION-------------------------





//----------------Pines------------------------------------
int SERF = 2; //Entrada Fila
int SRCLKF = 4; //Registro de entrada para las filas
int RCLKF = 3; // Registro de salida para las filas

int SERC = 5; //Entrada Columna
int SRCLKC = 7; //Registro de entrada para las columnas 
int RCLKC = 6; //Registro de salida para las columnas

char cadena;


//Arreglo para recorrer las filas
unsigned char Filas[] = {B00000001,B00000010,B00000100,B00001000,B00010000,B00100000,B01000000,B10000000};
unsigned char LA[] = {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
unsigned char LB[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
unsigned char LC[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
unsigned char LD[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
unsigned char LE[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
unsigned char LF[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
unsigned char LG[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
unsigned char LH[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
unsigned char LI[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
unsigned char LJ[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
unsigned char LK[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
unsigned char LL[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
unsigned char LM[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
unsigned char LN[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
unsigned char LO[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
unsigned char LP[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
unsigned char LQ[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
unsigned char LR[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
unsigned char LS[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
unsigned char LT[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char LU[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
unsigned char LV[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
unsigned char LW[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
unsigned char LX[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
unsigned char LY[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char LZ[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};



void setup(){
  // Entradas y registros 
  int puertos[]={ 2, 3 , 4 , 5 , 6, 7}; 

  for(int i = 2; i<8; i++){
    pinMode(puertos[i], OUTPUT);
  }
  
  Serial.begin(9600);
  Serial.print("Ingrese una letra A-Z: ");
  Serial.println();
  verificacion();
}


void verificacion(){
  unsigned char matriz[]={B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
 
  for(int i=0; i<8; i++){
    digitalWrite(RCLKC,LOW);
    shiftOut(SERC, SRCLKC, MSBFIRST, matriz[i]);
    digitalWrite(RCLKC,HIGH);
    
    for(int j=0; j<8; j++){
      digitalWrite(RCLKF,LOW);     
      shiftOut(SERF, SRCLKF, MSBFIRST, Filas[j]);
      digitalWrite(RCLKF,HIGH);
    }  
    
  }

  
  /*
  unsigned char matriz1[]={B00000000,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000};
  
  for(int i=0; i<8; i++){
    digitalWrite(RCLKF,LOW);
    digitalWrite(RCLKC,LOW);  

    shiftOut(SERF, SRCLKF, MSBFIRST, Filas[i]);
    shiftOut(SERC, SRCLKC, MSBFIRST, matriz[i]);

    digitalWrite(RCLKF,HIGH);
    digitalWrite(RCLKC,HIGH);  

  }*/

}

void imagen(char let){
  switch (let){
    case 'A':
    for(int i=0; i<8; i++){
      digitalWrite(RCLKF,LOW);
      digitalWrite(RCLKC,LOW);  

      shiftOut(SERF, SRCLKF, MSBFIRST, Filas[i]);
      shiftOut(SERC, SRCLKC, MSBFIRST, LA[i]);

      digitalWrite(RCLKF,HIGH);
      digitalWrite(RCLKC,HIGH);
  	}

    break;
  
  }

}


void loop(){

  verificacion();
  if(Serial.available()>0){ //Espera a que halla algo
    String datoEntrada="";
    delay(1000); //Espera a que la persona ingresa el dato
    while(Serial.available()>0){
    	cadena= Serial.read();
    }
  }
  //imagen(cadena);
  
}











