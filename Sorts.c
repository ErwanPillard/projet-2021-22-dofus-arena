#include "Sorts.h"
#include "classe.h"

// faire un switch case pour les rands
// faire une fonctionne Initialisation Corps à corps -> pas de rapport avec les classes, indépendantes

void initialiserSorts(Classe classe[]){
    srand(time(NULL));
    //Initialisation Classe 1
    ////////* Sorts 1*/////////////
    classe[0].sorts[0].numSort = 1;
    classe[0].sorts[0].nombrePA = 5;
    classe[0].sorts[0].nombrePVinflige = rand() % (5) + 18;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 18 et MAX = 22
    //classe[0].sorts[0].porteeX = ;
    //classe[0].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[0].sorts[1].numSort = 2;
    classe[0].sorts[1].nombrePA = 2;
    classe[0].sorts[1].nombrePVinflige = rand() % (5) + 10;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 10 et MAX = 14
    //classe[0].sorts[1].porteeX = ;
    //classe[0].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[0].sorts[2].numSort = 3;
    classe[0].sorts[2].nombrePA = 6;
    classe[0].sorts[2].nombrePVinflige = rand() %(5) + 22;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 22 et MAX = 26
    //classe[0].sorts[2].porteeX = ;
    //classe[0].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[0].sorts[3].numSort = 4;
    classe[0].sorts[3].nombrePA = 3;
    classe[0].sorts[3].nombrePVinflige = rand() %(5) + 14;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 14 et MAX = 18
    //classe[0].sorts[3].porteeX = ;
    //classe[0].sorts[3].porteeY = ;


    //Initialisation Classe 2
    ////////* Sorts 1*/////////////
    classe[1].sorts[0].numSort = 1;
    classe[1].sorts[0].nombrePA = 4;
    classe[1].sorts[0].nombrePVinflige = rand() % (5) + 15;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 15 et MAX = 19
    //classe[1].sorts[0].porteeX = ;
    //classe[1].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[1].sorts[1].numSort = 2;
    classe[1].sorts[1].nombrePA = 3;
    classe[1].sorts[1].nombrePVinflige = rand() % (5) + 8;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 8 et MAX = 12
    //classe[1].sorts[1].porteeX = ;
    //classe[1].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[1].sorts[2].numSort = 3;
    classe[1].sorts[2].nombrePA = 2;
    classe[1].sorts[2].nombrePVinflige = rand() % (5) + 13;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 13 et MAX = 17
    //classe[1].sorts[2].porteeX = ;
    //classe[1].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[1].sorts[3].numSort = 4;
    classe[1].sorts[3].nombrePA = 3;
    classe[1].sorts[3].nombrePVinflige = rand() % (5) + 15;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 15 et MAX = 19
    //classe[1].sorts[3].porteeX = ;
    //classe[1].sorts[3].porteeY = ;

    //Initialisation Classe 3
    ////////* Sorts 1*/////////////
    classe[2].sorts[0].numSort = 1;
    classe[2].sorts[0].nombrePA = 4;
    classe[2].sorts[0].nombrePVinflige = rand() % (5) + 18;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 18 et MAX = 22
    //classe[2].sorts[0].porteeX = ;
    //classe[2].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[2].sorts[1].numSort = 2;
    classe[2].sorts[1].nombrePA = 5;
    classe[2].sorts[1].nombrePVinflige = rand() % (5) + 22;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 22 et MAX = 26
    //classe[2].sorts[1].porteeX = ;
    //classe[2].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[2].sorts[2].numSort = 3;
    classe[2].sorts[2].nombrePA = 3;
    classe[2].sorts[2].nombrePVinflige = rand() % (5) + 16;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 16 et MAX = 20
    //classe[2].sorts[2].porteeX = ;
    //classe[2].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[2].sorts[3].numSort = 4;
    classe[2].sorts[3].nombrePA = 4;
    classe[2].sorts[3].nombrePVinflige = rand() % (5) + 18;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 18 et MAX = 22
    //classe[2].sorts[3].porteeX = ;
    //classe[2].sorts[3].porteeY = ;

    //Initialisation Classe 4
    ////////* Sorts 1*/////////////
    classe[3].sorts[0].numSort = 1;
    classe[3].sorts[0].nombrePA = 2;
    classe[3].sorts[0].nombrePVinflige = 0; // rajouter des PV au persos lorsqu'il utilise ce sort
    //classe[3].sorts[0].porteeX = ;
    //classe[3].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[3].sorts[1].numSort = 2;
    classe[3].sorts[1].nombrePA = 3;
    classe[3].sorts[1].nombrePVinflige = rand() % (5) + 16;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 16 et MAX = 20
    //classe[3].sorts[1].porteeX = ;
    //classe[3].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[3].sorts[2].numSort = 3;
    classe[3].sorts[2].nombrePA = 3;
    classe[3].sorts[2].nombrePVinflige = rand() % (5) + 15;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 15 et MAX = 19
    //classe[3].sorts[2].porteeX = ;
    //classe[3].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[3].sorts[3].numSort = 4;
    classe[3].sorts[3].nombrePA = 4;
    classe[3].sorts[3].nombrePVinflige = rand() % (5) + 20;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 20 et MAX = 24
    //classe[3].sorts[3].porteeX = ;
    //classe[3].sorts[3].porteeY = ;

}
