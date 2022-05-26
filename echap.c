//
// Created by 33782 on 04/05/2022.
//

#include "echap.h"

Rect initialisationMenuEchap(){
    Rect r;
    r.largeur = 300;
    r.hauteur = 250;
    r.x = (float)LARGEUR / 2 - r.largeur / 2;
    r.y = (float)HAUTEUR / 2 - r.hauteur / 2;
    r.color = NOIR;
    r.rounded_x = 10;
    r.rounded_y = 10;
    r.thickness = 5;
    return r;
}

void dessinerMenuEchap(Rect r){ // Menu doit aussi être accessible a la souris
    al_draw_filled_rounded_rectangle(r.x, r.y, r.x + r.largeur, r.y + r.hauteur, r.rounded_x, r.rounded_y, r.color);
    al_draw_rounded_rectangle(r.x, r.y, r.x + r.largeur, r.y + r.hauteur, r.rounded_x, r.rounded_y, OR, r.thickness);

    al_draw_text(r.font, NOIR, r.x + 70, r.y + 6, 0, "SAUVEGARDER");

    al_flip_display();
}
