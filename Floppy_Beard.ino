#include <Gamebuino-Meta.h>

// Les constantes
const int Tbird = 5;
const int Xbird = 10;
const int YTuyup = 0;

// Les variables

/*Oiseau*/
int Ybird = 32;
int SensY = 1;

/*Rectangle*/
int DistRectX = 40;
int XRect1 = DistRectX;
int XRect2 = DistRectX * 2;
int heightUp1 = random(5, 33);
int heightUp2 = random(5, 33);
int YTuydown1 = random((heightUp1 + 28), 58);
int YTuydown2 = random((heightUp2 + 28), 58);
int heightDown1 = gb.display.height() - YTuydown1;
int heightDown2 = gb.display.height() - YTuydown2;

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
    // Reinitialisation des distances entre 2 rectangles et les hauteurs des rectangles via random
    if ((XRect1 + 10) <= 0)
    {
      DistRectX = random(35, gb.display.width() - 10);
      heightUp1 = random(5, 31);
      YTuydown1 = heightUp1 + 28;
      heightDown1 = gb.display.height() - YTuydown1;
      XRect1 = XRect2 + DistRectX;
    }

    // Quand le deuxieme tuyau sort de lecran on le rajoute à l'arriere apres le 1er tuyau a une distance de DistRectX
    if ((XRect2 + 10) <= 0)
    {
      DistRectX = random(35, gb.display.width() - 10);
      heightUp2 = random(5, 31);
      YTuydown2 = heightUp2 + 28;
      heightDown2 = gb.display.height() - YTuydown2;
      XRect2 = XRect1 + DistRectX;
    }

    // Relancer le jeu si toucher

    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect1, YTuydown1, 10, heightDown1))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect1, YTuyup, 10, heightUp1))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect2, YTuydown2, 10, heightDown2))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XRect2, YTuyup, 10, heightUp2))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }

    /*Balle*/
    gb.display.setColor(YELLOW);
    gb.display.fillRect(Xbird, Ybird, Tbird, Tbird);

    /*Couple rectangle 1*/
    gb.display.setColor(GREEN);
    gb.display.fillRect(XRect1, YTuyup, 10, heightUp1);
    gb.display.fillRect(XRect1, YTuydown1, 10, heightDown1);

    /*Couple rectangle 2*/
    gb.display.fillRect(XRect2, YTuyup, 10, heightUp2);
    gb.display.fillRect(XRect2, YTuydown2, 10, heightDown2);

    /*Compteur*/
    gb.display.setColor(WHITE);
    gb.display.print(DistRectX);
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