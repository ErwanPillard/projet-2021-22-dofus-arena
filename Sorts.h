#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SORTS_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SORTS_H

#include "stdlib.h"
#include <time.h>

#include "coordonneesISO.h"
#include "joueur.h"

typedef struct Sort {
    int porteeX;
    int porteeY;
    int numSort;//sors numeroté de 1 a 4
    int nombrePA, nombrePVinflige;

    ALLEGRO_BITMAP *image;
} Sort;




#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SORTS_H
