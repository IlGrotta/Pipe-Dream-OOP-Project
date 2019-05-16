
 #include "../Headers/GestoreGioco.hpp"

using namespace std;
enum MYKEYS {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,KEY_ENTER};
extern const  int RIGHE;
 extern const  int COLONNE;
int Clock=5;  //per aumentare difficoltà, implementare che si differenzierà


GestoreGioco::GestoreGioco(ALLEGRO_TIMER* timer){  
   this->timer =timer;    
   giocatore=new Giocatore();     
   }

//#################NORMALE#########################################
void GestoreGioco::ModalitaNormale(GestoreGrafica& GG,GestoreAudio& GA){
 
   Tubo* ultimoTuboAttivo;     
   bool keys[5]={false,false,false,false,false};
   vector<Tubo*> Tubimatrice;
   list<Tubo*> ListaTubi;
   TuboIniziale=new TuboInizio();
   TuboFine=new TuboFinale();
   
   bool  PosizioniMatrice [RIGHE][COLONNE]={false};

   ALLEGRO_EVENT_QUEUE* event_queue=al_create_event_queue();
   al_register_event_source(event_queue, al_get_display_event_source(GG.getDisplay()));
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
   al_register_event_source(event_queue, al_get_keyboard_event_source());

   for(int i=0;i<5;i++)
   {
      Tubo* placeholder=new Tubo();
      ListaTubi.push_back(placeholder);
      ListaTubi.back()->SetCoordinate(0,i+1);
   }

   TuboIniziale->SetCoordinate(rand()%3+1, rand()%7);
   TuboFine->SetCoordinate(rand()%3+5, rand()%7);
   PosizioniMatrice[TuboIniziale->getRiga()][TuboIniziale->getColonna()]=true;
   PosizioniMatrice[TuboFine->getRiga()][TuboFine->getColonna()]=true;
   Tubimatrice.push_back(TuboFine);
   ultimoTuboAttivo=TuboIniziale;

   //#inizio ciclo
   bool esci=false; 
   bool redraw=true; 
   bool acquaScorre=false;
   int cont=0;
   while(!esci) {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
  
   if(ev.type == ALLEGRO_EVENT_TIMER) {
      redraw = true;
      
   }

   else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
    
       
   if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
      switch(ev.keyboard.keycode) {
         case ALLEGRO_KEY_UP:
            keys[KEY_UP] = true;
            break;

         case ALLEGRO_KEY_DOWN:
            keys[KEY_DOWN] = true;
            break;

         case ALLEGRO_KEY_LEFT: 
            keys[KEY_LEFT] = true;
            break;

         case ALLEGRO_KEY_RIGHT:
            keys[KEY_RIGHT] = true;
            break;

         case ALLEGRO_KEY_SPACE:
            keys[KEY_ENTER]=true;
            break;
      }
   } 


   if(ev.type == ALLEGRO_EVENT_KEY_UP) {
      switch(ev.keyboard.keycode) {
         case ALLEGRO_KEY_UP:
            keys[KEY_UP] = false;
            break;

         case ALLEGRO_KEY_DOWN:
            keys[KEY_DOWN] = false;
            break;

         case ALLEGRO_KEY_LEFT: 
            keys[KEY_LEFT] = false;
            break;

         case ALLEGRO_KEY_RIGHT:
            keys[KEY_RIGHT] = false;
            break;

         case ALLEGRO_KEY_SPACE:
            keys[KEY_ENTER]=false;
            break;
            
         case ALLEGRO_KEY_ESCAPE:
            esci = true;
            break;
      }  
   } 
 
   if(redraw && al_is_event_queue_empty(event_queue)) {
     cont++;
      if(cont==Clock) {
         if(ultimoTuboAttivo->getCont()<10 ){
                     ultimoTuboAttivo->AumentaCont();
                     cont=0;
          }

         else { //se cont del tubo==10
            int colonna1=ultimoTuboAttivo->getColonna();
            int riga1=ultimoTuboAttivo->getRiga();
            
            if(ultimoTuboAttivo->getUscita()==Top)        riga1--; 
            if(ultimoTuboAttivo->getUscita()==Bottom)     riga1++;
            if(ultimoTuboAttivo->getUscita()==Left)       colonna1--;
            if(ultimoTuboAttivo->getUscita()==Right)      colonna1++;

            if(colonna1<1 || colonna1>COLONNE || riga1<0 ||riga1>RIGHE|| PosizioniMatrice[riga1][colonna1]==false){
               //INSERIRE STAMPA GAMEOVER
                cout<<"Hai perso2 "<<endl;
               esci=true;
               break;
            }

            Tubo* tubosuccessivo=ProssimoTubo(colonna1,riga1,Tubimatrice,ultimoTuboAttivo->getUscita());
             if(tubosuccessivo==nullptr){  
               //INSERIRE STAMPA GAMEOVER 
               cout<<"Hai perso1 "<<endl;

               esci=true;
               break;
            }
           
            else if(tubosuccessivo->getTipoTubo()==End){
                  //stampa hai vinto
               cout<<"Hai vinto "<<endl;
               esci=true;
               break;
            }
           
            

            else{
               ultimoTuboAttivo=tubosuccessivo;
               ultimoTuboAttivo->setAcqua(true);
               cont=0;
            }//impostare tubo successivo

         }
         
      }
     
      if(keys[KEY_ENTER]){
         int rigaCorr= giocatore->getRiga();
         int colonnaCorr=giocatore->getColonna();
            
         if(!PosizioniMatrice[rigaCorr][colonnaCorr]){
            Tubimatrice.push_back(ListaTubi.front());
            Tubo* corr=Tubimatrice.back();
            corr->SetCoordinate(colonnaCorr,rigaCorr);             
            ListaTubi.pop_front();
            corr= new Tubo();
            ListaTubi.push_back(corr);
            PosizioniMatrice[rigaCorr][colonnaCorr]=true;
         }//se non c'è nessun tubo.
      }
      redraw = false;
      SpostaGiocatore(keys);
      GG.DisegnaBackground();
      StampaTubi(TuboIniziale,TuboFine,ListaTubi,Tubimatrice, GG);
      GG.DisegnaGiocatore(giocatore);        
      GG.flipDisplay();    
   }

}//fine while   

   al_destroy_event_queue(event_queue);
   delete TuboIniziale;
   for(auto i: ListaTubi) delete i;
   for(auto i:Tubimatrice) delete i;
} 

