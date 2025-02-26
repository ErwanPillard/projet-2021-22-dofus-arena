//
// Created by 33782 on 05/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_JOUEUR_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_JOUEUR_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
//#include "classe.h"

#define BLANC al_map_rgb(255,255,255)
#define NB_IMAGES 10

#include <time.h>

#include "coordonneesISO.h"

typedef struct{
    int classe;
    int caseX;//sur quelle case est positionné le joueur
    int caseY;
    int PM;
    int PA;
    int PV;
    ALLEGRO_BITMAP* sprite[NB_IMAGES];
}Joueur;

void initialiserJoueur(Joueur joueur[4]);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_JOUEUR_H