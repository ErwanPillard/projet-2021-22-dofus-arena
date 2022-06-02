#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SORTS_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SORTS_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "stdlib.h"
#define NB_IMAGE 7
#define NOIR al_map_rgb(0,0,0)

// if sorts 4 alors ca -> faire une fonction
#include <time.h>

#include "coordonneesISO.h"

/*typedef struct {
    image hauteur, largeur;
}visuImage;
*/

typedef struct {
    int porteeMax;
    int porteeMin;
    int numSort;//sors numeroté de 1 a 4
    int nombrePA, nombrePVinflige;
    ALLEGRO_BITMAP *image;
} Sort;

/*
typedef struct {
    int hauteur, largeur;
    ALLEGRO_BITMAP * visuImage[NB_IMAGE];
}image;


typedef struct {
    int porteeX;
    int porteeY;
    int numSort;//sors numeroté de 1 a 4
    int nombrePA, nombrePVinflige;
    image tabImage[3];
}Sort;
*/

void bouleDeFeux();
void traineeFeux();
void dessinerSortsGlace(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event);





#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SORTS_H
