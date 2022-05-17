//
// Created by erwan on 16/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_PARTIEENCOURS_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_PARTIEENCOURS_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <assert.h>
#include <stdio.h>

#include "joueur.h"
#include "classe.h"
#include "coordonneesISO.h"
#include "interfaceClasse.h"
#include "deplacement.h"
#include "arene.h"

void partie(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4], Classe classe[]);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_PARTIEENCOURS_H
