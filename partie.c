
#include "partie.h"
#include "menu.h"
#include "arene.h"
#include "interfaceSort.h"
#include "deplacement.h"

void partie(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4], Classe classe[], Partie donneePartie){
    ALLEGRO_TIMER *timer = NULL;

    ALLEGRO_FONT *compteur = al_load_font("../Polices/madetommy.ttf", 60, 0);

    timer = al_create_timer(15);

    bool end = false;
    bool redessiner = false;

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
    r[DEPLACER].x = 100;
    r[DEPLACER].y = 100;
    r[DEPLACER].largeur = 50;
    r[DEPLACER].hauteur = 50;
    r[DEPLACER].color = OR;

    r[SUIVANT].x = 200;
    r[SUIVANT].y = 100;
    r[SUIVANT].largeur = 50;
    r[SUIVANT].hauteur = 50;
    r[SUIVANT].color = BLEU;

    r[SORT1].x = 300;
    r[SORT1].y = 100;
    r[SORT1].largeur = 50;// Commentaire
    r[SORT1].hauteur = 50;// Commentaire
    r[SORT1].color = ORANGE;// Commentaire

// 200 par 283
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_ENIPSA/Affichage_bouton.png"); // enipsa
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_SRAM/Bouton_sort_SramRedim-removebg-preview.png"); // sram
    r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_IOP/Bouton_Sort_IOPparfait.png"); // IOP
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_HYPP/Bouton_Sort_HYppRedim-removebg-preview.png"); // Hypp



    r[BOUTON2].image = al_load_bitmap("../Image/Sorts/SORT_ENIPSA/BoutonPA_PM.png"); // bitmap PA et PM
    r[HORLOGE].image = al_load_bitmap("../Image/Sorts/SORT_ENIPSA/Horloge_marron2.0(1)redim.png");// bitmap Horloge 15 secondes

    r[SORT2].x = 400;
    r[SORT2].y = 100;
    r[SORT2].largeur = 50;
    r[SORT2].hauteur = 50;
    r[SORT2].color = ORANGE;

    //ALLEGRO_BITMAP * ecranSorts = al_load_bitmap("../Image/Sorts/SORT_ENIPSA/1 redim.png");

    dessinerArene(coordonneeIso, joueur, classe);
    //dessinerObsacle(map);
    //dessiner ellipse joueur qui joue
    al_draw_ellipse(coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].x, coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].y, 20, 15, BLEU, 3);
    dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie.nbJoueurs);
    al_draw_filled_rectangle(r[DEPLACER].x, r[DEPLACER].y, r[DEPLACER].x + r[DEPLACER].largeur,r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
    al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
    al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
    al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);
    al_draw_bitmap(r[BOUTON].image, 1150, 200, 0);
    al_draw_bitmap(r[BOUTON2].image, 100, 200, 0);
    al_draw_bitmap(r[HORLOGE].image, 550 , 10, 0);

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
                if(surPassageCase(event.mouse.x, event.mouse.y, r[DEPLACER])){
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
        }
        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            //dessinerObsacle(map);
            al_draw_ellipse(coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].x, coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].y, 20, 15, BLEU, 3);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie.nbJoueurs);
            al_draw_filled_rectangle(r[DEPLACER].x, r[DEPLACER].y, r[DEPLACER].x + r[DEPLACER].largeur,r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x, r[SUIVANT].y, r[SUIVANT].x + r[SUIVANT].largeur,r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);
            al_draw_bitmap(r[BOUTON].image, 1150, 200, 0);
            al_draw_bitmap(r[BOUTON2].image, 100, 200, 0);
            al_draw_bitmap(r[HORLOGE].image, 550 , 10, 0);
            al_flip_display();
            redessiner = false;
        }
        //dessinerCompteur((int)al_get_timer_count(timer), compteur);
        //al_flip_display();
    }
    al_destroy_timer(timer);
}