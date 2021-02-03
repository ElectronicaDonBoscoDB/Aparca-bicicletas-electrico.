#include <SPI.h>                            //ESTA SON LAS LIBRERIAS QUE TIENEN QUE TENER EL SENSOR RFID PARA PODER CONFIGURARLO CON ARDUINO MEGA.
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define RST_PIN         5          // ESTE PIN NO ES CONFIGURABLE TIENE QUE SER SI O SI EN EL ARDUINO MEGA.
#define SS_PIN          53         // ESTE PIN NO ES CONFIGURABLE TIENE QUE SER SI O SI EN EL ARDUINO MEGA.

MFRC522 mfrc522(SS_PIN, RST_PIN);  
LiquidCrystal_I2C lcd(0x27,16,2);    // AQUI SE DECLARA LA PANTALLA LCD PARA QUE SE VISUALICE.
String uid1 = "69 CD 70 59";        //  ESTA ES LA ID DE LA PRIMERA TARJETA
String uid2 = "32 D7 46 1E";       //   ESTA ES LA ID DE LA SEGUNDA TARJETA
String uid3 = "99 92 84 83";      //    ESTA ES LA ID DE LA TERCERA TARJETA
String uid4 = "29 42 95 83";     //     ESTA ES LA ID DE LA CUARTA TARJETA
void setup() 
{
  lcd.init();                      
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);   // PARA INICIAR LA COMUNICACIÓN SERIAL
  SPI.begin();         //  SPI bus
  mfrc522.PCD_Init(); 
  Serial.println(" Aproxima su tarjeta al lector ...");
  Serial.println();

}
void loop() 
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    LEYENDO TARJETA    ");
 // Reinicia el bucle si no hay una nueva tarjeta en el sensor / lector. Esto ahorra todo el proceso cuando está inactivo.
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Selecciona una de las tarjetas
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //muestra la ID de la tarjeta.
  Serial.print("Etiqueta ID :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  lcd.clear();
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == uid1) // Aquí se puede cambiar el ID de las tarjetas
  {
    Serial.println("Authorized access");
    Serial.println();
    lcd.setCursor(0,0);
    lcd.print("Tag 01");
    lcd.setCursor(0,1);
    lcd.print("Authorized access");
    delay(3000);
  }



 else if (content.substring(1) == uid2) //Aquí se puede cambiar el ID de las tarjetas
  {
    Serial.println("Authorized access");
    Serial.println();
    lcd.setCursor(0,0);
    lcd.print("Tag 02");
    lcd.setCursor(0,1);
    lcd.print("Authorized access");
    delay(3000);
  }

 else if (content.substring(1) == uid3) //Aquí se puede cambiar el ID de las tarjetas
  {
    Serial.println("Authorized access");
    Serial.println();
    lcd.setCursor(0,0);
    lcd.print("Tag 03");
    lcd.setCursor(0,1);
    lcd.print("Authorized access");
    delay(3000);
  }

 else   {
    Serial.println(" Access Denied"); // Cuando se pase una tarjeta que no esta autorizado saldra en la pantalla acceso denegado.
    lcd.setCursor(3,0);
    lcd.clear();
    lcd.print("Unknown");
    lcd.setCursor(0,1);
    lcd.print("Access Denied");
    delay(3000);
    lcd.clear();
  }
} 
