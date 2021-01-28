/* Arduino Code which sends data to google spreadsheet */
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"//Aqui estan las librerias necesiarias para el programa
#include<SPI.h>
#include<MFRC522.h>
#include <Ethernet.h>
#define SS_PIN 53 //Define los pines de la RFID
#define RST_PIN 5

#define TFT_DC 29  //Define los pines de la pantalla RFID
#define TFT_CS 33
#define TFT_RST 31
#define TFT_MISO 23
#define TFT_MOSI 27
#define TFT_CLK 25
#define No_Of_Card 11 //numero de tarjetas que se puede memorizar
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEDf2};
char server[] = "api.pushingbox.com";   //Servidor creado para la base de datos
IPAddress ip(10, 25, 65, 77); //Ip que le damos al ethernet shield
EthernetClient client;
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
byte id [No_Of_Card][4] = {
  {0x64, 0xC9, 0xDF, 0xE9},
  {0x35, 0x51, 0x7B, 0x50},
  {0x35, 0xD4, 0xAA, 0x4F },
  {0xC5, 0xE2, 0x9E, 0x2C },
  {0x16, 0x8C, 0xBA, 0x2D},
  {0x76, 0xB7, 0x0B, 0x2E},
  {0x54, 0x09, 0x09, 0x6F},
  {0xE4, 0xDB, 0xB5, 0x99},
  {0x73, 0x99, 0x2F, 0x13},
  {0x05, 0x47, 0xE5, 0x45},
  {0xEC, 0x76, 0x64, 0x34},
};//Clave de los llaveros


byte id_temp[3][3];
byte i;
int j = 0;
int Verde = 3; //Nombralos los pines con variables
int Rojo = 4;
int Azul = 6;
int Cerradura = 7 ;
int Buzzer = 35 ;
// the setup function runs once when you press reset or power the board
void setup() {


  Serial.begin(9600);
  SPI.begin();
  tft.begin();
  rfid.PCD_Init();

  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
  }
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");//Compara la mac y la ip para conectarse a internet
    Ethernet.begin(mac, ip);
  }
  delay(1000);
  Serial.println("connecting...");
  pinMode(Rojo, OUTPUT);
  pinMode(Verde, OUTPUT); //Declaramos los pines como salidas
  pinMode(Azul, OUTPUT);
  pinMode(Cerradura, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  testText4();
  // Serial.println("ILI9341 Test!");


}

// the loop function runs over and over again forever
void loop() {

  int m = 0;
  if (!rfid.PICC_IsNewCardPresent())
    return;
  if (!rfid.PICC_ReadCardSerial()) //Lee la tarjeta
    return;
  for (i = 0; i < 4; i++)
  {
    id_temp[0][i] = rfid.uid.uidByte[i]; //Compara si la tarje esta registrada o no
    delay(50);
  }

  for (i = 0; i < No_Of_Card; i++)
  {
    if (id[i][0] == id_temp[0][0])
    {
      if (id[i][1] == id_temp[0][1])
      {
        if (id[i][2] == id_temp[0][2])
        {
          if (id[i][3] == id_temp[0][3])
          {



            Serial.print("your card no :");//Dice el numero de la tarjeta
            for (int s = 0; s < 4; s++)
            {
              Serial.print(rfid.uid.uidByte[s]);
              Serial.print(" ");

            }
            Serial.println("\nValid Person");//Detecta que la persona es valida


            Sending_To_spreadsheet();//Registra a la persona en el excel
            j = 0;

            relepuertaon();//Desbloquea las cerraduras, activa el buzzer, muestra el texto en la pantalla,enciende los leds parpadeando en verde, bloquea la puerta enciende las luces en blanco muestra texto en la pantalla y luego lo borra
            Buzzeron();
            testText2();

            verde2(); verde(); verde(); verde(); relepuertaoff();
            // Buzzeroff();
            blanco();  testText(); testText6(); testText1();testText7(); testText4();
            Serial.println("termianan leds");
            rfid.PICC_HaltA(); rfid.PCD_StopCrypto1(); Serial.println("ha llegado"); return;

          }
        }
      }
    }

    else
    { j++;
      if (j == No_Of_Card)//Detecta que la tarjeta no es valida
      {
        Serial.println("Not a valid Person");
        Sending_To_spreadsheet();//Registra que la tarjeta no es valida en el excel
        j = 0;

        rojo(); rojo(); rojo(); rojo();   testText3(); testText5();testText4();//Al detectar que la tarjeta no es valida enciende los leds de color rojo y  activa el buzzer y muestra un texto enn la pantalla

      }
    }
  }

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}

void Sending_To_spreadsheet()   //Conexion a la hoja de calculos
{
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.print("GET /pushingbox?devid=v2AAFDF247E351ED&allowed_members=");     //Link del servidor
    if (j != No_Of_Card)
    {
      client.print('1');
      //      Serial.print('1');
    }
    else
    {
      client.print('0');
    }

    client.print("&Member_ID=");
    for (int s = 0; s < 4; s++)
    {
      client.print(rfid.uid.uidByte[s]);

    }
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: api.pushingbox.com");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}



void relepuertaon() {
  digitalWrite(Cerradura, 1);//Activa la cerradura

}
void relepuertaoff() {
  digitalWrite(Cerradura, 0);//Desactiva la cerradura
}
void verde() {
  
  digitalWrite(Verde, 255); //Verde
  digitalWrite(Azul, 0); //Azul
  digitalWrite(Rojo, 0); //Rojo
  delay(500);//Espera
  digitalWrite(Verde, 0);//Apaga el verde
  delay(500);//Espera
}
void verde2() {
  Buzzeroff();
  digitalWrite(Verde, 255); //Verde
  digitalWrite(Azul, 0); //Azul
  digitalWrite(Rojo, 0); //Rojo
  delay(500);//Espera
  digitalWrite(Verde, 0);//Verde
  delay(500);//Espera

}

void blanco() {
  
  digitalWrite(Verde, 255); //Verde
  digitalWrite(Azul, 255); //Azul
  digitalWrite(Rojo, 255); //Rojo
  
}
void rojo() {
  digitalWrite(Verde, 0); //Verde
  digitalWrite(Azul, 0); //Azul
  digitalWrite(Rojo, 255); //Rojo
  Buzzeron();
  delay(500);//Espera
  digitalWrite(Rojo, 0); //Apaga rojo
  Buzzeroff();
  delay(500);//Espera
}
void Buzzeron() {
  digitalWrite(Buzzer, 1);//Activa buzzer
}
void Buzzeroff() {
  digitalWrite(Buzzer, 0);//Desactiva buzzer
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
