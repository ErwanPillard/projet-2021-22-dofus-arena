//
// Created by erwan on 16/05/2022.
//

#include "deplacement.h"

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

void deplacementJoueur(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], int x, int y, int PM, Joueur joueur[], int joueurEnCours, int map[][12]){

    if(PM >= 0 && x <= 11 && y <= 11 && x >= 0 && y >= 0){

        if(mouseX >= coordonneeIso[x][y].x - 20 && mouseX <= coordonneeIso[x][y].x + 20 && mouseY >= coordonneeIso[x][y].y - 15 && mouseY <= coordonneeIso[x][y].y + 15 && map[x][y] != 1/*&& si il n'y a pas d'obstacle (fichier txt*/){
            map[joueur[joueurEnCours].caseX][joueur[joueurEnCours].caseY] = 0; // libère la case occupé par le joueur
            joueur[joueurEnCours].caseX = x;
            joueur[joueurEnCours].caseY = y;
            joueur[joueurEnCours].PM = PM;
            map[x][y] = 1; //case sur laquelle arrive le joueur est occupé
        }

        deplacementJoueur(mouseX, mouseY, coordonneeIso, x + 1, y, PM - 1, joueur, joueurEnCours, map);
        deplacementJoueur(mouseX, mouseY, coordonneeIso, x - 1, y, PM - 1, joueur, joueurEnCours, map);
        deplacementJoueur(mouseX, mouseY, coordonneeIso, x, y + 1, PM - 1, joueur, joueurEnCours, map);
        deplacementJoueur(mouseX, mouseY, coordonneeIso, x, y - 1, PM - 1, joueur, joueurEnCours, map);
    }
}
/*
int deplacementJoueurs(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], Joueur joueur[]){
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            if(mouseX >= coordonneeIso[i][j].x - 20 && mouseX <= coordonneeIso[i][j].x + 20 && mouseY >= coordonneeIso[i][j].y - 15 && mouseY <= coordonneeIso[i][j].y + 15){
                joueur[0].caseX = i;
                joueur[0].caseY = j;
            }
        }
    }
}
*/

void deplacement(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie donneePartie, ALLEGRO_TIMER *timer){
    bool end = false;
    bool redessiner = false;

    int map[12][12];
    FILE* file = NULL;
    file = fopen("../map.txt", "r");

    for(int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++) {
            fscanf(file, "%d", &map[i][j]);
            printf("%d", map[i][j]);
        }
        printf("\n");
    }

    dessinerArene(coordonneeIso, joueur, classe);
    surbrillanceDeplacementJoueur(coordonneeIso, joueur[donneePartie.joueurEnCours].caseX, joueur[donneePartie.joueurEnCours].caseY,joueur[0].PM, map);
    dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie.nbJoueurs);
    al_flip_display();

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                deplacementJoueur(event.mouse.x, event.mouse.y, coordonneeIso,joueur[donneePartie.joueurEnCours].caseX, joueur[donneePartie.joueurEnCours].caseY, joueur[donneePartie.joueurEnCours].PM, joueur, donneePartie.joueurEnCours, map);


                redessiner = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                joueur[donneePartie.joueurEnCours].PM = 3;
                donneePartie.joueurEnCours = (donneePartie.joueurEnCours + 1) % donneePartie.nbJoueurs;
                redessiner = true;
                break;
            }
        }
        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            surbrillanceDeplacementJoueur(coordonneeIso, joueur[donneePartie.joueurEnCours].caseX, joueur[donneePartie.joueurEnCours].caseY,joueur[donneePartie.joueurEnCours].PM, map);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie.nbJoueurs);
            al_flip_display();
            redessiner = false;
        }
    }
}