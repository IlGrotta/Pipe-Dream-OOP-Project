#ifndef TUBOFINALE_HPP
#define TUBOFINALE_HPP
#include "Tubo.hpp"

class TuboFinale: public Tubo{
public:
TuboFinale();
string getPath() override;
TipoTubo getTipoTubo() override;


};

#endif