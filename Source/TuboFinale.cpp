#include "../Headers/TuboFinale.hpp"

    TuboFinale::TuboFinale(){
            cont=0;
            acqua=false;
                tipoTubo=End;
                entrata=Left;
    }
string TuboFinale::getPath(){
        string s="../Assets/special/end";
        
        return s;
}

TipoTubo TuboFinale:: getTipoTubo() {
        return End;
}