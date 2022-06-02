//
// Created by Erwan Pillard on 29/05/2022.
//

#include "interfaceSort.h"
#include "menu.h"
#include "deplacement.h"

void surbrillanceSortCercle(CoordonneeISO coordonneeIso[][12], int x, int y, int map[][12], Joueur joueur[], int joueurEnCours, Classe classe[], int numSort){
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

void applicationSort(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], Joueur joueur[], int joueurEnCours, int map[][12]){
    int distanceX, distanceY;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            if(mouseX >= coordonneeIso[i][j].x - 20 && mouseX <= coordonneeIso[i][j].x + 20 && mouseY >= coordonneeIso[i][j].y - 15 && mouseY <= coordonneeIso[i][j].y + 15){

                //Calcul la distance JOUEUR-CASE en nb de case
                distanceX = abs(joueur[joueurEnCours].caseX - i);
                distanceY = abs(joueur[joueurEnCours].caseY - j);
                if ((distanceX + distanceY) <= 5 && (distanceX + distanceY) >= 4){
                    /*
                    for (int k = 0; k < nbJoueurs; k++) {
                        if(joueur[k].caseX == i && joueur[k].caseY == j){
                            //joueur[k].PA -= dega du sort
                        }
                    }
                     */
                }
            }
        }
    }
}

void surbrillanceLigneDroite(CoordonneeISO coordonneeIso[][12], int x, int y, int map[][12], Joueur joueur[], int joueurEnCours, Classe classe[], int numSort){
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

void sortLigneDroite(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]){
    bool end = false;
    bool redessiner = true;

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{

                applicationSort(event.mouse.x, event.mouse.y, coordonneeIso, joueur, donneePartie->joueurEnCours, map);

                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    joueur[donneePartie->joueurEnCours].PM = 3;
                    donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
                }
                end = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                joueur[donneePartie->joueurEnCours].PM = 3;
                donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                end = true;
                break;
            }
        }
        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            surbrillanceLigneDroite(coordonneeIso, joueur[donneePartie->joueurEnCours].caseX, joueur[donneePartie->joueurEnCours].caseY, map, joueur, donneePartie->joueurEnCours, classe, 1);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
            al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);
            al_draw_bitmap(r[BOUTON].image, 1150, 200, 0);
            al_draw_bitmap(r[BOUTON2].image, 100, 200, 0);
            al_draw_bitmap(r[HORLOGE].image, 550 , 10, 0);
            al_flip_display();
            redessiner = false;
        }
    }
}

void sortCercle(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]){
    bool end = false;
    bool redessiner = true;

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{

                applicationSort(event.mouse.x, event.mouse.y, coordonneeIso, joueur, donneePartie->joueurEnCours, map);

                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    joueur[donneePartie->joueurEnCours].PM = 3;
                    donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
                }
                end = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                joueur[donneePartie->joueurEnCours].PM = 3;
                donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                end = true;
                break;
            }
        }

        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            surbrillanceSortCercle(coordonneeIso, joueur[donneePartie->joueurEnCours].caseX, joueur[donneePartie->joueurEnCours].caseY, map, joueur, donneePartie->joueurEnCours, classe, 0);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
            al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);
            al_draw_bitmap(r[BOUTON].image, 1150, 200, 0);
            al_draw_bitmap(r[BOUTON2].image, 100, 200, 0);
            al_draw_bitmap(r[HORLOGE].image, 550 , 10, 0);
            al_flip_display();
            redessiner = false;
        }
    }
}

void sort6(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]){
    bool end = false;
    bool redessiner = false;

    dessinerArene(coordonneeIso, joueur, classe);
    surbrillanceSortCercle(coordonneeIso, joueur[donneePartie->joueurEnCours].caseX, joueur[donneePartie->joueurEnCours].caseY, map, joueur, donneePartie->joueurEnCours, classe, 6);
    dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
    al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
    al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
    al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
    al_flip_display();

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{

                applicationSort(event.mouse.x, event.mouse.y, coordonneeIso, joueur, donneePartie->joueurEnCours, map);

                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    joueur[donneePartie->joueurEnCours].PM = 3;
                    donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
                }
                end = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                joueur[donneePartie->joueurEnCours].PM = 3;
                donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                end = true;
                break;
            }
        }

        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
            al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_flip_display();
            redessiner = false;
        }

    }
}

void sort11(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]){
    bool end = false;
    bool redessiner = false;

    dessinerArene(coordonneeIso, joueur, classe);
    surbrillanceSortCercle(coordonneeIso, joueur[donneePartie->joueurEnCours].caseX, joueur[donneePartie->joueurEnCours].caseY, map, joueur, donneePartie->joueurEnCours, classe, 11);
    dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
    al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
    al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
    al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
    al_flip_display();

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{

                applicationSort(event.mouse.x, event.mouse.y, coordonneeIso, joueur, donneePartie->joueurEnCours, map);

                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    joueur[donneePartie->joueurEnCours].PM = 3;
                    donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
                }
                end = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                joueur[donneePartie->joueurEnCours].PM = 3;
                donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                end = true;
                break;
            }
        }

        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
            al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_flip_display();
            redessiner = false;
        }

    }
}

void sort16(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]){
    bool end = false;
    bool redessiner = false;

    dessinerArene(coordonneeIso, joueur, classe);
    surbrillanceSortCercle(coordonneeIso, joueur[donneePartie->joueurEnCours].caseX, joueur[donneePartie->joueurEnCours].caseY, map, joueur, donneePartie->joueurEnCours, classe, 16);
    dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
    al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
    al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
    al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
    al_flip_display();

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{

                applicationSort(event.mouse.x, event.mouse.y, coordonneeIso, joueur, donneePartie->joueurEnCours, map);

                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    joueur[donneePartie->joueurEnCours].PM = 3;
                    donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
                }
                end = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                joueur[donneePartie->joueurEnCours].PM = 3;
                donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                end = true;
                break;
            }
        }

        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
            al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_flip_display();
            redessiner = false;
        }

    }
}
