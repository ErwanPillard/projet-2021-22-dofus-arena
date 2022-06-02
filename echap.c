//
// Created by 33782 on 04/05/2022.
//

#include "echap.h"

Rect initialisationMenuEchap(Rect* r){
    r[0].largeur = 300;
    r[0].hauteur = 250;
    r[0].x = (float)LARGEUR / 2 - r[0].largeur / 2;
    r[0].y = (float)HAUTEUR / 2 - r[0].hauteur / 2;
    r[0].color = NOIR;
    r[0].rounded_x = 10;
    r[0].rounded_y = 10;
    r[0].thickness = 5;
    r[0].font = al_load_font("../Polices/Achafont.ttf", 20, 0);

    r[1].largeur = 300;
    r[1].hauteur = 250;
    r[1].x = (float)LARGEUR / 2 - r[0].largeur / 2;
    r[1].y = (float)HAUTEUR / 2 - r[0].hauteur / 2;
    r[1].color = NOIR;
    r[1].rounded_x = 10;
    r[1].rounded_y = 10;
    r[1].thickness = 5;
    r[1].font = al_load_font("../Polices/Achafont.ttf", 20, 0);
}

void dessinerMenuEchap(ALLEGRO_BITMAP* imagePrincipale,Rect r[]){ // Menu doit aussi être accessible a la souris
    al_draw_bitmap(imagePrincipale, 0, 0, 0);
    for (int i = 0; i < 3; i++) {
        al_draw_filled_rectangle(r[i].x, r[i].y, r[i].x + r[i].largeur, r[i].y + r[i].hauteur, r[i].color);
        al_draw_rectangle(r[i].x, r[i].y, r[i].x + r[i].largeur, r[i].y + r[i].hauteur, r[i].colorThickness, r[i].thickness);
    }
    al_draw_text(r[0].font, NOIR, r[0].x + 70, r[0].y + 6, 0, "SAUVEGARDER");
    al_draw_text(r[1].font, NOIR, r[1].x + 50, r[1].y + 6, 0, "DIDACTICIEL");
    al_flip_display();
}

void interfaceEchap(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT event){
    bool end = false;

    Rect rectangleAccueil[0];
    initialisationMenuEchap(rectangleAccueil);

    ALLEGRO_BITMAP* imagePricncipale = al_load_bitmap("../Image/dofus3.jpg");
    ALLEGRO_SAMPLE *whoosh = al_load_sample("../Sound/whoosh.ogg");

    dessinerMenuEchap(imagePricncipale, rectangleAccueil);

    while(!end){
        al_wait_for_event(queue, &event);
        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                dessinerMenuEchap(imagePricncipale,rectangleAccueil);
            }else if (event.type == ALLEGRO_EVENT_KEY_UP){
                end = 1;
            }

            }
        }

}
