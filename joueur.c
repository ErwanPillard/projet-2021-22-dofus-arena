#include "joueur.h"

void initialiserJoueur(Joueur joueur[4]){
    srand(time(NULL));

    joueur[0].classe = 5;
    joueur[0].caseX = rand()%12;
    joueur[0].caseY = rand()%12;
    joueur[0].PM = 3;
    joueur[0].PA = 6;
    joueur[0].PV = 50;

    joueur[1].classe = 5;
    joueur[1].caseX = rand()%12;
    joueur[1].caseY = rand()%12;
    joueur[1].PM = 3;
    joueur[1].PA = 6;
    joueur[1].PV = 50;

    joueur[2].classe = 5;
    joueur[2].caseX = rand()%12;
    joueur[2].caseY = rand()%12;
    joueur[2].PM = 3;
    joueur[2].PA = 6;
    joueur[2].PV = 50;

    joueur[3].classe = 5;
    joueur[3].caseX = rand()%12;
    joueur[3].caseY = rand()%12;
    joueur[3].PM = 3;
    joueur[3].PA = 6;
    joueur[3].PV = 50;

}
