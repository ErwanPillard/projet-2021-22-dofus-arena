//
// Created by 33782 on 04/05/2022.
//

#include "classe.h"

Classe initialisationClasses(Classe classe[]){

    //1er classe
    classe[0].fondEcran = al_load_bitmap("../Image/ombresram.jpg");
    classe[0].perso[0].image = al_load_bitmap("../Image/ombresram1.png");
    classe[0].perso[1].image = al_load_bitmap("../Image/ombresram2.png");
    classe[0].perso[2].image = al_load_bitmap("../Image/ombresram3.png");
    classe[0].perso[3].image = al_load_bitmap("../Image/ombresram4.png");
    classe[0].perso[4].image = al_load_bitmap("../Image/ombresram5.png");
    classe[0].perso[5].image = al_load_bitmap("../Image/ombresram6.png");
    classe[0].perso[6].image = al_load_bitmap("../Image/ombresram7.png");
    classe[0].perso[7].image = al_load_bitmap("../Image/ombresram8.png");



}

void dessinerInterfaceClasses(Classe c[]){
    al_clear_to_color(NOIR);
    al_draw_scaled_bitmap(c[0].fondEcran, 0, 0, 1200, 675, 0, 0, 1400, 807, 0);
    al_flip_display();
}

void classe(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE* queue, Joueur joueur[], Partie donneePartie, Classe classe[]){
    int classeEncours;
    for (int i = 0; i < donneePartie.nbJoueurs; i++) {
        while(joueur[i].classe == 0) {
            al_wait_for_event(queue, &event);
            switch (event.type) {
                case ALLEGRO_EVENT_KEY_UP: {
                    if (surPassageCase(event.mouse.x, event.mouse.y, classe[0].rectangle[VALIDER])){

                    }
                    break;
                }
            }
        }
    }
}