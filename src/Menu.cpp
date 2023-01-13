#include "Menu.h"

Menu::Menu()
{
  jugar = false;
  salir = true;
  punto = 0;
  vida = 5;
  cargar_imagen_menu();
}

void Menu::pintar_menu()
{
    blit(menuEmpezar,screen,0,0,0,0,700,500);
}

void Menu::cargar_imagen_menu()
{
    menuInicio=load_bitmap("menu.bmp",NULL);
	menuEmpezar=load_bitmap("empezar.bmp",NULL);
	menuSalir=load_bitmap("salir.bmp",NULL);
    mouse=load_bitmap("mouse.bmp",NULL);

    if(!menuInicio)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR EL MENU INICIO");
    }
    else if(!menuEmpezar)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR EL MENU EMPEZAR");
    }
    else if(!menuSalir)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR EL MENU SALIR");
    }
    else if(!mouse)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR EL MOUSE");
    }
}

void Menu::empezar()
{
  while(jugar==false)
  {
       if(mouse_x >= 253 && mouse_x <= 360 && mouse_y >= 267  && mouse_y <= 288)
       {
          blit(menuEmpezar,buffer2,0,0,0,0,700,500);
             if(mouse_b & 1)
             {
                jugar = true;
                salir = false;
             }
       }
       else if(mouse_x >= 232 && mouse_x <= 382 && mouse_y >= 300 && mouse_y <= 324)
       {
           blit(menuSalir,buffer2,0,0,0,0,700,500);
             if(mouse_b & 1)
             {
               jugar = true;
               salir = true;
             }
       }
       else
       {
           blit(menuInicio,buffer2,0,0,0,0,700,500);
       }

       masked_blit(mouse,buffer2,0,0,mouse_x,mouse_y,25,26);
       blit(buffer2,screen,0,0,0,0,700,500);
      }
}

void Menu::puntuacion()
{
   textprintf(screen,font,510,50,palette_color[3], "PUNTOS: %d",punto);
   textprintf(screen,font,510,70,palette_color[12],"VIDAS: %d",vida);
   textprintf(screen,font,510,120,palette_color[15],"PARA DISPARAR PRESIONE");
   textprintf(screen,font,510,140,palette_color[15],"LA TECLA A");
   textprintf(screen,font,510,210,palette_color[2],"OBJETIVO: MATAR AL");
   textprintf(screen,font,510,230,palette_color[2],"VIRUS Y SOBREVIVIR.");
   textprintf(screen,font,510,420,palette_color[13],"PARA SALIR PRESIONE");
   textprintf(screen,font,510,440,palette_color[13],"   LA TECLA ESC.");
}

Menu::~Menu()
{
    destroy_bitmap(menuInicio);
    destroy_bitmap(menuEmpezar);
    destroy_bitmap(menuSalir);
    destroy_bitmap(mouse);
}
