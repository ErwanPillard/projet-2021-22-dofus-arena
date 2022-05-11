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

#include "menu.h"
#include "joueur.h"

#define LARGEUR_TUILE 80
#define HAUTEUR_TUILE 47
#define POSITION_MAP_ISO_X 700 //premier carré en haut a gauche
#define POSITION_MAP_ISO_Y 150

typedef struct{
    float x, y;
}CoordonneeISO;

void dessinerArene(ALLEGRO_BITMAP *font, CoordonneeISO coordonneeIso[12][12], Joueur joueur[4]);
void dessinerSurbrillance(CoordonneeISO coordonneeIso[12][12]);

void dessinerJoueur(CoordonneeISO coordonneeIso[12][12], Joueur joueur[]);

void initialiserCoordMilieuTuile(CoordonneeISO coordonneeIso[12][12]);

void arene(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, Joueur joueur[4]);


#endif ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_ARENE_H