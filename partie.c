
#include "partie.h"
#include "menu.h"
#include "arene.h"
#include "interfaceSort.h"
#include "deplacement.h"

unsigned char passage(int mouse_x, int mouse_y, int x, int y, int largeur,int hauteur){
    if(mouse_x >= x && mouse_y >= y && mouse_x <= x + largeur && mouse_y <= y + hauteur){
        return 1;
    }
    return 0;
}

void initialisationBoutonPartie(BUTTON *bouton){
    // Bouton déplacer

    bouton[DEPLACER].image = al_load_bitmap("../Image/Decor/Boutondeplacer.png");
    bouton[DEPLACER].x = 1400;
    bouton[DEPLACER].y = 100;
    bouton[DEPLACER].largeur = 800;
    bouton[DEPLACER].hauteur = 800;


    //Bouton suivant
    //bouton[SUIVANT].image = al_load_bitmap("../Image/Decor/Boutondeplacer.png");
    bouton[SUIVANT].x = 200;
    bouton[SUIVANT].y = 100;
    bouton[SUIVANT].largeur = 50;
    bouton[SUIVANT].hauteur = 50;

    // Bouton Sort 1
    //bouton[SORT1].image = al_load_bitmap("../Image/Decor/Boutondeplacer.png");
    bouton[SORT1].x = 300;
    bouton[SORT1].y = 100;
    bouton[SORT1].largeur = 50;
    bouton[SORT1].hauteur = 50;

    // Bouton Sort 2
    bouton[SORT2].x = 300;
    bouton[SORT2].y = 100;
    bouton[SORT2].largeur = 50;
    bouton[SORT2].hauteur = 50;

    // Bouton Sort 3
    bouton[SORT3].x = 300;
    bouton[SORT3].y = 100;
    bouton[SORT3].largeur = 50;
    bouton[SORT3].hauteur = 50;

    // Bouton Sort 4
    bouton[SORT4].x = 300;
    bouton[SORT4].y = 100;
    bouton[SORT4].largeur = 50;
    bouton[SORT4].hauteur = 50;

    // Bouton Attaque Corps à corps
    bouton[ATTAQUE].x = 300;
    bouton[ATTAQUE].y = 100;
    bouton[ATTAQUE].largeur = 50;
    bouton[ATTAQUE].hauteur = 50;

}

void dessinerBoutonDeplacer(BUTTON bouton[] ){
    al_draw_scaled_bitmap(bouton[DEPLACER].image, 100, 100, 330, 146, bouton[DEPLACER].x, bouton[DEPLACER].y, bouton[DEPLACER].largeur, bouton[DEPLACER].hauteur, 0);
}

void dessinerTousBoutton(BUTTON bouton[]){
    // Bouton Déplacer
    dessinerBoutonDeplacer(bouton);
}

