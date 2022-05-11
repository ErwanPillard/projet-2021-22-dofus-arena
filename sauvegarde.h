//
// Created by Yannis on 06/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SAUVEGARDE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SAUVEGARDE_H
#include "joueur.h"
#include "partie.h"
#include "classe.h"
#include <wchar.h>
#include <stdio.h>
#include <string.h>
#define CHEMIN_SAUVEGARDE "C:/Users"
#define LG_MAX_CHEMIN_SAUVEGARDE 128
#define LG_MAX_NOM_PARTIE 64

FILE* creerFichier();
void copierJoueur(Joueur j[], Partie donneePartie, FILE* creerFichier(), FILE *myFile, Classe classe);
int copierMAPDansFichier(FILE *myFile);
int fermerFichier(FILE* myFile);
int sauvegarderPartie();


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_SAUVEGARDE_H
