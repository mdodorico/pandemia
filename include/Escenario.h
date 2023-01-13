#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <allegro.h>

extern BITMAP *buffer;

class Escenario
{
    public:
        Escenario();

        BITMAP *fondo_1;
        BITMAP *pared_1;
        BITMAP *fondo_2;
        BITMAP *pared_2;
        BITMAP *fondo_3;
        BITMAP *pared_3;
        BITMAP *fondo_4;
        BITMAP *pared_4;
        BITMAP *fondo_5;
        BITMAP *pared_5;
        BITMAP *fondo_6;
        BITMAP *pared_6;

        char mapa[50][50];

        unsigned int width,height;

        void abrir_archivo_primer_escenario();
        void abrir_archivo_segundo_escenario();
        void abrir_archivo_tercer_escenario();
        void abrir_archivo_cuarto_escenario();
        void abrir_archivo_quinto_escenario();
        void abrir_archivo_sexto_escenario();

        void cargar_primer_escenario();
        void cargar_segundo_escenario();
        void cargar_tercer_escenario();
        void cargar_cuarto_escenario();
        void cargar_quinto_escenario();
        void cargar_sexto_escenario();

        void cargar_imagenes_primer_escenario();
        void cargar_imagenes_segundo_escenario();
        void cargar_imagenes_tercer_escenario();
        void cargar_imagenes_cuarto_escenario();
        void cargar_imagenes_quinto_escenario();
        void cargar_imagenes_sexto_escenario();

        virtual ~Escenario();
};

#endif // ESCENARIO_H
