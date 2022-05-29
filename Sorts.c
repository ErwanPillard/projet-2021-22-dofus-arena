#include "Sorts.h"

// faire un switch case pour les rands
// faire une fonctionne Initialisation Corps à corps -> pas de rapport avec les classes, indépendantes

/*
void bouleDeFeux(){//mettre dans la fonction timer en répétant la fonction en faisant avancer le x=x+30
    //Classe * classe;
    int x = 10;
    int y = 50;
    ALLEGRO_BITMAP *ima1 = al_load_bitmap("../Image/Sorts/Bdf1.jpg");
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    al_flip_display();
}*/

/*
void traineeFeux(){
    int x = 10;
    int y = 50;

    //ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/Sorts/traineeDeFeu1.png");
    //ALLEGRO_BITMAP *img2 = al_load_bitmap("../Image/Sorts/traineeDeFeu2.png");
    ALLEGRO_BITMAP *img3 = al_load_bitmap("../Image/Sorts/traineeDeFeu3.png");
    //ALLEGRO_BITMAP *img4 = al_load_bitmap("../Image/Sorts/traineeDeFeu4.png");
    //ALLEGRO_BITMAP *img5 = al_load_bitmap("../Image/Sorts/traineeDeFeu5.png");

    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    al_flip_display();
    sleep(1);
}

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
    bouleDeFeux();
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
*/