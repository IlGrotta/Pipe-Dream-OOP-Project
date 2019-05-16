#ifndef TUBO_HPP
#define TUBO_HPP

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/keyboard.h>
#include <string>
   using namespace std;
    enum DirezioneAcqua{
        Top,Bottom,Left,Right, NULLO
};
    enum TipoTubo{
        BottomLeft,TopLeft,BottomRight,TopRight,Vertical,Horizontal,VerticalHorizontal, Special, End };
        
    
class Tubo{
protected:
    string pathPng; 
    TipoTubo tipoTubo; int cont; 
     DirezioneAcqua uscita;
     DirezioneAcqua entrata;
    bool acqua;
    int Riga;  int Colonna;

    
public:
     Tubo();
     Tubo(int);
     void AumentaCont();

    DirezioneAcqua getEntrata();
    DirezioneAcqua getUscita();
    void setEntrata(DirezioneAcqua);
    void setUscita(DirezioneAcqua);
    void SetCoordinate(int,int);
    virtual string getPath();
    virtual TipoTubo getTipoTubo();
    int getCont();
    bool getAcqua();
    void setAcqua(bool);
    int getRiga();
    int getColonna();


    virtual ~Tubo(){};
}; //fine classe










#endif