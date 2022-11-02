#include <Gamebuino-Meta.h>

void setup()
{
  gb.begin();
}

void loop()
{
  while (!gb.update())
    ;
  gb.display.clear();
}
// Les constantes
const int Xbird = 10;
const int Tbird = 5;
// Les fonctions

// Les variables

int Ybird = 32;

// Les dessins

gb.display.fillrect(Xbird, Ybird, Tbird, Tbird)