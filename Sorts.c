#include "Sorts.h"
#include "classe.h"
#include "coordonneesISO.h"
#include "arene.h"


// faire un switch case pour les rands
// faire une fonctionne Initialisation Corps à corps -> pas de rapport avec les classes, indépendantes

void initialiserSorts(Classe classe[]){
    srand(time(NULL));
    //Initialisation Classe 1
    ////////* Sorts 1*/////////////
    classe[0].sorts[0].numSort = 1;
    classe[0].sorts[0].nombrePA = 5;
    classe[0].sorts[0].nombrePVinflige = rand() % (5) + 18;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 18 et MAX = 22
    classe[0].sorts[0].image[1] = al_load_bitmap("../Image/Sorts/posters-boule-de-feu.jpg.jpg");// boule de feux
    // boucle for
    //classe[0].sorts[0].porteeX = ;
    //classe[0].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[0].sorts[1].numSort = 2;
    classe[0].sorts[1].nombrePA = 2;
    classe[0].sorts[1].nombrePVinflige = rand() % (5) + 10;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 10 et MAX = 14
    classe[0].sorts[1].image[1] = al_load_bitmap("../Image/Sorts/traineeDeFeu1.png");// traine de feux ( découper la trainée en 6 bitmap)
    classe[0].sorts[1].image[2] = al_load_bitmap("../Image/Sorts/traineeDeFeu2.png");// voir si ca repeint derriere
    classe[0].sorts[1].image[3] = al_load_bitmap("../Image/Sorts/traineeDeFeu3.png");
    classe[0].sorts[1].image[4] = al_load_bitmap("../Image/Sorts/traineeDeFeu4.png");
    classe[0].sorts[1].image[5] = al_load_bitmap("../Image/Sorts/traineeDeFeu5.png");
    //classe[0].sorts[1].porteeX = ;
    //classe[0].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[0].sorts[2].numSort = 3;
    classe[0].sorts[2].nombrePA = 6;
    classe[0].sorts[2].nombrePVinflige = rand() %(5) + 22;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 22 et MAX = 26
    //classe[0].sorts[2].porteeX = ;
    //classe[0].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[0].sorts[3].numSort = 4;
    classe[0].sorts[3].nombrePA = 3;
    classe[0].sorts[3].nombrePVinflige = rand() %(5) + 14;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 14 et MAX = 18
    //classe[0].sorts[3].porteeX = ;
    //classe[0].sorts[3].porteeY = ;


    //Initialisation Classe 2
    ////////* Sorts 1*/////////////
    classe[1].sorts[0].numSort = 1;
    classe[1].sorts[0].nombrePA = 4;
    classe[1].sorts[0].nombrePVinflige = rand() % (5) + 15;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 15 et MAX = 19
    //classe[1].sorts[0].porteeX = ;
    //classe[1].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[1].sorts[1].numSort = 2;
    classe[1].sorts[1].nombrePA = 3;
    classe[1].sorts[1].nombrePVinflige = rand() % (5) + 8;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 8 et MAX = 12
    //classe[1].sorts[1].porteeX = ;
    //classe[1].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[1].sorts[2].numSort = 3;
    classe[1].sorts[2].nombrePA = 2;
    classe[1].sorts[2].nombrePVinflige = rand() % (5) + 13;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 13 et MAX = 17
    //classe[1].sorts[2].porteeX = ;
    //classe[1].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[1].sorts[3].numSort = 4;
    classe[1].sorts[3].nombrePA = 3;
    classe[1].sorts[3].nombrePVinflige = rand() % (5) + 15;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 15 et MAX = 19
    //classe[1].sorts[3].porteeX = ;
    //classe[1].sorts[3].porteeY = ;

    //Initialisation Classe 3
    ////////* Sorts 1*/////////////
    classe[2].sorts[0].numSort = 1;
    classe[2].sorts[0].nombrePA = 4;
    classe[2].sorts[0].nombrePVinflige = rand() % (5) + 18;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 18 et MAX = 22
    //classe[2].sorts[0].porteeX = ;
    //classe[2].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[2].sorts[1].numSort = 2;
    classe[2].sorts[1].nombrePA = 5;
    classe[2].sorts[1].nombrePVinflige = rand() % (5) + 22;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 22 et MAX = 26
    //classe[2].sorts[1].porteeX = ;
    //classe[2].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[2].sorts[2].numSort = 3;
    classe[2].sorts[2].nombrePA = 3;
    classe[2].sorts[2].nombrePVinflige = rand() % (5) + 16;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 16 et MAX = 20
    //classe[2].sorts[2].porteeX = ;
    //classe[2].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[2].sorts[3].numSort = 4;
    classe[2].sorts[3].nombrePA = 4;
    classe[2].sorts[3].nombrePVinflige = rand() % (5) + 18;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 18 et MAX = 22
    //classe[2].sorts[3].porteeX = ;
    //classe[2].sorts[3].porteeY = ;

    //Initialisation Classe 4
    ////////* Sorts 1*/////////////
    classe[3].sorts[0].numSort = 1;
    classe[3].sorts[0].nombrePA = 2;
    classe[3].sorts[0].nombrePVinflige = 0; // rajouter des PV au persos lorsqu'il utilise ce sort
    //classe[3].sorts[0].porteeX = ;
    //classe[3].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[3].sorts[1].numSort = 2;
    classe[3].sorts[1].nombrePA = 3;
    classe[3].sorts[1].nombrePVinflige = rand() % (5) + 16;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 16 et MAX = 20
    //classe[3].sorts[1].porteeX = ;
    //classe[3].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[3].sorts[2].numSort = 3;
    classe[3].sorts[2].nombrePA = 3;
    classe[3].sorts[2].nombrePVinflige = rand() % (5) + 15;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 15 et MAX = 19
    //classe[3].sorts[2].porteeX = ;
    //classe[3].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[3].sorts[3].numSort = 4;
    classe[3].sorts[3].nombrePA = 4;
    classe[3].sorts[3].nombrePVinflige = rand() % (5) + 20;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 20 et MAX = 24
    //classe[3].sorts[3].porteeX = ;
    //classe[3].sorts[3].porteeY = ;

}

