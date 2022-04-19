//
// Created by Utilisateur on 19/04/2022.
//

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define OR al_map_rgb(255,251,14)
#define ORfonce al_map_rgb(238,225,32)
#define BLANC al_map_rgb(255,255,255)
#define NOIR al_map_rgb(0,0,0)

#define LARGEUR 1400
#define HAUTEUR 807


typedef struct{
    float x, y, largeur, hauteur, thickness, rounded_x, rounded_y;
    ALLEGRO_COLOR color;
}Rect;

Rect initialisationInterface0(Rect *rectanglefilled, Rect *rectangle){
    rectanglefilled[0].largeur = 200;
    rectanglefilled[0].hauteur = 50;
    rectanglefilled[0].x = (float)LARGEUR / 2 - rectanglefilled[0].largeur / 2;
    rectanglefilled[0].y = (float)HAUTEUR / 2 - rectanglefilled[0].hauteur / 2;
    rectanglefilled[0].color = OR;

    rectangle[0].largeur = 200;
    rectangle[0].hauteur = 50;
    rectangle[0].x = (float)LARGEUR / 2 - rectangle[0].largeur / 2;
    rectangle[0].y = (float)HAUTEUR / 2 - rectangle[0].hauteur / 2;
    rectangle[0].thickness = 5;
    rectangle[0].color = ORfonce;
}

