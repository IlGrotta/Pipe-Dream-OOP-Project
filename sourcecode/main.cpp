#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/keyboard.h>
#include <iostream>
#include "GestoreGrafica.hpp"
#include "GestoreGioco.hpp"
#include "GestoreAudio.hpp"
int WINDOWH=224; 
int WINDOWW=320 ;    
const float FPS=15.0;
enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,KEY_ENTER
};
int main(){
        if(!al_init()) {std::cout<<"Errore inizializzazione Allegro!"; return -1;}
        if(!al_init_image_addon()) {   std::cout << "Errore inizializzazione ImageAddon";    return -1;}
        if(!al_install_audio()){std::cout << "Errore inizializzazione audio"; return -1;}
        if(!al_install_keyboard()){std::cout<<"Errore inizializzazione tastiera"; return -1;}
       //al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW); //indico che lo schermo sarà fullscreen
        al_set_new_display_flags(ALLEGRO_WINDOWED);

    ALLEGRO_BITMAP* icona=al_load_bitmap("../Assets/cioby.png");
    

         srand(time(NULL));

        bool keys[5]={false,false,false,false,false};
        ALLEGRO_EVENT_QUEUE* event_queue=al_create_event_queue();
        ALLEGRO_TIMER* timer;
        timer= al_create_timer(1.0/FPS);
        ALLEGRO_DISPLAY* display= al_create_display(WINDOWW, WINDOWH);
                    if(!display) std::cout<<"Errore creazione display";
         ALLEGRO_BITMAP* buffer=al_create_bitmap(WINDOWW,WINDOWH);
                    if(!buffer) std::cout<<"Errore inizializzazione buffer";
                    al_register_event_source(event_queue, al_get_display_event_source(display));
                    al_register_event_source(event_queue, al_get_timer_event_source(timer));
                    al_register_event_source(event_queue, al_get_keyboard_event_source());
   srand(time(0));
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
  
  
  
  
  
  
  al_set_display_icon(display,icona);
  al_set_window_title(display,"FAZIO");
GestoreGrafica grafica(scaleW,scaleH,scaleX,scaleY,buffer,display);
GestoreGioco gioco(timer);
GestoreAudio audio;

bool esci=false;
bool redraw=true;
al_start_timer(timer);
gioco.ModalitaNormale(grafica,audio);


// distruttori
al_destroy_timer(timer);
al_destroy_event_queue(event_queue);
al_destroy_bitmap(buffer);
al_destroy_display(display);
al_uninstall_keyboard();
}













