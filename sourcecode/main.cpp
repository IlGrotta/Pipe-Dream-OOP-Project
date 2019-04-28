#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/keyboard.h>
#include <iostream>
#include "GestoreGrafica.hpp"
#include "GestoreGioco.hpp"
int WINDOWH=224; 
int WINDOWW=320 ;    


int main(){
if(!al_init()) {std::cout<<"Errore inizializzazione Allegro!"; return -1;}
     if(!al_init_image_addon()) {   std::cout << "Errore inizializzazione ImageAddon";    return -1;}
    if(!al_install_audio()){std::cout << "Errore inizializzazione audio"; return -1;}
     if(!al_install_keyboard()){std::cout<<"Errore inizializzazione tastiera"; return -1;}
     al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW); //indico che lo schermo sarà fullscreen

    ALLEGRO_DISPLAY* display= al_create_display(WINDOWW, WINDOWH);
                    if(!display) std::cout<<"Errore creazione display";
     ALLEGRO_BITMAP* buffer=al_create_bitmap(WINDOWW,WINDOWH);
                    if(!buffer) std::cout<<"Errore inizializzazione bitman";

        int windowHeight = al_get_display_height(display);  //creo i fattori di scala per scalare le bitmap sul display
        int windowWidth = al_get_display_width(display);
        float sx = windowWidth / float(WINDOWW); 
        float sy = windowHeight / float(WINDOWH);
        int fattorescala = std::min(sx, sy);
        int scaleW = WINDOWW * fattorescala;
        int scaleH = WINDOWH * fattorescala;
        int scaleX = (windowWidth - scaleW) / 2;
        int scaleY = (windowHeight - scaleH) / 2;


//placeholder

 //per disegnare, selezionare target il buffer e usare al_draw_scaled_bimap





GestoreGrafica grafica(scaleW,scaleH,scaleX,scaleY,buffer,display);
GestoreGioco gioco();

// creare gestoreGrafica, GestoreGioco e GestoreSuoni

// distruttori

al_destroy_bitmap(buffer);
al_destroy_display(display);
al_uninstall_keyboard();
}