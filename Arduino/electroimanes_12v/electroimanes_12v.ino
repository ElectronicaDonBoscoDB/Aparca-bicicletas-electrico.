int Cerradura = 7 ;      //definimos el pin que vamos a utilizar para las cerraduras.

void setup() {                //definimos cerradura como salida
pinMode(Cerradura, OUTPUT);
}

void loop() {                //se ha creado dos funciones
relepuertaon();              // esta funcion para abrir las cerraduras.
relepuertaoff();             //esta función para bloquear las cerraduras.
}

void relepuertaon() {
  digitalWrite(Cerradura, 1);//Activa la cerradura

}
void relepuertaoff() {
  digitalWrite(Cerradura, 0);//Desactiva la cerradura
}
