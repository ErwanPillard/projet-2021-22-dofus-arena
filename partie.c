
#include "partie.h"
#include "menu.h"
#include "arene.h"
#include "interfaceSort.h"
#include "deplacement.h"
#include "interfaceClasse.h"

void initialisationBoutonPartie(BUTTON *bouton){
    // Bouton déplacer

    bouton[DEPLACER].image = al_load_bitmap("../Image/Decor/Boutondeplacer.png");
    bouton[DEPLACER].x = 1200;
    bouton[DEPLACER].y = 500;
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

void dessinerTousBoutton(BUTTON bouton[]){
    // Bouton Déplacer
    al_draw_bitmap(bouton[DEPLACER].image, bouton[DEPLACER].x, bouton[DEPLACER].y, 0);
}

void initialiserRectangleParametreJoueurs(Rect r2[]){
    r2[PV].x = 100;
    r2[PV].y = 10;
    r2[PV].largeur = 200;
    r2[PV].hauteur = 10;
    r2[PV].thickness = 3;
    r2[PV].color = VERT;
    r2[PV].colorThickness = NOIR;

    r2[PM].x = 100;
    r2[PM].y = 30;
    r2[PM].largeur = 200;
    r2[PM].hauteur = 10;
    r2[PM].thickness = 3;
    r2[PM].color = OR;
    r2[PM].colorThickness = NOIR;

    r2[PA].x = 100;
    r2[PA].y = 50;
    r2[PA].largeur = 200;
    r2[PA].hauteur = 10;
    r2[PA].thickness = 3;
    r2[PA].color = BLEU;
    r2[PA].colorThickness = NOIR;
}

void dessinerParametreJoueur(Rect r[], Partie donneePartie, Joueur joueur[], Classe classe[], ALLEGRO_BITMAP *tab[]){
    for (int i = 0; i < donneePartie.nbJoueurs; i++) {
        al_draw_scaled_bitmap(tab[joueur[i].classe], 0, 0, 250, 250, 10, 10 + (80*i), 80, 80,0);

        al_draw_filled_rectangle(r[PV].x,r[PV].y + (i*90),r[PV].x + (joueur[i].PV * r[PV].largeur)/50, r[PV].y + (i*90) + r[PV].hauteur, r[PV].color);
        al_draw_rectangle(r[PV].x,r[PV].y + (i*90),r[PV].x + r[PV].largeur, r[PV].y + (i*90) + r[PV].hauteur, r[PV].colorThickness,r[PV].thickness);

        al_draw_filled_rectangle(r[PA].x,r[PA].y + (i*90),r[PA].x + (joueur[i].PA * r[PA].largeur)/6, r[PA].y + (i*90) + r[PA].hauteur, r[PA].color);
        al_draw_rectangle(r[PA].x,r[PA].y + (i*90),r[PA].x + r[PA].largeur, r[PA].y + (i*90) + r[PA].hauteur, r[PA].colorThickness,r[PA].thickness);

        al_draw_filled_rectangle(r[PM].x,r[PM].y + (i*90),r[PM].x + (joueur[i].PM * r[PM].largeur)/3, r[PM].y + (i*90) + r[PM].hauteur, r[PM].color);
        al_draw_rectangle(r[PM].x,r[PM].y + (i*90),r[PM].x + r[PM].largeur, r[PM].y + (i*90) + r[PM].hauteur, r[PM].colorThickness, r[PM].thickness);
    }
}

void partie(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4], Classe classe[], Partie donneePartie, ALLEGRO_BITMAP *tabClasses[]){
    ALLEGRO_TIMER *timer = NULL;

    timer = al_create_timer(15);

    bool end = false;
    bool redessiner = true;

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

    Rect r2[3];
    initialiserRectangleParametreJoueurs(r2);

    Rect r[10];
    r[DEPLACER].x = 600;
    r[DEPLACER].y = 100;
    r[DEPLACER].largeur = 50;
    r[DEPLACER].hauteur = 50;
    r[DEPLACER].color = OR;

    r[SUIVANT].x = 700;
    r[SUIVANT].y = 100;
    r[SUIVANT].largeur = 50;
    r[SUIVANT].hauteur = 50;
    r[SUIVANT].color = NOIR;

    r[SORT1].x = 600;
    r[SORT1].y = 200;
    r[SORT1].largeur = 50;// Commentaire
    r[SORT1].hauteur = 50;// Commentaire
    r[SORT1].color = ORANGE;// Commentaire

    r[SORT2].x = 700;
    r[SORT2].y = 200;
    r[SORT2].largeur = 50;// Commentaire
    r[SORT2].hauteur = 50;// Commentaire
    r[SORT2].color = ORANGE;// Commentaire
/*
    HORLOGE horloge[15];
    horloge[0].image = al_load_bitmap("../Image/Decor/Horloge 1 s parfait.png");
    horloge[0].x = 500;
    horloge[0].y = 50;

    horloge[1].image = al_load_bitmap("../Image/Decor/Horloge 2 s parfait.png");
    horloge[2].image = al_load_bitmap("../Image/Decor/Horloge 3 s parfait.png");
    horloge[3].image = al_load_bitmap("../Image/Decor/Horloge 4 s parfait.png");
    horloge[4].image = al_load_bitmap("../Image/Decor/Horloge 5 s parfait.png");
    horloge[5].image = al_load_bitmap("../Image/Decor/Horloge 6 s parfait.png");
    horloge[6].image = al_load_bitmap("../Image/Decor/Horloge 7 s parfait.png");
    horloge[7].image = al_load_bitmap("../Image/Decor/Horloge 8 s parfait.png");
    horloge[8].image = al_load_bitmap("../Image/Decor/Horloge 9 s parfait.png");
    horloge[9].image = al_load_bitmap("../Image/Decor/Horloge 10 s parfait.png");
    horloge[10].image = al_load_bitmap("../Image/Decor/Horloge 11 s parfait.png");
    horloge[11].image = al_load_bitmap("../Image/Decor/Horloge 12 s parfait.png");
    horloge[12].image = al_load_bitmap("../Image/Decor/Horloge 13 s parfait.png");
    horloge[13].image = al_load_bitmap("../Image/Decor/Horloge 14 s parfait.png");
    horloge[14].image = al_load_bitmap("../Image/Decor/Horloge 15 s parfait.png");
*/
// 200 par 283
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_ENIPSA/Affichage_bouton.png"); // enipsa
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_SRAM/Bouton_sort_SramRedim-removebg-preview.png"); // sram
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_IOP/Bouton_Sort_IOPparfait.png"); // IOP
    //r[BOUTON].image = al_load_bitmap("../Image/Sorts/SORT_HYPP/Bouton_Sort_HYppRedim-removebg-preview.png"); // Hypp

    //r[BOUTON2].image = al_load_bitmap("../Image/Decor/BoutonPA_PM.png"); // bitmap PA et PM

    //ALLEGRO_BITMAP * ecranSorts = al_load_bitmap("../Image/Sorts/SORT_ENIPSA/1 redim.png");

    al_start_timer(timer);

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                end = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                if(surPassage(event.mouse.x, event.mouse.y, bouton[DEPLACER].x, bouton[DEPLACER].y, bouton[DEPLACER].largeur, bouton[DEPLACER].hauteur)){
                    deplacement(event, queue, coordonneeIso, joueur, classe, &donneePartie, timer, r, map, r2, tabClasses);
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
                    choixSort(event, queue, coordonneeIso, joueur, classe, donneePartie, timer, r, map, sort1, classe[joueur[donneePartie.joueurEnCours].classe].sorts[sort1].type, r2, tabClasses);
                    redessiner = true;
                }
                if(surPassageCase(event.mouse.x, event.mouse.y, r[SORT2])){
                    choixSort(event, queue, coordonneeIso, joueur, classe, donneePartie, timer, r, map, sort1, classe[joueur[donneePartie.joueurEnCours].classe].sorts[sort2].type, r2, tabClasses);
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

            dessinerParametreJoueur(r2, donneePartie, joueur, classe, tabClasses);

            dessinerTousBoutton(bouton);

            al_flip_display();
            redessiner = false;
        }
    }
    al_destroy_timer(timer);
}