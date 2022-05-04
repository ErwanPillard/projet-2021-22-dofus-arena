//
// Created by 33782 on 04/05/2022.
//

#include "classe.h"

Classe initialisationClasses(Classe classe[]){
    classe[0].fondEcran = al_load_bitmap("../Image/ombresram.jpg");

}

void dessinerInterfaceClasses(Classe c[]){
    al_clear_to_color(NOIR);
    al_draw_scaled_bitmap(c[0].fondEcran, 0, 0, 1200, 675, 0, 0, 1400, 807, 0);

    al_flip_display();
}