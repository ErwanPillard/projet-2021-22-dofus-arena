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
void dessinerFilledRectangle2(float x, float y, float largeur, float hauteur, ALLEGRO_COLOR color){
    al_draw_filled_rectangle(x, y, x+largeur, y+hauteur, color);
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
    float y = 400.0f;
    //Correspond au numéro 3
    r[1].largeur = 100;
    r[1].hauteur = 100;
    r[1].x = (float)LARGEUR / 2 - r[1].largeur / 2;
    r[1].y = y-100;
    r[1].color = OR;
    r[1].colorThickness = ORfonce;
    r[1].font = al_load_font("../Polices/allegroopen.ttf", 145, 0);

//Correspond au numéro 2
    r[0].largeur = 100;
    r[0].hauteur = 100;
    r[0].x = ((float)LARGEUR / 2 - r[0].largeur / 2) - (r[1].largeur + 5);
    r[0].y = y-100;
    r[0].color = OR;
    r[0].colorThickness = ORfonce;
    r[0].font = al_load_font("../Polices/allegroopen.ttf", 145, 0);
//Correspond au numéro 4
    r[2].largeur = 100;
    r[2].hauteur = 100;
    r[2].x = ((float)LARGEUR / 2 - r[2].largeur / 2) + (r[1].largeur + 5);
    r[2].y = y-100;
    r[2].color = OR;
    r[2].colorThickness = ORfonce;
    r[2].font = al_load_font("../Polices/allegroopen.ttf", 145, 0);
//Correspond au numéro 1
    r[3].largeur = 100;
    r[3].hauteur = 100;
    r[3].x = ((float)LARGEUR / 2 - r[3].largeur / 2) + (r[2].largeur + 5);
    r[3].y = y+200;
    r[3].color = OR;
    r[3].colorThickness = ORfonce;
    r[3].font = al_load_font("../Polices/allegroopen.ttf", 145, 0);
}


void dessinerInterface1(ALLEGRO_BITMAP *imagePrincipale, Rect r[]){
    al_draw_bitmap(imagePrincipale, 0, 0, 0);
    ALLEGRO_BITMAP *nbjoueurs = al_load_bitmap("../Image/nbjoueurs.png");
    al_draw_bitmap(nbjoueurs, 200, 0, 0);

    dessinerFilledRectangle(r[0].x, r[0].y,r[0].x + r[0].largeur, r[0].y + r[0].hauteur, r[0].color);
    dessinerFilledRectangle(r[1].x, r[1].y,r[1].x + r[1].largeur, r[1].y + r[1].hauteur, r[1].color);
    dessinerFilledRectangle(r[2].x, r[2].y,r[2].x + r[2].largeur, r[2].y + r[2].hauteur, r[2].color);
    dessinerFilledRectangle(r[3].x, r[3].y,r[3].x + r[3].largeur, r[3].y + r[3].hauteur, r[3].color);
    al_draw_text(r[0].font, NOIR, r[0].x + 25, r[0].y - 35, 0, "2");
    al_draw_text(r[1].font, NOIR, r[1].x + 25, r[1].y - 35, 0, "3");
    al_draw_text(r[2].font, NOIR, r[2].x + 25, r[2].y - 35, 0, "4");
    al_draw_text(r[3].font, NOIR, r[3].x + 25, r[3].y - 35, 0, "1");

    al_flip_display();
}

void menu(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event, Partie *donneePartie){
    bool end = false;

    Rect rectangleInterfaceChoixJoueurs[NB_RECTANGLE_NBJ];
    ALLEGRO_BITMAP *imagePrincipale = al_load_bitmap("../Image/dofus3.jpg");

    ALLEGRO_SAMPLE *whoosh = al_load_sample("../Sound/whoosh.ogg");

    initialisationInterface1(rectangleInterfaceChoixJoueurs);
    dessinerInterface1(imagePrincipale, rectangleInterfaceChoixJoueurs);

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                if (surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[0])) {
                    al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                    donneePartie->nbJoueurs = 2;
                    end = true;
                }
                if (surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[1])) {
                    al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                    donneePartie->nbJoueurs = 3;
                    end = true;
                }
                if (surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[2])) {
                    al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                    donneePartie->nbJoueurs = 4;
                    end = true;
                }
                if (surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[3])) {
                    al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);

                    donneePartie->nbJoueurs = 1;
                    end = true;
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{
                for (int i = 0; i < NB_RECTANGLE_NBJ; i++) {
                    if(surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[i])){
                        rectangleInterfaceChoixJoueurs[i].color = rectangleInterfaceChoixJoueurs[i].colorThickness;
                    }
                    else{
                        rectangleInterfaceChoixJoueurs[i].color = OR;
                    }
                }
                break;
            }
        }
        dessinerInterface1(imagePrincipale, rectangleInterfaceChoixJoueurs);
    }

    //Liberation

    //Bitmap
    al_destroy_bitmap(imagePrincipale);

    //Font
    al_destroy_font(rectangleInterfaceChoixJoueurs[0].font);
    al_destroy_font(rectangleInterfaceChoixJoueurs[1].font);
    al_destroy_font(rectangleInterfaceChoixJoueurs[2].font);
    al_destroy_font(rectangleInterfaceChoixJoueurs[3].font);

    //SAMPLE
    al_destroy_sample(whoosh);

}

