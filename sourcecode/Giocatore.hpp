#ifndef GIOCATORE_HPP
#define GIOCATORE_HPP
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

enum Direzione{Nord=0,Sud,Est,Ovest};


class Giocatore{
public:





private:
    int riga;
    int colonna;
    ALLEGRO_BITMAP*  bitmap;

public:
    
    Giocatore(){ bitmap=al_load_bitmap("../Assets/mouse.png"); riga=0; colonna=1;          }
    ALLEGRO_BITMAP*  getBitmap(){return bitmap;}
    int getRiga();
    int getColonna();
    void setRiga(int);
    void setColonna(int);

    ~Giocatore(){  al_destroy_bitmap(bitmap);}

};

#endif