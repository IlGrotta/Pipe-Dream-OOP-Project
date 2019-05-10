#include "TuboFinale.hpp"

    TuboFinale::TuboFinale(){
            cont=0;
            acqua=false;

    }
string TuboFinale::getPath(){
        string s="../Assets/special/end";
        
        return s;
}

int TuboFinale:: getTipoTubo() {
        return 11;
}