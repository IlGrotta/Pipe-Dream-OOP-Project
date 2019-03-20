#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>


#ifndef GESTOREGRAFICA_H
#define GESTOREGRAFICA_H
class GestoreGrafica
{
    private:
        int scale_w;      //risoluzione dinamica
        int scale_h;
        int scale_x;
        int scale_y;
        ALLEGRO_DISPLAY * display;
        ALLEGRO_BITMAP * buffer;
        
        
    public:
        GestoreGrafica();
        GestoreGrafica(const int&, const int& ,const int&, const int&, ALLEGRO_BITMAP *, ALLEGRO_DISPLAY *);
        ~GestoreGrafica();
        };

        #endif