//
// Created by Erwan Pillard on 29/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACESORT_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACESORT_H

#include "coordonneesISO.h"
#include "joueur.h"
#include "arene.h"
#include "partie.h"

void sortCercle(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]);

void sortLigneDroite(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie *donneePartie, ALLEGRO_TIMER *timer, Rect r[5], int map[][12]);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACESORT_H
