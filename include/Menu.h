#ifndef MENU_H
#define MENU_H

#include<allegro.h>

extern BITMAP *buffer2;

class Menu
{
    public:
        Menu();

        BITMAP *menuInicio;
        BITMAP *menuEmpezar;
        BITMAP *menuSalir;
        BITMAP *mouse;

        unsigned int punto,vida;
        bool jugar;
        bool salir;

        void empezar();
        void pintar_menu();
        void cargar_imagen_menu();
        void puntuacion();

        virtual ~Menu();
};

#endif // MENU_H
