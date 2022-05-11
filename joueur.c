//
// Created by 33782 on 05/05/2022.
//

#include "joueur.h"

void initialiserJoueur(Joueur joueur[4]){
    srand(time(NULL));

    joueur[0].classe = 5;
    joueur[0].caseX = rand()%12;
    joueur[0].caseY = rand()%12;
    joueur[0].PM = 3;

    joueur[1].classe = 5;
    joueur[2].classe = 5;
    joueur[3].classe = 5;
}


