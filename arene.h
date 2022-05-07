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

#include "menu.h"

typedef struct{
}Arene;

void initialiserArene();
void dessinerArene();

void arene(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_ARENE_H
