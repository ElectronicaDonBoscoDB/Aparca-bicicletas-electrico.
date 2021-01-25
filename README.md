# Aparca bicicletas eléctrico.
> ![bicicletas eléctricas. ](https://i.ibb.co/vd05wTK/latigo.png)> 
## ¿De que trata el proyecto?
El proyecto se basa en que se ha creado un aparcamiento de bicicletas eléctricas, que están cubiertas por una estructura metálica y lo que se ha  echo a sido adaptarle a esta estructura unos enchufes para que se puedan cargar las bicicletas, también se a utilizado Arduino que es el cerebro de este proyecto ya que gracias a Arduino se a podido añadirle a la estructura de metal un sensor RFID que es un lector de tarjetas. Lo que hace este lector de tarjetas es registrar al usuario cuando alguien pasa la tarjeta y no es correcta no se activaran los pistones de la puerta y si es correcta le da acceso para poder abrir la puerta de la estructura metálica y que pueda coger la bicicleta, en el momento en que la tarjeta le da acceso, la tarjeta manda la información del usuario a un Excel donde se podrá verificar quien ha accedido a la bici, a que hora, quien es con el numero de la tarjeta etc.

Una vez que la tarjeta le da acceso se encenderá unas luces leds de color blanco controlado por Arduino y estas luces estarán dentro de la estructura metálica para que el usuario que haya accedido a coger la bicicleta pueda tener visualización dentro y poder coger la bicicleta fácilmente.

# Arduino Mega
![mega](https://i.ibb.co/P6rdfmR/arduino-mega-2560.jpg)

Para poder programar en Arduino tienes que descargarte su propio programa para poder programar y hacer lo que tu quieras    https://www.arduino.cc/en/software .


 Para la parte de electrónica se a utilizado Arduino Mega ya que en el proyecto se necesita muchos pines digitales y el Arduino Mega era el que mejor se adaptaba para poder conectar todo los componentes electrónicos ya que es el cerebro de este proyecto, en el Arduino se a conectado el sensor RFID (lector de tarjetas),Arduino Ethernet Shield, las luces leds, un buzzer (un pequeño altavoz), una pantalla lcd.
 
 
 # Arduino Ethernet Shield.

![Shield](https://i.ibb.co/Hqt1dKT/interrr.png)


El Arduino ethernet shield nos da la capacidad de conectar un Arduino a una red ethernet.
Se ha utilizado para poder subir información de los usuarios a internet y poder controlar quien utiliza el aparca bicicletas y cuanto uso le da a lo largo del mes.

[Arduino Ethernet Shield.](https://www.amazon.es/Girasol-Ethernet-Arduino-R3-Mega-2560-1280-A057/dp/B00HG82V1A/ref=asc_df_B00HG82V1A/?tag=googshopes-21&linkCode=df0&hvadid=82853727250&hvpos=&hvnetw=g&hvrand=6687566675366269954&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1005530&hvtargid=pla-124952602620&psc=1)


# Sensor RFID


![RFDI](https://i.ibb.co/JBGqwcv/kkkkk.jpg)

Este sensor se encarga de dar acceso o denegar el permiso para poder acceder al aparcamiento de bicicletas, esta programado para que a la persona que le de acceso active los pistones y pueda entrar.
También lo que hará esta tarjeta es subir la información del usuario a un Excel para tener control sobre quien utiliza y quien no las bicicletas.

# EXCEL

![EXEL IMFO](https://i.ibb.co/X29HnxB/pl.png)

Se a creado esta función para que se pueda controlar dentro de la empresa quien utiliza y quien no las bicicletas al final de cada mes, con el fin de que al usuario que se le ha dado una tarjeta lo utilice y si no lo utiliza darle de baja y darle la tarjeta a otro usuario en la empresa que quiera utilizar las bicicletas.
 
 
# Pantalla LCD
![pantalla lcd](https://i.ibb.co/7V59yFr/mm.png)


Se a utilizado una pantalla de 2,8 pulgadas que esta programada mediante Arduino para que en ella muestre un mensaje al pasar la tarjeta, si es errónea saldrá un mensaje "Tarjeta incorrecta" y si la tarjeta es correcta se visualizara en la pantalla "cierre la puerta después de entrar ".
# Cerraduras

![cerraduras](https://i.ibb.co/Cz8R4JH/mm.png)

En el proyecto tenemos dos cerraduras que tienen un pistón cada uno que se alimentan a 12v y lo que hemos echo a sido conectarlos a Arduino mediante un Mosfet BJT para poder programarlo y que se excite cuando el sensor de tarjetas haya dado acceso a la persona para poder entrar al aparca bicicletas.


# Luces Led.

![leds](https://i.ibb.co/kXGhHLR/led.png)

Se han utilizado luces led para iluminar dentro del aparcamiento, así el usuario podrá tener visualización.
Estas luces led se han programado por **Arduino** y no solo visualiza un color, también se ha programado para que cuando pases la tarjeta y el usuario este registrado se encenderán de color Verde y si no es reconocida por el lector se pondrán en color Rojo.


# Buzzer (Altavoz).


![altavoz](https://i.ibb.co/2MWtLBL/pepepe.png)

Este pequeño altavoz se ha añadido por si vas despistado y pasas la tarjeta de prisa y te equivocas sonara 5 veces de manera cortada y si pasas correctamente la tarjeta sonara una sola vez de manera continua para que el usuario sepa que tiene acceso.
Este altavoz se activara a la vez que las **luces led**.
