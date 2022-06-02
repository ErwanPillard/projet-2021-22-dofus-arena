//
// Created by erwan on 16/05/2022.
//

#include "deplacement.h"
#include "menu.h"

void surbrillanceDeplacementJoueur(CoordonneeISO coordonneeIso[][12], int x, int y, int PM, int map[][12]){

    if(PM >= 0 && x <= 11 && y <= 11 && x >= 0 && y >= 0){
        //si il n'y a pas d'obstacle (fichier txt):
        if(map[x][y] != 1){

            al_draw_filled_ellipse(coordonneeIso[x][y].x, coordonneeIso[x][y].y, 20, 15, BLEU);
        }

        surbrillanceDeplacementJoueur(coordonneeIso, x + 1, y, PM - 1, map);
        surbrillanceDeplacementJoueur(coordonneeIso, x - 1, y, PM - 1, map);
        surbrillanceDeplacementJoueur(coordonneeIso, x, y + 1, PM - 1, map);
        surbrillanceDeplacementJoueur(coordonneeIso, x, y - 1, PM - 1, map);
    }

}

void dessierDeplacementJoueur(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event, int distanceX, int distanceY, int positionJoueurX, int positionJoueurY, CoordonneeISO coordonneeIso[][12], Partie donneePartie, Joueur joueur[4], Classe classe[]){
    ALLEGRO_TIMER *timer = NULL;

    bool end = false;

    float x2 = coordonneeIso[positionJoueurX + distanceX][positionJoueurY + distanceY].x;
    float y2 = coordonneeIso[positionJoueurX + distanceX][positionJoueurY + distanceY].y;

    float x1 = coordonneeIso[positionJoueurX][positionJoueurY].x;
    float y1 = coordonneeIso[positionJoueurX][positionJoueurY].y;

    float coefDirecteur = (y2 - y1)/(x2 - x1);
    float b = y1 - coefDirecteur * x1;

    timer = al_create_timer(1.0/6);

    al_register_event_source(queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_TIMER:{
                coordonneeIso[positionJoueurX][positionJoueurY].x += 1;
                coordonneeIso[positionJoueurX][positionJoueurY].y += 1;

                dessinerArene(coordonneeIso, joueur, classe);
                //dessinerObsacle(map);
                al_draw_ellipse(coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].x, coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].y, 20, 15, BLEU, 3);
                dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie.nbJoueurs);
                al_flip_display();
                break;
            }
        }
        if(x1 == x2 && y1 == y2){

            end = true;
        }
    }
}

void deplacementJ(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], Joueur joueur[], int joueurEnCours, int map[][12]){
    int distanceX, distanceY;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            if(mouseX >= coordonneeIso[i][j].x - 20 && mouseX <= coordonneeIso[i][j].x + 20 && mouseY >= coordonneeIso[i][j].y - 15 && mouseY <= coordonneeIso[i][j].y + 15 && map[i][j] != 1){

                //Calcul la distance JOUEUR-CASE en nb de case
                distanceX = abs(joueur[joueurEnCours].caseX - i);
                distanceY = abs(joueur[joueurEnCours].caseY - j);
                if ((distanceX + distanceY) <= joueur[joueurEnCours].PM){
                    //dessierDeplacementJoueur(queue, event, distanceX, distanceY, joueur[joueurEnCours].caseX, joueur[joueurEnCours].caseY, coordonneeIso, donneePartie, joueur, classe);

                    map[joueur[joueurEnCours].caseX][joueur[joueurEnCours].caseY] = 0;
                    joueur[joueurEnCours].caseX = i;
                    joueur[joueurEnCours].caseY = j;
                    joueur[joueurEnCours].PM = joueur[joueurEnCours].PM - (distanceX + distanceY);
                    map[i][j] = 1;
                }
            }
        }
    }
}

void deplacement(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]){
    bool end = false;
    bool redessiner = true;

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                //Si on clic sur une case en surbrillance (3PM)
                //deplacementJoueur(event.mouse.x, event.mouse.y, coordonneeIso,joueur[donneePartie->joueurEnCours].caseX, joueur[donneePartie->joueurEnCours].caseY, joueur[donneePartie->joueurEnCours].PM, joueur, donneePartie->joueurEnCours, map);
                deplacementJ(event.mouse.x, event.mouse.y, coordonneeIso, joueur, donneePartie->joueurEnCours, map);
                //Si on veux changer de joueur en mode déplacement
                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    joueur[donneePartie->joueurEnCours].PM = 3;
                    donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour RAZ le timer : stop puis start
                }
                end = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                //Joueur suivant
                joueur[donneePartie->joueurEnCours].PM = 3;
                donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                end = true;
                break;
            }
        }

        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            //dessinerObsacle(map);
            surbrillanceDeplacementJoueur(coordonneeIso, joueur[donneePartie->joueurEnCours].caseX, joueur[donneePartie->joueurEnCours].caseY,joueur[donneePartie->joueurEnCours].PM, map);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
            al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);
            al_flip_display();
            redessiner = false;
        }
    }
}