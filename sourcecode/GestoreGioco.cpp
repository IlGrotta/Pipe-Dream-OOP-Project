
 #include "GestoreGioco.hpp"

 

using namespace std;
enum MYKEYS {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,KEY_ENTER};
const int RIGHE=7;
const int COLONNE=10;



GestoreGioco::GestoreGioco(  ALLEGRO_TIMER* timer){  
   srand(time(0));
   this->timer =timer;    
   giocatore=new Giocatore();
         
         }

//#################NORMALE#########################################
void GestoreGioco::ModalitaNormale(GestoreGrafica& GG,GestoreAudio& GA){
 
      
      bool keys[5]={false,false,false,false,false};
      vector<Tubo*> Tubimatrice;
      list<Tubo*> ListaTubi;
      Tubo* TuboIniziale=new TuboInizio();
      Tubo* TuboFine=new TuboFinale();

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





        //#inizio ciclo
      bool esci=false; bool redraw=true; 
    while(!esci)
        {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
  
      if(ev.type == ALLEGRO_EVENT_TIMER) {
         redraw = true;
      }
     else   if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
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

               case ALLEGRO_KEY_ENTER:
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
            case ALLEGRO_KEY_ENTER:
                     keys[KEY_ENTER]=false;
                     break;
            case ALLEGRO_KEY_ESCAPE:
               esci = true;
               break;
         }
      } 
 
       if(redraw && al_is_event_queue_empty(event_queue)) {
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
         delete TuboFine;
         for(auto i: ListaTubi) delete i;
         for(auto i:Tubimatrice) delete i;
}
// #########fine normale##################à
void GestoreGioco::StampaTubi(Tubo* TuboIniziale, Tubo* TuboFinale,  list <Tubo*> ListaTubi, vector<Tubo*> tubiMatrice, GestoreGrafica& GG){
 GG.DisegnaTubo(TuboIniziale);
 GG.DisegnaTubo(TuboFinale);

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