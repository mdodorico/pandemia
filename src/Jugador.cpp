#include "Jugador.h"

Jugador::Jugador(unsigned int _dx, unsigned int _dy, unsigned int _player, Escenario *Map)
{
    player =_player;
    dx=_dx;
    dy=_dy;
    M = Map;
    dir = UP;
    cargar_imagen();
}

void Jugador::setDx(unsigned int _dx){ dx = _dx;};
void Jugador::setDy(unsigned int _dy){ dy = _dy;};
void Jugador::setPlayer(unsigned int _player){ player = _player;};

unsigned int Jugador::getDx(){return  dx;};
unsigned int Jugador::getDy(){return dy;};
unsigned int Jugador::getDir(){return dir;};
unsigned int Jugador::getPlayer(){return player;};

void Jugador::cargar_imagen()
{
    personaje = load_bitmap("jugador.bmp", NULL);

    if(!personaje)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE JUGADOR");
    }
}

void Jugador::pintar_jugador()
{
    masked_blit(personaje,buffer,dir*width,0,dx,dy,width,height);
}

void Jugador::mover_jugador()
{
        if(key[KEY_UP])
        {
            dir = UP;
            if((M->mapa[(dy/10)][(dx/10)] == '.')&&(M->mapa[(dy/10)][(dx+10)/10] == '.')&&(M->mapa[(dy/10)][(dx+20)/10] == '.')&&(M->mapa[(dy/10)][(dx+28)/10] == '.'))
            {
                    dy-=2;
            }
        }
        if(key[KEY_DOWN])
        {
            dir = DOWN;
            if((M->mapa[(dy/10)+3][(dx/10)] == '.')&&(M->mapa[(dy/10)+3][(dx+10)/10] == '.')&&(M->mapa[(dy/10)+3][(dx+20)/10] == '.')&&(M->mapa[(dy/10)+3][(dx+28)/10] == '.'))
            {
                    dy +=2;
            }
        }
        if(key[KEY_LEFT])
        {
            dir = LEFT;
            if((M->mapa[(dy/10)][(dx/10)] == '.')&&(M->mapa[(dy+10)/10][dx/10] == '.')&&(M->mapa[(dy+20)/10][dx/10] == '.')&&(M->mapa[(dy+28)/10][dx/10] == '.'))
            {
                     dx -=2;
            }
        }
        if(key[KEY_RIGHT])
        {
            dir = RIGHT;
            if((M->mapa[(dy/10)][(dx/10)+3] =='.')&&(M->mapa[(dy+10)/10][(dx/10)+3] =='.')&&(M->mapa[(dy+20)/10][(dx/10)+3] =='.')&&(M->mapa[(dy+28)/10][(dx/10)+3] =='.'))
            {
              dx +=2;
            }
        }
        rest(6);
}

Jugador::~Jugador()
{
    destroy_bitmap(personaje);
}
