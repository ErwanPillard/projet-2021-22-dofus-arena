//
// Created by Yannis on 06/05/2022.
//

#include "sauvegarde.h"
#include "menu.h"

#define NB_RECT 2

void dessinerInterfaceChargement(Rect r[]){
    ALLEGRO_BITMAP *imagePrincipale = al_load_bitmap("../Image/dofus3.jpg");
    
    al_draw_bitmap(imagePrincipale,0,0,0);

    al_draw_filled_rectangle(r[0].x, r[0].y,r[0].x + r[0].largeur,r[0].y + r[0].hauteur,r[0].color);
    al_draw_rectangle(r[0].x,r[0].y,r[0].x + r[0].largeur, r[0].y + r[0].hauteur,r[0].color,r[0].thickness);
    al_draw_text(r[0].font, NOIR, r[0].x + 60, r[0].y + 6, 0, "PARTIE ?");

    al_flip_display();
}


void charger(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event){
    bool end = false;

    Rect r[NB_RECT];

    r[0].largeur = 200;
    r[0].hauteur = 50;
    r[0].x = (float)LARGEUR / 2 - r[0].largeur / 2;
    r[0].y = (float)HAUTEUR / 2 - r[0].hauteur / 2;
    r[0].color = OR;
    r[0].thickness = 5;
    r[0].colorThickness = ORfonce;
    r[0].font = al_load_font("../Polices/Achafont.ttf", 30, 0);

    ALLEGRO_SAMPLE *whoosh = al_load_sample(".../Sound/whoosh.ogg");

    dessinerInterfaceChargement(r);
    
    while(!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                if(surPassageCase(event.mouse.x, event.mouse.y, r[0])){
                    al_play_sample(whoosh, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, 0);
                    //action a faire

                    end = true;
                }
                break;
            }
        }
        
    }
    
}


/*
FILE* creerFichier(){
    char chemin[LG_MAX_CHEMIN_SAUVEGARDE];
    char nomPartie[LG_MAX_NOM_PARTIE];
    printf("Comment voulez-vous appeler votre partie?\n");
    scanf("%s",nomPartie);
    sprintf(chemin,"%s/%s", CHEMIN_SAUVEGARDE, nomPartie);
    FILE* monFichier = fopen(chemin,"w");
    return monFichier;
}*/

/*
void copierJoueur(Joueur j[], Partie donneePartie, FILE* creerFichier(), FILE *myFile, Classe classe){
    for(int i=0; i < donneePartie.nbJoueurs; i++){
        fprintf(myFile, "JOUEUR:%s\n",donneePartie.nom);
        fprintf(myFile,"%s%\n",
                classe.nom,
                classe.skin,
                classe.sorts);
    }
}


int fermerFichier(FILE* myFile){
    return fclose (myFile);
}

int sauvegarderPartie(){
    FILE *sauvegarde = creerFichier();
    //ouvrirFichier();
    if (NULL != sauvegarde){
        copierJoueur(sauvegarde);
    }
    else {
        printf("Erreur sur création fichier\n");
    }
    if (0 != fermerFichier(sauvegarde)) {
        printf ("Erreur lors de la fermeture du fichier de sauvegarde\n");
    }
}

/*
int rechargerPlateau(FILE * myFile){
    // Recharger plateau
    fscanf(myFile,"PLATEAU:%d;%d\n", &monPlateau.nbJoueurs, &monPlateau.indexJoueurCourant);

    // Recharger Joueurs
    for(int i=0;i<monPlateau.nbJoueurs;i++){
        fscanf(myFile, "JOUEUR:%[^\n]",monPlateau.tabJoueurs[i].nom);
        fscanf(myFile, "%d;%d;%f;%d\n",
               &monPlateau.tabJoueurs[i].propriete,
               &monPlateau.tabJoueurs[i].cartes,
               &monPlateau.tabJoueurs[i].argent,
               &monPlateau.tabJoueurs[i].positionJoueur);
    }

    
    for(int i=0; i<NB_MAX_JOUEUR;i++){
        fscanf(myFile, "PRET:%f\n", &monPlateau.maBanque.tabPretParJoueur[i]);
    }

    // Recharger Cases
    for(int i=0; i<NB_CASE;i++){
        fscanf(myFile, "CASE:%[^\n]", monPlateau.tabCases[i].nom);
        fscanf(myFile, "%d,%d,%f\n",
               &monPlateau.tabCases[i].nature,
               &monPlateau.tabCases[i].index,
               &monPlateau.tabCases[i].valTaxes);
    }
}*/