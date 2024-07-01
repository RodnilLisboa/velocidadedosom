#define pinoEmissor 4 
#define pinoReceptor 2

float velocidade;
float segundos;
float metros;

unsigned long distancia;
unsigned long duracao;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Endereço I2C do LCD
#define I2C_ADDR 0x27

// Número de colunas e linhas do LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);

void setup() { 
  Serial.begin(9600); 
  pinMode(pinoEmissor, OUTPUT); //define pinoEmissor como saída
  pinMode(pinoReceptor, INPUT); //define pinoReceptor como entrada
  
  lcd.begin(16, 2);
  lcd.backlight(); // Ativar iluminação de fundo, se suportado pelo LCD
}

void loop() {
  // manda um pulso de dez microssegundos
  digitalWrite(pinoEmissor, HIGH); //manda o sinal
  delayMicroseconds(10); //por dez microssegundos
  digitalWrite(pinoEmissor, LOW); //para de mandar o sinal
  
  duracao = pulseIn(pinoReceptor, HIGH); //recebe o sinal
  Serial.print(" Tempo para o pulso viajar:  ");
  Serial.print(duracao);
  Serial.println(" microseconds"); //mostra a duração do pulso em microssegundos
  
  distancia = 19; //calcula a distância
  Serial.print(" Percurso entre o sensor e o objeto:  ");
  Serial.print(distancia); 
  Serial.println(" cm"); //mostra a duração em 
  
  segundos = duracao / 2 * 0.000001; //passa de microssegundos para segundos
  metros = distancia * 0.01; //passa de centímetros para metro
  velocidade = metros / segundos; //calcula a velocidade
  Serial.print(" Velocidade do som:  ");
  Serial.print(velocidade);
  Serial.println(" m/s"); //mostra a velocidade em metros por segundo
  
  lcd.setCursor(0,0);
  lcd.print(duracao);
   lcd.setCursor(0,1);
     lcd.print("microssegundos");
       //lcd.print(velocidade);
   //lcd.print("m/s");
   delay(2000); // delay in milliseconds 
     lcd.clear();

}