void partie(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4], Classe classe[], Partie donneePartie){
    ALLEGRO_TIMER *timer = NULL;

    ALLEGRO_FONT *compteur = al_load_font("../Polices/madetommy.ttf", 60, 0);

    timer = al_create_timer(15);

    bool end = false;
    bool redessiner = false;


    // Bouton
    BUTTON bouton[8];
    initialisationBoutonPartie(bouton);
    dessinerTousBoutton(bouton);

    int map[12][12]; // fichier txt (obstacle, decor...)
    CoordonneeISO coordonneeIso[12][12];

    al_register_event_source(queue, al_get_timer_event_source(timer));

    initialiserArene(map);
    initialiserCoordMilieuTuile(coordonneeIso);
    initialiserSorts(classe);

    printf("x: %f | y: %f\n", coordonneeIso[0][0].x, coordonneeIso[0][0].y);
    printf("x: %f | y: %f\n", coordonneeIso[3][0].x, coordonneeIso[3][0].y);

    donneePartie.joueurEnCours = 0;

    Rect r[10];

// 200 par 283
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_ENIPSA/Affichage_bouton.png"); // enipsa
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_SRAM/Bouton_sort_SramRedim-removebg-preview.png"); // sram
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_IOP/Bouton_Sort_IOPparfait.png"); // IOP
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_HYPP/Bouton_Sort_HYppRedim-removebg-preview.png"); // Hypp

    r[BOUTON2].image = al_load_bitmap("../Image/Decor/BoutonPA_PM.png"); // bitmap PA et PM

// Bouton horloge
    //r[HORLOGE].image = al_load_bitmap("../Image/Decor/Horloge 15 s parfait.png");// bitmap Horloge 15 secondes
    //r[HORLOGE].image = al_load_bitmap("../Image/Decor/Horloge_14_s-Parfait.png");// bitmap Horloge 14 secondes
    //r[HORLOGE].image = al_load_bitmap("../Image/Decor/Horloge 13 s parfait.png");// bitmap Horloge 13 secondes
    //r[HORLOGE].image = al_load_bitmap("../Image/Decor/Horloge 12 s Parfaite.png");// bitmap Horloge 12 secondes
    //r[HORLOGE].image = al_load_bitmap("../Image/Decor/Horloge 11 s parfaite.png");// bitmap Horloge 11 secondes
    //r[HORLOGE].image = al_load_bitmap("../Image/Decor/Horloge 10 s parfaite.png");// bitmap Horloge 10 secondes

    r[HORLOGE].image = al_load_bitmap("../Image/Decor/Horloge 9 s parfaite.png");// bitmap Horloge 9 secondes

    //ALLEGRO_BITMAP * ecranSorts = al_load_bitmap("../Image/Sorts/SORT_ENIPSA/1 redim.png");

    dessinerArene(coordonneeIso, joueur, classe);
    //dessinerObsacle(map);
    //dessiner ellipse joueur qui joue
    al_draw_ellipse(coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].x, coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].y, 20, 15, BLEU, 3);
    dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie.nbJoueurs);
    //al_draw_filled_rectangle(r[DEPLACER].x, r[DEPLACER].y, r[DEPLACER].x + r[DEPLACER].largeur,r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
    al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
    al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
    al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);
    //al_draw_bitmap(r[BOUTON].image, 1150, 200, 0);
    al_draw_bitmap(r[BOUTON2].image, 100, 200, 0);
    al_draw_bitmap(r[HORLOGE].image, 550 , -50, 0);
    al_draw_bitmap(bouton[DEPLACER].image, (float)LARGEUR /2 - 30, (float)HAUTEUR / 2 - 125, 0);

    al_flip_display();

    al_start_timer(timer);

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                end = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                if(passage(event.mouse.x, event.mouse.y, (int)bouton[DEPLACER].x, bouton[DEPLACER].y, bouton[DEPLACER].largeur, bouton[DEPLACER].hauteur)){
                    deplacement(event, queue, coordonneeIso, joueur, classe, &donneePartie, timer, r, map);
                    redessiner = true;
                }
                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    joueur[donneePartie.joueurEnCours].PM = 3;
                    donneePartie.joueurEnCours = (donneePartie.joueurEnCours + 1) % donneePartie.nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
                    redessiner = true;
                }
                if(surPassageCase(event.mouse.x, event.mouse.y, r[SORT1])){
                    choixSort(event, queue, coordonneeIso, joueur, classe, donneePartie, timer, r, map, sort1, classe[joueur[donneePartie.joueurEnCours].classe].sorts[sort1].type);
                    redessiner = true;
                }
                if(surPassageCase(event.mouse.x, event.mouse.y, r[SORT2])){
                    choixSort(event, queue, coordonneeIso, joueur, classe, donneePartie, timer, r, map, sort1, classe[joueur[donneePartie.joueurEnCours].classe].sorts[sort2].type);
                    redessiner = true;
                }
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                joueur[donneePartie.joueurEnCours].PM = 3;
                donneePartie.joueurEnCours = (donneePartie.joueurEnCours + 1) % donneePartie.nbJoueurs;
                redessiner = true;
                break;
            }
            case ALLEGRO_EVENT_KEY_UP:{
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:{
                        //interfaceechap
                        interfaceEchap(queue, event);
                        break;
                    }
                }
                break;
            }
        }
        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            //dessinerObsacle(map);
            al_draw_ellipse(coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].x, coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].y, 20, 15, BLEU, 3);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie.nbJoueurs);
            //al_draw_filled_rectangle(r[DEPLACER].x, r[DEPLACER].y, r[DEPLACER].x + r[DEPLACER].largeur,r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x, r[SUIVANT].y, r[SUIVANT].x + r[SUIVANT].largeur,r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);
            //al_draw_bitmap(r[BOUTON].image, 1150, 200, 0);
            al_draw_bitmap(r[BOUTON2].image, 100, 200, 0);
            al_draw_bitmap(r[HORLOGE].image, 550 , -50, 0);
            al_draw_bitmap(r[DEPLACER].image, (float)LARGEUR /2 - 30, (float)HAUTEUR / 2 - 125, 0);
            al_flip_display();
            redessiner = false;
        }
        //dessinerCompteur((int)al_get_timer_count(timer), compteur);
        //al_flip_display();
    }
    al_destroy_timer(timer);
}