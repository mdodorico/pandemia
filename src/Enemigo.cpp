#include "Enemigo.h"

Enemigo::Enemigo(unsigned int _dx, unsigned int _dy, unsigned int _player, Escenario *Map)
{
    player =_player;
    dx=_dx;
    dy=_dy;
    M = Map;
    dir = UP;
    cargar_imagen_enemigo();
}

void Enemigo::setDx(unsigned int _dx){dx = _dx;};
void Enemigo::setDy(unsigned int _dy){dy = _dy;};

unsigned int Enemigo::getDx(){return dx;};
unsigned int Enemigo::getDy(){return dy;};
unsigned int Enemigo::getDir(){return dir;};

void Enemigo::cargar_imagen_enemigo()
{
    enemigo = load_bitmap("virus.bmp", NULL);

    if(!enemigo)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE ENEMIGO");
    }
}

void Enemigo::pintar_enemigo()
{
    masked_blit(enemigo,buffer,dir*width,0,dx,dy,width,height);
}

void Enemigo::mover_enemigo()
{
        if((dir == UP)&&(M->mapa[(dy/10)][(dx/10)] == '.')&&(M->mapa[(dy/10)][(dx+10)/10] == '.')&&(M->mapa[(dy/10)][(dx+20)/10] == '.')&&(M->mapa[(dy/10)][(dx+28)/10] == '.'))
        {
            dy-=2;
        }
        else if((dir == DOWN)&&(M->mapa[(dy/10)+3][(dx/10)] == '.')&&(M->mapa[(dy/10)+3][(dx+10)/10] == '.')&&(M->mapa[(dy/10)+3][(dx+20)/10] == '.')&&(M->mapa[(dy/10)+3][(dx+28)/10] == '.'))
        {
            dy +=2;
        }
        else if((dir == LEFT)&&(M->mapa[(dy/10)][(dx/10)] == '.')&&(M->mapa[(dy+10)/10][dx/10] == '.')&&(M->mapa[(dy+20)/10][dx/10] == '.')&&(M->mapa[(dy+28)/10][dx/10] == '.'))
        {
             dx -=2;
        }
        else if((dir == RIGHT)&&(M->mapa[(dy/10)][(dx/10)+3] =='.')&&(M->mapa[(dy+10)/10][(dx/10)+3] =='.')&&(M->mapa[(dy+20)/10][(dx/10)+3] =='.')&&(M->mapa[(dy+28)/10][(dx/10)+3] =='.'))
        {
             dx +=2;
        }
        else
        {
            direccion_aleatoria();
        }
}

void Enemigo::direccion_aleatoria()
{
    unsigned int d = 1 +rand()%(4-0);
    switch(d)
    {
        case 4: dir = DOWN; break;
        case 3: dir = LEFT; break;
        case 1: dir = RIGHT; break;
        case 2: dir = UP; break;
    }
}

Enemigo::~Enemigo()
{
    destroy_bitmap(enemigo);
}
