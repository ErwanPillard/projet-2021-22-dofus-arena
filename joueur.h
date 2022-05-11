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

#include <time.h>

typedef struct{
    int classe;
    int caseX;//sur quelle case est positionné le joueur
    int caseY;
    int PM;
}Joueur;

void initialiserJoueur(Joueur joueur[4]);


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_JOUEUR_H