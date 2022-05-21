//
// Created by erwan on 16/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_DEPLACEMENT_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_DEPLACEMENT_H

#include "stdio.h"

#include "coordonneesISO.h"
#include "joueur.h"
#include "arene.h"
#include "partie.h"

#define BLEU al_map_rgb(0, 0, 255)

void deplacement(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, CoordonneeISO coordonneeIso[][12], Joueur joueur[], Classe classe[], Partie donneePartie, ALLEGRO_TIMER *timer, Rect r[5]);
void deplacementJoueur(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], int x, int y, int PM, Joueur joueur[], int joueurEnCours, int map[][12]);
void surbrillanceDeplacementJoueur(CoordonneeISO coordonneeIso[][12], int x, int y, int PM, int map[][12]);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_DEPLACEMENT_H
