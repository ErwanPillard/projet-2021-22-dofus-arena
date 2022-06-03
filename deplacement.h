//
// Created by erwan on 16/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_DEPLACEMENT_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_DEPLACEMENT_H

#include "stdio.h"
#include "stdlib.h"

#include "coordonneesISO.h"
#include "joueur.h"
#include "arene.h"
#include "partie.h"

#define BLEU al_map_rgb(106, 244, 252)
#define ORANGE al_map_rgb(243, 111, 2)

typedef struct{
    int x, y;
}Chemin;

void deplacement(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, BUTTON bouton[5], int map[][12], Rect r2[], ALLEGRO_BITMAP *tabClasses[]);
void deplacementJoueur(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], int x, int y, int PM, Joueur joueur[], int joueurEnCours, int map[][12]);
void surbrillanceDeplacementJoueur(CoordonneeISO coordonneeIso[][12], int x, int y, int PM, int map[][12]);

void deplacementJ(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], Joueur joueur[], int joueurEnCours, int map[][12], int* distanceX, int* distanceY);

void dessierDeplacementJoueur(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event, int distanceX, int distanceY, int positionJoueurX, int positionJoueurY, CoordonneeISO coordonneeIso[][12], Partie donneePartie, Joueur joueur[4], Classe classe[]);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_DEPLACEMENT_H
