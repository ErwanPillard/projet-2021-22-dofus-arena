//
// Created by Yannis on 06/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SAUVEGARDE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SAUVEGARDE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "joueur.h"
#include "partie.h"
#include "classe.h"
#include "arene.h"
#include "rect.h"
#include <wchar.h>
#include <stdio.h>
#include <string.h>
#define CHEMIN_SAUVEGARDE "C:/Users"
#define LG_MAX_CHEMIN_SAUVEGARDE 128
#define LG_MAX_NOM_PARTIE 64

FILE* creerFichier();
void copierJoueur(Joueur j[], Partie donneePartie, FILE* creerFichier(), FILE *myFile, Classe classe);
int copierMAPDansFichier(FILE *myFile);
int fermerFichier(FILE* myFile);
int sauvegarderPartie();

void charger(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SAUVEGARDE_H
