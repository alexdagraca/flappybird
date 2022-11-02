#include <Gamebuino-Meta.h>

// Les constantes
const int Xbird = 10;
const int Tbird = 5;
const int YTuyup = 0;
const int YTuydown = 64;
// Les fonctions

// Les variables

int Ybird = 32;
int SensY = 1;
int XRect1 = 50;
int SensX = -1;

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

  // Déplacement couple Rectangle 1
  XRect1 = XRect1 - SensX;

  // Les dessins

  /*Balle*/
  gb.display.setColor(YELLOW);
  gb.display.fillRect(Xbird, Ybird, Tbird, Tbird);

  /*Couple rectangle 1*/
  gb.display.setColor(GREEN);
  gb.display.fillRect(XRect1, YTuyup, 10, 20);
  gb.display.fillRect(XRect1, YTuydown, 10, -15);
}
