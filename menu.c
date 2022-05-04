//
// Created by 33782 on 29/04/2022.
//

#include "menu.h"

unsigned char surPassageCase(int mouse_x, int mouse_y, Rect rectanglefilled){
    if(mouse_x >= (int)rectanglefilled.x && mouse_y >= (int)rectanglefilled.y && mouse_x <= (int)rectanglefilled.x + (int)rectanglefilled.largeur && mouse_y <= (int)rectanglefilled.y + (int)rectanglefilled.hauteur){
        return 1;
    }
    return 0;
}

void dessinerFilledRectangle(float x, float y, float largeur, float hauteur, ALLEGRO_COLOR color){
    al_draw_filled_rectangle(x, y, largeur, hauteur, color);
}

void dessinerRectangle(float x, float y, float largeur, float hauteur, ALLEGRO_COLOR color, float thickness){
    al_draw_rectangle(x, y, largeur, hauteur, color, thickness);
}

unsigned char clicExterneRectangle( int mouse_x, int mouse_y, Rect r){
    if(!(mouse_x >= (int)r.x && mouse_y >= (int)r.y && mouse_x <= (int)r.x + (int)r.largeur && mouse_y <= (int)r.y + (int)r.hauteur)){
        return 1;
    }
    return 0;
}

Rect initialisationInterface1(Rect *r){
    float y = 200.0f;
    r[1].largeur = 50;
    r[1].hauteur = 50;
    r[1].x = (float)LARGEUR / 2 - r[1].largeur / 2;
    r[1].y = y;
    r[1].color = OR;
    r[1].colorThickness = ORfonce;

    r[0].largeur = 50;
    r[0].hauteur = 50;
    r[0].x = ((float)LARGEUR / 2 - r[0].largeur / 2) - 55;
    r[0].y = y;
    r[0].color = OR;
    r[0].colorThickness = ORfonce;

    r[2].largeur = 50;
    r[2].hauteur = 50;
    r[2].x = ((float)LARGEUR / 2 - r[2].largeur / 2) + 55;
    r[2].y = y;
    r[2].color = OR;
    r[2].colorThickness = ORfonce;

    r[3].largeur = 50;
    r[3].hauteur = 50;
    r[3].x = ((float)LARGEUR / 2 - r[3].largeur / 2) + 110;
    r[3].y = y;
    r[3].color = OR;
    r[3].colorThickness = ORfonce;
}

void dessinerInterface1(ALLEGRO_BITMAP *imagePrincipale, ALLEGRO_FONT *nbJoueurs1,ALLEGRO_FONT *nbJoueurs2,ALLEGRO_FONT *nbJoueurs3, ALLEGRO_FONT *nbJoueurs4, Rect r[]){
    al_draw_bitmap(imagePrincipale, 0, 0, 0);

    dessinerFilledRectangle(r[0].x, r[0].y,r[0].x + r[0].largeur, r[0].y + r[0].hauteur, r[0].color);
    dessinerFilledRectangle(r[1].x, r[1].y,r[1].x + r[1].largeur, r[1].y + r[1].hauteur, r[1].color);
    dessinerFilledRectangle(r[2].x, r[2].y,r[2].x + r[2].largeur, r[2].y + r[2].hauteur, r[2].color);
    dessinerFilledRectangle(r[3].x, r[3].y,r[3].x + r[3].largeur, r[3].y + r[3].hauteur, r[3].color);
    al_draw_text(nbJoueurs1, NOIR, r[0].x + 10, r[0].y - 10, 0, "2");
    al_draw_text(nbJoueurs1, NOIR, r[1].x + 10, r[1].y - 10, 0, "3");
    al_draw_text(nbJoueurs1, NOIR, r[2].x + 10, r[2].y - 10, 0, "4");
    al_draw_text(nbJoueurs1, NOIR, r[3].x + 10, r[3].y - 10, 0, "1");

    al_flip_display();
}