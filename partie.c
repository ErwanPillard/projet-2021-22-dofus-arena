
#include "partie.h"
#include "menu.h"
#include "arene.h"
#include "interfaceSort.h"
#include "deplacement.h"
#include "interfaceClasse.h"

void initialisationBoutonPartie(BUTTON *bouton){
    // Bouton déplacer

    bouton[DEPLACER].image = al_load_bitmap("../Image/Decor/Boutondeplacer.png");
    bouton[DEPLACER].x = 1000;
    bouton[DEPLACER].y = 100;
    bouton[DEPLACER].largeur = 120;
    bouton[DEPLACER].hauteur = 170;


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

void horloge(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event){
    ALLEGRO_TIMER *timer3 = NULL;
    int i = 0;
    bool end = false;

    ALLEGRO_BITMAP *horloge1= al_load_bitmap("../Image/Decor/Horloge 15 s parfait.png");
    ALLEGRO_BITMAP *horloge2= al_load_bitmap("../Image/Decor/Horloge_14_s-Parfait.png");
    ALLEGRO_BITMAP *horloge3= al_load_bitmap("../Image/Decor/Horloge 13 s parfait.png");
    ALLEGRO_BITMAP *horloge4= al_load_bitmap("../Image/Decor/Horloge 12 s Parfaite.png");
    ALLEGRO_BITMAP *horloge5= al_load_bitmap("../Image/Decor/Horloge 11 s parfaite.png");
    ALLEGRO_BITMAP *horloge6= al_load_bitmap("../Image/Decor/Horloge 10 s parfaite.png");
    ALLEGRO_BITMAP *horloge7= al_load_bitmap("../Image/Decor/Horloge 9 s parfaite.png");
    ALLEGRO_BITMAP *horloge8= al_load_bitmap("../Image/Decor/Horloge 8 s parfaite.png");
    ALLEGRO_BITMAP *horloge9= al_load_bitmap("../Image/Decor/Horloge 7 s parfaite.png");
    ALLEGRO_BITMAP *horloge10= al_load_bitmap("../Image/Decor/Horloge 6 s ^parfaite.png");
    ALLEGRO_BITMAP *horloge11= al_load_bitmap("../Image/Decor/Horloge 5 s parfaite.png");
    ALLEGRO_BITMAP *horloge12= al_load_bitmap("../Image/Decor/Horloge 4 s parfaite.png");
    ALLEGRO_BITMAP *horloge13= al_load_bitmap("../Image/Decor/Horloge 3 s parfaite.png");
    ALLEGRO_BITMAP *horloge14= al_load_bitmap("../Image/Decor/Horloge 2 s parfaite.png");
    ALLEGRO_BITMAP *horloge15= al_load_bitmap("../Image/Decor/Horloge 1 s parfaite.png");

    timer3 = al_create_timer(1.0/1.0);

    al_register_event_source(queue, al_get_timer_event_source(timer3));

    al_start_timer(timer3);


    while (!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_TIMER: {
                al_clear_to_color(al_map_rgb(0, 0, 0));

                if(i==0){
                    al_draw_bitmap(horloge1, 550, -50, 0);

                }
                if(i==1){
                    al_draw_bitmap(horloge2, 550, -50, 0);

                }
                if(i==2){
                    al_draw_bitmap(horloge3, 550, -50, 0);

                }
                if(i==3){
                    al_draw_bitmap(horloge4, 550, -50, 0);

                }
                if(i==4){
                    al_draw_bitmap(horloge5, 550, -50, 0);

                }
                if(i==5){
                    al_draw_bitmap(horloge6, 550, -50, 0);

                }
                if(i==6){
                    al_draw_bitmap(horloge7, 550, -50, 0);

                }
                if(i==7){
                    al_draw_bitmap(horloge8, 550, -50, 0);

                }
                if(i==8){
                    al_draw_bitmap(horloge9, 550, -50, 0);

                }
                if(i==9){
                    al_draw_bitmap(horloge10, 550, -50, 0);

                }
                if(i==10){
                    al_draw_bitmap(horloge11, 550, -50, 0);

                }
                if(i==11){
                    al_draw_bitmap(horloge12, 550, -50, 0);

                }
                if(i==12){
                    al_draw_bitmap(horloge13, 550, -50, 0);

                }
                if(i==13){
                    al_draw_bitmap(horloge14, 550, -50, 0);

                }
                if(i==14){
                    al_draw_bitmap(horloge15, 550, -50, 0);

                }
                al_flip_display();
                i++;

                break;
            }
        }
    }
    al_destroy_timer(timer3);
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
    //Horloge
     //horloge(queue, event);

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
    //al_draw_bitmap(r[BOUTON].image, 1150, 200, 0);



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
                if(surPassage(event.mouse.x, event.mouse.y, (int)bouton[DEPLACER].x, (int)bouton[DEPLACER].y, (int)bouton[DEPLACER].largeur, (int)bouton[DEPLACER].hauteur)){
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
            al_draw_filled_rectangle(r[DEPLACER].x, r[DEPLACER].y, r[DEPLACER].x + r[DEPLACER].largeur,r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
            al_draw_filled_rectangle(r[SUIVANT].x, r[SUIVANT].y, r[SUIVANT].x + r[SUIVANT].largeur,r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
            al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
            al_draw_filled_rectangle(r[SORT2].x,r[SORT2].y,r[SORT2].x + r[SORT2].largeur, r[SORT2].y + r[SORT2].hauteur, r[SORT2].color);
            al_flip_display();
            redessiner = false;
        }
        //dessinerCompteur((int)al_get_timer_count(timer), compteur);
        //al_flip_display();
    }
    al_destroy_timer(timer);
}