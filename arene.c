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
    ALLEGRO_BITMAP *obstacle1 = al_load_bitmap("../Image/obstacle1.png");
    ALLEGRO_BITMAP *obstacle2 = al_load_bitmap("../Image/obstacle2.png");
    ALLEGRO_BITMAP *obstacleGlace = al_load_bitmap("../Image/obstacleGlace.png");
    ALLEGRO_BITMAP *obstacleGlace2 = al_load_bitmap("../Image/gl.png");
    ALLEGRO_BITMAP *herbe = al_load_bitmap("../Image/herbe.png");
    ALLEGRO_BITMAP *lave = al_load_bitmap("../Image/lave.png");
    ALLEGRO_BITMAP *grosarbre = al_load_bitmap("../Image/arbrevol2.png");
    ALLEGRO_BITMAP *arbrerose = al_load_bitmap("../Image/arbrerose.png");
    ALLEGRO_BITMAP *kamas = al_load_bitmap("../Image/kamas.png");

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            al_draw_bitmap(sol6,POSITION_MAP_ISO_X - LARGEUR_TUILE /2 - (j * (LARGEUR_TUILE /2)) + (i * (LARGEUR_TUILE/2)), POSITION_MAP_ISO_Y + (HAUTEUR_TUILE/2 * j) + i * HAUTEUR_TUILE/2,0);
        }
    }

    //dessinerSurbrillance(coordonneeIso);

    dessinerJoueur(coordonneeIso, joueur);

    //obstacles
    al_draw_bitmap(obstacleGlace, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+20, 0);
    al_draw_bitmap(kamas, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+10, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+177, 0);
    al_draw_bitmap(arbrerose, POSITION_MAP_ISO_X - LARGEUR_TUILE /2-247, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+166, 0);
    al_draw_bitmap(sol5, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+39, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+365, 0);
    //al_draw_bitmap(sol5, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+78, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+385, 0);
    al_draw_bitmap(obstacleGlace2, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+374, 0);

    //al_draw_bitmap(obstacle2, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+320, 0);
    //al_draw_bitmap(obstacle2, POSITION_MAP_ISO_X - LARGEUR_TUILE /2-120, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+157, 0);
    // al_draw_bitmap(herbe, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+115, 0);
    //al_draw_bitmap(lave, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+41, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+138, 0);
    al_flip_display();
}


void arene(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4]){
    bool end = false;

    ALLEGRO_BITMAP *fond = al_load_bitmap("../Image/Map3.png");
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