//
// Created by Erwan Pillard on 29/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACESORT_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACESORT_H

#include "coordonneesISO.h"
#include "joueur.h"
#include "arene.h"
#include "partie.h"


void choixSort(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[],Partie donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12], int numSort, int type, Rect r2[], ALLEGRO_BITMAP *tabClasses[]);

void dessinerSortsGlace(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, Rect r[5], int cibleX, int cibleY, Rect r2[], ALLEGRO_BITMAP *tabClasses[]);

void sortCercle(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12], int numSort, Rect r2[], ALLEGRO_BITMAP *tabClasses[]);

void sortLigneDroite(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12], int numSort, Rect r2[], ALLEGRO_BITMAP *tabClasses[]);

void verifSiJoueurSurCase(int cibleX, int cibleY, int nbJoueurs, Joueur joueur[], Classe classe[], int numSort);
#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACESORT_H
