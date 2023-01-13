#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <allegro.h>
#include "Escenario.h"

extern BITMAP *buffer;

class Enemigo
{
    public:
        Enemigo();
        Enemigo(unsigned int _dx, unsigned int _dy, unsigned int, Escenario *Map);

        BITMAP* enemigo;

        unsigned int dx,dy,player;
        unsigned int height = 28;
        unsigned int width = 28;

        enum Direccion{UP,RIGHT,DOWN,LEFT};
        Direccion dir;

        Escenario *M;

        void cargar_imagen_enemigo();
        void mover_enemigo();
        void pintar_enemigo();
        void direccion_aleatoria();

        unsigned int getDx();
        unsigned int getDy();
        unsigned int getDir();

        void setDx(unsigned int);
        void setDy(unsigned int);

        virtual ~Enemigo();
};

#endif // ENEMIGO_H
