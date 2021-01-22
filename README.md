# Aparca bicicletas eléctrico.
> ![bicicletas eléctricas. ](https://i.ibb.co/vd05wTK/latigo.png)> 
## ¿De que trata nuestro proyecto?
Nuestro proyecto se basa en que hemos creado un aparcamiento de bicicletas eléctricas, que están cubiertas por una estructura metálica y lo que hemos echo a sido adaptarle a esta estructura unos enchufes para que se puedan cargar las bicicletas, también hemos utilizado Arduino que es el cerebro de este proyecto ya que gracias a Arduino hemos podido añadirle a la estructura de metal un sensor RFID que es un lector de tarjetas. Lo que hace este lector de tarjetas es registrar al usuario cuando alguien pasa la tarjeta y no es correcta no se activaran los pistones de la puerta y si es correcta le da acceso para poder abrir la puerta de la estructura metálica y que pueda coger la bicicleta, en el momento en que la tarjeta le da acceso, la tarjeta manda la información del usuario a un Excel donde se podrá verificar quien ha accedido a la bici, a que hora, quien es con el numero de la tarjeta etc.

Una vez que la tarjeta le da acceso se encenderá unas luces leds de color blanco controlado por Arduino y estas luces estarán dentro de la estructura metálica para que el usuario que haya accedido a coger la bicicleta pueda tener visualización dentro y poder coger la bicicleta fácilmente.

# Arduino Mega
![mega](https://i.ibb.co/P6rdfmR/arduino-mega-2560.jpg)

Para poder programar en Arduino tienes que descargarte su propio programa para poder programarlo yhacer lo que tu quieras    https://www.arduino.cc/en/software .


 Para la parte de electrónica hemos utilizado Arduino Mega ya que en nuestro proyecto necesitábamos muchos dines digitales y el Arduino Mega era el que mejor se adaptaba para poder conectar todo nuestros componentes electrónicos ya que es el cerebro de este proyecto, en el Arduino hemos conectado el sensor RFID (lector de tarjetas), las luces leds, un buzzer (un pequeño altavoz), una pantalla lcd.
# Pantalla LCD
![pantalla lcd](https://i.ibb.co/7V59yFr/mm.png)


Hemos utilizado una pantalla de 2,8 pulgadas que esta programada mediante Arduino para que en ella muestre un mensaje al pasar la tarjeta si es errónea saldrá un mensaje "Tarjeta incorrecta" y si la tarjeta es correcta se visualizara en la pantalla "cierre la puerta después de entrar ".
# Cerraduras

![cerraduras](https://i.ibb.co/Cz8R4JH/mm.png)

En el proyecto tenemos dos cerraduras que tienen un pistón cada uno que se alimentan a 12v y lo que hemos echo a sido conectarlos a Arduino mediante un Mosfet BJT para poder programarlo y que se excite cuando el sensor de tarjetas haya dado acceso a la persona para poder entrar al aparca bicicletas.
