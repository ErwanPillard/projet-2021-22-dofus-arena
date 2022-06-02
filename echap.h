//
// Created by 33782 on 04/05/2022.
//
#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_ECHAP_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_ECHAP_H


#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <time.h>
#include "rect.h"

#define LARGEUR 1400
#define HAUTEUR 807

#define OR al_map_rgb(255,251,14)
#define ORfonce al_map_rgb(238,225,32)
#define BLANC al_map_rgb(255,255,255)
#define NOIR al_map_rgb(0,0,0)

Rect initialisationMenuEchap(Rect* r);
void dessinerMenuEchap(ALLEGRO_BITMAP* imagePrincipal,Rect r[]);
void interfaceEchap(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT event);
#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_ECHAP
