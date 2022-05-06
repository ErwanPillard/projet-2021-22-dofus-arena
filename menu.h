//
// Created by 33782 on 29/04/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_MENU_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "partie.h"

#define LARGEUR 1400
#define HAUTEUR 807

#define OR al_map_rgb(255,251,14)
#define ORfonce al_map_rgb(238,225,32)
#define BLANC al_map_rgb(255,255,255)
#define NOIR al_map_rgb(0,0,0)

#define NB_RECTANGLE_NBJ 4

typedef struct{
    float x, y, largeur, hauteur, thickness, rounded_x, rounded_y;
    ALLEGRO_COLOR color;
    ALLEGRO_COLOR colorThickness;
    ALLEGRO_FONT *font;
}Rect;

unsigned char surPassageCase(int mouse_x, int mouse_y, Rect rectanglefilled);
void dessinerFilledRectangle2(float x, float y, float largeur, float hauteur, ALLEGRO_COLOR color);
void dessinerFilledRectangle(float x, float y, float largeur, float hauteur, ALLEGRO_COLOR color);

void dessinerRectangle(float x, float y, float largeur, float hauteur, ALLEGRO_COLOR color, float thickness);

unsigned char clicExterneRectangle( int mouse_x, int mouse_y, Rect r);

Rect initialisationInterface1(Rect *r);

void dessinerInterface1(ALLEGRO_BITMAP *imagePrincipale, Rect r[]);

void menu(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event, Partie *donneePartie);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_MENU_H
