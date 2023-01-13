#include "Escenario.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <allegro.h>

using namespace std;

Escenario::Escenario()
{
    width = 10;
    height = 10;

    cargar_imagenes_primer_escenario();
    cargar_imagenes_segundo_escenario();
    cargar_imagenes_tercer_escenario();
    cargar_imagenes_cuarto_escenario();
    cargar_imagenes_quinto_escenario();
    cargar_imagenes_sexto_escenario();
}

void abrir_archivo_primer_escenario() //DETERMINA EL ARCHIVO A ABRIR PARA CREAR EL ESCENARIO
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario1.txt",ios::in);

    if(archivo_mapa.fail())
    {
        cout<<"ERROR: NO SE PUDO CARGAR EL ESCENARIO";
        exit(-1);
    }
    archivo_mapa.close();
}

void abrir_archivo_segundo_escenario()
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario2.txt",ios::in);

    if(archivo_mapa.fail())
    {
        cout<<"ERROR: NO SE PUDO CARGAR EL ESCENARIO";
        exit(-1);
    }
    archivo_mapa.close();
}

void abrir_archivo_tercer_escenario()
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario3.txt",ios::in);

    if(archivo_mapa.fail())
    {
        cout<<"ERROR: NO SE PUDO CARGAR EL ESCENARIO";
        exit(-1);
    }
    archivo_mapa.close();
}

void abrir_archivo_cuarto_escenario()
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario4.txt",ios::in);

    if(archivo_mapa.fail())
    {
        cout<<"ERROR: NO SE PUDO CARGAR EL ESCENARIO";
        exit(-1);
    }
    archivo_mapa.close();
}

void abrir_archivo_quinto_escenario()
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario5.txt",ios::in);

   if(archivo_mapa.fail())
   {
     cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DEL MAPA";
     exit(-1);
   }
   archivo_mapa.close();
}

void abrir_archivo_sexto_escenario()
{
   ifstream archivo_mapa;
   archivo_mapa.open("escenario6.txt",ios::in);

   if(archivo_mapa.fail())
   {
     cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DEL MAPA";
     exit(-1);
   }
   archivo_mapa.close();
}

void Escenario::cargar_primer_escenario()
{
    for(unsigned int c=0; c<50; c++)
    {
      for(unsigned int f=0; f<50 ; f++)
        {
          if(mapa[f][c] == 'P')
          {
                draw_sprite(buffer,pared_1, c*width, f*height);
          }
          else if(mapa[f][c] == '.')
          {
                draw_sprite(buffer,fondo_1, c*width, f*height);
          }
        }
    }
}

void Escenario::cargar_segundo_escenario()
{
    for(unsigned int c=0; c<50; c++)
    {
      for(unsigned int f=0; f<50 ; f++)
        {
          if(mapa[f][c] == 'P')
          {
                draw_sprite(buffer,pared_2, c*width, f*height);
          }
          else if(mapa[f][c] == '.')
          {
                draw_sprite(buffer,fondo_2, c*width, f*height);
          }
        }
    }
}

void Escenario::cargar_tercer_escenario()
{
    for(unsigned int c=0; c<50; c++)
    {
      for(unsigned int f=0; f<50 ; f++)
        {
          if(mapa[f][c] == 'P')
          {
                draw_sprite(buffer,pared_3, c*width, f*height);
          }
          else if(mapa[f][c] == '.')
          {
                draw_sprite(buffer,fondo_3, c*width, f*height);
          }
        }
    }
}

void Escenario::cargar_cuarto_escenario()
{
    for(unsigned int c=0; c<50; c++)
    {
      for(unsigned int f=0; f<50 ; f++)
        {
          if(mapa[f][c] == 'P')
          {
                draw_sprite(buffer,pared_4, c*width, f*height);
          }
          else if(mapa[f][c] == '.')
          {
                draw_sprite(buffer,fondo_4, c*width, f*height);
          }
        }
    }
}

void Escenario::cargar_quinto_escenario()
{
    for(unsigned int c=0; c<50; c++)
    {
      for(unsigned int f=0; f<50 ; f++)
        {
          if(mapa[f][c] == 'P')
          {
                draw_sprite(buffer,pared_5, c*width, f*height);
          }
          else if(mapa[f][c] == '.')
          {
                draw_sprite(buffer,fondo_5, c*width, f*height);
          }
        }
    }
}

void Escenario::cargar_sexto_escenario()
{
    for(unsigned int c=0; c<50; c++)
    {
      for(unsigned int f=0; f<50 ; f++)
        {
          if(mapa[f][c] == 'P')
          {
                draw_sprite(buffer,pared_6, c*width, f*height);
          }
          else if(mapa[f][c] == '.')
          {
                draw_sprite(buffer,fondo_6, c*width, f*height);
          }
        }
    }
}

void Escenario::cargar_imagenes_primer_escenario()
{
    fondo_1 = load_bitmap("fondo_1.bmp",NULL);
    pared_1 = load_bitmap("pared_1.bmp",NULL);

    if(!pared_1)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE PAREDES NIVEL 1");
    }
    else if(!fondo_1)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE FONDO NIVEL 1");
    }
}

void Escenario::cargar_imagenes_segundo_escenario()
{
    fondo_2 = load_bitmap("fondo_2.bmp",NULL);
    pared_2 = load_bitmap("pared_2.bmp",NULL);

    if(!pared_2)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE PAREDES NIVEL 2");
    }
    else if (!fondo_2)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE FONDO NIVEL 2");
    }
}

void Escenario::cargar_imagenes_tercer_escenario()
{
    fondo_3 = load_bitmap("fondo_3.bmp",NULL);
    pared_3 = load_bitmap("pared_3.bmp",NULL);

    if(!pared_3)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE PAREDES NIVEL 3");
    }
    else if (!fondo_3)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE FONDO NIVEL 3");
    }
}

void Escenario::cargar_imagenes_cuarto_escenario()
{
    fondo_4 = load_bitmap("fondo_4.bmp",NULL);
    pared_4 = load_bitmap("pared_4.bmp",NULL);

    if(!pared_4)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE PAREDES NIVEL 4");
    }
    else if (!fondo_4)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE FONDO NIVEL 4");
    }
}

void Escenario::cargar_imagenes_quinto_escenario()
{
    fondo_5 = load_bitmap("fondo_5.bmp",NULL);
    pared_5 = load_bitmap("pared_5.bmp",NULL);

    if(!pared_5)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE PAREDES NIVEL 5");
    }
    else if (!fondo_5)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE FONDO NIVEL 5");
    }
}

void Escenario::cargar_imagenes_sexto_escenario()
{
    fondo_6 = load_bitmap("fondo_6.bmp",NULL);
    pared_6 = load_bitmap("pared_6.bmp",NULL);

    if(!pared_6)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE PAREDES NIVEL 6");
    }
    else if (!fondo_6)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR IMAGEN DE FONDO NIVEL 6");
    }
}

Escenario::~Escenario()
{
    destroy_bitmap(fondo_1);
    destroy_bitmap(pared_1);
    destroy_bitmap(fondo_2);
    destroy_bitmap(pared_2);
    destroy_bitmap(fondo_3);
    destroy_bitmap(pared_3);
    destroy_bitmap(fondo_4);
    destroy_bitmap(pared_4);
    destroy_bitmap(fondo_5);
    destroy_bitmap(pared_5);
    destroy_bitmap(fondo_6);
    destroy_bitmap(pared_6);
}
