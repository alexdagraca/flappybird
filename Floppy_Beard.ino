#include <Gamebuino-Meta.h>

// Les constantes
const int Tbird = 5;
const int Xbird = 10;
const int YTuyup = 0;
const int YTuydown = 64;
// Les fonctions

// Les variables

/*Oiseau*/
int Ybird = 32;
int SensY = 1;
/*Rectangle*/
int XRect1 = 50;
int XRect2 = 95;
int XRect3 = 140;
int XRect4 = 185;
int XRect5 = 230;
int SensX = 1;
int GameOn = 1;

void setup()
{
  gb.begin();
}

void loop()
{
  while (!gb.update())
    ;
  gb.display.clear();
  if (GameOn == 1)
  {
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

    // Relancer le jeu si toucher (Rect1)

    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect1, YTuydown, 10, 45))
    {
      GameOn = 0;
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect1, YTuy20, 10, 45))
    {
      GameOn = 0;
    }

    // Les dessins

    /*Balle*/
    gb.display.setColor(YELLOW);
    gb.display.fillRect(Xbird, Ybird, Tbird, Tbird);

    /*Couple rectangle 1*/
    gb.display.setColor(GREEN);
    gb.display.fillRect(XRect1, YTuyup, 10, 20);
    gb.display.fillRect(XRect1, YTuydown, 10, 45);

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
  else
  {
    gb.display.print("Pressez A pour recommencer");
    if (gb.buttons.pressed(BUTTON_A))
    {
      GameOn = 1;
      Ybird = 32;
      XRect1 = 50;
      XRect2 = 95;
      XRect3 = 140;
      XRect4 = 185;
      XRect5 = 230;
    }
  }
}