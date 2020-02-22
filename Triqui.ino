#include <Adafruit_TFTLCD.h>
#include <Adafruit_GFX.h>
#include <TouchScreen.h>
#include <stdint.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define TS_MINX 130
#define TS_MINY 120
#define TS_MAXX 955
#define TS_MAXY 915

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF



#define YP A2
#define XM A3
#define YM 8
#define XP 9

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

boolean buttonEnabled = true;

int Casilla11 = 2;
int Casilla12 = 3;
int Casilla13 = 4;
int Casilla21 = 5;
int Casilla22 = 6;
int Casilla23 = 7;
int Casilla31 = 8;
int Casilla32 = 9;
int Casilla33 = 10;
int Boton = 0;
int Turno = 1;
int Ocupado = 0;
int Boton1 = 0, Boton2 = 0, Boton3 = 0, Boton4 = 0, Boton5 = 0, Boton6 = 0, Boton7 = 0, Boton8 = 0, Boton9 = 0;
int Transicion = 0;

//int Turno[] = {1,2,3,4,5,6,7,8,9};

void setup() {

  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);

  tft.setCursor(45, 95);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("BIENVENIDO A TRIQUI");

  tft.fillRect(50, 125, 210, 40, RED);
  tft.drawRect(50, 125, 210, 40, BLACK);
  tft.setCursor(80, 135);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("INICIAR JUEGO");

  tft.setCursor(70, 225);
  tft.setTextColor(BLACK);
  tft.setTextSize(1);
  tft.print("EL PRIMERO EN JUGAR TIENE LA X");

}

void loop() {

  TSPoint p = ts.getPoint();

  if (p.z > ts.pressureThreshhold) {

    p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, 240);
    
    buttonEnabled = false;
    Serial.println(Casilla11);
    Serial.println(Casilla12);
    Serial.println(Casilla13);
    Serial.println(Casilla21);
    Serial.println(Casilla22);
    Serial.println(Casilla23);
    Serial.println(Casilla31);
    Serial.println(Casilla32);
    Serial.println(Casilla33);
    Serial.print("X = "); Serial.print(p.x);
    Serial.print("\tY = "); Serial.print(p.y);
    Serial.print("\tPressure = "); Serial.println(p.z);



    //MOVIMIENTO 1:

    //CASILLA 1.1
    if (p.x > 50 && p.x < 123 && p.y > 10 && p.y < 83 && Boton1 != HIGH && Transicion==1) {

      if (Turno % 2 != 0 && Transicion == 1) {

        Serial.println("La X");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(75, 30);
        tft.setTextColor(RED);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        //delay(300);
        Boton1 = HIGH;
        Serial.println(Turno);
        Casilla11 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }

      else if (Turno % 2 == 0) {

        Serial.println("La O");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(75, 30);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        //delay(300);
        Boton1 = HIGH;
        Serial.println(Turno);
        Casilla11 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }
    }
    //CASILLA 1.2
    if (p.x > 50 && p.x < 123 && p.y > 83 && p.y < 157 && Boton2 != HIGH && Transicion==1) {
      if (Turno % 2 != 0) {

        Serial.println("La X");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(75, 103);
        tft.setTextColor(RED);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        Boton2 = HIGH;
        Casilla12 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }

      else if (Turno % 2 == 0) {

        Serial.println("La O");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(75, 103);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        Boton2 = HIGH;
        Casilla12 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }
    }
    //CASILLA 1.3
    if (p.x > 50 && p.x < 123 && p.y > 157 && p.y < 231 && Boton3 != HIGH && Transicion==1) {

      if (Turno % 2 != 0) {

        Serial.println("La X");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(75, 176);
        tft.setTextColor(RED);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        Boton3 = HIGH;
        Casilla13 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }

      else if (Turno % 2 == 0) {

        Serial.println("La O");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(75, 176);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        Boton3 = HIGH;
        Casilla13 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }
    }
    //CASILLA 2.1.
    if (p.x > 106.6 && p.x < 179.6 && p.y > 10 && p.y < 83 && Boton4 != HIGH && Transicion==1) {

      if (Turno % 2 != 0) {

        Serial.println("La X");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(147.6, 30);
        tft.setTextColor(RED);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        Boton4 = HIGH;
        Casilla21 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }

      else if (Turno % 2 == 0) {

        Serial.println("La O");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(147.6, 30);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        Boton4 = HIGH;
        Casilla21 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }
    }
    //CASILLA 2.2
    if (p.x > 106.6 && p.x < 179.6 && p.y > 83 && p.y < 157 && Boton5 != HIGH && Transicion==1) {

      if (Turno % 2 != 0) {

        Serial.println("La X");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(147.6, 103);
        tft.setTextColor(RED);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        Boton5 = HIGH;
        Casilla22 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }

      else if (Turno % 2 == 0) {

        Serial.println("La O");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(147.6, 103);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        Boton5 = HIGH;
        Casilla22 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }
    }
    //CASILLA 2.3
    if (p.x > 106.6 && p.x < 179.6 && p.y > 157 && p.y < 231 && Boton6 != HIGH && Transicion==1) {
      if (Turno % 2 != 0) {

        Serial.println("La X");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(147.6, 176);
        tft.setTextColor(RED);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        Boton6 = HIGH;
        Casilla23 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }

      else if (Turno % 2 == 0) {

        Serial.println("La O");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(147.6, 176);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        Boton6 = HIGH;
        Casilla23 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }
    }

    //CASILLA 3.1
    if (p.x > 163.2 && p.x < 236.2 && p.y > 10 && p.y < 83 && Boton7 != HIGH && Transicion==1) {
      if (Turno % 2 != 0) {

        Serial.println("La X");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(219.8, 30);
        tft.setTextColor(RED);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        Boton7 = HIGH;
        Casilla31 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }

      else if (Turno % 2 == 0) {

        Serial.println("La O");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(219.8, 30);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        Boton7 = HIGH;
        Casilla31 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }
    }
    //CASILLA 3.2
    if (p.x > 163.2 && p.x < 236.2 && p.y > 83 && p.y < 157 && Boton8 != HIGH && Transicion==1) {

      if (Turno % 2 != 0) {

        Serial.println("La X");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(219.8, 103);
        tft.setTextColor(RED);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        Boton8 = HIGH;
        Casilla32 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }

      else if (Turno % 2 == 0) {

        Serial.println("La O");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(219.8, 103);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        Boton8 = HIGH;
        Casilla32 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }
    }
    //CASILLA 3.3
    if (p.x > 163.2 && p.x < 236.2 && p.y > 157 && p.y < 231 && Boton9 != HIGH && Transicion==1) {
      if (Turno % 2 != 0) {

        Serial.println("La X");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(219.8, 176);
        tft.setTextColor(RED);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        Boton9 = HIGH;
        Casilla33 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }

      else if (Turno % 2 == 0) {

        Serial.println("La O");

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(219.8, 176);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        Boton9 = HIGH;
        Casilla33 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
        }
      }
    }

    if (p.x > 50 && p.x < 260 && p.y > 125 && p.y < 165 && Boton != HIGH) {

      Serial.println("Botón");

      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

      tft.fillScreen(WHITE);
      tft.drawRect(50, 10, 220, 220, BLACK);

      tft.fillRect(123, 10, 2, 220, BLACK);
      tft.fillRect(197, 10, 2, 220, BLACK);

      tft.fillRect(50, 83, 220, 2, BLACK);
      tft.fillRect(50, 157, 220, 2, BLACK);

      Boton = HIGH;

      Transicion = 1;

    }
  }
}
