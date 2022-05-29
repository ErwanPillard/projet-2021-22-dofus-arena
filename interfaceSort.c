//
// Created by Erwan Pillard on 29/05/2022.
//

#include "interfaceSort.h"
#include "menu.h"

void surbrillanceSortCercle(CoordonneeISO coordonneeIso[][12], int x, int y, int map[][12], Joueur joueur[], int joueurEnCours, Classe classe[], int numSort){
    int distanceX, distanceY;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            //Calcul la distance JOUEUR-CASE en nb de case
            distanceX = abs(joueur[joueurEnCours].caseX - i);
            distanceY = abs(joueur[joueurEnCours].caseY - j);
            if ((distanceX + distanceY) <= classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMax && (distanceX + distanceY) >= classe[joueur[joueurEnCours].classe].sorts[numSort].porteeMin){
                if(map[x][y] != 1){
                    al_draw_filled_ellipse(coordonneeIso[i][j].x, coordonneeIso[i][j].y, 20, 15, BLEU);
                }
            }
        }
    }
}

void applicationSort(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], Joueur joueur[], int joueurEnCours, int map[][12]){
    int distanceX, distanceY;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            if(mouseX >= coordonneeIso[i][j].x - 20 && mouseX <= coordonneeIso[i][j].x + 20 && mouseY >= coordonneeIso[i][j].y - 15 && mouseY <= coordonneeIso[i][j].y + 15 && map[i][j] != 1){

                //Calcul la distance JOUEUR-CASE en nb de case
                distanceX = abs(joueur[joueurEnCours].caseX - i);
                distanceY = abs(joueur[joueurEnCours].caseY - j);
                if ((distanceX + distanceY) <= 5 && (distanceX + distanceY) >= 4){

                }
            }
        }
    }
}

void sort1(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]){
    bool end = false;
    bool redessiner = false;

    dessinerArene(coordonneeIso, joueur, classe);
    surbrillanceSortCercle(coordonneeIso, joueur[donneePartie->joueurEnCours].caseX, joueur[donneePartie->joueurEnCours].caseY, map, joueur, donneePartie->joueurEnCours, classe, 0);
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

