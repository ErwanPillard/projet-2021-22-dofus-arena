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

void dessinerMenuEchap(){
    // Menu doit aussi être accessible a la souris
    ALLEGRO_TIMER *timer = NULL;
    bool end = false;
    ALLEGRO_BITMAP* menu1 = al_load_bitmap("../Image/menu-2.png");
    ALLEGRO_BITMAP* menu2 = al_load_bitmap("../Image/menu-3.png");
    ALLEGRO_BITMAP* menu3 = al_load_bitmap("../Image/menu-4.png");
    ALLEGRO_BITMAP* menu4 = al_load_bitmap("../Image/menu-5.png");
    ALLEGRO_BITMAP* fond = al_load_bitmap("../Image/FondEcran.jpeg");

    al_draw_bitmap(fond, 0, 0, 0);
    al_draw_bitmap(menu1, 210, 110, 0);





    al_flip_display();
}

void interfaceEchap(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT event){
    bool end = false;
    Rect r[NB_RECT];

    initialisationMenuEchap(r);

    ALLEGRO_BITMAP* imagePricncipale = al_load_bitmap("../Image/dofus3.jpg");
    ALLEGRO_SAMPLE *whoosh = al_load_sample("../Sound/whoosh.ogg");
    al_play_sample_instance(whoosh);

    dessinerMenuEchap();

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_KEY_DOWN:{
                case ALLEGRO_KEY_ESCAPE:{
                    al_draw_bitmap(imagePricncipale, 0, 0, 0);
                    break;
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{
                    if(event.mouse.x>300&&event.mouse.y<500){
                        al_draw_rectangle(300, 400, 400, 300, NOIR, 30);
                    }

                break;
            }
        }

    }
}


