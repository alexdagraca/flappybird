#include <Gamebuino-Meta.h>

// Les constantes
const int Tbird = 5;
const int Xbird = 10;
const int YTuyauUp = 0;

// Les variables

/*Oiseau*/
int Ybird = 32;
int SensY = 1;

/*Rectangle*/
int DistEntreTuyaux = 40;
int XTuyau1 = DistEntreTuyaux;
int XTuyau2 = DistEntreTuyaux * 2;
int heightUp1 = random(5, 33);
int heightUp2 = random(5, 33);
int YTuyaudown1 = random((heightUp1 + 28), 58);
int YTuyaudown2 = random((heightUp2 + 28), 58);
int heightDown1 = gb.display.height() - YTuyaudown1;
int heightDown2 = gb.display.height() - YTuyaudown2;

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

    if (XTuyau1 == Xbird || XTuyau2 == Xbird)
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

    XTuyau1 -= SensX;

    XTuyau2 = XTuyau2 - SensX;

    countX += SensX;

    // Quand le premier tuyau sort de l'écran on le rajoute à l'arrière après le 2ème tuyau à une distance de DistEntreTuyaux
    // Réinitialisation des distances entre 2 couples de tuyaux et les hauteurs des tuyaux via le random
    if ((XTuyau1 + 10) <= 0)
    {
      DistEntreTuyaux = random(35, gb.display.width() - 10);
      heightUp1 = random(5, 31);
      YTuyaudown1 = heightUp1 + 28;
      heightDown1 = gb.display.height() - YTuyaudown1;
      XTuyau1 = XTuyau2 + DistEntreTuyaux;
    }

    // Quand le deuxième tuyau sort de l'écran on le rajoute à l'arrière après le 1er tuyau à une distance de DistEntreTuyaux
    if ((XTuyau2 + 10) <= 0)
    {
      DistEntreTuyaux = random(35, gb.display.width() - 10);
      heightUp2 = random(5, 31);
      YTuyaudown2 = heightUp2 + 28;
      heightDown2 = gb.display.height() - YTuyaudown2;
      XTuyau2 = XTuyau1 + DistEntreTuyaux;
    }

    // Relancer le jeu si toucher

    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XTuyau1, YTuyaudown1, 10, heightDown1))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XTuyau1, YTuyauUp, 10, heightUp1))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XTuyau2, YTuyaudown2, 10, heightDown2))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }
    if (gb.collide.rectRect(Xbird, Ybird, Tbird, Tbird, XTuyau2, YTuyauUp, 10, heightUp2))
    {
      GameOn = 0;
      gb.sound.tone(100, 500);
    }

    /*Balle*/
    gb.display.setColor(YELLOW);
    gb.display.fillRect(Xbird, Ybird, Tbird, Tbird);

    /*Couple rectangle 1*/
    gb.display.setColor(GREEN);
    gb.display.fillRect(XTuyau1, YTuyauUp, 10, heightUp1);
    gb.display.fillRect(XTuyau1, YTuyaudown1, 10, heightDown1);

    /*Couple rectangle 2*/
    gb.display.fillRect(XTuyau2, YTuyauUp, 10, heightUp2);
    gb.display.fillRect(XTuyau2, YTuyaudown2, 10, heightDown2);

    /*Compteur*/
    gb.display.setColor(WHITE);
    gb.display.print(countPoints);
  }

  // Fonction GameOver

  else
  {
    gb.display.print("Votre score est de :");
    gb.display.println(countPoints);
    gb.display.println("");
    gb.display.println("Pressez A pour recommencer");
    if (gb.buttons.pressed(BUTTON_A))
    {
      GameOn = 1;
      countPoints = 0;
      Ybird = 32;
      XTuyau1 = DistEntreTuyaux;
      XTuyau2 = DistEntreTuyaux * 2;
    }
  }
}