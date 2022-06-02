#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <assert.h>
#include <time.h>
#include "menu.h"

#include "interfaceClasse.h"
#include "partie.h"

#define LARGEUR 1400
#define HAUTEUR 807
#include "chargement.h"
#include "interface0.h"

int main(){
    //Déclarations
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_EVENT event;

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

    display = al_create_display(LARGEUR, HAUTEUR);
    assert(display != NULL);

    al_set_window_title(display, "Dofus");
    al_set_window_position(display, 10, 0);

    queue = al_create_event_queue();
    assert(queue != NULL);

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());

    //Musique
    al_reserve_samples(2);

    ALLEGRO_SAMPLE *music_Accueil = al_load_sample("../Sound/musique1.ogg");

    assert(music_Accueil != NULL);

    ALLEGRO_SAMPLE_INSTANCE *musicInstance = al_create_sample_instance(music_Accueil);
    al_set_sample_instance_playmode(musicInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(musicInstance, al_get_default_mixer());

    //al_play_sample_instance(musicInstance);

    Partie donneePartie = {0};
    Joueur joueur[4];
    Classe classe[4];
    initialiserClasses(classe);

    al_wait_for_event(queue, &event);

    while(!end){
        //didacticiel();
        //traineeFeux();
        //bouleDeFeux();
        //courrirIop();
        //affichageChargement();
        interface0(queue, event);
        menu(queue, event, &donneePartie);
        interfaceClasse(event, queue, joueur, donneePartie, classe);
        //affichageChargement2();
        partie(event, queue, joueur, classe, donneePartie);
        interfaceEchap(queue, event);
        end = true;
    }
}

/*
//Libération de la mémoire
al_destroy_display(display);

//Bitmap
al_destroy_bitmap(imagePrincipale);
al_destroy_bitmap(classes[0].fondEcran);

//Font
al_destroy_font(rectangleAccueil[0].font);
al_destroy_font(rectangleAccueil[1].font);
al_destroy_font(rectangleAccueil[2].font);

al_destroy_font(rectangleInterfaceChoixJoueurs[0].font);
al_destroy_font(rectangleInterfaceChoixJoueurs[1].font);
al_destroy_font(rectangleInterfaceChoixJoueurs[2].font);
al_destroy_font(rectangleInterfaceChoixJoueurs[3].font);

//Sample
al_destroy_sample(music_Accueil);
al_destroy_sample_instance(musicInstance);
al_destroy_sample(whoosh);

//Event
al_destroy_event_queue(queue);
return 0;
*/