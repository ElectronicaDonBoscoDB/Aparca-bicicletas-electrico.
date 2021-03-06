# BIKE-PARK.
> ![bicicletas eléctricas. ](https://i.ibb.co/vd05wTK/latigo.png)> 
## ¿De que trata el proyecto?
Es un proyecto innovador en el que se convinan un  aparcamiento de bicicletas común y la electrónica, creando un aparcamiento de bicicletas electrónico. 


El aparcamiento está cubierto por una estructura metálica semicircular y esta adaptada para  bicicletas electricas con  enchufes para que se puedan cargar en caso de que les falte bateria, con luces leds para que tengan una buena visualización y con dos electroimanes(cerraduras) que se encuentran en las puertas.



El aparcamiento tiene un cuadro eléctrico, en su interior se encuentra una fuente de alimentación de 12V, magnetotermicos, diferencial y Pias para proteger los circuitos eléctricos. Aparte de eso también esta  Arduino Mega, es el contolador principal ya que gracias a Arduino se a podido programar la pantalla LCD,un sensor RFID y un Buzzer, Además hay una placa de circuito integrado que comunica todo los componentes electrónicos en un mismo circuito.



Se a utilizado en un sofware llamado **[Trello](https://trello.com/b/LMd40IME/aparcabicis)** un calendario online, donde se a marcado un objetivo cada semana para verificar que se estaba trabajando bien y saber si se iba correctamente en el proyecto Bike-Park.


# Funcionamiento 

En el interior del Bike-Park se encuentran las luces leds que estan situada en los laterales del interior de la estructura y los electroimanes en los laterales de la puerta. En el exterior del Bike-Park en el lateral izquierdo de la estructura se encuentra un cuadro eléctrico el cual contiene una pantalla LCD, un sensor RFID y un Buzzer.
Cuando el usuario pasa la tarjeta por el sensor RFID y se encuentra registrado en el programa de Arduino, lo primero que hace es subir la imformación del usuario a un Excel para saber a final de mes quien utiliza y quien no el Bike-Park. Se enciende el Buzzer emitiendo un solo pitido continuo durante 3 segundos que a la vez activa las luces leds, primero en color verde intermitente visualizando que la tarjeta es correcta y después cambaia a color blanco fijo donde se mantiene encendido durante 1 minuto y la pantalla LCD visualiza diferentes textos indicando: "puerta abierta", "Cierre la puerta", "Gracias", estos mensaje también apareceran en Euskera.

La otra opción es cuando el usuario acerque su tarjeta en el sensor RFID  y detecte la tarjeta como no registrada en el sistema, se subira a un Excel imformación de que algun usuario no registrado en el sistema ha intentado acceder al Bike-Park. Lo que hace la tarjeta que no esta registrada es no activa los electroimanes de la puerta, el Buzzer se activa sonando 5 veces, las luces leds se encienden en color rojo y la pantalla LCD visualiza un mensaje de "Tarjeta incorrecta" o "Txartel okerra".



# Arduino Mega
![mega](https://i.ibb.co/hdxcs20/proyecto-final-todo-conectado.png) 

Para programar en Arduino tienes que descargarte su propio sofware https://www.arduino.cc/en/software  que es un lenguaje c++.


 Para la parte de electrónica se a utilizado Arduino Mega. Para este proyecto se ha utilizado muchos pines digitales y el Arduino Mega era el que mejor se ha adaptado para poder conectar todos los componentes electrónicos, siendo  el cerebro de este proyecto, en el Arduino se a conectado el sensor RFID (lector de tarjetas),Arduino Ethernet Shield, las luces leds, un buzzer (pequeño altavoz), una pantalla lcd y las Cerraduras. Aparte de conectar todos los componentes electronicos se han programado para que realizen su funcion correctamente, además se an añadido a esta programación librerias, codigos, se ha creado un servidor para la conexión a internet etc.
 
 
 # Arduino Ethernet Shield.

![Shield](https://i.ibb.co/Hqt1dKT/interrr.png)


El Arduino ethernet shield es el que da la capacidad de conectar un Arduino a una red de internet mediante un cable ETHERNET, es decir el Arduino ethernet shield es una placa de tamaño reducido que trae una toma de RJ45 en su propio circuito integrado y para conseguir que Arduino Mega tenga conexión a internet se conectan estos dos modulos, el Arduino ethernet shield encima de el Arduino Mega, conectandolos con pines específicos.


 Arduino ethernet shield se a utilizado para poder subir información a un EXCEL donde estan registrados todos los usuarios y controlar el uso que le dan al Bike-Park a lo largo del mes.
La tabla EXCEL se creó para poder ver el registro de cada usuario y poder darle de baja en el sistema en caso de que no le de uso y poder registrar a nuevos usuarios que quieran utilizar el Bike-Park.

[Arduino Ethernet Shield.](https://www.amazon.es/Girasol-Ethernet-Arduino-R3-Mega-2560-1280-A057/dp/B00HG82V1A/ref=asc_df_B00HG82V1A/?tag=googshopes-21&linkCode=df0&hvadid=82853727250&hvpos=&hvnetw=g&hvrand=6687566675366269954&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1005530&hvtargid=pla-124952602620&psc=1)


[SCRIPT](https://script.google.com/u/1/home/projects/1AHv-A95fr-WKhxJjRaKxP7JcMDadVkK7agKZwLtyXLvbldq81C3BFrr_/edit) Es un Sofware que se ha utilizado para transmitir los datos de los usuarios que se ha registrado con cada tarjeta en arduino y que aparezcan en el Excel.


# Sensor RFID


![RFDI](https://i.ibb.co/MkJnCsQ/RFIDFINAL.png)

Este sensor se encarga de dar acceso o denegar el permiso para poder acceder al Bike-Park, esta programado para que a la persona que le de acceso active los pistones y pueda entrar.También lo que hace el sensor RFID es mosntrar la id de cada tarjeta tarjeta en el arduino.

[Sensor RFID.](https://www.amazon.es/azdelivery-RC522-RFID-Arduino-Raspberry-Inclus/dp/B074S8MRQ7/ref=sr_1_12?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=rfid&qid=1611648731&sr=8-12)


# EXCEL

![EXEL IMFO](https://i.ibb.co/th63Xj1/graficas.png)

Se a creado una tabla EXCEL donde aparece todos los usuarios que an pasado la tarjeta por el sensor RFID registrando su información. Esto se a echo para que se lleve un control de quien utiliza y quien no las bicicletas al final de cada mes, en caso de no utilizar dar de baja en el Bike-Park y poder registrar a nuevos usuarios en la empresa que quiera utilizar las bicicletas.
A parte de registrar la información de los usuarios en la tabla Excel, también se a creado una gráfica en **DATASTUDIO** donde se visualiza la cantidad de veces que se ha utilizado el aparcamiento.
 
 
# Pantalla LCD
![pantalla lcd](https://i.ibb.co/HTXXHHh/lcdxdfinal.png)


Se a utilizado una pantalla de 2,8 pulgadas que esta programada mediante Arduino para que en ella muestre un mensaje al pasar la tarjeta, si es errónea saldrá un mensaje "Tarjeta incorrecta" y si la tarjeta es correcta se visualizara en la pantalla "cierre la puerta después de entrar ", tambien aparacera este mismo mensaje en Euskera.

[Pantalla LCD.](https://www.amazon.es/gp/product/B07MXH92RL/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1)


# Cerraduras

![cerraduras](https://i.ibb.co/nPw8gQy/electroimanes-12v-final.png)

En el Bike-Park se encuentran dos cerraduras que tienen un pistón, cada uno se alimenta a 12V, para conseguir este voltaje se ha integrado en el cuadro eléctrico una fuente de alimentación de 12V y lo que se a conseguido a sido conectarlos a Arduino mediante unos transistores BC337 para poder controlarlos, ya que Arduino tiene un voltaje de salida máximo de 5V y los electroimanes se alimentan a 12V. Para que se exciten los pistones, el sensor de tarjetas tiene que detectar que el usuario esta registrado en el sistema para poder entrar al Bike-Park.

[Cerrojos electromagnéticos.](https://www.nafsa.es/productos/cerrojos-seguridad-electromagneticos/cu20cpb/)


# Luces Led.

![leds](https://i.ibb.co/3sMNfCh/Luces-led-12v-final.png) 

Se han utilizado luces led para la iluminación del interior del Bike park.
Estas luces led se han programado mediante **Arduino** **Mega** y con transitores **IRF530**, se han utilizado estos transistores por que las luces leds se alimentan a 12V y para conseguir este voltaje se ha conectado a una fuente de alimentación de 12V a la misma que estan conectadas los **electroimanes**. Esto se ha echo debido que arduino da una salida de voltaje como maximo de 5V , por eso se utilizo estos transistores para poder controlar ambas tensiones y poder programar las luces leds con el color que se necesitaba segun la situación, es decir si el usuario no esta registrado se encendaran las luces en color rojo en modo intermitente y si esta registrado se encenderan en color verde en modo intermitente y después cambiara a color blanco fijo durante un tiempo para que el usuario pueda ver dentro del Bike-Park.

[Luces Led.](https://www.efectoled.com/es/comprar-tiras-led-monocolor/60-tira-led-12v-dc-smd5050-60ledm-5m-rgb-ip65.html?)


# Buzzer (Altavoz).


![buzzer montador](https://i.ibb.co/hdFr4gq/buzzer-final.png)

El altavoz es utilizado para indicar el estado de los electroimanes, cuando el altavoz haga un pitido constante indicara que la puerta esta abierta y que ha pasado su tarjeta correctamente, en cambio si la tarjeta no es utilizada de manera correcta o se intente entrar con otra tarjeta la cual no este registrada dicho altavoz empezara a hacer un sonido intermitente.

[Altavoz.](https://www.digikey.es/product-detail/es/murata-electronics/PKM22EPPH2001-B0/490-4691-ND/1219322?utm_adgroup=Alarms%2C%20Buzzers%2C%20and%20Sirens&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Product_Audio%20Products&utm_term=&productid=1219322&gclid=CjwKCAiAoOz-BRBdEiwAyuvA6zgxQUegh7BL6GhSCe8hY-i_EjmltysM9wPGEdsBY-yMeewsGVh59xoCWakQAvD_BwE)

