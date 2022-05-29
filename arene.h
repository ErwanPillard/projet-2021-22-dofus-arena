//
// Created by 33782 on 03/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_ARENE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_ARENE_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <assert.h>
#include <stdio.h>

#define OR al_map_rgb(255,251,14)
#define ORfonce al_map_rgb(238,225,32)
#define BLANC al_map_rgb(255,255,255)
#define NOIR al_map_rgb(0,0,0)
#define LARGEUR 1400
#define HAUTEUR 807

#define LARGEUR_TUILE 80
#define HAUTEUR_TUILE 41
#define POSITION_MAP_ISO_X 700 //premier carré en haut a gauche
#define POSITION_MAP_ISO_Y 300

#include "joueur.h"
#include "classe.h"
#include "coordonneesISO.h"
#include "deplacement.h"

void dessinerArene(CoordonneeISO coordonneeIso[12][12], Joueur joueur[4], Classe classe[]);
void dessinerSurbrillance(CoordonneeISO coordonneeIso[12][12]);
//void dessinerObsacle();
void dessinerJoueurs(CoordonneeISO coordonneeIso[12][12], Joueur joueur[], Classe classe[], int nbJoueurs);
void dessinerObsacle(int map[][12]);
void dessinerCompteur(int tmp, ALLEGRO_FONT *compteur);
void initialiserCoordMilieuTuile(CoordonneeISO coordonneeIso[12][12]);
void initialiserArene(int map[][12]);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_ARENE_H