int buttonPin2 = 2; // nomeia o pino2 do arduino como buttonPin2
int buttonPin3 = 3; // nomeia o pino3 do arduino como buttonPin3
int ledPin = 13;    // nomeia o pino13 do arduino como ledPin 
int botao1 = A0;    //selecionando o A0 como botao1
int valor_botao1 = 0; //iniciando a variavel
int botao2 = A1;  //selecionando o A1 como botao2
int valor_botao2 = 0; //iniciando a variavel

int buttonStatus2;  // Variavel de estado do buttonPin2
int buttonStatus3;  // Variavel de estado do buttonPin2

void setup() {
  pinMode(ledPin, OUTPUT);            
  pinMode(buttonPin2, INPUT_PULLUP);  
  pinMode(buttonPin3, INPUT_PULLUP); 
  Serial.begin(9600);				   
}

void loop() {
  buttonStatus2 = digitalRead(buttonPin2);
  buttonStatus3 = digitalRead(buttonPin3);
  valor_botao1 = analogRead(botao1);
  valor_botao2 = analogRead(botao2);

  if (buttonStatus2 == LOW){   // quando o botao2 for pressionado, printa o valor1 no Serial
    digitalWrite(ledPin, HIGH);
    char buffer[30];
    int val1 = valor_botao1;
    sprintf(buffer, "A%d", val1);
    Serial.println(buffer);
    delay(500);
  }

  if (buttonStatus3 == LOW){   // quando o botao3 for pressionado, printa o valor2 no Serial
    digitalWrite(ledPin, HIGH);
    char buffer[30];
    int val2 = valor_botao2;
    sprintf(buffer, "B%d", val2);
    Serial.println(buffer);
     delay(500);
  }
}
