//
// Created by erwan on 07/05/2022.
//

#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACECLASSE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACECLASSE_H


#include "joueur.h"
#include "classe.h"
#include "partie.h"

#include <stdio.h>

#define OR al_map_rgb(255,251,14)
#define ORfonce al_map_rgb(238,225,32)
#define BLANC al_map_rgb(255,255,255)
#define NOIR al_map_rgb(0,0,0)
#define LARGEUR 1400
#define HAUTEUR 807

#define NB_POSITION 9
#define NB_RECT 9

#define VIOLET al_map_rgb(148,0,211)
#define VERT al_map_rgb(0, 255, 0)
#define VERTfonce al_map_rgb(47, 179, 47)

enum classe{VALIDER, FLECHE, CLASSE1, CLASSE2, CLASSE3, CLASSE4, TEXTE};

typedef struct {
    ALLEGRO_BITMAP *image;
}Perso;

typedef struct { //different entre chaque classes
    ALLEGRO_BITMAP *fondEcran;
    ALLEGRO_BITMAP *infoClasse;
    Perso perso[NB_POSITION];
    int disponible;
}AffichageClasse;

typedef struct{ //similaire pour différentes classes
    ALLEGRO_BITMAP *bitmap;
    float x, y;
    float largeur, hauteur;
    ALLEGRO_FONT *texte;
}InterfaceClasse;

unsigned char surPassage(int mouse_x, int mouse_y, int x, int y, int largeur,int hauteur);// duplication fonction à optimiser

void dessinerBoutonValide(InterfaceClasse interfaceC[]);
void dessinerFleche(InterfaceClasse interfaceC[]);
void dessinerBoutonClasses(InterfaceClasse interfaceC[]);
void dessinerTexteInterfaceClasse(InterfaceClasse interfaceC[], Joueur joueur[], Classe classe[], int nbJoueurs, int joueurEnCours);

void initialisationInterfaceClasses(AffichageClasse *classe, InterfaceClasse *interfaceC);
void dessinerInterfaceClasses(AffichageClasse affichageClasse[], int classeEnCours, int posJoueur, int joueurEnCours, int nbJoueurs, Joueur joueur[], InterfaceClasse interfaceC[], Classe classe[]);

void interfaceClasse(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE* queue, Joueur *joueur, Partie partie, Classe classe[]);


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_AA_INTERFACECLASSE_H
