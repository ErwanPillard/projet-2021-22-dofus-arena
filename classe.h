//
// Created by 33782 on 04/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H

#include "menu.h"
#include "partie.h"
#include "joueur.h"

#define NB_POSITION 8
#define NB_RECT 5

enum bouton{VALIDER};

typedef struct {
    int x, y;
    ALLEGRO_BITMAP *image;
}Perso;

typedef struct {
    ALLEGRO_BITMAP *fondEcran;
    Perso perso[NB_POSITION];
    Rect rectangle[NB_RECT];
}Classe;


Classe initialisationClasses(Classe classe[]);
void dessinerInterfaceClasses(Classe c[]);


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H
