//
// Created by 33782 on 06/05/2022.
//

#include "chargement.h"

void didacticiel(){
    int x = 10;
    int y = 250;
    ALLEGRO_BITMAP *imgIop = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    ALLEGRO_BITMAP *boule = al_load_bitmap("../Image/bouleFeu.png");
    ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/1.png");
    ALLEGRO_BITMAP *img2 = al_load_bitmap("../Image/D2.png");
    ALLEGRO_BITMAP *img3 = al_load_bitmap("../Image/D3.png");
    ALLEGRO_BITMAP *img4 = al_load_bitmap("../Image/D4.png");
    ALLEGRO_BITMAP *img5 = al_load_bitmap("../Image/D5.png");
    ALLEGRO_BITMAP *img6 = al_load_bitmap("../Image/D6.png");
    ALLEGRO_BITMAP *img7 = al_load_bitmap("../Image/D7.png");
    ALLEGRO_BITMAP *imgsors = al_load_bitmap("../Image/Classes/CoeurIop/IopPos6.png");
    al_draw_bitmap(img1, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img2, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img3, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img4, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img5, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img6, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img7, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img1, 10, 250, 0);
    al_flip_display();
    sleep(2);
    al_clear_to_color(NOIR);
    BDF();
}

void courrirIop(){
    int x = 10;
    int y = 250;
    ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    ALLEGRO_BITMAP *img2 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos2.png");
    ALLEGRO_BITMAP *img3 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos3.png");
    ALLEGRO_BITMAP *img4 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos4.png");
    ALLEGRO_BITMAP *img5 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos5.png");
    ALLEGRO_BITMAP *img6 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos6.png");
    al_draw_bitmap(img1, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(2);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img2, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img4, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img5, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap(img1, x, y, 0);x=x+30;
   // al_flip_display();
   // sleep(1);
    //al_clear_to_color(NOIR);
    al_draw_bitmap(img2, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img4, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img5, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, x+30, y, 0);x=x+30;
    al_flip_display();
    sleep(1);

}
void BDF(){
    int x = 130;
    int y = 250;
    ALLEGRO_BITMAP *boule = al_load_bitmap("../Image/bouleFeu.png");
    ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    ALLEGRO_BITMAP *img6 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos6.png");
    al_draw_bitmap(img1, 10, 250, 0);
    al_flip_display();
    sleep(2);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, 10, 250, 0);
    al_draw_bitmap(boule, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, 10, 250, 0);

    al_draw_bitmap(boule, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, 10, 250, 0);

    al_draw_bitmap(boule, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, 10, 250, 0);
    al_draw_bitmap(boule, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, 10, 250, 0);
    al_draw_bitmap(boule, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, 10, 250, 0);
    al_draw_bitmap(boule, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
}


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

void affichageChargement2(){
    ALLEGRO_COLOR couleur2 = al_map_rgb(255,255,247);
    ALLEGRO_COLOR couleur1 = al_map_rgb(16,56,69);
    ALLEGRO_BITMAP *ecranChargement2 = al_load_bitmap("../Image/chargement2.jpeg");
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