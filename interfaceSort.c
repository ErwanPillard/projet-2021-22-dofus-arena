//
// Created by Erwan Pillard on 29/05/2022.
//

#include "interfaceSort.h"
#include "menu.h"
#include "deplacement.h"

void surbrillanceSortCercle(CoordonneeISO coordonneeIso[][12], Joueur joueur[], int joueurEnCours, Classe classe[], int numSort){
    int distanceX, distanceY;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            //Calcul la distance JOUEUR-CASE en nb de case
            distanceX = abs(joueur[joueurEnCours].caseX - i);
            distanceY = abs(joueur[joueurEnCours].caseY - j);
            if ((distanceX + distanceY) <= classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax && (distanceX + distanceY) >= classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMin){
                al_draw_filled_ellipse(coordonneeIso[i][j].x, coordonneeIso[i][j].y, 20, 15, BLEU);
            }
        }
    }
}

void surbrillanceLigneDroite(CoordonneeISO coordonneeIso[][12], Joueur joueur[], int joueurEnCours, Classe classe[], int numSort){
    //Ligne 1
    for (int i = joueur[joueurEnCours].caseX - classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax; i <= joueur[joueurEnCours].caseX + classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax; i++) {
        if(i <= 11 && i >= 0 && classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMin <= abs(joueur[joueurEnCours].caseX - i)){
            al_draw_filled_ellipse(coordonneeIso[i][joueur[joueurEnCours].caseY].x, coordonneeIso[i][joueur[joueurEnCours].caseY].y, 20, 15, BLEU);
        }
    }

    //Ligne 2
    for (int i = joueur[joueurEnCours].caseY - classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax; i <= joueur[joueurEnCours].caseY + classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax; i++) {
        if(i <= 11 && i >= 0 && classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMin <= abs(joueur[joueurEnCours].caseY - i)){
            al_draw_filled_ellipse(coordonneeIso[joueur[joueurEnCours].caseX][i].x, coordonneeIso[joueur[joueurEnCours].caseX][i].y, 20, 15, BLEU);
        }
    }
}

void choixSort(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[],Partie donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12], int numSort, int type, Rect r2[], ALLEGRO_BITMAP *tabClasses[]){
    switch (type) {
        case CERCLE:{
            sortCercle(event, queue, coordonneeIso, joueur, classe, &donneePartie, timer, r, map, numSort, r2, tabClasses);
            break;
        }
        case LIGNE:{
            sortLigneDroite(event, queue, coordonneeIso, joueur, classe, &donneePartie, timer, r, map, numSort, r2, tabClasses);
            break;
        }
    }
}

int applicationSortCercle(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], Joueur joueur[], int joueurEnCours, Classe classe[], int numSort, int* cibleX, int* cibleY){
    int distanceX, distanceY;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            if(mouseX >= coordonneeIso[i][j].x - 20 && mouseX <= coordonneeIso[i][j].x + 20 && mouseY >= coordonneeIso[i][j].y - 15 && mouseY <= coordonneeIso[i][j].y + 15){

                //Calcul la distance JOUEUR-CASE en nb de case
                distanceX = abs(joueur[joueurEnCours].caseX - i);
                distanceY = abs(joueur[joueurEnCours].caseY - j);
                if ((distanceX + distanceY) <= classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax && (distanceX + distanceY) >= classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMin){
                    *cibleX = i;
                    *cibleY = j;
                    joueur[joueurEnCours].PA = joueur[joueurEnCours].PA -  classe[joueur[joueurEnCours].classe].sorts[numSort].nombrePA;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int applicationSortLigne(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], Joueur joueur[], int joueurEnCours, Classe classe[], int numSort, int* cibleX, int* cibleY){
    //Ligne 1
    for (int i = joueur[joueurEnCours].caseX - classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax; i <= joueur[joueurEnCours].caseX + classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax; i++) {
        if(i <= 11 && i >= 0 && classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMin <= abs(joueur[joueurEnCours].caseX - i)){
            if(mouseX >= coordonneeIso[i][joueur[joueurEnCours].caseY].x - 20 && mouseX <= coordonneeIso[i][joueur[joueurEnCours].caseY].x + 20 && mouseY >= coordonneeIso[i][joueur[joueurEnCours].caseY].y - 15 && mouseY <= coordonneeIso[i][joueur[joueurEnCours].caseY].y + 15){
                *cibleX = i;
                *cibleY = joueur[joueurEnCours].caseY;
                joueur[joueurEnCours].PA = joueur[joueurEnCours].PA -  classe[joueur[joueurEnCours].classe].sorts[numSort].nombrePA;
                return true;
            }
        }
    }

    //Ligne 2
    for (int i = joueur[joueurEnCours].caseY - classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax; i <= joueur[joueurEnCours].caseY + classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax; i++) {
        if(i <= 11 && i >= 0 && classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMin <= abs(joueur[joueurEnCours].caseY - i)){
            if(mouseX >= coordonneeIso[joueur[joueurEnCours].caseX][i].x - 20 && mouseX <= coordonneeIso[joueur[joueurEnCours].caseX][i].x + 20 && mouseY >= coordonneeIso[joueur[joueurEnCours].caseX][i].y - 15 && mouseY <= coordonneeIso[joueur[joueurEnCours].caseX][i].y + 15){
                *cibleX = joueur[joueurEnCours].caseX;
                *cibleY = i;
                joueur[joueurEnCours].PA = joueur[joueurEnCours].PA -  classe[joueur[joueurEnCours].classe].sorts[numSort].nombrePA;
                return true;
            }
        }
    }
    return false;
}

void verifSiJoueurSurCase(int cibleX, int cibleY,int nbJoueurs, Joueur joueur[], Classe classe[], int numSort){
    for (int i = 0; i < nbJoueurs; i++) {
        if (joueur[i].caseX == cibleX && joueur[i].caseY == cibleY){
            joueur[i].PV = joueur[i].PV - classe[joueur[i].classe].sorts[numSort].nombrePVinflige;
        }
    }
}

void sortLigneDroite(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12], int numSort, Rect r2[], ALLEGRO_BITMAP *tabClasses[]){
    bool end = false;
    bool redessiner = true;
    bool animation = false;
    ALLEGRO_SAMPLE *whoosh2 = al_load_sample("../Sound/whoosh2.ogg");

    int cibleX, cibleY;

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{

                animation = applicationSortLigne(event.mouse.x, event.mouse.y, coordonneeIso, joueur, donneePartie->joueurEnCours, classe, numSort, &cibleX, &cibleY);
                printf("%d | %d", cibleX, cibleY);
                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    al_play_sample(whoosh2, 10.0f, 0.0f, 2.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                    joueur[donneePartie->joueurEnCours].PM = 3;
                    joueur[donneePartie->joueurEnCours].PA = 6;
                    donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
                    end = true;
                }
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                al_play_sample(whoosh2, 10.0f, 0.0f, 2.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                joueur[donneePartie->joueurEnCours].PM = 3;
                joueur[donneePartie->joueurEnCours].PA = 6;
                donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                end = true;
                break;
            }
        }
        if(animation == true){
            dessinerSortsGlace(queue,event,coordonneeIso,joueur,classe,donneePartie, r, cibleX, cibleY, r2, tabClasses);
            verifSiJoueurSurCase(cibleX, cibleY, donneePartie->nbJoueurs, joueur, classe, numSort);
            redessiner = true;
            animation = false;
            end = true;
        }

        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            surbrillanceLigneDroite(coordonneeIso, joueur, donneePartie->joueurEnCours, classe, 1);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
            al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);

            dessinerParametreJoueur(r2, *donneePartie, joueur, classe, tabClasses);

            al_flip_display();
            redessiner = false;
        }
    }
}

