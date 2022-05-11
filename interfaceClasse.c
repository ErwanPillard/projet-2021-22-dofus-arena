
#include "interfaceClasse.h"

unsigned char surPassage(int mouse_x, int mouse_y, int x, int y, int largeur,int hauteur){// duplication fonction à optimiser
    if(mouse_x >= x && mouse_y >= y && mouse_x <= x + largeur && mouse_y <= y + hauteur){
        return 1;
    }
    return 0;
}

void initialisationInterfaceClasses(AffichageClasse *classe, InterfaceClasse *interfaceC){
    //Affichage général
    interfaceC[VALIDER].bitmap = al_load_bitmap("../Image/bouttonStart.png");
    interfaceC[VALIDER].x = 1200;
    interfaceC[VALIDER].y = 700;
    interfaceC[VALIDER].largeur = 165;
    interfaceC[VALIDER].hauteur = 73;

    interfaceC[FLECHE].bitmap = al_load_bitmap("../Image/fleche.png");
    interfaceC[FLECHE].x = (float)LARGEUR /2 - 30;
    interfaceC[FLECHE].y = (float)HAUTEUR /2;
    interfaceC[FLECHE].largeur = 100;
    interfaceC[FLECHE].hauteur = 80;

    interfaceC[CLASSE1].bitmap = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum1.png");
    interfaceC[CLASSE1].x = 600;
    interfaceC[CLASSE1].y = 700;
    interfaceC[CLASSE1].hauteur = 75;
    interfaceC[CLASSE1].largeur = 75;


    interfaceC[CLASSE2].bitmap = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    interfaceC[CLASSE2].x = 655;
    interfaceC[CLASSE2].y = 700;
    interfaceC[CLASSE2].hauteur = 75;
    interfaceC[CLASSE2].largeur = 75;

    interfaceC[CLASSE3].bitmap = al_load_bitmap("../Image/Classes/eniripsa/eniripsa1.png");
    interfaceC[CLASSE3].x = 710;
    interfaceC[CLASSE3].y = 700;
    interfaceC[CLASSE3].hauteur = 75;
    interfaceC[CLASSE3].largeur = 75;

    interfaceC[CLASSE4].bitmap = al_load_bitmap("../Image/Classes/huppermage/hup1.png");
    interfaceC[CLASSE4].x = 765;
    interfaceC[CLASSE4].y = 700;
    interfaceC[CLASSE4].hauteur = 75;
    interfaceC[CLASSE4].largeur = 75;



    //Texte
    interfaceC[TEXTE].texte = al_load_font("../Polices/madetommy.ttf", 20, 0);

    //1er classe
    classe[0].fondEcran = al_load_bitmap("../Image/Classes/OmbreSrum/ombresram.jpg");
    classe[0].infoClasse = al_load_bitmap("../Image/Classes/OmbreSrum/infoSram.png");

    classe[0].perso[0].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum1.png");
    classe[0].perso[1].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum2.png");
    classe[0].perso[2].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum3.png");
    classe[0].perso[3].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum4.png");
    classe[0].perso[4].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum5.png");
    classe[0].perso[5].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum6.png");
    classe[0].perso[6].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum7.png");
    classe[0].perso[7].image = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum8.png");


    //2eme classe
    classe[1].fondEcran = al_load_bitmap("../Image/Classes/CoeurIop/IOP.jpg");
    classe[1].infoClasse = al_load_bitmap("../Image/Classes/CoeurIop/IOP.png");

    classe[1].perso[0].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    classe[1].perso[1].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP2.png");
    classe[1].perso[2].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP3.png");
    classe[1].perso[3].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP4.png");
    classe[1].perso[4].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP5.png");
    classe[1].perso[5].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP6.png");
    classe[1].perso[6].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP7.png");
    classe[1].perso[7].image = al_load_bitmap("../Image/Classes/CoeurIop/IOP8.png");


    classe[2].infoClasse = al_load_bitmap("../Image/Classes/eniripsa/infoEniripsa.png");
    classe[2].fondEcran = al_load_bitmap("../Image/Classes/eniripsa/eniripsafondecran.jpg");
    classe[2].perso[0].image = al_load_bitmap("../Image/Classes/eniripsa/eniripsa1.png");
    classe[2].perso[1].image = al_load_bitmap("../Image/Classes/eniripsa/eniripsa2.png");
    classe[2].perso[2].image = al_load_bitmap("../Image/Classes/eniripsa/eniripsa3.png");
    classe[2].perso[3].image = al_load_bitmap("../Image/Classes/eniripsa/eniripsa4.png");
    classe[2].perso[4].image = al_load_bitmap("../Image/Classes/eniripsa/eniripsa5.png");
    classe[2].perso[5].image = al_load_bitmap("../Image/Classes/eniripsa/eniripsa6.png");
    classe[2].perso[6].image = al_load_bitmap("../Image/Classes/eniripsa/eniripsa7.png");
    classe[2].perso[7].image = al_load_bitmap("../Image/Classes/eniripsa/eniripsa8.png");

    //4eme classe
    classe[3].fondEcran = al_load_bitmap("../Image/Classes/huppermage/huppermagefd2.jpg");
    classe[3].infoClasse = al_load_bitmap("../Image/Classes/huppermage/infoHuppermage.png");
    classe[3].perso[0].image = al_load_bitmap("../Image/Classes/huppermage/hup1.png");
    classe[3].perso[1].image = al_load_bitmap("../Image/Classes/huppermage/hup2.png");
    classe[3].perso[2].image = al_load_bitmap("../Image/Classes/huppermage/hup3.png");
    classe[3].perso[3].image = al_load_bitmap("../Image/Classes/huppermage/hup4.png");
    classe[3].perso[4].image = al_load_bitmap("../Image/Classes/huppermage/hup5.png");
    classe[3].perso[5].image = al_load_bitmap("../Image/Classes/huppermage/hup6.png");
    classe[3].perso[6].image = al_load_bitmap("../Image/Classes/huppermage/hup7.png");
    classe[3].perso[7].image = al_load_bitmap("../Image/Classes/huppermage/hup8.png");
}

