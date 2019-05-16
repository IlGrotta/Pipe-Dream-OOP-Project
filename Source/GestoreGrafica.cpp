#include "../Headers/GestoreGrafica.hpp"
extern int WINDOWH;
extern int WINDOWW;

GestoreGrafica::GestoreGrafica() {}

GestoreGrafica::GestoreGrafica(const int &scale_w, const int &scale_h, const int &scale_x, const int &scale_y, ALLEGRO_BITMAP *buffer, ALLEGRO_DISPLAY *display)
{
    this->scale_h = scale_h;
    this->scale_w = scale_w;
    this->scale_x = scale_x;
    this->scale_y = scale_y;
    this->buffer = buffer;
    this->display = display;
}

void GestoreGrafica::DisegnaTubo(Tubo* tubo)

    {
        ALLEGRO_BITMAP* bitmap=NULL;
        al_set_target_bitmap(buffer);
        if(tubo->getAcqua() )  {
            string pathAcqua;
                if(tubo->getEntrata()==Top)       pathAcqua=tubo->getPath()+"/water_top/water_"+to_string(tubo->getCont())+".png";
                if(tubo->getEntrata()==Bottom) pathAcqua=tubo->getPath()+"/water_bottom/water_"+to_string(tubo->getCont())+".png";
                if(tubo->getEntrata()==Left)       pathAcqua=tubo->getPath()+"/water_left/water_"+to_string(tubo->getCont())+".png";
                if(tubo->getEntrata()==Right)     pathAcqua=tubo->getPath()+"/water_right/water_"+to_string(tubo->getCont())+".png";
                const char* pathAcquaC= pathAcqua.c_str();
                bitmap=al_load_bitmap(pathAcquaC);
                al_draw_bitmap(bitmap,tubo->getColonna()*32, tubo->getRiga()*32, 0);     
                 al_destroy_bitmap(bitmap);
                                }
                            
           
            string pathTubo= tubo->getPath()+"pipe.png"; 
            bitmap=al_load_bitmap(pathTubo.c_str());
            al_draw_bitmap(bitmap,tubo->getColonna()*32, tubo->getRiga()*32, 0);     

        al_destroy_bitmap(bitmap);
    }


    void GestoreGrafica::DisegnaTubo(Tubo* tubo,int riga,int colonna)

    {
        ALLEGRO_BITMAP* bitmap=NULL;
        al_set_target_bitmap(buffer);
        
        if(tubo->getAcqua()){
         
            string s=tubo->getPath();
            if(tubo->getEntrata()==Top) s.append("water_top/water_");
            if(tubo->getEntrata()==Bottom) s.append("water_bottom/water_");
            if(tubo->getEntrata()==Left) s.append("water_left/water_");
            if(tubo->getEntrata()==Right) s.append("water_right/water_");
            s.append(to_string(tubo->getCont()));
            s.append(".png");
            bitmap=al_load_bitmap(s.c_str());
            al_draw_bitmap(bitmap,colonna*32, riga*32, 0);
            al_destroy_bitmap(bitmap);
        }
            string pathTubo= tubo->getPath()+"pipe.png"; 
           
            bitmap=al_load_bitmap(pathTubo.c_str());
            al_draw_bitmap(bitmap,colonna*32, riga*32, 0);     

        al_destroy_bitmap(bitmap);
    }

void GestoreGrafica::flipDisplay()
    {
     
        al_set_target_bitmap(al_get_backbuffer(display));
       
        al_draw_scaled_bitmap(buffer, 0, 0, WINDOWW, WINDOWH, scale_x, scale_y, scale_w, scale_h, 0);
        al_flip_display();
        al_set_target_bitmap(buffer);
        al_clear_to_color(al_map_rgb(0,0,0));
        
    }

void GestoreGrafica::DisegnaGiocatore(Giocatore* giocatore){
        al_set_target_bitmap(buffer);
        al_draw_bitmap(giocatore->getBitmap(), giocatore->getColonna()*32, giocatore->getRiga()*32, 0);     
    }


void GestoreGrafica::DisegnaBackground(){
 al_set_target_bitmap(buffer);
        al_clear_to_color(al_map_rgb(111,111,212));
}