void surbrillanceSort(){

}

void applicationSort(){

}

/*void sort(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]){
    bool end = false;
    bool redessiner = false;

    dessinerArene(coordonneeIso, joueur, classe);
    surbrillanceDeplacementJoueur(coordonneeIso, joueur[donneePartie->joueurEnCours].caseX, joueur[donneePartie->joueurEnCours].caseY,joueur[donneePartie->joueurEnCours].PM, map);
    dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
    al_draw_filled_rectangle(r[DEPLACER].x,r[DEPLACER].y,r[DEPLACER].x + r[DEPLACER].largeur, r[DEPLACER].y + r[DEPLACER].hauteur, r[DEPLACER].color);
    al_draw_filled_rectangle(r[SUIVANT].x,r[SUIVANT].y,r[SUIVANT].x + r[SUIVANT].largeur, r[SUIVANT].y + r[SUIVANT].hauteur, r[SUIVANT].color);
    al_draw_filled_rectangle(r[SORT1].x,r[SORT1].y,r[SORT1].x + r[SORT1].largeur, r[SORT1].y + r[SORT1].hauteur, r[SORT1].color);
    al_flip_display();

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{

                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    joueur[donneePartie->joueurEnCours].PM = 3;
                    donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
                }

                end = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                joueur[donneePartie->joueurEnCours].PM = 3;
                donneePartie->joueurEnCours = (donneePartie->joueurEnCours + 1) % donneePartie->nbJoueurs;
                end = true;
                break;
            }
        }
/*
        if(redessiner == true){
            dessinerArene(coordonneeIso, joueur, classe);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie->nbJoueurs);
            al_draw_filled_rectangle(r[0].x,r[0].y,r[0].x + r[0].largeur, r[0].y + r[0].hauteur, r[0].color);
            al_draw_filled_rectangle(r[1].x,r[1].y,r[1].x + r[1].largeur, r[1].y + r[1].hauteur, r[1].color);
            al_flip_display();
            redessiner = false;
        }

    }
}*/
void bouleDeFeux(){//mettre dans la fonction timer en répétant la fonction en faisant avancer le x=x+30
    //Classe * classe;
    int x =10;
    int y = 50;
    ALLEGRO_BITMAP *ima1 = al_load_bitmap("../Image/Sorts/posters-boule-de-feu.jpg.jpg");
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    al_flip_display();
}

void traineeFeux(){
    int x = 10;
    int y = 50;

    ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/Sorts/traineeDeFeu1.png");
    ALLEGRO_BITMAP *img2 = al_load_bitmap("../Image/Sorts/traineeDeFeu2.png");
    ALLEGRO_BITMAP *img3 = al_load_bitmap("../Image/Sorts/traineeDeFeu3.png");
    ALLEGRO_BITMAP *img4 = al_load_bitmap("../Image/Sorts/traineeDeFeu4.png");
    ALLEGRO_BITMAP *img5 = al_load_bitmap("../Image/Sorts/traineeDeFeu5.png");

    al_draw_bitmap(img1, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img2, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img4, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img5, x, y, 0);
    al_flip_display();
    sleep(1);
}

void didacticiel(){
    int x = 10;
    int y = 250;
    ALLEGRO_BITMAP *imgIop = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    ALLEGRO_BITMAP *boule = al_load_bitmap("../Image/bouleFeu.png");
    ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/1.png");
    ALLEGRO_BITMAP *img2 = al_load_bitmap("../Image/D2.png");
    ALLEGRO_BITMAP *img3 = al_load_bitmap("../Image/D3.png");
    ALLEGRO_BITMAP *img4 = al_load_bitmap("../Image/D4.png");
    ALLEGRO_BITMAP *img5 = al_load_bitmap("../Image/D5.png");
    ALLEGRO_BITMAP *img6 = al_load_bitmap("../Image/D6.png");
    ALLEGRO_BITMAP *img7 = al_load_bitmap("../Image/D7.png");
    ALLEGRO_BITMAP *imgsors = al_load_bitmap("../Image/Classes/CoeurIop/IopPos6.png");
    al_draw_bitmap(img1, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img2, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img3, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img4, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img5, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img6, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img7, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img1, 10, 250, 0);
    al_flip_display();
    sleep(2);
    al_clear_to_color(NOIR);
    bouleDeFeux();
}

void courrirIop(){
    int x = 10;
    int y = 250;
    ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    ALLEGRO_BITMAP *img2 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos2.png");
    ALLEGRO_BITMAP *img3 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos3.png");
    ALLEGRO_BITMAP *img4 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos4.png");
    ALLEGRO_BITMAP *img5 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos5.png");
    ALLEGRO_BITMAP *img6 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos6.png");
    al_draw_bitmap(img1, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(2);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img2, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img4, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img5, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap(img1, x, y, 0);x=x+30;
    // al_flip_display();
    // sleep(1);
    //al_clear_to_color(NOIR);
    al_draw_bitmap(img2, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img4, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img5, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, x+30, y, 0);x=x+30;
    al_flip_display();
    sleep(1);

}
