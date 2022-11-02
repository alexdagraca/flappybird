#include <Gamebuino-Meta.h>

// Les constantes
const int Xbird = 10;
const int Tbird = 5;
const int YTuyup = 0;
const int YTuydown = 64;
// Les fonctions

// Les variables

/*Oiseau*/
int Ybird = 32;
int SensY = 1;
/*Rectangle*/
int XRect1 = 50;
int XRect2 = 65;
int XRect3 = 90;
int XRect4 = 105;
int XRect5 = 115;
int SensX = 1;

void setup()
{
  gb.begin();
}

void loop()
{
  while (!gb.update())
    ;
  gb.display.clear();

  // Déplacement du carré

  if (gb.buttons.pressed(BUTTON_UP))
  {
    Ybird = Ybird - 15;
  }
  else
  {
    Ybird = Ybird + SensY;
  }

  if (Ybird + 5 == 66)
  {
    Ybird = 25;
  }

  // Déplacement couple Rectangle

  XRect1 = XRect1 - SensX;
  XRect2 = XRect2 - SensX;
  XRect3 = XRect3 - SensX;
  XRect4 = XRect4 - SensX;
  XRect5 = XRect5 - SensX;

  // Les dessins

  /*Balle*/
  gb.display.setColor(YELLOW);
  gb.display.fillRect(Xbird, Ybird, Tbird, Tbird);

  /*Couple rectangle 1*/
  gb.display.setColor(GREEN);
  gb.display.fillRect(XRect1, YTuyup, 10, 20);
  gb.display.fillRect(XRect1, YTuydown, 10, -15);

  /*Couple rectangle 2*/
  gb.display.fillRect(XRect2, YTuyup, 10, 20);
  gb.display.fillRect(XRect2, YTuydown, 10, -15);

  /*Couple rectangle 3*/
  gb.display.fillRect(XRect3, YTuyup, 10, 20);
  gb.display.fillRect(XRect3, YTuydown, 10, -15);

  /*Couple rectangle 4*/
  gb.display.fillRect(XRect4, YTuyup, 10, 20);
  gb.display.fillRect(XRect4, YTuydown, 10, -15);

  /*Couple rectangle 5*/
  gb.display.fillRect(XRect5, YTuyup, 10, 20);
  gb.display.fillRect(XRect5, YTuydown, 10, -15);
}