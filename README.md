# Aparca-bicicletas-electrico.
Este proyecto trata de un aparcamiento de bicicletas eléctrico , lo que hemos conseguido es que el aparcamiento se abra mediante tarjetas electrónicas y    registre las personas que utilicen  estas bicicletas de manera segura .
# Aparca bicicletas eléctrico.
> ![bicicletas eléctricas. ](https://i.ibb.co/vd05wTK/latigo.png)> 

## ¿De que trata nuestro proyecto?
Nuestro proyecto se basa en que hemos creado un aparcamiento de bicicletas eléctricas, que están cubiertas por una estructura metálica y lo que hemos echo a sido adaptarle a esta estructura unos enchufes para que se puedan cargar las bicicletas, también hemos utilizado Arduino que es el cerebro de este proyecto ya que gracias a Arduino hemos podido añadirle a la estructura de metal un sensor RFID que es un lector de tarjetas. Lo que hace este lector de tarjetas es registrar al usuario cuando alguien pasa la tarjeta y no es correcta no se activaran los pistones de la puerta y si es correcta le da acceso para poder abrir la puerta de la estructura metálica y que pueda coger la bicicleta, en el momento en que la tarjeta le da acceso, la tarjeta manda la información del usuario a un Excel donde se podrá verificar quien ha accedido a la bici, a que hora, quien es con el numero de la tarjeta etc.

Una vez que la tarjeta le da acceso se encenderá unas luces leds de color blanco controlado por Arduino y estas luces estarán dentro de la estructura metálica para que el usuario que haya accedido a coger la bicicleta pueda tener visualización dentro y poder coger la bicicleta fácilmente.

# Arduino Mega
![mega](https://i.ibb.co/P6rdfmR/arduino-mega-2560.jpg)


 Para la parte de electrónica hemos utilizado Arduino Mega ya que en nuestro proyecto necesitábamos muchos dines digitales y el Arduino Mega era el que mejor se adaptaba para poder conectar todo nuestros componentes electrónicos ya que es el cerebro de este proyecto, en el Arduino hemos conectado el sensor RFID (lector de tarjetas), las luces leds, un buzzer (un pequeño altavoz), una pantalla lcd.
