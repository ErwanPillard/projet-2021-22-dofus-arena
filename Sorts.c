#include <unistd.h>
#include "Sorts.h"

// faire un switch case pour les rands
// faire une fonctionne Initialisation Corps à corps -> pas de rapport avec les classes, indépendantes


void bouleDeFeux(){//mettre dans la fonction timer en répétant la fonction en faisant avancer le x=x+30
    //Classe * classe;
    int x = 10;
    int y = 50;
    ALLEGRO_BITMAP *ima1 = al_load_bitmap("../Image/Sorts/Bdf1.jpg");
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap( classe[0].sorts[0].image[1],x,y,0);
    al_draw_bitmap(ima1, 0, 0, 0);
    al_flip_display();
}


void traineeFeux(){
    int x = 10;
    int y = 50;

    //ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/Sorts/traineeDeFeu1.png");
    //ALLEGRO_BITMAP *img2 = al_load_bitmap("../Image/Sorts/traineeDeFeu2.png");
    ALLEGRO_BITMAP *img3 = al_load_bitmap("../Image/Sorts/traineeDeFeu3.png");
    //ALLEGRO_BITMAP *img4 = al_load_bitmap("../Image/Sorts/traineeDeFeu4.png");
    //ALLEGRO_BITMAP *img5 = al_load_bitmap("../Image/Sorts/traineeDeFeu5.png");

    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    y=y+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    al_flip_display();
    sleep(1);
}

void didacticiel(){
    int x = 10;
    int y = 250;
    ALLEGRO_BITMAP *imgIop = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    ALLEGRO_BITMAP *boule = al_load_bitmap("../Image/bouleFeu.png");
    ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/1.png");
    ALLEGRO_BITMAP *img2 = al_load_bitmap("../Image/D2.png");
    ALLEGRO_BITMAP *img3 = al_load_bitmap("../Image/D3.png");
    ALLEGRO_BITMAP *img4 = al_load_bitmap("../Image/D4.png");
    ALLEGRO_BITMAP *img5 = al_load_bitmap("../Image/D5.png");
    ALLEGRO_BITMAP *img6 = al_load_bitmap("../Image/D6.png");
    ALLEGRO_BITMAP *img7 = al_load_bitmap("../Image/D7.png");
    ALLEGRO_BITMAP *imgsors = al_load_bitmap("../Image/Classes/CoeurIop/IopPos6.png");
    al_draw_bitmap(img1, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img2, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img3, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img4, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img5, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img6, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_draw_bitmap(img7, 0, 0, 0);
    al_flip_display();
    sleep(3);
    al_clear_to_color(NOIR);
}

void courrirIop(){
    int x = 10;
    int y = 250;
    ALLEGRO_BITMAP *img1 = al_load_bitmap("../Image/Classes/CoeurIop/IOP1.png");
    ALLEGRO_BITMAP *img2 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos2.png");
    ALLEGRO_BITMAP *img3 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos3.png");
    ALLEGRO_BITMAP *img4 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos4.png");
    ALLEGRO_BITMAP *img5 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos5.png");
    ALLEGRO_BITMAP *img6 = al_load_bitmap("../Image/Classes/CoeurIop/IopPos6.png");
    al_draw_bitmap(img1, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(2);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img2, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);
    x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img4, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img5, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    //al_draw_bitmap(img1, x, y, 0);x=x+30;
    // al_flip_display();
    // sleep(1);
    //al_clear_to_color(NOIR);
    al_draw_bitmap(img2, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img3, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img4, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img5, x, y, 0);x=x+30;
    al_flip_display();
    sleep(1);
    al_clear_to_color(NOIR);
    al_draw_bitmap(img6, x+30, y, 0);x=x+30;
    al_flip_display();
    sleep(1);

}

void dessinerSortsGlace(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event){
    ALLEGRO_TIMER *timer2 = NULL;
    int i = 0;
    bool end = false;

    ALLEGRO_BITMAP *sortGlace= al_load_bitmap("../Image/sortGlace.png");

    timer2 = al_create_timer(1.0/60);

    al_register_event_source(queue, al_get_timer_event_source(timer2));

    al_start_timer(timer2);


    while (!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_TIMER: {
                al_clear_to_color(al_map_rgb(255, 255, 255));

                al_draw_bitmap(sortGlace, 300, i, 0);

                i = i + 5;

                al_flip_display();
                break;
            }
        }
    }
}

void dessinerSorts2(ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event){
    ALLEGRO_TIMER *timer2 = NULL;
    int i = 0;
    bool end = false;

    ALLEGRO_BITMAP *sort0= al_load_bitmap("../Image/test.png");
    ALLEGRO_BITMAP *sort1= al_load_bitmap("../Image/test2.png");
    ALLEGRO_BITMAP *sort2= al_load_bitmap("../Image/test3.png");
    ALLEGRO_BITMAP *sort3= al_load_bitmap("../Image/test4.png");
    ALLEGRO_BITMAP *sort4= al_load_bitmap("../Image/test5.png");
    ALLEGRO_BITMAP *sort5= al_load_bitmap("../Image/test6.png");

    timer2 = al_create_timer(1.0/10);

    al_register_event_source(queue, al_get_timer_event_source(timer2));

    al_start_timer(timer2);


    while (!end){
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_TIMER: {
                al_clear_to_color(al_map_rgb(0, 0, 0));

                if(i==0){
                    al_draw_bitmap(sort0, 300, 300, 0);

                }
                if(i==1){
                    al_draw_bitmap(sort1, 300, 300, 0);

                }
                if(i==2){
                    al_draw_bitmap(sort2, 300, 300, 0);

                }
                if(i==3){
                    al_draw_bitmap(sort3, 300, 300, 0);

                }
                if(i==4){
                    al_draw_bitmap(sort4, 300, 300, 0);

                }
                if(i==5){
                    al_draw_bitmap(sort5, 300, 300, 0);

                }
                if(i==6){
                    al_draw_bitmap(sort0, 300, 300, 0);

                }
                if(i==7){
                    al_draw_bitmap(sort1, 300, 300, 0);

                }
                if(i==8){
                    al_draw_bitmap(sort2, 300, 300, 0);

                }
                if(i==9){
                    al_draw_bitmap(sort3, 300, 300, 0);

                }
                if(i==10){
                    al_draw_bitmap(sort4, 300, 300, 0);

                }
                if(i==11){
                    al_draw_bitmap(sort5, 300, 300, 0);

                }
                al_flip_display();
                i++;

                break;
            }
        }
    }
}



