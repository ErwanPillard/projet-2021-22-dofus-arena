
#include "classe.h"
#include "Sorts.h"
void initialiserClasses(Classe *classe){

    //Nom
    strcpy(classe[0].nom, "L'ombre de Sram");
    strcpy(classe[1].nom, "Coeur d'Iop");
    strcpy(classe[2].nom, "Les mains d'Eniripsa");
    strcpy(classe[3].nom, "La rune d'huppermage");

    //Dipsoniblilité classe
    classe[0].dispo = true;
    classe[1].dispo = true;
    classe[2].dispo = true;
    classe[3].dispo = true;

    //Skin
    classe[0].skin = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum1.png");
    classe[1].skin = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    classe[2].skin = al_load_bitmap("../Image/Classes/eniripsa/eniripsa1.png");
    classe[3].skin = al_load_bitmap("../Image/Classes/huppermage/hup1.png");
    //PA par classe
    classe[0].PaTotal = 6;// reinitialiser à chaque tour
    classe[1].PaTotal = 6;
    classe[2].PaTotal = 6;
    classe[3].PaTotal = 6;
    // Pv de départ par classe
    classe[0].PvDepart = 48;// même pendant toute la partie
    classe[1].PvDepart = 50;
    classe[2].PvDepart = 40;
    classe[3].PvDepart = 42;


}

