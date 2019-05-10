#include "TuboInizio.hpp"

    TuboInizio::TuboInizio(){
            cont=0;
            acqua=false;

    }
string TuboInizio::getPath(){
        string s="../Assets/special/pipe_start/start";
        s.append(to_string(cont) );
        return s;
}

int TuboInizio:: getTipoTubo() {
        return 12;
}