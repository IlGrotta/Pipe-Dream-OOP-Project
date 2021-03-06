#ifndef GESTOREGIOCO_HPP
#define GESTOREGIOCO_HPP
#include <vector>
 #include <list>
#include "Tubo.hpp"
#include "TuboInizio.hpp"
#include "TuboFinale.hpp"
#include "GestoreAudio.hpp"
#include "Giocatore.hpp"
#include "GestoreGrafica.hpp"

using namespace std;


class GestoreGioco{
    private:
    ALLEGRO_TIMER* timer;
    Giocatore* giocatore;
    Tubo* TuboIniziale;
    Tubo* TuboFine;
    public:
    GestoreGioco(  ALLEGRO_TIMER* timer);
        void ModalitaNormale(GestoreGrafica&,GestoreAudio&); //non so se ci son problemi con la "à", quindi non scrivo "Modalità"!
        void ModalitaATempo(GestoreGrafica&,GestoreAudio&);
        void StampaTubi(Tubo*,Tubo*, list<Tubo*>,vector<Tubo*> ,GestoreGrafica& );
        void SpostaGiocatore(bool[5]);
        Tubo* ProssimoTubo(int colonna1, int riga1, vector<Tubo*>, DirezioneAcqua DaDoveArriva);
    ~GestoreGioco(){delete giocatore ;}
};

#endif