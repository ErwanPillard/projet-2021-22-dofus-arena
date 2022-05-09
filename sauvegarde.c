//
// Created by Yannis on 06/05/2022.
//
/*
#include "sauvegarde.h"

FILE* creerFichier(){
    char chemin[LG_MAX_CHEMIN_SAUVEGARDE];
    char nomPartie[LG_MAX_NOM_PARTIE];
    printf("Comment voulez vous appeler votre partie?\n");
    scanf("%s",nomPartie);
    sprintf(chemin,"%s/%s", CHEMIN_SAUVEGARDE, nomPartie);
    FILE* monFichier = fopen(chemin,"w");
    return monFichier;
}

void copierJoueur(Joueur j[], Partie donneePartie, FILE* creerFichier()){
    for(int i=0; i < donneePartie.nbJoueurs; i++){
        fprintf(FILE*, "JOUEUR:%s\n",donneePartie.tabJoueur[i].nom);
        fprintf(FILE*;
    }
}*/