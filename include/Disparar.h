#ifndef DISPARAR_H
#define DISPARAR_H

#include <allegro.h>
#include "Jugador.h"
#include "Enemigo.h"
#include "Escenario.h"

extern BITMAP *buffer;

class Disparar
{
    public:
        Disparar();
        Disparar(int _dx, int _dy, int _dir, Jugador * _j, Enemigo* _e, Escenario*_M);

        BITMAP *bala_jugador;
        BITMAP *bala_enemigo;

        int x, y, dx, dy, dir;
        int width = 10;
        int height = 10;

        enum Direccion{UP,RIGHT,DOWN,LEFT};

        Escenario *M;
        Jugador *J;
        Enemigo *E;

        int getX();
        int getY();
        int j = 0;

        void cargar_imagen_disparos();
        void pintar_disparo();
        void mover_disparo_jugador();
        void mover_disparo_enemigo();
        bool colision_pared();
        bool colision_enemigo(Enemigo *_E);
        bool colision_jugador(Jugador *J);

        virtual ~Disparar();
};

#endif // DISPARAR_H