void sortCercle(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12], int numSort, Rect r2[], ALLEGRO_BITMAP *tabClasses[]){
    bool end = false;
    bool redessiner = true;
    bool animation = false;
    ALLEGRO_SAMPLE *whoosh2 = al_load_sample("../Sound/whoosh2.ogg");

    int cibleX, cibleY;

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                //dessinerSortsGlace(queue,event,coordonneeIso,joueur,classe,donneePartie,r,map);

                animation = applicationSortCercle(event.mouse.x, event.mouse.y, coordonneeIso, joueur, donneePartie->joueurEnCours, classe, numSort, &cibleX, &cibleY);

                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    al_play_sample(whoosh2, 10.0f, 0.0f, 2.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                    joueur[donneePartie->joueurEnCours].PM = 3;
                    joueur[donneePartie->joueurEnCours].PA = 6;
                    donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
                }
                end = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                al_play_sample(whoosh2, 10.0f, 0.0f, 2.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                joueur[donneePartie->joueurEnCours].PM = 3;
                joueur[donneePartie->joueurEnCours].PA = 6;
                donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                end = true;
                break;
            }
        }

        if(animation == true){
            dessinerSortsGlace(queue,event,coordonneeIso,joueur,classe,donneePartie,r, cibleX, cibleY, r2, tabClasses);
            verifSiJoueurSurCase(cibleX, cibleY, donneePartie->nbJoueurs, joueur, classe, numSort);
            redessiner = true;
            animation = false;
            end = true;
        }

        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            surbrillanceSortCercle(coordonneeIso, joueur, donneePartie->joueurEnCours, classe, 0);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
            al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);

            dessinerParametreJoueur(r2, *donneePartie, joueur, classe, tabClasses);

            al_flip_display();
            redessiner = false;
        }
    }
}

void dessinerSortsGlace(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, Rect r[5], int cibleX, int cibleY, Rect r2[], ALLEGRO_BITMAP *tabClasses[]){
    ALLEGRO_TIMER *timer2 = NULL;
    float i = 0;
    bool end = false;

    ALLEGRO_BITMAP *sortGlace= al_load_bitmap("../Image/sortGlace.png");

    ALLEGRO_SAMPLE *explosion = al_load_sample("../Sound/explosion_grenade.ogg");

    timer2 = al_create_timer(1.0/60);

    al_register_event_source(queue, al_get_timer_event_source(timer2));

    al_start_timer(timer2);


    while (!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_TIMER: {

                dessinerArene(coordonneeIso, joueur, classe);
                dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
                al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
                al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
                al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
                al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);

                al_draw_bitmap(sortGlace, coordonneeIso[cibleX][cibleY].x - 30, i, 0);

                i = i + 10;

                al_flip_display();
                break;
            }
        }
        if(i >= coordonneeIso[cibleX][cibleY].y - 40){
            al_play_sample(explosion, 1.0f, 0.0f, 2.0f, ALLEGRO_PLAYMODE_ONCE, 0);
            end = true;
        }
    }
    al_destroy_timer(timer2);
}