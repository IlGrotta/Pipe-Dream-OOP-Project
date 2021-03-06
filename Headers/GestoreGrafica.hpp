#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Tubo.hpp"
#include "Giocatore.hpp"
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
       
       ALLEGRO_DISPLAY* getDisplay(){return display;}
        GestoreGrafica();
        GestoreGrafica(const int&, const int& ,const int&, const int&, ALLEGRO_BITMAP *, ALLEGRO_DISPLAY *);
        ~GestoreGrafica() {}  
        void DisegnaTubo(Tubo* );
        void DisegnaTubo(Tubo* tubo,int riga,int colonna);
        void DisegnaGiocatore(Giocatore*);
        void flipDisplay();
        void DisegnaBackground();
        };

        #endif