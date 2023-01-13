#ifndef JUGADOR_H
#define JUGADOR_H

#include <allegro.h>
#include "Escenario.h"

extern BITMAP *buffer;

class Jugador
{
   public:
       Jugador();
       Jugador(unsigned int _dx, unsigned int _dy, unsigned int, Escenario *Map);

       BITMAP* personaje;

       unsigned int dx,dy,player;
       unsigned int height = 61;
       unsigned int width = 47;

       enum Direccion{UP,RIGHT,DOWN,LEFT};
       Direccion dir;

       Escenario *M;

       void pintar_jugador();
       void mover_jugador();
       void cargar_imagen();

       unsigned int getDx();
       unsigned int getDy();
       unsigned int getPlayer();
       unsigned int getDir();

       void setDx(unsigned int);
       void setDy(unsigned int);
       void setPlayer(unsigned int);

       virtual ~Jugador();
};

#endif // JUGADOR_H
