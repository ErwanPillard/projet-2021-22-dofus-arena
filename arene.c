#include "arene.h"
#include "deplacement.h"
//****************************************Initialiser***************************************//

void initialiserCoordMilieuTuile(CoordonneeISO coordonneeIso[12][12]){
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            coordonneeIso[i][j].x = POSITION_MAP_ISO_X - LARGEUR_TUILE /2 - (j * (LARGEUR_TUILE /2)) + (i * (LARGEUR_TUILE/2)) + LARGEUR_TUILE/2;
            coordonneeIso[i][j].y = POSITION_MAP_ISO_Y + (HAUTEUR_TUILE/2 * j) + i * HAUTEUR_TUILE/2 + HAUTEUR_TUILE/2;
        }
    }
}

void initialiserArene(int map[][12]){
    FILE* file = NULL;
    file = fopen("../map.txt", "r");

    for(int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++) {
            fscanf(file, "%d", &map[i][j]);
        }
        //printf("\n");
    }
    fclose(file);
}



//****************************************Dessiner***************************************//
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

void dessinerJoueurs(CoordonneeISO coordonneeIso[12][12], Joueur joueur[], Classe classe[], int nbJoueurs){
    for(int i = 0; i < nbJoueurs; i++){
        al_draw_scaled_bitmap(classe[joueur[i].classe].skin, 0, 0, 250,250, coordonneeIso[joueur[i].caseX][joueur[i].caseY].x - 42, coordonneeIso[joueur[i].caseX][joueur[i].caseY].y - 83, 100, 100, 0);
    }
}

void dessinerObsacle(int map[][12]){
    ALLEGRO_BITMAP *obstacle1 = al_load_bitmap("../Image/obstacle1.png");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            if(map[i][j] == 2){
                //al_draw_bitmap(obstacle1,POSITION_MAP_ISO_X - LARGEUR_TUILE /2 - (j * (LARGEUR_TUILE /2)) + (i * (LARGEUR_TUILE/2)), POSITION_MAP_ISO_Y + (HAUTEUR_TUILE/2 * j) + i * HAUTEUR_TUILE/2 - 31,0);
                al_draw_scaled_bitmap(obstacle1, 0, 0, 80, 72, POSITION_MAP_ISO_X - LARGEUR_TUILE /2 - (j * (LARGEUR_TUILE /2)) + (i * (LARGEUR_TUILE/2)) + 3, POSITION_MAP_ISO_Y + (HAUTEUR_TUILE/2 * j) + i * HAUTEUR_TUILE/2 - 28,74, 67,0);
            }
        }
    }
}

void dessinerCompteur(int tmp, ALLEGRO_FONT *compteur){
    al_draw_textf(compteur, BLEU, 10,10, 0, "%d", tmp);
}

/*
void dessinerObsacle(){
    ALLEGRO_BITMAP *obstacle1 = al_load_bitmap("../Image/obstacle1.png");
    ALLEGRO_BITMAP *obstacle2 = al_load_bitmap("../Image/obstacle2.png");
    ALLEGRO_BITMAP *obstacleGlace = al_load_bitmap("../Image/obstacleGlace.png");
    ALLEGRO_BITMAP *obstacleGlace2 = al_load_bitmap("../Image/gl.png");
    ALLEGRO_BITMAP *herbe = al_load_bitmap("../Image/herbe.png");
    ALLEGRO_BITMAP *lave = al_load_bitmap("../Image/lave.png");
    ALLEGRO_BITMAP *grosarbre = al_load_bitmap("../Image/arbrevol2.png");
    ALLEGRO_BITMAP *arbrerose = al_load_bitmap("../Image/arbrerose.png");
    ALLEGRO_BITMAP *kamas = al_load_bitmap("../Image/kamas.png");
    ALLEGRO_BITMAP *Huppermagepv = al_load_bitmap("../Image/Huppermagepng.png");
    ALLEGRO_BITMAP *CoeurIop = al_load_bitmap("../Image/CoeurIop.png");
    ALLEGRO_BITMAP *Iniripsa = al_load_bitmap("../Image/Iniripsa.png");

    //obstacles
    al_draw_bitmap(obstacleGlace, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+20, 0);

    // dessiner bitmap sors joueurs
    al_draw_bitmap(Huppermagepv, 20, 20, 0);//Sors huppermage
    al_draw_bitmap(CoeurIop, 20, 20, 0);//Sors Coeurs D'iop etc..
    al_draw_bitmap(Iniripsa, 20, 20, 0);//Sors iniripsa

    al_draw_bitmap(kamas, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+10, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+177, 0);
    al_draw_bitmap(arbrerose, POSITION_MAP_ISO_X - LARGEUR_TUILE /2-247, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+166, 0);
    //al_draw_bitmap(sol5, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+78, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+385, 0);
    al_draw_bitmap(obstacleGlace2, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+374, 0);

    //al_draw_bitmap(obstacle2, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+320, 0);
    //al_draw_bitmap(obstacle2, POSITION_MAP_ISO_X - LARGEUR_TUILE /2-120, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+157, 0);
    // al_draw_bitmap(herbe, POSITION_MAP_ISO_X - LARGEUR_TUILE /2, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+115, 0);
    //al_draw_bitmap(lave, POSITION_MAP_ISO_X - LARGEUR_TUILE /2+41, POSITION_MAP_ISO_Y +HAUTEUR_TUILE/2+138, 0);
}
*/
void dessinerArene(CoordonneeISO coordonneeIso[12][12], Joueur joueur[4], Classe classe[]){
    ALLEGRO_BITMAP *fond = al_load_bitmap("../Image/Map3.png");
    al_draw_scaled_bitmap(fond, 0, 0, 1397, 807, 0, 0, LARGEUR, HAUTEUR, 0);
    ALLEGRO_BITMAP *sol = al_load_bitmap("../Image/sol.png");
    ALLEGRO_BITMAP *sol2 = al_load_bitmap("../Image/sol2.png");
    ALLEGRO_BITMAP *sol3 = al_load_bitmap("../Image/sol3.png");
    ALLEGRO_BITMAP *sol4 = al_load_bitmap("../Image/sol4.png");
    ALLEGRO_BITMAP *sol5 = al_load_bitmap("../Image/sol5.png");
    ALLEGRO_BITMAP *sol6 = al_load_bitmap("../Image/sol6.png");
    ALLEGRO_BITMAP *test= al_load_bitmap("../Image/test.png");

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            al_draw_bitmap(sol4,POSITION_MAP_ISO_X - LARGEUR_TUILE /2 - (j * (LARGEUR_TUILE /2)) + (i * (LARGEUR_TUILE/2)), POSITION_MAP_ISO_Y + (HAUTEUR_TUILE/2 * j) + i * HAUTEUR_TUILE/2,0);
        }
    }
    al_draw_bitmap(test, 300, 300, 0);


    //dessinerSurbrillance(coordonneeIso);

    //dessinerJoueur(coordonneeIso, joueur, classe);
    //dessinerObstacle(CoordonneeISO coordonneeIso[12][12]);
}