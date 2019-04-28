#ifndef GESTOREGIOCO_HPP
#define GESTOREGIOCO_HPP

#include "Tubo.hpp"
#include "GestoreGrafica.hpp"
#include "GestoreAudio.hpp"
using namespace std;


class GestoreGioco{
    private:

    public:
        void ModalitaNormale(GestoreGrafica&,GestoreAudio&); //non so se ci son problemi con la "à", quindi non scrivo "Modalità"!
        void ModalitaATempo(GestoreGrafica&,GestoreAudio&);
        GestoreGioco();


};

#endif