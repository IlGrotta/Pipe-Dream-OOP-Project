//ricordati srand(time(0))
 #include "GestoreGioco.hpp"
 #include "vector"
using namespace std;
GestoreGioco::GestoreGioco(){ srand(time(0));   }
void GestoreGioco::ModalitaNormale(GestoreGrafica& GG,GestoreAudio& GA){
    vector <Tubo*> ListaTubi;
        for(int i=0;i<5;i++)
            {
                ListaTubi[i]=new Tubo();
                ListaTubi[i]->SetCoordinate(0,i+1);
            }
        vector <Tubo*> TubiPosizionati;
        Tubo* TuboIniziale=nullptr;
        Tubo* TuboFinale=nullptr;

        

        


}