#include "arene.h"

void initialiserArene(){

}



void dessinerArene(ALLEGRO_BITMAP *fond ){

    al_draw_scaled_bitmap(fond, 0, 0, 1920, 1080, 0, 0, LARGEUR, HAUTEUR, 0);

    //contour

    float x1 = LARGEUR / 2;
    float y1 = 20;

    float x2 = 1380;
    float y2 = 400;

    // y = ax + b
    // a = yb - ya / xb - xa

    //y = 0,56x - 372
    al_draw_line((float)LARGEUR/2, 20, (float)LARGEUR - 20, 400, BLANC, 5);

    //y = -0,56x + 412
    al_draw_line((float)LARGEUR/2, 20, 20, 400, BLANC, 5);
    //al_draw_line(20, (float)HAUTEUR / 2, (float)LARGEUR / 2, HAUTEUR - 20, BLANC, 5);
    //al_draw_line((float)LARGEUR / 2, HAUTEUR - 20, (float)LARGEUR - 20, (float)HAUTEUR / 2, BLANC, 5);

    //gauche droite
    al_draw_line(x1 - 40, 42.4f , 10, 10, BLANC, 5);

    al_flip_display();
}

void arene(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue){
    bool end = false;

    ALLEGRO_BITMAP *fond = al_load_bitmap("../Image/Classes/CoeurIop/IOP.jpg");

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                end = true;
                break;
            }
        }
        dessinerArene(fond);
    }
}