void dessinerImageFond(int classeEnCours, AffichageClasse classe[]){
    switch (classeEnCours) {
        case 0:{
            al_draw_scaled_bitmap(classe[0].fondEcran, 0, 0, 1200, 675, 0, 0, LARGEUR, HAUTEUR, 0);
            al_draw_scaled_bitmap(classe[0].infoClasse, 0, 0, 878, 1240, 30, 0, 585, 826, 0);
            break;
        }
        case 1:{
            al_draw_scaled_bitmap(classe[1].fondEcran, 0, 0, 1920, 1080, 0, 0, LARGEUR, HAUTEUR, 0);
            al_draw_scaled_bitmap(classe[1].infoClasse, 0, 0, 882, 1250, 30, 0, 585, 826, 0);

            break;
        }
        case 2:{
            al_draw_scaled_bitmap(classe[2].fondEcran, 0, 0, 1920, 1080, 0, 0, LARGEUR, HAUTEUR, 0);
            al_draw_scaled_bitmap(classe[2].infoClasse, 0, 0, 905, 1280, 30, 0, 585, 826, 0);
            break;
        }
        case 3:{
            al_draw_scaled_bitmap(classe[3].fondEcran, 0, 0, 680, 382, 0, 0, LARGEUR, HAUTEUR, 0);
            al_draw_scaled_bitmap(classe[3].infoClasse, 0, 0, 790, 1124, 30, 0, 585, 826, 0);
            break;
        }
    }
}

void dessinerBoutonValide(InterfaceClasse interfaceC[]){
    al_draw_scaled_bitmap(interfaceC[VALIDER].bitmap, 0, 0, 330, 146, interfaceC[VALIDER].x, interfaceC[VALIDER].y, interfaceC[VALIDER].largeur,interfaceC[VALIDER].hauteur, 0);
}

void dessinerFleche(InterfaceClasse interfaceC[]){
    al_draw_scaled_bitmap(interfaceC[FLECHE].bitmap, 0, 0, 406, 324, interfaceC[FLECHE].x, interfaceC[FLECHE].y, interfaceC[FLECHE].largeur,interfaceC[FLECHE].hauteur, 0);
}

void dessinerBoutonClasses(InterfaceClasse interfaceC[]) { // 4 classes
    al_draw_scaled_bitmap(interfaceC[2].bitmap, 0, 0, 250, 250, interfaceC[2].x, interfaceC[2].y,interfaceC[2].largeur, interfaceC[2].hauteur, 0);
    al_draw_scaled_bitmap(interfaceC[3].bitmap, 0, 0, 250, 250, interfaceC[3].x, interfaceC[3].y,interfaceC[3].largeur, interfaceC[3].hauteur, 0);
    al_draw_scaled_bitmap(interfaceC[4].bitmap, 0, 0, 250, 250, interfaceC[4].x, interfaceC[4].y,interfaceC[4].largeur, interfaceC[4].hauteur, 0);
    al_draw_scaled_bitmap(interfaceC[5].bitmap, 0, 0, 250, 250, interfaceC[5].x, interfaceC[5].y,interfaceC[5].largeur, interfaceC[5].hauteur, 0);
}

