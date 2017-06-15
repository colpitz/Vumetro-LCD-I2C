#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x26 y 16 columnas x 2 filas.
//SLC A0 - SDA  A1., alimentacion 5V.
LiquidCrystal_I2C lcd(0x26, 16, 2); //
byte A[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte B[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};
byte C[8] = {
  B01000,
   B01000,
   B01000,
   B01000,
   B01000,
   B01000,
   B01000,
   B01000,
};
byte D[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
};
byte E[8] = {
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
};
byte F[8] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
};

void setup() {
  // Inicializar el LCD
  lcd.init();

  //Encender la luz de fondo.
  lcd.backlight();

  //creamos los nuevos caracteres
  lcd.createChar (0, A);
  lcd.createChar (1, B);
  lcd.createChar (2, C);
  lcd.createChar (3, D);
  lcd.createChar (4, E);
  lcd.createChar (5, F);

  // Escribimos el texto en el LCD
  lcd.setCursor(0, 0);
  lcd.print("VUMETRO");

}

void loop () {


  for (int cur = 0 ; cur < 16; cur++) {

    for (int cont = 0 ; cont < 6; cont++) {
      lcd.setCursor(cur, 1);

      lcd.write(byte(cont));
    }
    delay(5);
  }
  for (int cur = 16 ; cur >= 0; cur--) {

    for (int cont = 5 ; cont >= 0; cont--) {
      lcd.setCursor(cur, 1);

      lcd.write(byte(cont));
    }
    delay(5);
  }
}
