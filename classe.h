//
// Created by 33782 on 04/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H

#include "menu.h"
#include "partie.h"
#include "joueur.h"

#define NB_POSITION 8
#define NB_RECT 8

enum bouton{VALIDER, CLASSE1, CLASSE2, CLASSE3, CLASSE4, FLECHEGAUCHE, FLECHEDROITE};

typedef struct {
    int x, y, largeur, hauteur;
    ALLEGRO_BITMAP *image;
    ALLEGRO_COLOR color;
}Perso;

typedef struct {
    ALLEGRO_BITMAP *fondEcran;
    Perso perso[NB_POSITION];
    Rect rectangle[NB_RECT];
}Classe;


void initialisationClasses(Classe *classe);
void dessinerInterfaceClasses(Classe c[], int classeEnCours, int posJoueur);

void classe(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE* queue, Joueur *joueur, Classe *classe, int indiceJoueur, int classeEnCours, int posJoueur);


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H
