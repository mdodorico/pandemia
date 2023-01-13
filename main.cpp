#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <list>
#include <allegro.h>

#include "Iniciar.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Disparar.h"
#include "Escenario.h"
#include "Menu.h"
#include "Sonido.h"

#define PANTALLA_ANCHO 700
#define PANTALLA_ALTO 500

using namespace std;

char mapa[50][50];

BITMAP *buffer;
BITMAP *buffer2;

/******** CARGAR PRIMER ESCENARIO *********/
void crear_primer_escenario(Escenario *m) //DETERMINA EL MAPA A DIBUJAR
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario1.txt",ios::in);

   if(archivo_mapa.fail())
   {
     cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DEL MAPA";
     exit(-1);
   }

   for(unsigned int i=0; i<50; i++)
   {
      for(unsigned int j=0; j<50-2; j++)
      {
         archivo_mapa>>mapa[i][j];
         m->mapa[i][j] = mapa[i][j];
      }
   }
   archivo_mapa.close();
}

/******** CARGAR SEGUNDO ESCENARIO ********/
void crear_segundo_escenario(Escenario *m)
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario2.txt",ios::in);

   if(archivo_mapa.fail())
   {
     cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DEL MAPA";
     exit(-1);
   }

   for(unsigned int i=0; i<50; i++)
   {
      for(unsigned int j=0; j<50-2; j++)
      {
         archivo_mapa>>mapa[i][j];
         m->mapa[i][j] = mapa[i][j];
      }
   }
   archivo_mapa.close();
}

/******** CARGAR TERCER ESCENARIO ********/
void crear_tercer_escenario(Escenario *m)
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario3.txt",ios::in);

   if(archivo_mapa.fail())
   {
     cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DEL MAPA";
     exit(-1);
   }

   for(unsigned int i=0; i<50; i++)
   {
      for(unsigned int j=0; j<50-2; j++)
      {
         archivo_mapa>>mapa[i][j];
         m->mapa[i][j] = mapa[i][j];
      }
   }
   archivo_mapa.close();
}

/******** CARGAR CUARTO ESCENARIO ********/
void crear_cuarto_escenario(Escenario *m)
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario4.txt",ios::in);

   if(archivo_mapa.fail())
   {
     cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DEL MAPA";
     exit(-1);
   }

   for(unsigned int i=0; i<50; i++)
   {
      for(unsigned int j=0; j<50-2; j++)
      {
         archivo_mapa>>mapa[i][j];
         m->mapa[i][j] = mapa[i][j];
      }
   }
   archivo_mapa.close();
}

/******** CARGAR QUINTO ESCENARIO ********/
void crear_quinto_escenario(Escenario *m)
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario5.txt",ios::in);

   if(archivo_mapa.fail())
   {
     cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DEL MAPA";
     exit(-1);
   }

   for(unsigned int i=0; i<50; i++)
   {
      for(unsigned int j=0; j<50-2; j++)
      {
         archivo_mapa>>mapa[i][j];
         m->mapa[i][j] = mapa[i][j];
      }
   }
   archivo_mapa.close();
}

/******** CARGAR SEXTO ESCENARIO ********/
void crear_sexto_escenario(Escenario *m)
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario6.txt",ios::in);

   if(archivo_mapa.fail())
   {
     cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DEL MAPA";
     exit(-1);
   }

   for(unsigned int i=0; i<50; i++)
   {
      for(unsigned int j=0; j<50-2; j++)
      {
         archivo_mapa>>mapa[i][j];
         m->mapa[i][j] = mapa[i][j];
      }
   }
   archivo_mapa.close();
}

/******** CARGAR LA PANTALLA ********/
void crear_pantalla()
{
    blit(buffer,screen,0,0,0,0,PANTALLA_ANCHO,PANTALLA_ALTO);
}

