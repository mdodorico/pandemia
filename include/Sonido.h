#ifndef SONIDO_H
#define SONIDO_H

#include <allegro.h>

class Sonido
{
    public:
        Sonido();

        SAMPLE *disparo;
        SAMPLE *sumarPuntos;
        SAMPLE *perderVida;
        MIDI *musicaFondo;

        void sonido_disparo();
        void sonido_puntos();
        void sonido_quitar_vida();
        void musica_fondo();
        void detener_sonidos();

        virtual ~Sonido();
};

#endif // SONIDO_H
