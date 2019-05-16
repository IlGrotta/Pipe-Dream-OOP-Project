#include "../Headers/Tubo.hpp"

bool Tubo::getAcqua(){return acqua;}
int Tubo::getCont(){ return cont;}
string Tubo::getPath(){return pathPng;}
TipoTubo Tubo::getTipoTubo(){return tipoTubo;}

Tubo::Tubo(){
  
 int valore= rand()%6;
 if(valore==0){pathPng="../Assets/bottom_left/"; tipoTubo=BottomLeft;       } //b-l
 if(valore==1){pathPng="../Assets/top_left/"; tipoTubo=TopLeft;                      } //t-L
 if(valore==2){pathPng="../Assets/bottom_right/";    tipoTubo=BottomRight;                          } //b-R
 if(valore==3){pathPng="../Assets/top_right/";   tipoTubo=TopRight;                                      }// t-R
 if(valore==4){pathPng="../Assets/vertical/";   tipoTubo=Vertical;                                  } //ver
 if(valore==5){pathPng="../Assets/horizontal/"; tipoTubo=Horizontal;                                             } //hor

  cont=0;  acqua=false;  Colonna=0; Riga=0;
 }



void Tubo::SetCoordinate(int colo, int riga){

  Colonna=colo; Riga=riga;
  }
int Tubo::getRiga(){return Riga;}
int Tubo::getColonna(){return Colonna;}



void Tubo::AumentaCont(){
  //da fare
  if(cont<10)cont++;
}

void Tubo::setAcqua(bool a){acqua=a; }

DirezioneAcqua Tubo::getEntrata(){return entrata;};
DirezioneAcqua Tubo::getUscita(){return uscita;};

void Tubo::setEntrata(DirezioneAcqua dir){entrata=dir;}
void Tubo::setUscita(DirezioneAcqua dir){uscita=dir;}