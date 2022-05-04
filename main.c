
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <assert.h>

#include "menu.h"
#include "interface0.h"
#include "echap.h"

#define LARGEUR 1400
#define HAUTEUR 807

int main(){
    //Déclarations
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_EVENT event;

    Rect rectangleAccueil[5]; // Cases de la premiere page accueil
    Rect rectangleMenuEchap;
    Rect rectangleInterfaceChoixJoueurs[5];

    int historiquePageActive[1000] = {0}; // faire un malloc (tableau dynamique) !!!!
    int tailleLogique = 0;

    int nbJoueurs;

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

    initialisationInterface0(rectangleAccueil);
    initialisationInterface1(rectangleInterfaceChoixJoueurs);
    rectangleMenuEchap = initialisationMenuEchap();


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
    ALLEGRO_BITMAP *map1 = al_load_bitmap("../Image/map1.jpeg");

    ALLEGRO_FONT *nbJoueurs1 = al_load_font("../Polices/Achafont.ttf", 60, 0);
    ALLEGRO_FONT *nbJoueurs2 = al_load_font("../Polices/Achafont.ttf", 60, 0);
    ALLEGRO_FONT *nbJoueurs3 = al_load_font("../Polices/Achafont.ttf", 60, 0);
    ALLEGRO_FONT *nbJoueurs4 = al_load_font("../Polices/Achafont.ttf", 60, 0);




    al_reserve_samples(2);

    ALLEGRO_SAMPLE *music_Accueil = al_load_sample("../Sound/musique1.ogg");
    ALLEGRO_SAMPLE *whoosh = al_load_sample("../Sound/whoosh.ogg");

    assert(music_Accueil != NULL);
    assert(whoosh != NULL);

    ALLEGRO_SAMPLE_INSTANCE *musicInstance = al_create_sample_instance(music_Accueil);
    al_set_sample_instance_playmode(musicInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(musicInstance, al_get_default_mixer());

    //Premier affichage

    dessinerInterface0(imagePrincipale, rectangleAccueil);

    al_play_sample_instance(musicInstance);
    //Boucle d événements
    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_AXES:{
                for (int i = 0; i < 3 ;i++) {
                    if(historiquePageActive[tailleLogique] == 0 && surPassageCase(event.mouse.x, event.mouse.y, rectangleAccueil[i])){
                        rectangleAccueil[i].color = rectangleAccueil[i].colorThickness;
                    }
                    else{
                        rectangleAccueil[i].color = OR;
                    }
                }
                for (int i = 0; i < 5; i++) {
                    if(historiquePageActive[tailleLogique] == 1 && surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[i])){
                        rectangleInterfaceChoixJoueurs[i].color = rectangleInterfaceChoixJoueurs[i].colorThickness;
                    }
                    else{
                        rectangleInterfaceChoixJoueurs[i].color = OR;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                for (int i = 0; i < 3; i++) {
                    if(historiquePageActive[tailleLogique] == 0){
                        if(surPassageCase(event.mouse.x, event.mouse.y, rectangleAccueil[0])){
                            al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                            tailleLogique++;
                            historiquePageActive[tailleLogique] = 1;
                        }
                        else if(surPassageCase(event.mouse.x, event.mouse.y, rectangleAccueil[1])){
                            //charger un ancienne partie
                        }
                        else if(surPassageCase(event.mouse.x, event.mouse.y, rectangleAccueil[2])){
                            end = true;
                        }
                    }
                }
                if(historiquePageActive[tailleLogique] == 1){
                    if(surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[0])){
                        al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                        tailleLogique++;
                        historiquePageActive[tailleLogique] = 2;
                        nbJoueurs = 2;
                    }
                    else if(surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[1])){
                        al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                        tailleLogique++;
                        historiquePageActive[tailleLogique] = 2;
                        nbJoueurs = 2;
                    }
                    else if(surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[2])){
                        al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                        tailleLogique++;
                        historiquePageActive[tailleLogique] = 2;
                        nbJoueurs = 4;
                    }
                    else if(surPassageCase(event.mouse.x, event.mouse.y, rectangleInterfaceChoixJoueurs[3])){
                        al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                        tailleLogique++;
                        historiquePageActive[tailleLogique] = 2;
                        nbJoueurs = 1;
                    }
                }

                if(historiquePageActive[tailleLogique] == 6 && clicExterneRectangle(event.mouse.x, event.mouse.y, rectangleMenuEchap)){
                    tailleLogique++;
                    historiquePageActive[tailleLogique] = historiquePageActive[tailleLogique - 2];
                }

                break;
            }
            case ALLEGRO_EVENT_KEY_DOWN:{
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:{
                        if (historiquePageActive[tailleLogique] != 6) {
                            tailleLogique++;
                            historiquePageActive[tailleLogique] = 6;
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
                dessinerInterface0(imagePrincipale, rectangleAccueil);
                break;
            }
            case 1:{
                dessinerInterface1(imagePrincipale, nbJoueurs1, nbJoueurs2, nbJoueurs3, nbJoueurs4 ,rectangleInterfaceChoixJoueurs);
                break;
            }
            case 2:{
                al_clear_to_color(NOIR);
                al_draw_bitmap(map1, 0, 0, 0);
                al_flip_display();
                break;
            }
            case 3:{
                break;
            }
            case 6:{
                dessierMenuEchap(rectangleMenuEchap);
            }
        }
    }

    //Libération de la mémoire
    al_destroy_display(display);

    //Bitmap
    al_destroy_bitmap(imagePrincipale);

    //Font
    al_destroy_font(rectangleAccueil[0].font);
    al_destroy_font(rectangleAccueil[1].font);
    al_destroy_font(rectangleAccueil[2].font);

    al_destroy_font(nbJoueurs1);
    al_destroy_font(nbJoueurs2);
    al_destroy_font(nbJoueurs3);
    al_destroy_font(nbJoueurs4);

    //Sample
    al_destroy_sample(music_Accueil);
    al_destroy_sample_instance(musicInstance);
    al_destroy_sample(whoosh);

    //Event
    al_destroy_event_queue(queue);
    return 0;
}

