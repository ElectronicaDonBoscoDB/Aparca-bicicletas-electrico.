# BIKE-PARK.
> ![bicicletas eléctricas. ](https://i.ibb.co/vd05wTK/latigo.png)> 
## ¿De que trata el proyecto?
El proyecto se basa en que se ha creado un aparcamiento de bicicletas electrónico , que están cubiertas por una estructura metálica y lo que se ha  echo a sido adaptarle a esta estructura unos enchufes para que se puedan cargar las bicicletas, también se a utilizado Arduino que es el cerebro de este proyecto ya que gracias a Arduino se a podido añadirle a la estructura de metal un sensor RFID que es un lector de tarjetas, una pantalla LCD para que se pueda ver si tienes o no accseso, un Buzzer que pitara cuando pases la tarjeta . Lo que hace este lector de tarjetas es registrar al usuario cuando alguien pasa la tarjeta y no sea correcta no se activaran los pistones de la puerta y si es correcta le da acceso para poder abrir la puerta de la estructura metálica y que pueda coger la bicicleta, en el momento en que la tarjeta le da acceso, la tarjeta manda la información del usuario a un Excel donde se podrá verificar quien ha accedido a la bicicleta, a que hora, quien es con el numero de la tarjeta etc.

Una vez que la tarjeta le da acceso se encenderá unas luces leds de color blanco controlado por Arduino y estas luces estarán dentro de la estructura metálica para que el usuario que haya accedido a coger la bicicleta pueda tener visualización dentro y poder coger la bicicleta fácilmente.

# Arduino Mega
![mega](https://i.ibb.co/dBnq7BY/mm.png) 

Para poder programar en Arduino tienes que descargarte su propio programa para poder programar y hacer lo que tu quieras    https://www.arduino.cc/en/software .


 Para la parte de electrónica se a utilizado Arduino Mega ya que en el proyecto se necesita muchos pines digitales y el Arduino Mega era el que mejor se adaptaba para poder conectar todo los componentes electrónicos ya que es el cerebro de este proyecto, en el Arduino se a conectado el sensor RFID (lector de tarjetas),Arduino Ethernet Shield, las luces leds, un buzzer (un pequeño altavoz), una pantalla lcd.
 
 
 # Arduino Ethernet Shield.

![Shield](https://i.ibb.co/Hqt1dKT/interrr.png)


El Arduino ethernet shield nos da la capacidad de conectar un Arduino a una red de internet mediante un cable ETHERNET.
Se a utilizado para poder subir información a un EXCEL donde estan registrados todos los usuarios y controlar el uso que le dan al aparca bicicletas a lo largo del mes.
La tabla EXCEL se a creado para poder ver el registro de cada usuario y poder darle de baja y poder registrar a nuevos usuarios que quieran utilizar el aparcabicicletas.

[Arduino Ethernet Shield.](https://www.amazon.es/Girasol-Ethernet-Arduino-R3-Mega-2560-1280-A057/dp/B00HG82V1A/ref=asc_df_B00HG82V1A/?tag=googshopes-21&linkCode=df0&hvadid=82853727250&hvpos=&hvnetw=g&hvrand=6687566675366269954&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1005530&hvtargid=pla-124952602620&psc=1)


# Sensor RFID


![RFDI](https://i.ibb.co/DD0LMzQ/interrr.png)

Este sensor se encarga de dar acceso o denegar el permiso para poder acceder al aparcamiento de bicicletas, esta programado para que a la persona que le de acceso active los pistones y pueda entrar.
También lo que hará esta tarjeta es subir la información del usuario a un Excel para tener control sobre quien utiliza y quien no las bicicletas.

[Sensor RFID.](https://www.amazon.es/azdelivery-RC522-RFID-Arduino-Raspberry-Inclus/dp/B074S8MRQ7/ref=sr_1_12?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=rfid&qid=1611648731&sr=8-12)


# EXCEL

![EXEL IMFO](https://i.ibb.co/X29HnxB/pl.png)

Se a creado esta función para que se pueda controlar dentro de la empresa quien utiliza y quien no las bicicletas al final de cada mes, con el fin de que al usuario que se le ha dado una tarjeta lo utilice y si no lo utiliza darle de baja y darle la tarjeta a otro usuario en la empresa que quiera utilizar las bicicletas.
 
 
# Pantalla LCD
![pantalla lcd](https://i.ibb.co/7V59yFr/mm.png)


Se a utilizado una pantalla de 2,8 pulgadas que esta programada mediante Arduino para que en ella muestre un mensaje al pasar la tarjeta, si es errónea saldrá un mensaje "Tarjeta incorrecta" y si la tarjeta es correcta se visualizara en la pantalla "cierre la puerta después de entrar ".

[Pantalla LCD.](https://www.amazon.es/gp/product/B07MXH92RL/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1)


# Cerraduras

![cerraduras](https://i.ibb.co/Cz8R4JH/mm.png)

En el proyecto tenemos dos cerraduras que tienen un pistón cada uno que se alimentan a 12v y lo que hemos echo a sido conectarlos a Arduino mediante un Mosfet BJT para poder programarlo y que se excite cuando el sensor de tarjetas haya dado acceso a la persona para poder entrar al aparca bicicletas.

[Cerrojos electromagnéticos.](https://www.nafsa.es/productos/cerrojos-seguridad-electromagneticos/cu20cpb/)
# Luces Led.

![leds](https://i.ibb.co/kXGhHLR/led.png)

Se han utilizado luces led para iluminar dentro del aparcamiento, así el usuario podrá tener visualización.
Estas luces led se han programado por **Arduino** y no solo visualiza un color, también se ha programado para que cuando pases la tarjeta y el usuario este registrado se encenderán de color Verde y si no es reconocida por el lector se pondrán en color Rojo.

[Luces Led.](https://www.efectoled.com/es/comprar-tiras-led-monocolor/60-tira-led-12v-dc-smd5050-60ledm-5m-rgb-ip65.html?)


# Buzzer (Altavoz).


![altavoz](https://i.ibb.co/2MWtLBL/pepepe.png)

Este pequeño altavoz se ha añadido por si vas despistado y pasas la tarjeta de prisa y te equivocas sonara 5 veces de manera cortada y si pasas correctamente la tarjeta sonara una sola vez de manera continua para que el usuario sepa que tiene acceso.
Este altavoz se activara a la vez que las **luces led**.

[Altavoz.](https://www.digikey.es/product-detail/es/murata-electronics/PKM22EPPH2001-B0/490-4691-ND/1219322?utm_adgroup=Alarms%2C%20Buzzers%2C%20and%20Sirens&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Product_Audio%20Products&utm_term=&productid=1219322&gclid=CjwKCAiAoOz-BRBdEiwAyuvA6zgxQUegh7BL6GhSCe8hY-i_EjmltysM9wPGEdsBY-yMeewsGVh59xoCWakQAvD_BwE)
