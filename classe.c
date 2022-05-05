//
// Created by 33782 on 04/05/2022.
//

#include "classe.h"

void initialisationClasses(Classe *classe){

    //1er classe
    classe[0].fondEcran = al_load_bitmap("../Image/Classes/OmbreSrum/ombresram.jpg");
    classe[0].perso[0].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum1.png");
    classe[0].perso[1].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum2.png");
    classe[0].perso[2].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum3.png");
    classe[0].perso[3].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum4.png");
    classe[0].perso[4].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum5.png");
    classe[0].perso[5].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum6.png");
    classe[0].perso[6].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum7.png");
    classe[0].perso[7].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum8.png");

    classe[0].rectangle[VALIDER].x = 10;
    classe[0].rectangle[VALIDER].y = 10;
    classe[0].rectangle[VALIDER].hauteur = 10;
    classe[0].rectangle[VALIDER].largeur = 10;
}



void dessinerInterfaceClasses(Classe classe[], int classeEnCours, int posJoueur){
    al_clear_to_color(NOIR);
    al_draw_scaled_bitmap(classe[classeEnCours].fondEcran, 0, 0, 1200, 675, 0, 0, 1400, 807, 0);
    al_draw_bitmap(classe[classeEnCours].perso[posJoueur].image, (float)LARGEUR /2, (float)HAUTEUR / 2, 0);
    for (int i = 0; i < NB_RECT; i++) {
        al_draw_filled_rectangle(classe[classeEnCours].rectangle[i].x, classe[classeEnCours].rectangle[i].y, classe[classeEnCours].rectangle[i].x + classe[classeEnCours].rectangle[i].largeur, classe[classeEnCours].rectangle[i].y + classe[classeEnCours].rectangle[i].hauteur, BLANC);
    }
    al_flip_display();
}

void classe(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE* queue, Joueur *joueur, Classe *classe, int indiceJoueur, int classeEnCours, int posJoueur){
    al_wait_for_event(queue, &event);
    switch (event.type) {
        case ALLEGRO_EVENT_KEY_UP: {
            if (surPassageCase(event.mouse.x, event.mouse.y, classe[classeEnCours].rectangle[VALIDER])){
                joueur[indiceJoueur].classe = classeEnCours;
            }
            else if(surPassageCase(event.mouse.x, event.mouse.y, classe[classeEnCours].rectangle[CLASSE1])){
                classeEnCours = 1;
            }
            else if(surPassageCase(event.mouse.x, event.mouse.y, classe[classeEnCours].rectangle[CLASSE2])){
                classeEnCours = 2;
            }
            else if(surPassageCase(event.mouse.x, event.mouse.y, classe[classeEnCours].rectangle[CLASSE3])) {
                classeEnCours = 3;
            }
            else if(surPassageCase(event.mouse.x, event.mouse.y, classe[classeEnCours].rectangle[CLASSE4])){
                classeEnCours = 4;
            }
            else if(surPassageCase(event.mouse.x, event.mouse.y, classe[classeEnCours].rectangle[FLECHEDROITE])){
                posJoueur = (posJoueur + 1 ) % 8;
            }
            else if(surPassageCase(event.mouse.x, event.mouse.y, classe[classeEnCours].rectangle[FLECHEDROITE])){
                posJoueur = (posJoueur - 1 ) % 8;
            }
            break;
        }
    }
}