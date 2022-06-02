//
// Created by 33782 on 06/05/2022.
//
#include "chargement.h"


void affichageChargement(){
    ALLEGRO_BITMAP *ecranChargement = al_load_bitmap("../Image/FondEcran.jpeg");
    ALLEGRO_FONT *chargement = al_load_font("../Polices/Achafont.ttf", 40, 0);
    ALLEGRO_FONT *chargement1 = al_load_font("../Polices/Achafont.ttf", 45, 0);
    ALLEGRO_FONT *chargement2 = al_load_font("../Polices/Achafont.ttf", 35, 0);

    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, 50, 40, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, 400, 40, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, 1000, 40, OR2);
    al_draw_text(chargement, NOIR,  655, 720, 0, "chargement des mondes...");
    al_draw_text(chargement2, NOIR,  810, 728, 0, "65%");
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, LARGEUR-90, 40, OR2);
    al_draw_text(chargement, NOIR,  644, 720, 0, "chargement des packages...");
    al_draw_text(chargement2, NOIR,  810, 728, 0, "90%");
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, LARGEUR-60, 40, OR2);
    al_draw_text(chargement1, NOIR,  696, 718, 0, "lancement...");
    al_draw_text(chargement2, NOIR,  770, 728, 0, "100%");
    al_flip_display();
    sleep(1.5);
}

void affichageChargement2(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event){
    bool end  = false;
    ALLEGRO_COLOR couleur2 = al_map_rgb(255,255,247);
    ALLEGRO_COLOR couleur1 = al_map_rgb(16,56,69);
    ALLEGRO_BITMAP *ecranChargement2 = al_load_bitmap("../Image/chargement2.jpeg");
    ALLEGRO_BITMAP *didacticiel= al_load_bitmap("../Image/proposdida.png");


    ALLEGRO_FONT *chargement = al_load_font("../Polices/Achafont.ttf", 40, 0);
    ALLEGRO_FONT *chargement1 = al_load_font("../Polices/Achafont.ttf", 45, 0);
    ALLEGRO_FONT *chargement2 = al_load_font("../Polices/Achafont.ttf", 35, 0);

    al_draw_bitmap(ecranChargement2, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, 50, 40, couleur2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement2, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, 400, 40, couleur2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement2, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, 1000, 40, couleur2);
    al_draw_text(chargement, couleur1,  655, 720, 0, "chargement des mondes...");
    al_draw_text(chargement2, couleur1,  810, 728, 0, "65%");
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement2, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, LARGEUR-90, 40, couleur2);
    al_draw_text(chargement, couleur1,  644, 720, 0, "chargement des packages...");
    al_draw_text(chargement2, couleur1,  810, 728, 0, "90%");
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement2, 0, 0, 0);
    dessinerFilledRectangle2(30, HAUTEUR-80, LARGEUR-60, 40, couleur2);
    al_draw_text(chargement1, couleur1,  696, 718, 0, "lancement...");
    al_draw_text(chargement2, couleur1,  770, 728, 0, "100%");
    al_flip_display();
    sleep(2);
}