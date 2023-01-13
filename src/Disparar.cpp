#include "Disparar.h"

Disparar::Disparar(int _dx, int _dy, int _dir, Jugador* _j, Enemigo* _e, Escenario*_M)
{
    dx=_dx;
    dy=_dy;
    dir=_dir;
    M = _M;
    J = _j;
    E = _e;
    cargar_imagen_disparos();
}

int Disparar::getX(){return dx;};
int Disparar::getY(){return dy;};

void Disparar::cargar_imagen_disparos()
{
    bala_jugador = load_bitmap("bala_jugador.bmp", NULL);
    bala_enemigo = load_bitmap("bala_enemigo.bmp", NULL);

    if(!bala_jugador)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE DISPARO JUGADOR");
    }
    else if(!bala_enemigo)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE DISPARO ENEMIGO");
    }
}

void Disparar::pintar_disparo()
{
    masked_blit(bala_jugador,buffer,0,0,dx,dy,width,height);
    masked_blit(bala_enemigo,buffer,0,0,dx,dy,width,height);
}

void Disparar::mover_disparo_jugador()
{
        if(dir == UP)
        {
            dy-=12;
            masked_blit(bala_jugador,buffer,0,0,dx+11,dy,width,height);
        }
        if(dir == RIGHT)
        {
            dx+=15;
            masked_blit(bala_jugador,buffer,0,0,dx+15,dy+11,width,height);
        }
        if(dir == DOWN)
        {
            dy+=15;
            masked_blit(bala_jugador,buffer,0,0,dx+13,dy+20,width,height);
        }
        if(dir == LEFT)
        {
            dx-=15;
            masked_blit(bala_jugador,buffer,0,0,dx+5,dy+11,width,height);
        }
}

void Disparar::mover_disparo_enemigo()
{
        if(dir == UP)
        {
            dy-=12;
            masked_blit(bala_enemigo,buffer,0,0,dx+11,dy,width,height);
        }
        if(dir == RIGHT)
        {
            dx+=15;
            masked_blit(bala_enemigo,buffer,0,0,dx+15,dy+11,width,height);
        }
        if(dir == DOWN)
        {
            dy+=15;
            masked_blit(bala_enemigo,buffer,0,0,dx+13,dy+20,width,height);
        }
        if(dir == LEFT)
        {
            dx-=15;
            masked_blit(bala_enemigo,buffer,0,0,dx+5,dy+11,width,height);
        }
}

bool Disparar::colision_pared()
{
    if (dir == UP)
    {
        if((M->mapa[(dy/10)][(dx/10)] != '.')||
           (M->mapa[(dy/10)][(dx+10)/10] != '.')||
           (M->mapa[(dy/10)][(dx+20)/10] != '.')||
           (M->mapa[(dy/10)][(dx+3)/10] != '.'))
           {
              if((M->mapa[(dy/10)][((dx+10)/10)] == 'P'))
              {
                  M->mapa[(dy/10)][((dx+10)/10)] == 'P';
              }
              return true;
           }
    }

    else if(dir == DOWN)
    {
        if((M->mapa[(dy/10)+3][(dx/10)] != '.')||
           (M->mapa[(dy/10)+3][(dx+10)/10] != '.')||
           (M->mapa[(dy/10)+3][(dx+20)/10] != '.')||
           (M->mapa[(dy/10)+3][(dx+28)/10] != '.'))
           {
              if((M->mapa[(dy/10)][((dx+10)/10)] == 'P'))
              {
                  M->mapa[(dy/10)][((dx+10)/10)] == 'P';
              }
              return true;
           }
    }

    else if(dir == LEFT)
    {
        if((M->mapa[(dy/10)][(dx/10)] != '.')||
           (M->mapa[(dy+10)/10][dx/10] != '.')||
           (M->mapa[(dy+20)/10][dx/10] != '.')||
           (M->mapa[(dy+28)/10][dx/10] != '.'))
           {
              if((M->mapa[(dy/10)][((dx+10)/10)] == 'P'))
              {
                  M->mapa[(dy/10)][((dx+10)/10)] == 'P';
              }
              return true;
           }
    }

    else if(dir == RIGHT)
    {
        if((M->mapa[(dy/10)][(dx/10)+3] !='.')||
           (M->mapa[(dy+10)/10][(dx/10)+3] !='.')||
           (M->mapa[(dy+20)/10][(dx/10)+3] !='.')||
           (M->mapa[(dy+28)/10][(dx/10)+3] !='.'))
           {
              if((M->mapa[(dy/10)][((dx+10)/10)] == 'P'))
              {
                  M->mapa[(dy/10)][((dx+10)/10)] == 'P';
              }
              return true;
           }
    }
    return false;
}

bool Disparar::colision_enemigo(Enemigo *E)
{
    unsigned int p1 = 1 + rand()%450;
    unsigned int p2 = 1 + rand()%450;

    if((E->getDx()<dx+10) && (dx<E->getDx()+30) && (E->getDy()<dy+10) && (dy<E->getDy()+30))
    {
        if(J->getPlayer() == 2)
        {
                E->setDx(p1);
                E->setDy(p2);
                E->direccion_aleatoria();
        }
        else
        {
                E->setDx(p1);
                E->setDy(p2);
        }
        return true;
    }
    return false;
}

bool Disparar::colision_jugador(Jugador *J)
{
    if((J->getDx()<dx+10) && (dx<J->getDx()+30) && (J->getDy()<dy+10) && (dy<J->getDy()+30))
    {
        if(J->getPlayer() == 1)
        {
                J->setDx(280);
                J->setDy(445);
        }
        return true;
    }
    return false;
}

Disparar::~Disparar()
{
   destroy_bitmap(bala_jugador);
   destroy_bitmap(bala_enemigo);
}
