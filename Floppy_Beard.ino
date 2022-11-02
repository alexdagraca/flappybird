#include <Gamebuino-Meta.h>

// Les constantes
const int Xbird = 10;
const int Tbird = 5;

// Les fonctions

// Les variables

int Ybird = 32;
int SensY = 1;

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

  Ybird = Ybird + SensY;

  // Les dessins

  gb.display.fillRect(Xbird, Ybird, Tbird, Tbird);
}