// #########fine normale##################à


void GestoreGioco::StampaTubi(Tubo* TuboIniziale, Tubo* TuboFinale,  list <Tubo*> ListaTubi, vector<Tubo*> tubiMatrice, GestoreGrafica& GG){
 GG.DisegnaTubo(TuboIniziale);
 //GG.DisegnaTubo(TuboFinale);

   int cont=5;
    for(auto i: ListaTubi){
            GG.DisegnaTubo(i,cont,0);
            cont--;
    }

      for(auto i: tubiMatrice)
            GG.DisegnaTubo(i);
      

    }

void GestoreGioco::SpostaGiocatore(bool direzioni[5]){
   if(direzioni[ (int)KEY_UP ]==true &&  giocatore->getRiga()>0) giocatore->setRiga(  giocatore->getRiga()-1 );
   else if(direzioni[ (int)KEY_DOWN ]==true &&  giocatore->getRiga()<RIGHE-1) giocatore->setRiga(  giocatore->getRiga()+1 );
   else if(direzioni[ (int)KEY_LEFT]==true &&  giocatore->getColonna()>1 ) giocatore->setColonna(  giocatore->getColonna()-1 );
   else if(direzioni[ (int)KEY_RIGHT ]==true &&  giocatore->getColonna()<COLONNE -1) giocatore->setColonna(  giocatore->getColonna()+1          );
}



Tubo* GestoreGioco::ProssimoTubo(int colonna1, int riga1, vector<Tubo*>TubiMatrice, DirezioneAcqua daDoveArriva){
   Tubo* tubo=NULL;
   if(TuboIniziale->getRiga()==riga1 && TuboIniziale->getColonna()==colonna1) {cout<<"è nullo"<<endl;return nullptr;}
   for(auto a:TubiMatrice)
      if(a->getColonna()==colonna1 && a->getRiga()==riga1) tubo=a; //dato il controllo sulla matrice booleana, questo tubo DEVE esistere se la funzione viene chiamata
switch(daDoveArriva){
case(Bottom):
   if(tubo->getTipoTubo()==TopLeft){tubo->setEntrata(Top);tubo->setUscita(Left); return tubo;          }
   else if(tubo->getTipoTubo()==TopRight) {tubo->setEntrata(Top);tubo->setUscita(Right); return tubo;  }
   else if(tubo->getTipoTubo()==Vertical) {tubo->setEntrata(Top);tubo->setUscita(Bottom); return tubo;  }
   break;

case(Top):
   if(tubo->getTipoTubo()==BottomLeft){tubo->setEntrata(Bottom);tubo->setUscita(Left); return tubo;          }
   else if(tubo->getTipoTubo()==BottomRight) {tubo->setEntrata(Bottom);tubo->setUscita(Right); return tubo;  }
   else if(tubo->getTipoTubo()==Vertical) {tubo->setEntrata(Bottom);tubo->setUscita(Top); return tubo;  }
   break;

case(Right):
   if(tubo->getTipoTubo()==End){ return tubo;                              }
   if(tubo->getTipoTubo()==TopLeft){tubo->setEntrata(Left);tubo->setUscita(Top); return tubo;          }
   else if(tubo->getTipoTubo()==BottomLeft) {tubo->setEntrata(Left);tubo->setUscita(Bottom); return tubo;  }
   else if(tubo->getTipoTubo()==Horizontal) {tubo->setEntrata(Left);tubo->setUscita(Right); return tubo;   }
   break;

case(Left):
   if(tubo->getTipoTubo()==TopRight){tubo->setEntrata(Right);tubo->setUscita(Top); return tubo;          }
   else if(tubo->getTipoTubo()==BottomRight) {tubo->setEntrata(Right);tubo->setUscita(Bottom); return tubo;  }
   else if(tubo->getTipoTubo()==Horizontal) {tubo->setEntrata(Right);tubo->setUscita(Left); return tubo;  }
   break;

   default: return nullptr;

} //fine switch

return nullptr;
};

