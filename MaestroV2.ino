#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int nivel     = 1;
int adc_key_in  = 0;
int lcd_key  = 0;

#define btnSELECT  1
#define btnUP     2
#define btnDOWN   3
#define btnNONE   0

int read_LCD_buttons() {
  
  adc_key_in = analogRead(0);
  if (adc_key_in > 1000) return btnNONE;
  if (adc_key_in < 800 && adc_key_in > 450)   return btnSELECT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450 && adc_key_in > 250)  return btnDOWN;
}

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("  Autoescaneo ");
  lcd.setCursor(0,1);
  lcd.print("Nivel: 1 ");
  Serial.begin(9600); // Inicializa la comunicación serial
}

void loop() {

  lcd_key = read_LCD_buttons();

  if (lcd_key != 0){
    switch (lcd_key) {

      case btnUP: {
        if (nivel == 1){
          lcd.setCursor(0,1);
          lcd.print("Nivel: 1 ");
          nivel = 1; 
        }
        
        else if(nivel == 2){
          lcd.setCursor(0,1);
          lcd.print("Nivel: 1 ");
          nivel = 1; 

        }
        else if(nivel == 3){
          lcd.setCursor(0,1);
          lcd.print("Nivel: 2 ");
          nivel = 2; 

        }
        break;
      }
      case btnDOWN: {

        if (nivel == 1){
          lcd.setCursor(0,1);
          lcd.print("Nivel: 2 ");
          nivel = 2; 
        }
        
        else if(nivel == 2){
          lcd.setCursor(0,1);
          lcd.print("Nivel: 3 ");
          nivel = 3; 

        }
        else if(nivel == 3){
          lcd.setCursor(0,1);
          lcd.print("Nivel: 3 ");
          nivel = 3; 
        }
        break;
      }
      case btnSELECT: {

        if (nivel == 1){
          lcd.clear();
          lcd.print("Eligio: ");
          lcd.setCursor(0,1);
          lcd.print("Nivel 1 ");
          Serial.write(1); // Envía el nivel seleccionado a través de la comunicación serial
          delay(1500);
          lcd.clear();
          lcd.print("Escaneo en curso");
          Serial.write(1); // Envía el nivel seleccionado a través de la comunicación serial
          delay(800);
          lcd.clear();
          lcd.print("Escaneo finalizado");
          delay(1000);
          lcd.clear();
          lcd.print("Autoescaneo ");
          lcd.setCursor(0,1);
          lcd.print("Nivel: 1 ");
          nivel = 1;
        }
        
        else if(nivel == 2){
          lcd.clear();
          lcd.print("Eligio: ");
          lcd.setCursor(0,1);
          lcd.print("Nivel 2 ");
          Serial.write(1); // Envía el nivel seleccionado a través de la comunicación serial
          delay(1500);
          lcd.clear();
          lcd.print("Escaneo en curso");
          Serial.write(2); // Envía el nivel seleccionado a través de la comunicación serial
          delay(800);
          lcd.clear();
          lcd.print("Escaneo finalizado");
          delay(1000);
          lcd.clear();
          lcd.print("Autoescaneo ");
          lcd.setCursor(0,1);
          lcd.print("Nivel: 1 ");
          nivel = 1;        
        }
        else if(nivel == 3){
          lcd.clear();
          lcd.print("Eligio: ");
          lcd.setCursor(0,1);
          lcd.print("Nivel 3 ");
          Serial.write(3); // Envía el nivel seleccionado a través de la comunicación serial
          delay(1500);
          lcd.clear();
          lcd.print("Escaneo en curso");
          Serial.write(1); // Envía el nivel seleccionado a través de la comunicación serial
          delay(1000);
          lcd.clear();
          lcd.print("Escaneo finalizado");
          delay(1000);
          lcd.clear();
          lcd.print("Autoescaneo ");
          lcd.setCursor(0,1);
          lcd.print("Nivel: 1 ");
          nivel = 1;
        }       
        break;
      }
    }
  }
  delay(200);
}
