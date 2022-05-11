#include "arene.h"


//****************************************Initialiser***************************************//
void initialiserCoordMilieuTuile(CoordonneeISO coordonneeIso[12][12]){
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            coordonneeIso[i][j].x = POSITION_MAP_ISO_X - LARGEUR_TUILE /2 - (j * (LARGEUR_TUILE /2)) + (i * (LARGEUR_TUILE/2)) + LARGEUR_TUILE/2;
            coordonneeIso[i][j].y = POSITION_MAP_ISO_Y + (HAUTEUR_TUILE/2 * j) + i * HAUTEUR_TUILE/2 + HAUTEUR_TUILE/2;
        }
    }
}

void dessinerSurbrillance(CoordonneeISO coordonneeIso[12][12]){

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            printf("[%d][%d] x : %f y : %f\n", i,j, coordonneeIso[i][j].x, coordonneeIso[i][j].y);
        }
    }
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            al_draw_filled_ellipse(coordonneeIso[i][j].x, coordonneeIso[i][j].y, 20, 15, BLANC);
        }
    }
}

void dessinerJoueur(CoordonneeISO coordonneeIso[12][12], Joueur joueur[]){
    al_draw_filled_ellipse(coordonneeIso[joueur[0].caseX][joueur[0].caseY].x, coordonneeIso[joueur[0].caseX][joueur[0].caseY].y, 20, 15, BLANC);
}

void dessinerArene(ALLEGRO_BITMAP *fond, CoordonneeISO coordonneeIso[12][12], Joueur joueur[4]){
    al_draw_scaled_bitmap(fond, 0, 0, 1952, 1008, 0, 0, LARGEUR, HAUTEUR, 0);
    ALLEGRO_BITMAP *sol = al_load_bitmap("../Image/sol.png");
    ALLEGRO_BITMAP *sol2 = al_load_bitmap("../Image/sol2.png");
    ALLEGRO_BITMAP *sol3 = al_load_bitmap("../Image/sol3.png");
    ALLEGRO_BITMAP *sol4 = al_load_bitmap("../Image/sol4.png");
    ALLEGRO_BITMAP *sol5 = al_load_bitmap("../Image/sol5.png");
    ALLEGRO_BITMAP *sol6 = al_load_bitmap("../Image/sol6.png");

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            al_draw_bitmap(sol6,POSITION_MAP_ISO_X - LARGEUR_TUILE /2 - (j * (LARGEUR_TUILE /2)) + (i * (LARGEUR_TUILE/2)), POSITION_MAP_ISO_Y + (HAUTEUR_TUILE/2 * j) + i * HAUTEUR_TUILE/2,0);
        }
    }

    //dessinerSurbrillance(coordonneeIso);

    dessinerJoueur(coordonneeIso, joueur);
    al_flip_display();
}


void arene(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4]){
    bool end = false;

    ALLEGRO_BITMAP *fond = al_load_bitmap("../Image/jungle.jpeg");
    CoordonneeISO coordonneeIso[12][12];

    initialiserCoordMilieuTuile(coordonneeIso);

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                end = true;
                break;
            }
        }
        dessinerArene(fond, coordonneeIso, joueur);
    }
}