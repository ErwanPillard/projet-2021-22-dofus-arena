
#include "partie.h"
#include "menu.h"
#include "arene.h"

void partie(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4], Classe classe[], Partie donneePartie){
    ALLEGRO_TIMER *timer = NULL;

    bool end = false;
    bool redessiner = false;

    timer = al_create_timer(15);

    al_register_event_source(queue, al_get_timer_event_source(timer));

    CoordonneeISO coordonneeIso[12][12];
    initialiserCoordMilieuTuile(coordonneeIso);

    donneePartie.joueurEnCours = 0;

    Rect r[5];
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

    dessinerArene(coordonneeIso, joueur, classe);

    //dessiner ellipse joueur qui joue
    al_draw_ellipse(coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].x, coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].y, 20, 15, BLEU, 3);
    dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie.nbJoueurs);
    al_draw_filled_rectangle(r[0].x, r[0].y, r[0].x + r[0].largeur,r[0].y + r[0].hauteur, r[0].color);
    al_draw_filled_rectangle(r[1].x,r[1].y,r[1].x + r[1].largeur, r[1].y + r[1].hauteur, r[1].color);
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
                    deplacement(event, queue, coordonneeIso, joueur, classe, donneePartie, timer, r);
                    redessiner = true;
                }
                if(surPassageCase(event.mouse.x, event.mouse.y, r[SUIVANT])){
                    joueur[donneePartie.joueurEnCours].PM = 3;
                    donneePartie.joueurEnCours = (donneePartie.joueurEnCours + 1) % donneePartie.nbJoueurs;
                    al_stop_timer(timer);
                    al_start_timer(timer);//pour réinitialiser le timer : stop puis start
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
            al_draw_ellipse(coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].x, coordonneeIso[joueur[donneePartie.joueurEnCours].caseX][joueur[donneePartie.joueurEnCours].caseY].y, 20, 15, BLEU, 3);
            dessinerJoueurs(coordonneeIso, joueur, classe, donneePartie.nbJoueurs);
            al_draw_filled_rectangle(r[0].x, r[0].y, r[0].x + r[0].largeur,r[0].y + r[0].hauteur, r[0].color);
            al_draw_filled_rectangle(r[1].x, r[1].y, r[1].x + r[1].largeur,r[1].y + r[1].hauteur, r[1].color);
            al_flip_display();
            redessiner = false;
        }
    }
    al_destroy_timer(timer);
}