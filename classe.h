#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H

#include "menu.h"
#include "partie.h"
#include "joueur.h"

#define NB_POSITION 9
#define NB_RECT 9

#define VIOLET al_map_rgb(148,0,211)
#define VERT al_map_rgb(0, 255, 0)
#define VERTfonce al_map_rgb(47, 179, 47)

enum bouton{CLASSE1, CLASSE2, CLASSE3, CLASSE4, VALIDER, FLECHEDROITE};

typedef struct {
    ALLEGRO_BITMAP *image;
}Perso;

typedef struct {
    ALLEGRO_BITMAP *fondEcran;
    ALLEGRO_BITMAP *infoClasse;
    ALLEGRO_BITMAP *fleche;
    ALLEGRO_BITMAP *valide;
    Perso perso[NB_POSITION];
    Rect rectangle[NB_RECT];
    int disponible;
}Classe;


void initialisationClasses(Classe *classe);
void dessinerInterfaceClasses(Classe c[], int classeEnCours, int posJoueur);

void classe(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE* queue, Joueur *joueur, Partie partie);


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H
