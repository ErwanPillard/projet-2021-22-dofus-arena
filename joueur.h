//
// Created by 33782 on 05/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_JOUEUR_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_JOUEUR_H

typedef struct j{
    int classe;
    int x, y; // position
    int pas; // déplacement
    int tx, ty;// taille

    //animation
    int tour, nbtour;
    int nbimage;
    int imcourante;
    int dir;
}Joueur;

void initialiserJoueur(Joueur *joueur);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_JOUEUR_H
