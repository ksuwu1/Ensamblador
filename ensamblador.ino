// Declaracion de componentes del circuito
const int a = 5;
const int b = 10;
const int c = 12;
const int d = 9;
const int e = 11;
const int f = 7;
const int g = 13;
const int Disp1 = 6;
const int Disp2 = 8;

// Declaracion Variables de Boton
int input = 0;

void setup() {
  // Entradas
  pinMode(Disp1, OUTPUT);
  pinMode(Disp2, OUTPUT);
  // Salidas
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(Disp1, HIGH);
  digitalWrite(Disp2, LOW);

  // Operaciones
  if (Serial.available() > 0) {
    // Leer el comando desde el puerto serial
    String command = Serial.readStringUntil('\n');

    // Realizar operación según el comando ingresado
    if (command == "suma" || command == "resta" || command == "multiplicacion" || command == "division" || command == "xor" || command == "and" || command == "or") {
      // Realizar la operación solo si el comando es válido
      realizarOperacion(command);
      delay(1000);
    } else {
      Serial.println("Comando no válido");
    }
  }

  // Apagar Displays
  apagar();
}

// Métodos

// Conversion de Binario a decimal
int binarioADecimal(String binario) {
  return strtol(binario.c_str(), NULL, 2);
}

// Para operaciones
void realizarOperacion(String operacion) {
  String binario1 = leerBinario();
  String binario2 = leerBinario();
  int decimal1 = binarioADecimal(binario1);
  int decimal2 = binarioADecimal(binario2);

  int resultado = 0;

  if (operacion == "suma") {
    resultado = decimal1 + decimal2;
  } else if (operacion == "resta") {
    resultado = decimal1 - decimal2;
  } else if (operacion == "multiplicacion") {
    resultado = decimal1 * decimal2;
  } else if (operacion == "division") {

    if (decimal2 == 0 && decimal1 != 0) {
      infinito();//Cuando se divide xx/00
      Serial.println("Resultado de la operación: Infinito");
      return;
    } else if (decimal1 == 0 && decimal2 == 0) {
      error(); //Cuando se divide 00/00
      Serial.println("Error: División 00/00");
      return;
    } else {
      resultado = decimal1 / decimal2;
    }

  }else if (operacion == "xor"){
    if ((binario1 == "00" && binario2 == "00") || (binario1 == "11" && binario2 == "11")) {
      resultado = 0;
    } else {
      resultado = 1;
    }

  }else if (operacion == "and"){
    if ((binario1 == "11" && binario2 == "11")) {
      resultado = 1;
    } else {
      resultado = 0;
    }

  }else if (operacion == "or"){
    if ((binario1 == "00" && binario2 == "00")) {
      resultado = 0;
    } else {
      resultado = 1;
    }
  }

  mostrarNumeroEnDisplays(operacion, resultado);

  // Mostrar el resultado en el puerto serial
  Serial.print("Resultado de la operación: ");
  Serial.println(resultado);
}

// Método para leer un número binario desde el puerto serial
String leerBinario() {
  Serial.println("Ingrese un número binario:");
  while (!Serial.available()) {
    // Esperar a que el usuario ingrese datos
  }
  return Serial.readStringUntil('\n');
}

// Método para mostrar un número en los displays
void mostrarNumeroEnDisplays(String operacion, int numero) {
  if (operacion == "suma") {

    switch (numero) {
      case 0: cero(); break;
      case 1: uno(); break;
      case 2: dos(); break;
      case 3: tres(); break;
      case 4: cuatro(); break;
      case 5: cinco(); break;
      case 6: seis(); break;
      case 7: siete(); break;
      case 8: ocho(); break;
      case 9: nueve(); break;
      default: error(); break;
    }

  } else if (operacion == "resta") {

    switch (numero) {
      case -1: 
      apagar();
      delay(1000);
      uno();
      delay(1000); 
      apagar();
      signo();
      delay(1000);
    break;

    case -2:
      apagar();
      delay(1000);
      dos();
      delay(1000); 
      apagar();
      signo();
      delay(1000);
    break;

    case -3:
      apagar();
      delay(1000);
      dos();
      delay(1000); 
      apagar();
      signo();
      delay(1000);
    break;

    case 0: cero(); break;
    case 1: uno(); break;
    case 2: dos(); break;
    case 3: tres(); break;
    case 4: cuatro(); break;
    case 5: cinco(); break;
    case 6: seis(); break;
    case 7: siete(); break;
    case 8: ocho(); break;
    case 9: nueve(); break;
    default: error(); break;
    }

  } else if (operacion == "multiplicacion") {

    switch (numero) {
      case 0: cero(); break;
      case 1: uno(); break;
      case 2: dos(); break;
      case 3: tres(); break;
      case 4: cuatro(); break;
      case 5: cinco(); break;
      case 6: seis(); break;
      case 7: siete(); break;
      case 8: ocho(); break;
      case 9: nueve(); break;
      default: error(); break;
    }

  } else if (operacion == "division") {

    switch (numero) {
      case 0: cero(); break;
      case 1: uno(); break;
      case 2: dos(); break;
      case 3: tres(); break;
      case 4: cuatro(); break;
      case 5: cinco(); break;
      case 6: seis(); break;
      case 7: siete(); break;
      case 8: ocho(); break;
      case 9: nueve(); break;
      default: error(); break;
    }

  }  else if (operacion == "xor") {

    switch (numero) {
      case 0: cero(); break;
      case 1: uno(); break;
      default: error(); break;
    }
  
  }else if (operacion == "and") {

    switch (numero) {
      case 0: cero(); break;
      case 1: uno(); break;
      default: error(); break;
    }
  
  }else if (operacion == "or") {

    switch (numero) {
      case 0: cero(); break;
      case 1: uno(); break;
      default: error(); break;
    }
  
  }else {

    error();

  }

}

// DISPLAY 2 (NUMERAL)
void cero() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
}

void uno() {
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

void dos() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
}

void tres() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(c, HIGH);
}

void cuatro() {
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

void cinco() {
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void seis() {
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
}

void siete() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

void ocho() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void nueve() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void signo() {
  digitalWrite(g, HIGH);
  digitalWrite(Disp2, HIGH);
  digitalWrite(Disp1, LOW);
}

void infinito() {
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void error() {
  digitalWrite(a, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void apagar() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}