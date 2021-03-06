#define TFT_DC 29  //Define los pines de la pantalla LCD
#define TFT_CS 33
#define TFT_RST 31
#define TFT_MISO 23
#define TFT_MOSI 27
#define TFT_CLK 25
#define No_Of_Card 11 //numero de tarjetas que se puede memorizar
*//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);**/

void setup() {

testText4();

  Serial.begin(9600);
  SPI.begin();
  tft.begin(); //inicia la pantalla
  }

void loop(){
Serial.println("\nValid Person");//Detecta que la persona es valida

testText2();
testText(); testText6(); testText1();testText7(); testText4(); // se visualiza un mensaje de puerta Abierta.
}
else{
 Serial.println("Not a valid Person");
testText3(); testText5();testText4();    //se visualiza un mensaje de Puerta cerrada.
}

unsigned long testText() {

  tft.fillScreen(ILI9341_GREEN);//Define color de la pantallaa
  tft.setRotation(1);//Define la horientacion de la pantalla
  tft.setCursor(70, 25);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(4);//Define el tamaño de la letra
  tft.println("CIERRE");//Define el texto que aparecera en la pantalla
  tft.setRotation(1);//Define la horientacion de la pantalla
  tft.setCursor(120, 95);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(4);//Define el tamaño de la letra
  tft.println("LA");//Define el texto que aparecera en la pantalla
  tft.setRotation(1);//Define la horientacion de la pantalla
  tft.setCursor(70, 165);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(4);//Define el tamaño de la letra
  tft.println("PUERTA");//Define el texto que aparecera en la pantalla
  delay(1000);
}
unsigned long testText1() {

  tft.fillScreen(ILI9341_GREEN);//Define color de la pantallaa
  tft.setRotation(1);//Define la horientacion de la pantalla
  tft.setCursor(30, 80);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(6);//Define el tamaño de la letra
  tft.println("GRACIAS!");//Define el texto que aparecera en la pantalla

  tft.setRotation(2);//Define la horientacion de la pantalla
  tft.setCursor(120, 105);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(15);//Define el tamaño de la letra
  tft.println(":");//Define el texto que aparecera en la pantalla

  tft.setRotation(2);//Define la horientacion de la pantalla
  tft.setCursor(170, 130);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(8);//Define el tamaño de la letra
  tft.println("P");//Define el texto que aparecera en la pantalla
  delay(500);//Espera
 
}

unsigned long testText2() {

  tft.fillScreen(ILI9341_GREEN);
  tft.drawLine(50, 25, 25, 50, ILI9341_RED);
  tft.setRotation(1);
  tft.setCursor(35, 70);
  tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(3.9);
  tft.println("PUERTA ABIERTA");
  tft.setRotation(1);
  tft.setCursor(70, 140);
  tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(3.9);
  tft.println("ATE IREKIA");
  tft.setRotation(1);

}

unsigned long testText3() {

  tft.fillScreen(ILI9341_RED);
  tft.drawLine(50, 25, 25, 50, ILI9341_RED);
  tft.setRotation(1);
  tft.setCursor(54, 60);
  tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(5);
  tft.println("TARJETA");
  tft.setRotation(1);
  tft.setCursor(11, 150);
  tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(5);
  tft.println("INCORRECTA");
  tft.setRotation(1);



}
unsigned long testText4() {
  tft.fillScreen(ILI9341_BLACK);
}
unsigned long testText5() {
  tft.fillScreen(ILI9341_RED);
  tft.drawLine(50, 25, 25, 50, ILI9341_RED);
  tft.setRotation(1);
  tft.setCursor(54, 60);
  tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(5);
  tft.println("TXARTEL");
  tft.setRotation(1);
  tft.setCursor(74, 150);
  tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(5);
  tft.println("OKERRA");
  tft.setRotation(1);

  delay(1000);

}
unsigned long testText6() {

  tft.fillScreen(ILI9341_GREEN);
  
  tft.setRotation(1);
  tft.setCursor(100, 60);
  tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(4);
  tft.println("ITXI");
  tft.setRotation(1);
  tft.setCursor(105, 150);
  tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(4);
  tft.println("ATEA");
  tft.setRotation(1);

   
}
unsigned long testText7() {

  tft.fillScreen(ILI9341_GREEN);//Define color de la pantallaa
  tft.setRotation(1);//Define la horientacion de la pantalla
  tft.setCursor(60, 50);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(4);//Define el tamaño de la letra
  tft.println("ESKERRIK");//Define el texto que aparecera en la pantalla

 
  tft.setRotation(1);//Define la horientacion de la pantalla
  tft.setCursor(80, 90);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(4);//Define el tamaño de la letra
  tft.println(" ASKO!");//Define el texto que aparecera en la pantalla

  tft.setRotation(2);//Define la horientacion de la pantalla
  tft.setCursor(120, 105);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(15);//Define el tamaño de la letra
  tft.println(":");//Define el texto que aparecera en la pantalla

  tft.setRotation(2);//Define la horientacion de la pantalla
  tft.setCursor(170, 130);//Define los parametros en los que va a estar el texto
  tft.setTextColor(ILI9341_BLACK);//Define el color de la letra
  tft.setTextSize(8);//Define el tamaño de la letra
  tft.println("P");//Define el texto que aparecera en la pantalla
  delay(500);//Espera
  delay(5000);//Espera
  digitalWrite(Verde, 0); //Apaga verde
  digitalWrite(Azul, 0); //Apaga azul
  digitalWrite(Rojo, 0); //Apaga rojo
  delay(500);//Espera
}


//Esta programación hace que se encienda la pantalla, y muestre un mensaje de Puerta abierta y puerta cerrada.
