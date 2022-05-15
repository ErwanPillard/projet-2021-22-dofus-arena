//
// Created by 33782 on 04/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACE0_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACE0_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "menu.h"

#define LARGEUR 1400
#define HAUTEUR 807

#define OR al_map_rgb(255,251,14)
#define ORfonce al_map_rgb(238,225,32)
#define BLANC al_map_rgb(255,255,255)
#define NOIR al_map_rgb(0,0,0)


void initialisationInterface0(Rect *r);
void dessinerInterface0(ALLEGRO_BITMAP *imagePrincipale, Rect r[]);
void interface0(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT event);


#endif ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACE0_H
