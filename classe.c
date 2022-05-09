
#include "classe.h"

void initialiserClasses(Classe *classe){

    //Nom
    classe[0].nom = "L'ombre de Sram";
    classe[1].nom = "Coeur d'Iop";
    classe[2].nom = "Les mains d'Eniripsa";

    //Skin
    classe[0].skin = al_load_bitmap("../Image/Classes/OmbreSrum/ombresrum1.png");
    classe[1].skin = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    classe[2].skin = al_load_bitmap("../Image/Classes/eniripsa/eniripsa1.png");


    //Sorts


}