#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "Sorts.h"

typedef struct Classe {
    char nom[50];
    ALLEGRO_BITMAP *skin;
    Sort sorts[4];
    bool dispo;
} Classe;

enum typeSort{CERCLE, LIGNE, ZONE};

void initialiserClasses(Classe *classe);

void initialiserSorts(Classe classe[]);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_CLASSE_H
