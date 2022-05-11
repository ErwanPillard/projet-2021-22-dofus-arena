#include "arene.h"

void initialiserArene(){

}

void dessinerArene(ALLEGRO_BITMAP *fond){
    al_draw_scaled_bitmap(fond, 0, 0, 1952, 1008, 0, 0, LARGEUR, HAUTEUR, 0);
    ALLEGRO_BITMAP *sol = al_load_bitmap("../Image/sol.png");
    ALLEGRO_BITMAP *sol2 = al_load_bitmap("../Image/sol2.png");
    ALLEGRO_BITMAP *sol3 = al_load_bitmap("../Image/sol3.png");
    ALLEGRO_BITMAP *sol4 = al_load_bitmap("../Image/sol4.png");
    ALLEGRO_BITMAP *sol5 = al_load_bitmap("../Image/sol5.png");
    ALLEGRO_BITMAP *sol6 = al_load_bitmap("../Image/sol6.png");
    ALLEGRO_BITMAP *obstacle1 = al_load_bitmap("../Image/obstacle1.png");
    ALLEGRO_BITMAP *obstacle2 = al_load_bitmap("../Image/obstacle2.png");
    ALLEGRO_BITMAP *obstacleGlace = al_load_bitmap("../Image/obstacleGlace.png");
    ALLEGRO_BITMAP *obstacleGlace2 = al_load_bitmap("../Image/gl.png");
    ALLEGRO_BITMAP *herbe = al_load_bitmap("../Image/herbe.png");
    ALLEGRO_BITMAP *lave = al_load_bitmap("../Image/lave.png");

    /*
    for (int i = 0; i < 12; i++) {
        for (int j = 1; j < 13; j++) {
            al_draw_bitmap(sol3,(LARGEUR/2 - (j * 40)) + (i * 40), (20 * j)+ i * 20,0);
        }

    }*/

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
                al_draw_bitmap(sol4,POSITION_MAP_ISO_X - LARGEUR_TUILE /2 - (j * (LARGEUR_TUILE /2)) + (i * (LARGEUR_TUILE/2)), POSITION_MAP_ISO_Y + (HAUTEUR_TUILE/2 * j) + i * HAUTEUR_TUILE/2,0);

        }
    }
    //obstacles
    al_draw_bitmap(obstacleGlace, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+20, 0);
   // al_draw_bitmap(sol5, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+343, 0);
    //al_draw_bitmap(sol5, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+40, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+364, 0);
    //al_draw_bitmap(sol5, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+384, 0);
    al_draw_bitmap(sol5, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+39, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+365, 0);
    al_draw_bitmap(sol5, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+78, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+385, 0);
    al_draw_bitmap(obstacleGlace2, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+374, 0);

    //al_draw_bitmap(obstacle2, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+320, 0);
    //al_draw_bitmap(obstacle2, POSITION_MAP_ISO_X - LARGEUR_TUILE /2-120, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+157, 0);
   // al_draw_bitmap(herbe, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+115, 0);
    //al_draw_bitmap(lave, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+41, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+138, 0);
    al_flip_display();
}

/*
void dessinerArene(ALLEGRO_BITMAP *fond ){

    al_draw_scaled_bitmap(fond, 0, 0, 1920, 1080, 0, 0, LARGEUR, HAUTEUR, 0);

    for(int i = 0; i < 10; i++){
        al_draw_line((float)LARGEUR/2 + (i * 30), 20 + (i * 15), 20 + (i * 30), 400 + (i * 15), BLANC, 2);
    }
    for(int i = 0; i < 10; i++){
        al_draw_line((float)LARGEUR/2 - (i * 30), 20 + (i * 15), (float)LARGEUR - 20 - (i * 30), 400 + (i * 15), BLANC, 2);
    }

    al_flip_display();
}
*/

/*
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
}*/

void arene(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue){
    bool end = false;

    ALLEGRO_BITMAP *fond = al_load_bitmap("../Image/jungle.jpeg");


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