int main()
{
    inicia_allegro(PANTALLA_ANCHO,PANTALLA_ALTO);
	inicia_audio();

    list<Disparar *> DiJu;
    list<Disparar *>::iterator itJu;

    list<Disparar *> DiEne;
    list<Disparar *>::iterator itEne;

    buffer = create_bitmap(PANTALLA_ANCHO,PANTALLA_ALTO);
    buffer2 = create_bitmap(700,500);

    Menu I;
    I.empezar();
    I.pintar_menu();

    Escenario M;
    crear_primer_escenario(&M);

    Sonido S;
    S.musica_fondo();

    Jugador J(280,445,1,&M);

    Enemigo E1(400,30,2,&M);
    Enemigo E2(100,460,2,&M);
    Enemigo E3(200,140,2,&M);
    Enemigo E4(300,250,2,&M);
    Enemigo E5(50,320,2,&M);
    Enemigo E6(150,390,2,&M);
    Enemigo E7(95,130,2,&M);
    Enemigo E8(140,300,2,&M);
    Enemigo E9(290,310,2,&M);
    Enemigo E10(420,150,2,&M);
    Enemigo E11(350,80,2,&M);

    while(!key[KEY_ESC] && I.salir==false)
    {
            clear_to_color( buffer, 0x000000);

    /******** CONDICIÓN PARA TERMINAR EL JUEGO ********/
            if(I.vida == 0)
            {
                S.detener_sonidos();
                allegro_message("GAME OVER.\nSU PUNTAJE: %d", I.punto);
                exit(0);
            }

    /***************************************************/
    /****************** NIVEL 1 ***********************/
    /**************************************************/
            I.puntuacion();
            M.cargar_primer_escenario();

            J.pintar_jugador();
            E1.pintar_enemigo();
            E2.pintar_enemigo();
            E3.pintar_enemigo();
            E4.pintar_enemigo();
            E5.pintar_enemigo();
            E6.pintar_enemigo();

            if(key[KEY_A])
            {
                DiJu.push_back(new Disparar(J.getDx(), J.getDy(),J.getDir(),&J,&E1,&M));
                S.sonido_disparo();
            }

    /******** DISPAROS JUGADOR: SUMAR PUNTOS NIVEL 1 ********/
            for(itJu=DiJu.begin();itJu!=DiJu.end();)
            {
                (*itJu)->mover_disparo_jugador();

                if((*itJu)->colision_enemigo(&E1) ||
                   (*itJu)->colision_enemigo(&E2) ||
                   (*itJu)->colision_enemigo(&E3) ||
                   (*itJu)->colision_enemigo(&E4) ||
                   (*itJu)->colision_enemigo(&E5) ||
                   (*itJu)->colision_enemigo(&E6))
                {
                        I.punto+=25;
                        S.sonido_puntos();
                        delete(*itJu);
                        itJu=DiJu.erase(itJu);
                }
                else if((*itJu)->colision_pared())
                {
                        delete(*itJu);
                        itJu=DiJu.erase(itJu);
                }
                else
                {
                   itJu++;
                }
            }

    /******** DISPAROS ENEMIGOS: QUITAR VIDAS NIVEL 1 ********/
            for (itEne=DiEne.begin(); itEne!=DiEne.end();)
            {
                (*itEne)->mover_disparo_enemigo();

                if((*itEne)->colision_jugador(&J))
                {
                    I.vida-=1;
                    S.sonido_quitar_vida();
                    delete(*itEne);
                    itEne=DiEne.erase(itEne);
                }
                else if((*itEne)->colision_pared())
                {
                    delete(*itEne);
                    itEne= DiEne.erase(itEne);
                }
                else
                {
                    itEne++;
                }
            }

    /******** CANTIDAD DE DISPAROS NIVEL 1 ********/
            unsigned int disparos = 1 + rand()%60;

            if(disparos == 1)
            {
                DiEne.push_back(new Disparar(E1.getDx(), E1.getDy(),E1.getDir(),&J,&E1,&M));
            }
            if(disparos == 10)
            {
                 DiEne.push_back(new Disparar(E2.getDx(), E2.getDy(),E2.getDir(),&J,&E2,&M));
            }
            if(disparos == 20)
            {
                 DiEne.push_back(new Disparar(E3.getDx(), E3.getDy(),E3.getDir(),&J,&E3,&M));
            }
            if(disparos == 30)
            {
                 DiEne.push_back(new Disparar(E4.getDx(), E4.getDy(),E4.getDir(),&J,&E4,&M));
            }
            if(disparos == 40)
            {
                 DiEne.push_back(new Disparar(E5.getDx(), E5.getDy(),E5.getDir(),&J,&E5,&M));
            }
            if(disparos == 50)
            {
                 DiEne.push_back(new Disparar(E6.getDx(), E6.getDy(),E6.getDir(),&J,&E6,&M));
            }

            J.mover_jugador();
            E1.mover_enemigo();
            E2.mover_enemigo();
            E3.mover_enemigo();
            E4.mover_enemigo();
            E5.mover_enemigo();
            E6.mover_enemigo();


    /***************************************************/
    /****************** NIVEL 2 ***********************/
    /**************************************************/
            if(I.punto >= 100 && I.punto <= 199)
            {
                I.puntuacion();
                crear_segundo_escenario(&M);
                M.cargar_segundo_escenario();

                J.pintar_jugador();
                E1.pintar_enemigo();
                E2.pintar_enemigo();
                E3.pintar_enemigo();
                E4.pintar_enemigo();
                E5.pintar_enemigo();
                E6.pintar_enemigo();
                E7.pintar_enemigo();

                if(key[KEY_A])
                {
                   DiJu.push_back(new Disparar(J.getDx(), J.getDy(),J.getDir(),&J,&E1,&M));
                   S.sonido_disparo();
                }

    /******** DISPAROS JUGADOR: SUMAR PUNTOS NIVEL 2 ********/
                for(itJu=DiJu.begin();itJu!=DiJu.end();)
                {
                    (*itJu)->mover_disparo_jugador();

                    if((*itJu)->colision_enemigo(&E1) ||
                       (*itJu)->colision_enemigo(&E2) ||
                       (*itJu)->colision_enemigo(&E3) ||
                       (*itJu)->colision_enemigo(&E4) ||
                       (*itJu)->colision_enemigo(&E5) ||
                       (*itJu)->colision_enemigo(&E6) ||
                       (*itJu)->colision_enemigo(&E7))
                       {
                           I.punto+=25;
                           S.sonido_puntos();
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else if((*itJu)->colision_pared())
                       {
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else
                       {
                          itJu++;
                       }
                }

    /******** DISPAROS ENEMIGOS: QUITAR VIDAS NIVEL 2 ********/
                for (itEne=DiEne.begin(); itEne!=DiEne.end();)
                {
                    (*itEne)->mover_disparo_enemigo();

                    if((*itEne)->colision_jugador(&J))
                    {
                       I.vida-=1;
                       S.sonido_quitar_vida();
                       delete(*itEne);
                       itEne=DiEne.erase(itEne);
                    }
                    else if((*itEne)->colision_pared())
                    {
                       delete(*itEne);
                       itEne= DiEne.erase(itEne);
                    }
                    else
                    {
                       itEne++;
                    }
                }

    /******** CANTIDAD DE DISPAROS NIVEL 2 ********/
                unsigned int disparos = 1 + rand()%80;

                if(disparos >= 1 && disparos <=19 )
                {
                    DiEne.push_back(new Disparar(E1.getDx(), E1.getDy(),E1.getDir(),&J,&E1,&M));
                }
                if(disparos >= 20 && disparos <=25)
                {
                    DiEne.push_back(new Disparar(E2.getDx(), E2.getDy(),E2.getDir(),&J,&E2,&M));
                }
                if(disparos >= 30 && disparos <=35)
                {
                    DiEne.push_back(new Disparar(E3.getDx(), E3.getDy(),E3.getDir(),&J,&E3,&M));
                }
                if(disparos >= 40 && disparos <=45)
                {
                    DiEne.push_back(new Disparar(E4.getDx(), E4.getDy(),E4.getDir(),&J,&E4,&M));
                }
                if(disparos >= 50 && disparos <=55)
                {
                    DiEne.push_back(new Disparar(E5.getDx(), E5.getDy(),E5.getDir(),&J,&E5,&M));
                }
                if(disparos >= 60 && disparos <=65)
                {
                    DiEne.push_back(new Disparar(E6.getDx(), E6.getDy(),E6.getDir(),&J,&E6,&M));
                }
                if(disparos >= 70 && disparos <=75)
                {
                    DiEne.push_back(new Disparar(E7.getDx(), E7.getDy(),E7.getDir(),&J,&E7,&M));
                }

                J.mover_jugador();
                E1.mover_enemigo();
                E2.mover_enemigo();
                E3.mover_enemigo();
                E4.mover_enemigo();
                E5.mover_enemigo();
                E6.mover_enemigo();
                E7.mover_enemigo();
            }

    /***************************************************/
    /****************** NIVEL 3 ***********************/
    /**************************************************/
            else if(I.punto >= 200 && I.punto <= 299)
            {
                I.puntuacion();
                crear_tercer_escenario(&M);
                M.cargar_tercer_escenario();

                J.pintar_jugador();
                E1.pintar_enemigo();
                E2.pintar_enemigo();
                E3.pintar_enemigo();
                E4.pintar_enemigo();
                E5.pintar_enemigo();
                E6.pintar_enemigo();
                E7.pintar_enemigo();
                E8.pintar_enemigo();

                if(key[KEY_A])
                {
                   DiJu.push_back(new Disparar(J.getDx(), J.getDy(),J.getDir(),&J,&E1,&M));
                   S.sonido_disparo();
                }

    /******** DISPAROS JUGADOR: SUMAR PUNTOS NIVEL 3 ********/
                for(itJu=DiJu.begin();itJu!=DiJu.end();)
                {
                    (*itJu)->mover_disparo_jugador();

                    if((*itJu)->colision_enemigo(&E1) ||
                       (*itJu)->colision_enemigo(&E2) ||
                       (*itJu)->colision_enemigo(&E3) ||
                       (*itJu)->colision_enemigo(&E4) ||
                       (*itJu)->colision_enemigo(&E5) ||
                       (*itJu)->colision_enemigo(&E6) ||
                       (*itJu)->colision_enemigo(&E7) ||
                       (*itJu)->colision_enemigo(&E8)
                       )
                       {
                           I.punto+=25;
                           S.sonido_puntos();
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else if((*itJu)->colision_pared())
                       {
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else
                       {
                          itJu++;
                       }
                }

    /******** DISPAROS ENEMIGOS: QUITAR VIDAS NIVEL 3 ********/
                for (itEne=DiEne.begin(); itEne!=DiEne.end();)
                {
                    (*itEne)->mover_disparo_enemigo();

                    if((*itEne)->colision_jugador(&J))
                    {
                       I.vida-=1;
                       S.sonido_quitar_vida();
                       delete(*itEne);
                       itEne=DiEne.erase(itEne);
                    }
                    else if((*itEne)->colision_pared())
                    {
                       delete(*itEne);
                       itEne= DiEne.erase(itEne);
                    }
                    else
                    {
                       itEne++;
                    }
                }

    /******** CANTIDAD DE DISPAROS NIVEL 3 ********/
                unsigned int disparos = 1 + rand()%100;

                if(disparos >= 1 && disparos <= 29)
                {
                    DiEne.push_back(new Disparar(E1.getDx(), E1.getDy(),E1.getDir(),&J,&E1,&M));
                }
                if(disparos >= 30 && disparos <= 37)
                {
                    DiEne.push_back(new Disparar(E2.getDx(), E2.getDy(),E2.getDir(),&J,&E2,&M));
                }
                if(disparos >= 40 && disparos <= 47)
                {
                    DiEne.push_back(new Disparar(E3.getDx(), E3.getDy(),E3.getDir(),&J,&E3,&M));
                }
                if(disparos >= 50 && disparos <= 57)
                {
                    DiEne.push_back(new Disparar(E4.getDx(), E4.getDy(),E4.getDir(),&J,&E4,&M));
                }
                if(disparos >= 60 && disparos <= 67)
                {
                    DiEne.push_back(new Disparar(E5.getDx(), E5.getDy(),E5.getDir(),&J,&E5,&M));
                }
                if(disparos >= 70 && disparos <= 77)
                {
                    DiEne.push_back(new Disparar(E6.getDx(), E6.getDy(),E6.getDir(),&J,&E6,&M));
                }
                if(disparos >= 80 && disparos <= 87)
                {
                    DiEne.push_back(new Disparar(E7.getDx(), E7.getDy(),E7.getDir(),&J,&E7,&M));
                }
                if(disparos >= 90 && disparos <= 97)
                {
                    DiEne.push_back(new Disparar(E8.getDx(), E8.getDy(),E8.getDir(),&J,&E8,&M));
                }

                J.mover_jugador();
                E1.mover_enemigo();
                E2.mover_enemigo();
                E3.mover_enemigo();
                E4.mover_enemigo();
                E5.mover_enemigo();
                E6.mover_enemigo();
                E7.mover_enemigo();
                E8.mover_enemigo();
            }

    /***************************************************/
    /****************** NIVEL 4 ***********************/
    /**************************************************/
            if(I.punto >= 300 && I.punto <= 399)
            {
                I.puntuacion();
                crear_cuarto_escenario(&M);
                M.cargar_cuarto_escenario();

                J.pintar_jugador();
                E1.pintar_enemigo();
                E2.pintar_enemigo();
                E3.pintar_enemigo();
                E4.pintar_enemigo();
                E5.pintar_enemigo();
                E6.pintar_enemigo();
                E7.pintar_enemigo();
                E8.pintar_enemigo();
                E9.pintar_enemigo();

                if(key[KEY_A])
                {
                   DiJu.push_back(new Disparar(J.getDx(), J.getDy(),J.getDir(),&J,&E1,&M));
                   S.sonido_disparo();
                }

    /******** DISPAROS JUGADOR: SUMAR PUNTOS NIVEL 4 ********/
                for(itJu=DiJu.begin();itJu!=DiJu.end();)
                {
                    (*itJu)->mover_disparo_jugador();

                    if((*itJu)->colision_enemigo(&E1) ||
                       (*itJu)->colision_enemigo(&E2) ||
                       (*itJu)->colision_enemigo(&E3) ||
                       (*itJu)->colision_enemigo(&E4) ||
                       (*itJu)->colision_enemigo(&E5) ||
                       (*itJu)->colision_enemigo(&E6) ||
                       (*itJu)->colision_enemigo(&E7) ||
                       (*itJu)->colision_enemigo(&E8) ||
                       (*itJu)->colision_enemigo(&E9))
                       {
                           I.punto+=25;
                           S.sonido_puntos();
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else if((*itJu)->colision_pared())
                       {
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else
                       {
                          itJu++;
                       }
                }

    /******** DISPAROS ENEMIGOS: QUITAR VIDAS NIVEL 4 ********/
                for (itEne=DiEne.begin(); itEne!=DiEne.end();)
                {
                    (*itEne)->mover_disparo_enemigo();

                    if((*itEne)->colision_jugador(&J))
                    {
                       I.vida-=1;
                       S.sonido_quitar_vida();
                       delete(*itEne);
                       itEne=DiEne.erase(itEne);
                    }
                    else if((*itEne)->colision_pared())
                    {
                       delete(*itEne);
                       itEne= DiEne.erase(itEne);
                    }
                    else
                    {
                       itEne++;
                    }
                }

    /******** CANTIDAD DE DISPAROS NIVEL 4 ********/
                unsigned int disparos = 1 + rand()%120;

                if(disparos >= 1 && disparos <= 39 )
                {
                    DiEne.push_back(new Disparar(E1.getDx(), E1.getDy(),E1.getDir(),&J,&E1,&M));
                }
                if(disparos >= 40 && disparos <= 49)
                {
                    DiEne.push_back(new Disparar(E2.getDx(), E2.getDy(),E2.getDir(),&J,&E2,&M));
                }
                if(disparos >= 50 && disparos <= 59)
                {
                    DiEne.push_back(new Disparar(E3.getDx(), E3.getDy(),E3.getDir(),&J,&E3,&M));
                }
                if(disparos >= 60 && disparos <= 69)
                {
                    DiEne.push_back(new Disparar(E4.getDx(), E4.getDy(),E4.getDir(),&J,&E4,&M));
                }
                if(disparos >= 70 && disparos <= 79)
                {
                    DiEne.push_back(new Disparar(E5.getDx(), E5.getDy(),E5.getDir(),&J,&E5,&M));
                }
                if(disparos >= 80 && disparos <= 89)
                {
                    DiEne.push_back(new Disparar(E6.getDx(), E6.getDy(),E6.getDir(),&J,&E6,&M));
                }
                if(disparos >= 90 && disparos <= 99)
                {
                    DiEne.push_back(new Disparar(E7.getDx(), E7.getDy(),E7.getDir(),&J,&E7,&M));
                }
                if(disparos >= 100 && disparos <= 109)
                {
                    DiEne.push_back(new Disparar(E8.getDx(), E8.getDy(),E8.getDir(),&J,&E8,&M));
                }
                if(disparos >= 110 && disparos <= 119)
                {
                    DiEne.push_back(new Disparar(E9.getDx(), E9.getDy(),E9.getDir(),&J,&E9,&M));
                }
                J.mover_jugador();
                E1.mover_enemigo();
                E2.mover_enemigo();
                E3.mover_enemigo();
                E4.mover_enemigo();
                E5.mover_enemigo();
                E6.mover_enemigo();
                E7.mover_enemigo();
                E8.mover_enemigo();
                E9.mover_enemigo();
            }

    /***************************************************/
    /****************** NIVEL 5 ***********************/
    /**************************************************/
            if(I.punto >= 400 && I.punto <= 499)
            {
                I.puntuacion();
                crear_quinto_escenario(&M);
                M.cargar_quinto_escenario();

                J.pintar_jugador();
                E1.pintar_enemigo();
                E2.pintar_enemigo();
                E3.pintar_enemigo();
                E4.pintar_enemigo();
                E5.pintar_enemigo();
                E6.pintar_enemigo();
                E7.pintar_enemigo();
                E8.pintar_enemigo();
                E9.pintar_enemigo();
                E10.pintar_enemigo();

                if(key[KEY_A])
                {
                   DiJu.push_back(new Disparar(J.getDx(), J.getDy(),J.getDir(),&J,&E1,&M));
                   S.sonido_disparo();
                }

    /******** DISPAROS JUGADOR: SUMAR PUNTOS NIVEL 5 ********/
                for(itJu=DiJu.begin();itJu!=DiJu.end();)
                {
                    (*itJu)->mover_disparo_jugador();

                    if((*itJu)->colision_enemigo(&E1) ||
                       (*itJu)->colision_enemigo(&E2) ||
                       (*itJu)->colision_enemigo(&E3) ||
                       (*itJu)->colision_enemigo(&E4) ||
                       (*itJu)->colision_enemigo(&E5) ||
                       (*itJu)->colision_enemigo(&E6) ||
                       (*itJu)->colision_enemigo(&E7) ||
                       (*itJu)->colision_enemigo(&E8) ||
                       (*itJu)->colision_enemigo(&E9) ||
                       (*itJu)->colision_enemigo(&E10))
                       {
                           I.punto+=25;
                           S.sonido_puntos();
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else if((*itJu)->colision_pared())
                       {
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else
                       {
                          itJu++;
                       }
                }

    /******** DISPAROS ENEMIGOS: QUITAR VIDAS NIVEL 5 ********/
                for (itEne=DiEne.begin(); itEne!=DiEne.end();)
                {
                    (*itEne)->mover_disparo_enemigo();

                    if((*itEne)->colision_jugador(&J))
                    {
                       I.vida-=1;
                       S.sonido_quitar_vida();
                       delete(*itEne);
                       itEne=DiEne.erase(itEne);
                    }
                    else if((*itEne)->colision_pared())
                    {
                       delete(*itEne);
                       itEne= DiEne.erase(itEne);
                    }
                    else
                    {
                       itEne++;
                    }
                }

    /******** CANTIDAD DE DISPAROS NIVEL 5 ********/
                unsigned int disparos = 1 + rand()%140;

                if(disparos >= 1 && disparos <= 49 )
                {
                    DiEne.push_back(new Disparar(E1.getDx(), E1.getDy(),E1.getDir(),&J,&E1,&M));
                }
                if(disparos >= 50 && disparos <= 59)
                {
                    DiEne.push_back(new Disparar(E2.getDx(), E2.getDy(),E2.getDir(),&J,&E2,&M));
                }
                if(disparos >= 60 && disparos <= 69)
                {
                    DiEne.push_back(new Disparar(E3.getDx(), E3.getDy(),E3.getDir(),&J,&E3,&M));
                }
                if(disparos >= 70 && disparos <= 79)
                {
                    DiEne.push_back(new Disparar(E4.getDx(), E4.getDy(),E4.getDir(),&J,&E4,&M));
                }
                if(disparos >= 80 && disparos <= 89)
                {
                    DiEne.push_back(new Disparar(E5.getDx(), E5.getDy(),E5.getDir(),&J,&E5,&M));
                }
                if(disparos >= 90 && disparos <= 99)
                {
                    DiEne.push_back(new Disparar(E6.getDx(), E6.getDy(),E6.getDir(),&J,&E6,&M));
                }
                if(disparos >= 100 && disparos <= 109)
                {
                    DiEne.push_back(new Disparar(E7.getDx(), E7.getDy(),E7.getDir(),&J,&E7,&M));
                }
                if(disparos >= 110 && disparos <= 119)
                {
                    DiEne.push_back(new Disparar(E8.getDx(), E8.getDy(),E8.getDir(),&J,&E8,&M));
                }
                if(disparos >= 120 && disparos <= 129)
                {
                    DiEne.push_back(new Disparar(E9.getDx(), E9.getDy(),E9.getDir(),&J,&E9,&M));
                }
                if(disparos >= 130 && disparos <= 139)
                {
                    DiEne.push_back(new Disparar(E10.getDx(), E10.getDy(),E10.getDir(),&J,&E10,&M));
                }

                J.mover_jugador();
                E1.mover_enemigo();
                E2.mover_enemigo();
                E3.mover_enemigo();
                E4.mover_enemigo();
                E5.mover_enemigo();
                E6.mover_enemigo();
                E7.mover_enemigo();
                E8.mover_enemigo();
                E9.mover_enemigo();
                E10.mover_enemigo();
            }

    /***************************************************/
    /****************** NIVEL 6 ***********************/
    /**************************************************/
            if(I.punto >= 500 && I.punto <= 599)
            {
                I.puntuacion();
                crear_sexto_escenario(&M);
                M.cargar_sexto_escenario();

                J.pintar_jugador();
                E1.pintar_enemigo();
                E2.pintar_enemigo();
                E3.pintar_enemigo();
                E4.pintar_enemigo();
                E5.pintar_enemigo();
                E6.pintar_enemigo();
                E7.pintar_enemigo();
                E8.pintar_enemigo();
                E9.pintar_enemigo();
                E10.pintar_enemigo();
                E11.pintar_enemigo();

                if(key[KEY_A])
                {
                   DiJu.push_back(new Disparar(J.getDx(), J.getDy(),J.getDir(),&J,&E1,&M));
                   S.sonido_disparo();
                }

    /******** DISPAROS JUGADOR: SUMAR PUNTOS NIVEL 6 ********/
                for(itJu=DiJu.begin();itJu!=DiJu.end();)
                {
                    (*itJu)->mover_disparo_jugador();

                    if((*itJu)->colision_enemigo(&E1) ||
                       (*itJu)->colision_enemigo(&E2) ||
                       (*itJu)->colision_enemigo(&E3) ||
                       (*itJu)->colision_enemigo(&E4) ||
                       (*itJu)->colision_enemigo(&E5) ||
                       (*itJu)->colision_enemigo(&E6) ||
                       (*itJu)->colision_enemigo(&E7) ||
                       (*itJu)->colision_enemigo(&E8) ||
                       (*itJu)->colision_enemigo(&E9) ||
                       (*itJu)->colision_enemigo(&E10) ||
                       (*itJu)->colision_enemigo(&E11))
                       {
                           I.punto+=25;
                           S.sonido_puntos();
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else if((*itJu)->colision_pared())
                       {
                           delete(*itJu);
                           itJu=DiJu.erase(itJu);
                       }
                       else
                       {
                          itJu++;
                       }
                }

    /******** DISPAROS ENEMIGOS: QUITAR VIDAS NIVEL 6 ********/
                for (itEne=DiEne.begin(); itEne!=DiEne.end();)
                {
                    (*itEne)->mover_disparo_enemigo();

                    if((*itEne)->colision_jugador(&J))
                    {
                       I.vida-=1;
                       S.sonido_quitar_vida();
                       delete(*itEne);
                       itEne=DiEne.erase(itEne);
                    }
                    else if((*itEne)->colision_pared())
                    {
                       delete(*itEne);
                       itEne= DiEne.erase(itEne);
                    }
                    else
                    {
                       itEne++;
                    }
                }

    /******** CANTIDAD DE DISPAROS NIVEL 6 ********/
                unsigned int disparos = 1 + rand()%160;

                if(disparos >= 1 && disparos <= 59 )
                {
                    DiEne.push_back(new Disparar(E1.getDx(), E1.getDy(),E1.getDir(),&J,&E1,&M));
                }
                if(disparos >= 60 && disparos <= 69)
                {
                    DiEne.push_back(new Disparar(E2.getDx(), E2.getDy(),E2.getDir(),&J,&E2,&M));
                }
                if(disparos >= 70 && disparos <= 79)
                {
                    DiEne.push_back(new Disparar(E3.getDx(), E3.getDy(),E3.getDir(),&J,&E3,&M));
                }
                if(disparos >= 80 && disparos <= 89)
                {
                    DiEne.push_back(new Disparar(E4.getDx(), E4.getDy(),E4.getDir(),&J,&E4,&M));
                }
                if(disparos >= 90 && disparos <= 99)
                {
                    DiEne.push_back(new Disparar(E5.getDx(), E5.getDy(),E5.getDir(),&J,&E5,&M));
                }
                if(disparos >= 100 && disparos <= 109)
                {
                    DiEne.push_back(new Disparar(E6.getDx(), E6.getDy(),E6.getDir(),&J,&E6,&M));
                }
                if(disparos >= 110 && disparos <= 119)
                {
                    DiEne.push_back(new Disparar(E7.getDx(), E7.getDy(),E7.getDir(),&J,&E7,&M));
                }
                if(disparos >= 120 && disparos <= 129)
                {
                    DiEne.push_back(new Disparar(E8.getDx(), E8.getDy(),E8.getDir(),&J,&E8,&M));
                }
                if(disparos >= 130 && disparos <= 139)
                {
                    DiEne.push_back(new Disparar(E9.getDx(), E9.getDy(),E9.getDir(),&J,&E9,&M));
                }
                if(disparos >= 140 && disparos <= 149)
                {
                    DiEne.push_back(new Disparar(E10.getDx(), E10.getDy(),E10.getDir(),&J,&E10,&M));
                }
                if(disparos >= 150 && disparos <= 159)
                {
                    DiEne.push_back(new Disparar(E11.getDx(), E11.getDy(),E11.getDir(),&J,&E11,&M));
                }

                J.mover_jugador();
                E1.mover_enemigo();
                E2.mover_enemigo();
                E3.mover_enemigo();
                E4.mover_enemigo();
                E5.mover_enemigo();
                E6.mover_enemigo();
                E7.mover_enemigo();
                E8.mover_enemigo();
                E9.mover_enemigo();
                E10.mover_enemigo();
                E11.mover_enemigo();
            }

            crear_pantalla();
            clear_to_color( buffer, 0x000000);
     }

     destroy_bitmap(buffer);
     destroy_bitmap(buffer2);

     return 0;
}
END_OF_MAIN();
