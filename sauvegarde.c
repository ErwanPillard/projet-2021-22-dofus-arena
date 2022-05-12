//
// Created by Yannis on 06/05/2022.
//

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

    // Recharger Banque
    fscanf(myFile, "BANQUE:%d;%d\n", &monPlateau.maBanque.nbMaisonRestant, &monPlateau.maBanque.nbHotelRestant);
    for(int i=0; i<NB_MAX_PROPRIETE;i++){
        fscanf(myFile, "PROPRIETE:%[^\n]", monPlateau.maBanque.tabProp[i].nom);
        fscanf(myFile, "%f;%f;%d;%d;%d;%d\n",
               &monPlateau.maBanque.tabProp[i].prixdeRevente,
               &monPlateau.maBanque.tabProp[i].prixAchat,
               &monPlateau.maBanque.tabProp[i].nbMaisonSurProp,
               &monPlateau.maBanque.tabProp[i].nbHotelSurProp,
               &monPlateau.maBanque.tabProp[i].groupe,
               &monPlateau.maBanque.tabProp[i].indexJoueurPropritaire);
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