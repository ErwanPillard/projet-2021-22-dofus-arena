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

void surbrillanceJoueur(CoordonneeISO coordonneeIso[][12], int x, int y, int PM){

    al_draw_filled_ellipse(coordonneeIso[x][y].x, coordonneeIso[x][y].y, 20, 15, BLANC);

    if(PM > 0){
        surbrillanceJoueur(coordonneeIso, x + 1, y, PM - 1);
        surbrillanceJoueur(coordonneeIso, x - 1, y, PM - 1);
        surbrillanceJoueur(coordonneeIso, x, y + 1, PM - 1);
        surbrillanceJoueur(coordonneeIso, x, y - 1, PM - 1);
    }
}

int deplacementJoueurs(int mouseX, int mouseY, CoordonneeISO coordonneeIso[][12], Joueur joueur[]){
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            if(mouseX >= coordonneeIso[i][j].x - 20 && mouseX <= coordonneeIso[i][j].x + 20 && mouseY >= coordonneeIso[i][j].y - 15 && mouseY <= coordonneeIso[i][j].y + 15){
                joueur[0].caseX = i;
                joueur[0].caseY = j;
            }
        }
    }
}




