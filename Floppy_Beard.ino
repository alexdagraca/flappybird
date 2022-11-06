#include <Gamebuino-Meta.h>

// Les constantes
const int Tbird = 5;
const int Xbird = 10;
const int YTuyup = 0;
const int YTuydown = 49;
const int DistRectX = 45;

// Les variables

/*Oiseau*/
int Ybird = 32;
int SensY = 1;

/*Rectangle*/
int XRect1 = DistRectX;
int XRect2 = DistRectX * 2;
int SensX = 1;
int GameOn = 1;
int countPoints = 0;
int countX = 0;

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

    // Les fonctions

    // Comptabilité

    if (XRect1 == Xbird || XRect2 == Xbird)
    {
      countPoints++;
      gb.sound.tone(200, 500);
    }

    // Déplacement du carré

    if (gb.buttons.repeat(BUTTON_UP, 0))
    {
      Ybird = Ybird - 2;
    }
    else
    {
      Ybird = Ybird + SensY;
    }

    if (Ybird + 5 == 66)
    {
      Ybird = Ybird - SensY;
    };
    // Déplacement couple Rectangle

    XRect1 -= SensX;

    XRect2 = XRect2 - SensX;

    countX += SensX;

    // Quand le premier tuyau sort de lecran on le rajoute à l'arriere apres le 2eme tuyau a une distance de DistRectX
    if ((XRect1 + 10) <= 0)
    {
      XRect1 = XRect2 + DistRectX;
    }

    // Quand le deuxieme tuyau sort de lecran on le rajoute à l'arriere apres le 1er tuyau a une distance de DistRectX
    if ((XRect2 + 10) <= 0)
    {
      XRect2 = XRect1 + DistRectX;
    }

    // Relancer le jeu si toucher

    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect1, YTuydown, 10, 15))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect1, YTuyup, 10, 20))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect2, YTuydown, 10, 15))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect2, YTuyup, 10, 20))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }

    // Les dessins
    /*Contour Compteur
    gb.display.setColor(WHITE);
    gb.display.fillRect(31.8, 0, 2, 10);
    gb.display.fillRect(41.75, 0, 2, 10);
    gb.display.fillRect(33, 8, 10.5, 2);*/

    /*Balle*/
    gb.display.setColor(YELLOW);
    gb.display.fillRect(Xbird, Ybird, Tbird, Tbird);

    /*Couple rectangle 1*/
    gb.display.setColor(GREEN);
    gb.display.fillRect(XRect1, YTuyup, 10, 20);
    gb.display.fillRect(XRect1, YTuydown, 10, 15);

    /*Couple rectangle 2*/
    gb.display.fillRect(XRect2, YTuyup, 10, 20);
    gb.display.fillRect(XRect2, YTuydown, 10, 15);

    /*Compteur*/
    gb.display.setColor(WHITE);
    gb.display.print(countPoints);
  }

  // Fonction GameOver

  else
  {
    gb.display.println("Pressez A pour recommencer");
    if (gb.buttons.pressed(BUTTON_A))
    {
      GameOn = 1;
      countPoints = 0;
      Ybird = 32;
      XRect1 = DistRectX;
      XRect2 = DistRectX * 2;
    }
  }
}