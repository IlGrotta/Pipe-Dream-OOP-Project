#ifndef TUBOINIZIO_HPP
#define TUBOINIZIO_HPP
#include "Tubo.hpp"

class TuboInizio: public Tubo{
public:
TuboInizio();
string getPath() override;
int getTipoTubo() override;


};

#endif