void initialiserSorts(Classe classe[]){
    srand(time(NULL));
    //Initialisation Classe 1
    ////////* Sorts 1*/////////////
    classe[0].sorts[0].numSort = 1;
    classe[0].sorts[0].nombrePA = 5;

    classe[0].sorts[0].nombrePVinflige = rand() % (5) + 18;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 18 et MAX = 22
    classe[0].sorts[0].image = al_load_bitmap("../Image/Sorts/Bdf1.jpg");// boule de feux
    // boucle for
    classe[0].sorts[0].porteeMax = 7;
    classe[0].sorts[0].porteeMin = 4;

    ////////* Sorts 2*/////////////
    classe[0].sorts[1].numSort = 2;
    classe[0].sorts[1].nombrePA = 2;
    classe[0].sorts[1].nombrePVinflige = rand() % (5) + 10;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 10 et MAX = 14
    classe[0].sorts[1].image = al_load_bitmap("../Image/Sorts/trainéefeu1.png");// trainée de feux
    //classe[0].sorts[1].porteeX = ;
    //classe[0].sorts[1].porteeY = ;

    ////////* Sorts 3*/////////////
    classe[0].sorts[2].numSort = 3;
    classe[0].sorts[2].nombrePA = 6;
    classe[0].sorts[2].nombrePVinflige = rand() %(5) + 22;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 22 et MAX = 26
    classe[0].sorts[2].image = al_load_bitmap("../Image/Sorts/traine glace.jpg.png");// pic de glace
    //classe[0].sorts[2].porteeX = 3;
    //classe[0].sorts[2].porteeY = 2;
    ////////* Sorts 4*/////////////
    classe[0].sorts[3].numSort = 4;
    classe[0].sorts[3].nombrePA = 3;
    classe[0].sorts[3].nombrePVinflige = rand() %(5) + 14;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 14 et MAX = 18
    classe[0].sorts[3].image = al_load_bitmap("../Image/Sorts/foudre2.png");//foudre
    //classe[0].sorts[3].porteeX = ;
    //classe[0].sorts[3].porteeY = ;


    //Initialisation Classe 2
    ////////* Sorts 1*/////////////
    classe[1].sorts[0].numSort = 1;
    classe[1].sorts[0].nombrePA = 4;
    classe[1].sorts[0].nombrePVinflige = rand() % (5) + 15;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 15 et MAX = 19
    classe[1].sorts[0].image = al_load_bitmap("../Image/Sorts/epeefeux-removebg-preview.png");//épée enflammée
    //classe[1].sorts[0].porteeX = ;
    //classe[1].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[1].sorts[1].numSort = 2;
    classe[1].sorts[1].nombrePA = 3;
    classe[1].sorts[1].nombrePVinflige = rand() % (5) + 8;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 8 et MAX = 12
    classe[1].sorts[1].image = al_load_bitmap("../Image/Sorts/Sprite boule de neige.png");//Boule de neige
    //classe[1].sorts[1].porteeX = ;
    //classe[1].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[1].sorts[2].numSort = 3;
    classe[1].sorts[2].nombrePA = 2;
    classe[1].sorts[2].nombrePVinflige = rand() % (5) + 13;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 13 et MAX = 17
    classe[1].sorts[2].image = al_load_bitmap("../Image/Sorts/Aigle-removebg-preview.png");// dans les autres sens aussi pour qu'il soit dans la bonne direction
    //classe[1].sorts[2].porteeX = ;
    //classe[1].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[1].sorts[3].numSort = 4;
    classe[1].sorts[3].nombrePA = 3;
    classe[1].sorts[3].nombrePVinflige = rand() % (5) + 15;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 15 et MAX = 19
    classe[1].sorts[3].image = al_load_bitmap("../Image/Sorts/Explosion_feux.png");//pas encore découper mais on peut faire de plusieurs tailles
    //classe[1].sorts[3].porteeX = ;
    //classe[1].sorts[3].porteeY = ;

    //Initialisation Classe 3
    ////////* Sorts 1*/////////////
    classe[2].sorts[0].numSort = 1;
    classe[2].sorts[0].nombrePA = 4;
    classe[2].sorts[0].nombrePVinflige = rand() % (5) + 18;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 18 et MAX = 22
    classe[2].sorts[0].image = al_load_bitmap("../Image/Sorts/Neon1.png");//néon en forme d'anneau
    //classe[2].sorts[0].porteeX = ;
    //classe[2].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[2].sorts[1].numSort = 2;
    classe[2].sorts[1].nombrePA = 5;
    classe[2].sorts[1].nombrePVinflige = rand() % (5) + 22;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 22 et MAX = 26
    classe[2].sorts[1].image = al_load_bitmap("../Image/Sorts/Boomerang1.png");// Boomerang en feux
    //classe[2].sorts[1].porteeX = ;
    //classe[2].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[2].sorts[2].numSort = 3;
    classe[2].sorts[2].nombrePA = 3;
    classe[2].sorts[2].nombrePVinflige = rand() % (5) + 16;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 16 et MAX = 20
    classe[2].sorts[2].image = al_load_bitmap("../Image/Sorts/gaz_vert-removebg-preview(1).png");// Gaz vert enfumé
    //classe[2].sorts[2].porteeX = ;
    //classe[2].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[2].sorts[3].numSort = 4;
    classe[2].sorts[3].nombrePA = 4;
    classe[2].sorts[3].nombrePVinflige = rand() % (5) + 18;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 18 et MAX = 22
    classe[2].sorts[3].image = al_load_bitmap("../Image/Sorts/EtoileRouge1.jpg");// Etoile rouge
    //classe[2].sorts[3].porteeX = ;
    //classe[2].sorts[3].porteeY = ;

    //Initialisation Classe 4
    ////////* Sorts 1*/////////////
    classe[3].sorts[0].numSort = 1;
    classe[3].sorts[0].nombrePA = 2;
    classe[3].sorts[0].nombrePVinflige = 0; // rajouter des PV au persos lorsqu'il utilise ce sort
    classe[3].sorts[0].image = al_load_bitmap("../Image/Sorts/guerisson1.jpg");//sorts de guérrison
    //classe[3].sorts[0].porteeX = ;
    //classe[3].sorts[0].porteeY = ;
    ////////* Sorts 2*/////////////
    classe[3].sorts[1].numSort = 2;
    classe[3].sorts[1].nombrePA = 3;
    classe[3].sorts[1].nombrePVinflige = rand() % (5) + 16;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 16 et MAX = 20
    classe[3].sorts[1].image = al_load_bitmap("../Image/Sorts/Cylindre.png");// Cylindre en feux
    //classe[3].sorts[1].porteeX = ;
    //classe[3].sorts[1].porteeY = ;
    ////////* Sorts 3*/////////////
    classe[3].sorts[2].numSort = 3;
    classe[3].sorts[2].nombrePA = 3;
    classe[3].sorts[2].nombrePVinflige = rand() % (5) + 15;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 15 et MAX = 19
    classe[3].sorts[2].image = al_load_bitmap("../Image/Sorts/vague2.png");// Vague d'eau ___ Voir si lorsqu'on les mets avec un timer rend bien
    //classe[3].sorts[2].porteeX = ;
    //classe[3].sorts[2].porteeY = ;
    ////////* Sorts 4*/////////////
    classe[3].sorts[3].numSort = 4;
    classe[3].sorts[3].nombrePA = 4;
    classe[3].sorts[3].nombrePVinflige = rand() % (5) + 20;// rand() % ((MAX - MIN)+1) + MIN avec MIN= 20 et MAX = 24
    classe[3].sorts[3].image = al_load_bitmap("../Image/Sorts/fleche violet1.jpg"); // flèche violette
    //classe[3].sorts[3].porteeX = ;
    //classe[3].sorts[3].porteeY = ;

}