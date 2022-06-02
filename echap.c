//
// Created by 33782 on 04/05/2022.
//

#include "echap.h"
#define NB_RECT 2 // 2 rectangle

Rect initialisationMenuEchap(Rect* r){
    r[0].largeur = 400;
    r[0].hauteur = 350;
    r[0].x = (float)LARGEUR / 2 - r[0].largeur / 2;
    r[0].y = (float)HAUTEUR / 2 - r[0].hauteur / 2;
    r[0].color = OR;
    r[0].rounded_x = 10;
    r[0].rounded_y = 10;
    r[0].thickness = 5;
    r[0].font = al_load_font("../Polices/Achafont.ttf", 30, 0);

    r[1].largeur = 400;
    r[1].hauteur = 350;
    r[1].x = (float)LARGEUR / 2 - r[0].largeur / 2;
    r[1].y = (float)HAUTEUR / 2 - r[0].hauteur / 2;
    r[1].color = OR;
    r[1].rounded_x = 10;
    r[1].rounded_y = 10;
    r[1].thickness = 5;
    r[1].font = al_load_font("../Polices/Achafont.ttf", 30, 0);
}

void dessinerMenuEchap(Rect r[], ALLEGRO_BITMAP* imagePrincipale){ // Menu doit aussi être accessible a la souris

    al_draw_bitmap(imagePrincipale, 0, 0, 0);
    for (int i = 0; i < 3; i++) {
        al_draw_filled_rectangle(r[i].x, r[i].y, r[i].x + r[i].largeur, r[i].y + r[i].hauteur, r[i].color);
        al_draw_rectangle(r[i].x, r[i].y, r[i].x + r[i].largeur, r[i].y + r[i].hauteur, r[i].colorThickness, r[i].thickness);
    }
    al_draw_text(r[0].font, NOIR, r[0].x + 125, r[0].y + 50, 0, "SAUVEGARDER");
    al_draw_text(r[1].font, NOIR, r[1].x + 125, r[1].y + 250, 0, "DIDACTICIEL");

    al_flip_display();
}

void interfaceEchap(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT event){
    bool end = false;
    Rect r[NB_RECT];

    initialisationMenuEchap(r);

    ALLEGRO_BITMAP* imagePricncipale = al_load_bitmap("../Image/dofus3.jpg");
    ALLEGRO_SAMPLE *whoosh = al_load_sample("../Sound/whoosh.ogg");

    dessinerMenuEchap(r, imagePricncipale);

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{


                break;
            }
        }

    }
}


