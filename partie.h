//
// Created by 33782 on 05/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_PARTIE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_PARTIE_H

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
#include "rect.h"


typedef struct{
    int nbJoueurs;
    char nom[50];
    int joueurEnCours;
}Partie;

enum action{DEPLACER, SUIVANT, SORT1};

void partie(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4], Classe classe[],Partie donneePartie);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_PARTIE_H