unsigned char surPassageCase(int mouse_x, int mouse_y, Rect rectanglefilled[]){
    if(mouse_x >= (int)rectanglefilled[0].x && mouse_y >= (int)rectanglefilled[0].y && mouse_x <= (int)rectanglefilled[0].x + (int)rectanglefilled[0].largeur && mouse_y <= (int)rectanglefilled[0].y + (int)rectanglefilled[0].hauteur){
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

void dessinerInterface0(ALLEGRO_BITMAP *imagePrincipale, ALLEGRO_FONT *fontInterface0, Rect rectanglefilled[], Rect rectangle[]){

    al_draw_bitmap(imagePrincipale, 0, 0, 0);

    dessinerFilledRectangle(rectanglefilled[0].x, rectanglefilled[0].y, rectanglefilled[0].x + rectanglefilled[0].largeur, rectanglefilled[0].y + rectanglefilled[0].hauteur, rectanglefilled[0].color);
    dessinerRectangle(rectangle[0].x, rectangle[0].y, rectangle[0].x + rectangle[0].largeur, rectangle[0].y + rectangle[0].hauteur, rectangle[0].color, rectangle[0].thickness);

    al_draw_text(fontInterface0, NOIR, rectangle[0].x + 70, rectangle[0].y + 6, 0, "JOUER");

    al_flip_display();
}

Rect initialisationMenu(){
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

unsigned char clicExterneMenu( int mouse_x, int mouse_y, Rect r){
    if(!(mouse_x >= (int)r.x && mouse_y >= (int)r.y && mouse_x <= (int)r.x + (int)r.largeur && mouse_y <= (int)r.y + (int)r.hauteur)){
        return 1;
    }
    return 0;
}

void dessierMenuEchap(Rect r){ // Menu doit aussi être accessible a la souris
    al_draw_filled_rounded_rectangle(r.x, r.y, r.x + r.largeur, r.y + r.hauteur, r.rounded_x, r.rounded_y, r.color);
    al_draw_rounded_rectangle(r.x, r.y, r.x + r.largeur, r.y + r.hauteur, r.rounded_x, r.rounded_y, OR, r.thickness);
    al_flip_display();
}

Rect initialisationInterface1(Rect *r){
    r[0].largeur = 50;
    r[0].hauteur = 50;
    r[0].x = (float)LARGEUR / 2 - r[0].largeur / 2;
    r[0].y = 200;

    r[0].color = BLANC;
    r[1].largeur = 50;
    r[1].hauteur = 50;
    r[1].x = ((float)LARGEUR / 2 - r[1].largeur / 2) - 55;
    r[1].y = 200;
    r[1].color = BLANC;

    r[2].largeur = 50;
    r[2].hauteur = 50;
    r[2].x = ((float)LARGEUR / 2 - r[2].largeur / 2) + 55;
    r[2].y = 200;
    r[2].color = BLANC;
}

void dessinerInterface1(ALLEGRO_BITMAP *imagePrincipale, Rect r[]){
    al_draw_bitmap(imagePrincipale, 0, 0, 0);

    dessinerFilledRectangle(r[0].x, r[0].y,r[0].x + r[0].largeur, r[0].y + r[0].hauteur, r[0].color);
    dessinerFilledRectangle(r[1].x, r[1].y,r[1].x + r[1].largeur, r[1].y + r[1].hauteur, r[1].color);
    dessinerFilledRectangle(r[2].x, r[2].y,r[2].x + r[2].largeur, r[2].y + r[2].hauteur, r[2].color);

    al_flip_display();
}

void fenetre(){
    //Déclarations
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_EVENT event;


    Rect rectanglefilled[5];
    Rect rectangle[5];

    Rect rectangleMenuEchap;

    Rect rectangleInterface1[5];

    int historiquePageActive[1000] = {0}; // faire un malloc (tableau dynamique) !!!!
    int tailleLogique = 0;

    bool end = false;

    //Initialisation / installation addons
    assert(al_init());
    assert(al_init_image_addon());
    assert(al_install_mouse());
    assert(al_install_keyboard());
    assert(al_init_primitives_addon());
    al_init_font_addon();
    assert(al_init_ttf_addon());
    assert(al_install_audio());
    assert(al_init_acodec_addon());

    initialisationInterface0(rectanglefilled, rectangle);
    initialisationInterface1(rectangleInterface1);
    rectangleMenuEchap = initialisationMenu();


    //Création des éléments/données
    display = al_create_display(LARGEUR, HAUTEUR);
    assert(display != NULL);

    al_set_window_title(display, "Dofus");
    al_set_window_position(display, 10, 0);

    queue = al_create_event_queue();
    assert(queue != NULL);

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());

    ALLEGRO_BITMAP *imagePrincipale = al_load_bitmap("../Image/dofus3.jpg");

    ALLEGRO_FONT *fontInterface0 = al_load_font("../Polices/Achafont.ttf", 30, 0);

    al_reserve_samples(2);

    ALLEGRO_SAMPLE *music_Accueil = al_load_sample("../Sound/musique1.ogg");
    ALLEGRO_SAMPLE *whoosh = al_load_sample("../Sound/whoosh.ogg");

    assert(music_Accueil != NULL);
    assert(whoosh != NULL);

    ALLEGRO_SAMPLE_INSTANCE *musicInstance = al_create_sample_instance(music_Accueil);
    al_set_sample_instance_playmode(musicInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(musicInstance, al_get_default_mixer());

    //Premier affichage

    dessinerInterface0(imagePrincipale, fontInterface0, rectanglefilled, rectangle);

    al_play_sample_instance(musicInstance);

    //Boucle d événements
    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_AXES:{
                if(historiquePageActive[tailleLogique] == 0 && surPassageCase(event.mouse.x, event.mouse.y, rectanglefilled)){
                    rectanglefilled[0].color = rectangle[0].color;
                }
                else{
                    rectanglefilled[0].color = OR;
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                if(historiquePageActive[tailleLogique] == 0 && surPassageCase(event.mouse.x, event.mouse.y, rectanglefilled)){
                    al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                    tailleLogique++;
                    historiquePageActive[tailleLogique] = 2;
                }
                if(historiquePageActive[tailleLogique] == 1 && clicExterneMenu(event.mouse.x, event.mouse.y, rectangleMenuEchap)){
                    tailleLogique++;
                    historiquePageActive[tailleLogique] = historiquePageActive[tailleLogique - 2];
                }
                break;
            }
            case ALLEGRO_EVENT_KEY_DOWN:{
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:{
                        if (historiquePageActive[tailleLogique] != 1) {
                            tailleLogique++;
                            historiquePageActive[tailleLogique] = 1;
                        }
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                end = true;
                break;
            }
        }

        switch(historiquePageActive[tailleLogique]){
            case 0:{
                dessinerInterface0(imagePrincipale, fontInterface0, rectanglefilled, rectangle);
                break;
            }
            case 1:{
                dessierMenuEchap(rectangleMenuEchap);
                break;
            }
            case 2:{
                dessinerInterface1(imagePrincipale, rectangleInterface1);
                break;
            }
        }
    }

    //Libération de la mémoire
    al_destroy_display(display);
    al_destroy_bitmap(imagePrincipale);
    al_destroy_font(fontInterface0);
    al_destroy_sample(music_Accueil);
    al_destroy_sample_instance(musicInstance);
    al_destroy_sample(whoosh);
    al_destroy_event_queue(queue);
}

int main() {
    fenetre();
    return 0;
}
