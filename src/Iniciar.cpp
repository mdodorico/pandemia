#include "Iniciar.h"
#include <allegro.h>

void inicia_allegro(unsigned int ANCHO_, unsigned int ALTO_)
{
   allegro_init();
   install_keyboard();
   install_mouse();

   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED,ANCHO_,ALTO_,0,0);
}

void inicia_audio()
{
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
    {
       allegro_message("ERROR: NO SE PUDO INICIAR EL SONIDO\n%s\n", allegro_error);
       exit(-1);
    }
}
