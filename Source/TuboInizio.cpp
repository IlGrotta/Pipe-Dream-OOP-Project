#include "../Headers/TuboInizio.hpp"

TuboInizio::TuboInizio(){
            cont=0;
            acqua=false;
            tipoTubo=Special;
            uscita=Right;
                

    }
string TuboInizio::getPath(){
        string s="../Assets/special/pipe_start/start";
        s.append(to_string(cont) );
        return s;
}

TipoTubo TuboInizio:: getTipoTubo() {
        return Special;
}
