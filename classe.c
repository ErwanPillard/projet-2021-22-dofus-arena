//
// Created by 33782 on 04/05/2022.
//

#include "classe.h"

#include "stdio.h"
void initialisationClasses(Classe *classe){
    //1er classe
    classe[0].fondEcran = al_load_bitmap("../Image/Classes/OmbreSrum/ombresram.jpg");
    classe[0].infoClasse = al_load_bitmap("../Image/Classes/OmbreSrum/infoSram.png");
    classe[0].fleche = al_load_bitmap("../Image/fleche.png");

    classe[0].perso[0].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum1.png");
    classe[0].perso[1].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum2.png");
    classe[0].perso[2].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum3.png");
    classe[0].perso[3].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum4.png");
    classe[0].perso[4].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum5.png");
    classe[0].perso[5].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum6.png");
    classe[0].perso[6].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum7.png");
    classe[0].perso[7].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum8.png");

    classe[0].rectangle[VALIDER].hauteur = 50;
    classe[0].rectangle[VALIDER].largeur = 100;
    classe[0].rectangle[VALIDER].x = 1200;
    classe[0].rectangle[VALIDER].y = 700;
    classe[0].rectangle[VALIDER].color = VERT;

    classe[0].rectangle[FLECHEDROITE].x = (float)LARGEUR /2 - 30;
    classe[0].rectangle[FLECHEDROITE].y = (float)HAUTEUR /2;
    classe[0].rectangle[FLECHEDROITE].hauteur = 80;
    classe[0].rectangle[FLECHEDROITE].largeur = 100;
    classe[0].rectangle[FLECHEDROITE].color = BLANC;

    classe[0].rectangle[CLASSE1].hauteur = 50;
    classe[0].rectangle[CLASSE1].largeur = 50;
    classe[0].rectangle[CLASSE1].x = 550;
    classe[0].rectangle[CLASSE1].y = 700;
    classe[0].rectangle[CLASSE1].color = BLANC;

    classe[0].rectangle[CLASSE2].hauteur = 50;
    classe[0].rectangle[CLASSE2].largeur = 50;
    classe[0].rectangle[CLASSE2].x = 605;
    classe[0].rectangle[CLASSE2].y = 700;
    classe[0].rectangle[CLASSE2].color = BLANC;


    classe[1].fondEcran = al_load_bitmap("../Image/Classes/CoeurIop/IOP.jpg");
    classe[1].infoClasse = al_load_bitmap("../Image/Classes/CoeurIop/IOP.png");
    classe[1].perso[0].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    classe[1].perso[1].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP2.png");
    classe[1].perso[2].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP3.png");
    classe[1].perso[3].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP4.png");
    classe[1].perso[4].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP5.png");
    classe[1].perso[5].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP6.png");
    classe[1].perso[6].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP7.png");
    classe[1].perso[7].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP8.png");

    classe[1].rectangle[VALIDER].hauteur = 50;
    classe[1].rectangle[VALIDER].largeur = 100;
    classe[1].rectangle[VALIDER].x = 1200;
    classe[1].rectangle[VALIDER].y = 700;
    classe[1].rectangle[VALIDER].color = VERT;
}

void dessinerImageFond(int classeEnCours, Classe classe[]){
    switch (classeEnCours) {
        case 0:{
            al_draw_scaled_bitmap(classe[0].fondEcran, 0, 0, 1200, 675, 0, 0, 1400, 807, 0);
            al_draw_scaled_bitmap(classe[0].infoClasse, 0, 0, 878, 1240, 30, 0, 585, 826, 0);
            break;
        }
        case 1:{
            al_draw_scaled_bitmap(classe[1].fondEcran, 0, 0, 1920, 1080, 0, 0, 1400, 807, 0);
            al_draw_scaled_bitmap(classe[1].infoClasse, 0, 0, 882, 1250, 30, 0, 585, 826, 0);
            break;
        }
    }
}

void dessinerInterfaceClasses(Classe classe[], int classeEnCours, int posJoueur){

    al_clear_to_color(NOIR);

    dessinerImageFond(classeEnCours, classe);

    al_draw_bitmap(classe[classeEnCours].perso[posJoueur].image, (float)LARGEUR /2 - 30, (float)HAUTEUR / 2 - 125, 0);
    al_draw_scaled_bitmap(classe[0].fleche, 0, 0 , 406, 324, classe[0].rectangle[FLECHEDROITE].x, classe[0].rectangle[FLECHEDROITE].y, classe[0].rectangle[FLECHEDROITE].largeur, classe[0].rectangle[FLECHEDROITE].hauteur, 0);

    for (int i = 0; i < 5; i++) { // 0 a 5 jusqu'au enum VALIDER
        al_draw_filled_rectangle(classe[classeEnCours].rectangle[i].x, classe[classeEnCours].rectangle[i].y,
                                 classe[classeEnCours].rectangle[i].x + classe[classeEnCours].rectangle[i].largeur,
                                 classe[classeEnCours].rectangle[i].y + classe[classeEnCours].rectangle[i].hauteur,
                                 classe[classeEnCours].rectangle[i].color);
    }

    for (int i = 0; i < 4; ++i) {
        al_draw_filled_rectangle(classe[0].rectangle[i].x, classe[0].rectangle[i].y,
                                 classe[0].rectangle[i].x + classe[0].rectangle[i].largeur,
                                 classe[0].rectangle[i].y + classe[0].rectangle[i].hauteur,
                                 classe[0].rectangle[i].color);

    }

    al_flip_display();
}

void classe(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE* queue, Joueur *joueur, Partie donneePartie){
    bool end = false;

    Classe classe[4];
    initialisationClasses(classe);

    joueur[0].classe = 5;
    joueur[1].classe = 5;

    donneePartie.nbJoueurs = 3;

    int classeEnCours = 0;
    int posJoueur = 0;

    for (int i = 0; i < donneePartie.nbJoueurs; i++) {
        end = false;
        while(!end){
            al_wait_for_event(queue, &event);
            switch (event.type) {
                case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {
                    if (surPassageCase(event.mouse.x, event.mouse.y, classe[classeEnCours].rectangle[VALIDER])){
                        joueur[i].classe = classeEnCours;
                        end = true;
                    }
                    if(surPassageCase(event.mouse.x, event.mouse.y, classe[0].rectangle[CLASSE1])){
                        classeEnCours = 0;
                        posJoueur = 0;
                    }
                    if(surPassageCase(event.mouse.x, event.mouse.y, classe[0].rectangle[CLASSE2])){
                        classeEnCours = 1;
                        posJoueur = 0;
                    }
                    if(surPassageCase(event.mouse.x, event.mouse.y, classe[0].rectangle[CLASSE3])) {
                        classeEnCours = 2;
                        posJoueur = 0;
                    }
                    if(surPassageCase(event.mouse.x, event.mouse.y, classe[0].rectangle[CLASSE4])){
                        classeEnCours = 3;
                        posJoueur = 0;
                    }
                    if(surPassageCase(event.mouse.x, event.mouse.y, classe[0].rectangle[FLECHEDROITE])){
                        posJoueur = (posJoueur + 1) % 8;
                    }
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_AXES: {
                    for (int j = 0; j < NB_RECT; j++) {
                        if (surPassageCase(event.mouse.x, event.mouse.y, classe[classeEnCours].rectangle[j])){
                            //classe[classeEnCours].rectangle[j].color = NOIR;////////a modif
                        }
                        else{
                            //classe[classeEnCours].rectangle[j].color = BLANC;
                        }
                    }
                    break;
                }
            }
            dessinerInterfaceClasses(classe, classeEnCours, posJoueur);
        }
    }


}