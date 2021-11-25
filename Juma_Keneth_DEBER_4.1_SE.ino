/*CAPITULO IV: PERIFERICOS ESPECIALES 
 * DEBER 4.1
 * NOMBRE: Juma Keneth
 * OBJETIVO: Realizar un sistema en el cual se conecten 2 motores (parecido al diagrama que se utilizo en clase). 
 * Los datos de CAD, V y PWM se deben visulizar en una LCD para cada motor. 
 * 
 */
#include <LiquidCrystal.h>

LiquidCrystal lcd1(13,12,5,4,3,2);      //Pines para la LCD1.
LiquidCrystal lcd2(A4,A5,9,8,7,6);      //Pines para la LCD2.
int conversor1;                         //Variable para adquirir datos del conversor1 entre 0-1023.
int conversor2;                         //Variable para adquirir datos del conversor2 entre 0-1023.
float voltaje1;                         //Variable de conversion de conversor a voltaje.
float voltaje2;                         //Variable de conversion de conversor a voltaje.
const int swt=A2;                       //Pin del boton
const int btn=A3;                       //Pin del switch
int  dutty1;
int  dutty2;
 
void setup() {
  pinMode(swt,INPUT);                    //Define al swwitch como entrada
  pinMode(btn,INPUT);                    //Define al btn como entrada
  lcd1.begin(16,2);                      //Inicializa la LCD 16x2.
  lcd2.begin(16,2);                      //Inicializa la LCD 16x2.

}

void loop() {
  
  if(digitalRead(swt)==HIGH)
  {
      conversor1=analogRead(A0);              // Lectura del pin A0
      voltaje1=(conversor1*5.0)/1023.0;       // Conversor de voltaje.
      dutty1=(conversor1)/4;                  // Cambio la escala para dutty cicle.
      analogWrite(11,dutty1);                 // Envio del valor al pin 11.
      lcd1.setCursor(4,0);                    // Posicion en la LCD
      lcd1.print("CAD: " );                   // Mensaje de salida
      lcd1.setCursor(8,0);                    // Posicion en la LCD
      lcd1.print(conversor1);                 // Muestra el resultado del conversor
      lcd1.setCursor(0,1);                    // Posicion en la LCD
      lcd1.print("V: ");                      // Mensaje de salida
      lcd1.setCursor(3,1);                    // Posicion en la LCD
      lcd1.print(voltaje1);                   // Muestra el resultado del voltaje
      lcd1.setCursor(9,1);                    // Posicion en la LCD
      lcd1.print("PWM: ");                    // Mensaje de salida
      lcd1.setCursor(13,1);                   // Posicion en la LCD
      lcd1.print((dutty1*100)/255);           // Regla de tres para mostrar el valor de PWM en la LCD
      delay(300);                             
  }
  else {
    lcd1.clear();                           // limpia pantalla
  }
  
  if(digitalRead(btn)==HIGH)
  {
      conversor2=analogRead(A1);              //Lectura del canal A0-0-14
      voltaje2=(conversor2*5.0)/1023.0;       //Conversor de voltaje.
      dutty2=(conversor2)/4;                  //Cambio la escala para el dutty cicle.
      analogWrite(10,dutty2);                 //Envio de valor al pin 11.
      lcd2.setCursor(4,0);                    // posicin del cursor en la LCD
      lcd2.print("CAD: " );                   // Mensaje de salida
      lcd2.setCursor(8,0);                    // Posicion en la LCD
      lcd2.print(conversor2);                 // Muestra el resultado del conversor
      lcd2.setCursor(0,1);                    // posicion del cursor en la LCD
      lcd2.print("V: ");                      // mensaje de salida
      lcd2.setCursor(3,1);                    // posicion del cursor en la LCD
      lcd2.print(voltaje2);                   // muestra el resultado del voltaje
      lcd2.setCursor(9,1);                    // posicion del cursor en la LCD
      lcd2.print("PWM: ");                    // mensaje de salida
      lcd2.setCursor(13,1);                   // posicion del cursor en la LCD
      lcd2.print((dutty2*100)/255);           // realiza la regla de tres
      delay(300);                             
  }
  else {
    lcd2.clear();                           // limpia pantalla
  }
}
