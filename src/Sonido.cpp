#include "Sonido.h"

Sonido::Sonido()
{
    set_volume(250,200);

    disparo = load_wav("disparo.wav");
    sumarPuntos = load_wav("sumar puntos.wav");
    perderVida = load_wav("perder vida.wav");
    musicaFondo = load_midi("musica fondo.mid");

    if(!disparo)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR EL SONIDO DISPARO");
    }
    else if(!sumarPuntos)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR EL SONIDO SUMAR PUNTOS");
    }
    else if(!perderVida)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR EL SONIDO PERDER VIDA");
    }
    else if(!musicaFondo)
    {
        allegro_message("ERROR: NO SE PUDO CARGAR LA MUSICA DEL JUEGO");
    }
}

void Sonido::sonido_disparo()
{
    play_sample(disparo,100,128,3300,0);
}

void Sonido::sonido_puntos()
{
    play_sample(sumarPuntos,100,128,3300,0);
}

void Sonido::sonido_quitar_vida()
{
    play_sample(perderVida,100,128,3300,0);
}

void Sonido::musica_fondo()
{
    play_midi(musicaFondo,1);
}

void Sonido::detener_sonidos()
{
     stop_sample(disparo);
     stop_sample(sumarPuntos);
     stop_sample(perderVida);
}

Sonido::~Sonido()
{
    destroy_sample(disparo);
    destroy_sample(sumarPuntos);
    destroy_sample(perderVida);
    destroy_midi(musicaFondo);
}
