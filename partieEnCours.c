//
// Created by erwan on 16/05/2022.
//

#include "partieEnCours.h"

void partie(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4], Classe classe[]){
    bool end = false;

    CoordonneeISO coordonneeIso[12][12];
    initialiserCoordMilieuTuile(coordonneeIso);

    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                end = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                //si clic sur le carré déplacement :
                deplacementJoueur(event.mouse.x, event.mouse.y, coordonneeIso,joueur[0].caseX, joueur[0].caseY, joueur[0].PM, joueur);

                dessinerArene(coordonneeIso, joueur, classe);
                surbrillanceDeplacementJoueur(coordonneeIso, joueur[0].caseX, joueur[0].caseY,joueur[0].PM);
                dessinerJoueur(coordonneeIso, joueur, classe);
                al_flip_display();

                break;
            }
        }
    }
}