void dessinerTexteInterfaceClasse(InterfaceClasse interfaceC[], Joueur joueur[], Classe classe[], int nbJoueurs, int joueurEnCours){
    al_draw_textf(interfaceC[TEXTE].texte, BLANC, 10, 10, 0, "CHOIX DE CLASSE : JOUEUR %d", joueurEnCours + 1);
    for (int i = 0; i < nbJoueurs; i++) {
        if(joueur[i].classe >= 0 && joueur[i].classe <= 3) {
            al_draw_textf(interfaceC[TEXTE].texte, BLANC, 10, (float) (30 + i * 20), 0, "JOUEUR %d : %s", i + 1,
                          classe[joueur[i].classe].nom);
        }
    }
}

void dessinerInterfaceClasses(AffichageClasse affichageClasse[], int classeEnCours, int posJoueur, int joueurEnCours, int nbJoueurs, Joueur joueur[], InterfaceClasse interfaceC[], Classe classe[]){
    al_clear_to_color(NOIR);
    //Fond écran
    //Info joueur
    dessinerImageFond(classeEnCours, affichageClasse);
    //Skin
    al_draw_bitmap(affichageClasse[classeEnCours].perso[posJoueur].image, (float)LARGEUR /2 - 30, (float)HAUTEUR / 2 - 125, 0);

    //Bouton Valider
    dessinerBoutonValide(interfaceC);

    //Fleche
    dessinerFleche(interfaceC);

    //Bouton Classes
    dessinerBoutonClasses(interfaceC);

    //Texte
    dessinerTexteInterfaceClasse(interfaceC, joueur, classe, nbJoueurs, joueurEnCours);
    al_flip_display();
}

void interfaceClasse(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE* queue, Joueur *joueur, Partie donneePartie, Classe classe[]){
    bool end = false;

    AffichageClasse affichageClasse[4];
    InterfaceClasse interfaceC[7];

    initialisationInterfaceClasses(affichageClasse, interfaceC);

    initialiserJoueur(joueur);

    int classeEnCours = 0;
    int posJoueur = 0;

    for (int i = 0; i < donneePartie.nbJoueurs; i++) {
        end = false;
        while(!end){
            al_wait_for_event(queue, &event);
            switch (event.type) {
                case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {
                    if (surPassage(event.mouse.x, event.mouse.y, (int)interfaceC[VALIDER].x, (int)interfaceC[VALIDER].y, (int)interfaceC[VALIDER].largeur,(int)interfaceC[VALIDER].hauteur)){
                        joueur[i].classe = classeEnCours;
                        end = true;
                    }
                    if(surPassage(event.mouse.x, event.mouse.y, (int)interfaceC[CLASSE1].x, (int)interfaceC[CLASSE1].y, (int)interfaceC[CLASSE1].largeur,(int)interfaceC[CLASSE1].hauteur)){
                        classeEnCours = 0;
                        posJoueur = 0;
                    }
                    if(surPassage(event.mouse.x, event.mouse.y, (int)interfaceC[CLASSE2].x, (int)interfaceC[CLASSE2].y, (int)interfaceC[CLASSE2].largeur, (int)interfaceC[CLASSE2].hauteur)){
                        classeEnCours = 1;
                        posJoueur = 0;
                    }
                    if(surPassage(event.mouse.x, event.mouse.y, (int)interfaceC[CLASSE3].x, (int)interfaceC[CLASSE3].y, (int)interfaceC[CLASSE3].largeur,(int)interfaceC[CLASSE1].hauteur)) {
                        classeEnCours = 2;
                        posJoueur = 0;
                    }
                    if(surPassage(event.mouse.x, event.mouse.y, (int)interfaceC[CLASSE4].x, (int)interfaceC[CLASSE4].y, (int)interfaceC[CLASSE4].largeur, (int)interfaceC[CLASSE4].hauteur)){
                        classeEnCours = 3;
                        posJoueur = 0;
                    }
                    if(surPassage(event.mouse.x, event.mouse.y, (int)interfaceC[FLECHE].x, (int)interfaceC[FLECHE].y, (int)interfaceC[FLECHE].largeur,(int)interfaceC[FLECHE].hauteur)){
                        posJoueur = (posJoueur + 1) % 8;
                    }
                    break;
                }
                case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                    //fermer
                }
            }
            dessinerInterfaceClasses(affichageClasse, classeEnCours, posJoueur, i, donneePartie.nbJoueurs, joueur, interfaceC, classe);
        }
    }

    //Liberation
    //Bitmap
/*
    for (int i = 0; i < 4; i++) {
        al_destroy_bitmap(affichageClasse[i].fondEcran);
        al_destroy_bitmap(affichageClasse[i].infoClasse);
        for (int j = 0; j < 9; j++) {
            al_destroy_bitmap(affichageClasse[i].perso[j].image);
        }
    }
    for (int i = 0; i < 6; i++) {
        al_destroy_bitmap(interfaceC[i].bitmap);
    }
    al_destroy_font(interfaceC[6].texte);
    */
}