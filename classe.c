
#include "classe.h"

void initialiserClasses(Classe *classe){

    //Nom
    strcpy(classe[0].nom, "L'ombre de Sram");
    strcpy(classe[1].nom, "Coeur d'Iop");
    strcpy(classe[2].nom, "Les mains d'Eniripsa");
    strcpy(classe[3].nom, "La rune d'huppermage");

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

