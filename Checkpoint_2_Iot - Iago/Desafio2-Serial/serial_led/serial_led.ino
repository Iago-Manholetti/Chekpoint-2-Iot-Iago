#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 telaMara(SCREEN_WIDTH, SCREEN_HEIGHT); // definindo oled como telaMara rsrs

int ledPin = 9;    // nomeia o pino9 do arduino como ledPin 

void setup() {
  pinMode(ledPin, OUTPUT);     //Pino9 como saida 
  Serial.begin(9600);				   //Inicialica a comunicação serial

  telaMara.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  telaMara.clearDisplay();
}

void loop() {
  char dado;	// Declara dado como variavel local do tipo char
  int valor;  // Declara valor como variavel local do tipo int
  
  if(Serial.available() > 0){			// Se tem alguma coisa no buffer da serial
    dado = Serial.read();					// Entao salva em dado
    
    if(dado == 'A'){ //se o dado comecar com A
      
      valor = Serial.parseInt(); // Recebe o valor do Serial e passa para int
      telaMara.clearDisplay(); // comeca a configuracao da tela oled, limpando
      telaMara.setTextSize(2); //dobro de tamanho da letra
      telaMara.setTextColor(SSD1306_WHITE);//cor de texto: branco
      telaMara.setCursor(10,0); //posição do texto na tela
      telaMara.println(String("Pot1: ") + valor); //printa o valor do Potenciometro 1
      telaMara.display(); //mostra no Oled
      }
  
      if(dado == 'B'){ //se o dado comecar com B
      valor = Serial.parseInt();
      telaMara.clearDisplay();
      telaMara.setTextSize(2);
      telaMara.setTextColor(SSD1306_WHITE);
      telaMara.setCursor(10,0);
      telaMara.println(String("Pot2: ") + valor);
      telaMara.display();
      }
  delay(100);
  }//end if Serial.available
}//end loop
