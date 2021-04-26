#include <Ultrasonic.h>
//#include <Servo.h> //importa a biblioteca do servo motor



//Servo valvula_de_capsula_cafe;     // cria o objeto meuservo valvula de capsula de cafe
//Servo valvula_de_cafe;     // cria o objeto meuservo da valvula de café
HC_SR04 sensor1(4, 5); // (trigger, echo)
HC_SR04 sensor2(7, 6); // (trigger, echo)

//int potpin = A0;    // potenciometro no ligado no pino A0
//int valor;          // variavel que vai receber o valor lido do potenciometro
int valor_distancia_xicara = 0; //variavel responsável por pegar o valor da distância do sensor 1. Responsável por checar a distância da xicara
int valor_distancia_mao_usuario = 0; //variavel responsável por pegar o valor da distância do sensor 2. Responsável por checar a distância da mão do usuário.

int pos,pos2;

//declara os pinos do arduino que estão conectados nos servos motores
int valvula_de_capsula_cafe = 9;
int valvula_de_cafe = 10;


void setup() {
  Serial.begin(9600);
  //valvula_de_capsula_cafe.attach(9);  // configura o pino 9 do arduino para o servo motor
  //valvula_de_cafe.attach(10); // configura o pino 10 do arduino para o servo motor da
  pinMode(valvula_de_capsula_cafe, OUTPUT);
  pinMode(valvula_de_cafe, OUTPUT);
}

void loop() {
  valor_distancia_xicara = sensor1.distance();
  valor_distancia_mao_usuario = sensor2.distance();
  int angulo = 0;
  int angulo1 = 90;
  servoPos(valvula_de_capsula_cafe, angulo);
  delay(100);
  servoPos(valvula_de_cafe, angulo1);
  if (valor_distancia_xicara < 20) {
    Serial.println("Tem xicara");
    delay(100);
    angulo = 90;
    servoPos(valvula_de_capsula_cafe, angulo);
    Serial.println(angulo);
    Serial.println("Aberto 8");
    delay(100);

      // IF DE CAFE LONGO
     if ( valor_distancia_mao_usuario > 30 && angulo == 90) {
      angulo1 = 0;
      servoPos(valvula_de_cafe, angulo1);
      Serial.println(angulo1);
      Serial.println("Cafe longo (40ml)");
      delay(100);
      angulo1 = 90;
      servoPos(valvula_de_cafe, angulo1);
      Serial.println("Cafe longo, pronto");

       // IF DE CAFE CURTO
    }  else if (valor_distancia_mao_usuario <= 30 && angulo == 90 ) {
      angulo1 = 180;
      servoPos(valvula_de_cafe, angulo1);
      Serial.println(angulo1);
      Serial.println("Cafe curto (20ml)");
      delay(100);
      angulo1 = 90;
      servoPos(valvula_de_cafe, angulo1);
      Serial.println("Cafe curto, pronto");
    }
  }

  if ( valor_distancia_xicara >= 20) {
    angulo = 0;
    servoPos(valvula_de_capsula_cafe, angulo);
    Serial.println("Fechado");
    delay(100);
  }

}

//Função que controla a posição do servo motor. 
void servoPos (int servo, int pos)
{
  int microPulso = map(pos, 0,180,1000,2000);
  digitalWrite(servo, HIGH);
  delayMicroseconds(microPulso);
  digitalWrite(servo, LOW);
  delay(100);                   
}
