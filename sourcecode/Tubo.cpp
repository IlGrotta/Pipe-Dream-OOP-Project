#include "Tubo.hpp"
 // dir acqua= top=0, bottomo=1, left=2, right =3. Fare enum ewe
bool Tubo::getAcqua(){return acqua;}
int Tubo::getCont(){ return cont;}
int Tubo::getDirAcqua(){return dirAcqua;}
string Tubo::getPath(){return pathPng;}
int Tubo::getTipoTubo(){return tipoTubo;}

Tubo::Tubo(){
 tipoTubo= rand()%7;
 if(tipoTubo==0){pathPng="../Assets/bottom_left/";} //b-l
 if(tipoTubo==1){pathPng="../Assets/top_left/";} //t-L
 if(tipoTubo==2){pathPng="../Assets/bottom_right/";                              } //b-R
 if(tipoTubo==3){pathPng="../Assets/top_right/";}// t-R
 if(tipoTubo==4){pathPng="../Assets/vertical/";                              } //ver
 if(tipoTubo==5){pathPng="../Assets/horizontal/";} //hor
 if(tipoTubo==6){pathPng="../Assets/vertical_horizontal/";}//verhor
  cont=0; dirAcqua=0; acqua=false;  Colonna=0; Riga=0;
 }



void Tubo::SetCoordinate(int colo, int riga){

  Colonna=colo; Riga=riga;
  }
int Tubo::getRiga(){return Riga;}
int Tubo::getColonna(){return Colonna;}


Tubo::Tubo(int a){
 /* if(a==1){ //TUBOINIZIALW
    pathPng="../Assets/special/pipe_start/start0_"; tipoTubo=11;

  }
  if(a==2){ //tubofinale
    pathPng="../Assets/special/pipe_end/end0_";tipoTubo=12;

  }

    acqua=0; cont=0;
*/
}

void Tubo::AumentaCont(){
  //da fare
  cont++;
}