#include "interface0.h"

void initialisationInterface0(Rect *r){
    r[0].largeur = 200;
    r[0].hauteur = 50;
    r[0].x = (float)LARGEUR / 2 - r[0].largeur / 2;
    r[0].y = (float)HAUTEUR / 2 - r[0].hauteur / 2;
    r[0].color = OR;
    r[0].thickness = 5;
    r[0].colorThickness = ORfonce;
    r[0].font = al_load_font("../Polices/Achafont.ttf", 30, 0);

    r[1].largeur = 200;
    r[1].hauteur = 50;
    r[1].x = (float)LARGEUR / 2 - r[0].largeur / 2;
    r[1].y = r[0].y + r[0].hauteur + 20;
    r[1].color = OR;
    r[1].thickness = 5;
    r[1].colorThickness = ORfonce;
    r[1].font = al_load_font("../Polices/Achafont.ttf", 30, 0);

    r[2].largeur = 200;
    r[2].hauteur = 50;
    r[2].x = (float)LARGEUR / 2 - r[0].largeur / 2;
    r[2].y = r[1].y + r[1].hauteur + 20;
    r[2].color = OR;
    r[2].thickness = 5;
    r[2].colorThickness = ORfonce;
    r[2].font = al_load_font("../Polices/Achafont.ttf", 30, 0);
}

void dessinerInterface0(ALLEGRO_BITMAP *imagePrincipale, Rect r[]){
    al_draw_bitmap(imagePrincipale, 0, 0, 0);
    for (int i = 0; i < 3; i++) {
        al_draw_filled_rectangle(r[i].x, r[i].y, r[i].x + r[i].largeur, r[i].y + r[i].hauteur, r[i].color);
        al_draw_rectangle(r[i].x, r[i].y, r[i].x + r[i].largeur, r[i].y + r[i].hauteur, r[i].colorThickness, r[i].thickness);
    }
    al_draw_text(r[0].font, NOIR, r[0].x + 70, r[0].y + 6, 0, "JOUER");
    al_draw_text(r[1].font, NOIR, r[1].x + 50, r[1].y + 6, 0, "CHARGER");
    al_draw_text(r[2].font, NOIR, r[2].x + 50, r[2].y + 6, 0, "QUITTER");

    al_flip_display();
}

void interface0(){
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_EVENT event;

    bool end = false;

    ALLEGRO_BITMAP *imagePrincipale = al_load_bitmap("../Image/dofus3.jpg");

    Rect rectangleAccueil[5];
    initialisationInterface0(rectangleAccueil);

    ALLEGRO_SAMPLE *whoosh = al_load_sample("../Sound/whoosh.ogg");

    queue = al_create_event_queue();
    assert(queue != NULL);

    al_register_event_source(queue, al_get_mouse_event_source());

    al_wait_for_event(queue, &event);
    while(!end){
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_AXES:{
                for (int i = 0; i < 3 ;i++) {
                    if(surPassageCase(event.mouse.x, event.mouse.y, rectangleAccueil[i])){
                        rectangleAccueil[i].color = rectangleAccueil[i].colorThickness;
                    }
                    else{
                        rectangleAccueil[i].color = OR;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                for (int i = 0; i < 3; i++) {
                    if(surPassageCase(event.mouse.x, event.mouse.y, rectangleAccueil[0])){
                        al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                        end = true;
                    }
                    else if(surPassageCase(event.mouse.x, event.mouse.y, rectangleAccueil[1])){
                        //charger un ancienne partie
                    }
                    else if(surPassageCase(event.mouse.x, event.mouse.y, rectangleAccueil[2])){
                        //Liberation
                    }
                }
            }
        }
        dessinerInterface0(imagePrincipale, rectangleAccueil);
    }

    al_destroy_event_queue(queue);
}
