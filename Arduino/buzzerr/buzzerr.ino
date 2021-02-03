const int Buzzer = 8;    //el pin de arduino para el altavoz
const int Pulsador1 = 2;  // pin del primer pulsador puerta abierta
boolean Estado_pulsador1;
int Estado_anterior1;

const int Pulsador2 = 3;  // pin del segundo pulsador tarjeta erronea
boolean Estado_pulsador2;
int Estado_anterior2;

void setup() {
  pinMode(Pulsador1, INPUT_PULLUP); // aqui declaro al pulsador 1 como entrada
  pinMode(Pulsador2, INPUT_PULLUP); // aqui declaro al pulsador 1 como entrada
  pinMode(Buzzer, OUTPUT); // aqui declaro que el altavoz es una salida.

}
void loop() {
  if (digitalRead(Pulsador1) == LOW) {    //El pulsador está presionado
    Estado_anterior1 = 1;     //La variable que cambia
  }
  if (digitalRead(Pulsador1) == HIGH && Estado_anterior1 == 1) {   //aqui hemos soltado el pulsador por lo que empezara a hacer lo siguiente ...
    Estado_anterior1 = 0;    //La variable vuelve a su valor original

    for (int i = 0; i < 1; i++) {  // aqui cuando tu presiones el boton y sueltes va a hacer un unico pitido
      digitalWrite(Buzzer, HIGH); // aqui le dices que active el altavoz
      delay (2000); // durante 2 segundos
      digitalWrite(Buzzer, LOW); // aqui que el altavoz se apague


    }
  }

  if (digitalRead(Pulsador2) == LOW) {    //El pulsador está presionado
    Estado_anterior2 = 1;     //La variable que cambia
  }
  if (digitalRead(Pulsador2) == HIGH && Estado_anterior2 == 1) {     // aqui el pulsador esta sin pulsar
    Estado_anterior2 = 0;    //La variable vuelve a su valor original
    for (int i = 0; i < 3; i++) { // el pitido va a sonar 3 veces, pero no seguidos ya que definimos que sean 3 pitidos.
      digitalWrite(Buzzer, HIGH); // el altavoz se activa
      delay (500); // durante medio segundo 1/2 s.
      digitalWrite(Buzzer, LOW); // altavoz apagado
      delay (250); // durante 1/4 de segundo.
    }
  }
}
