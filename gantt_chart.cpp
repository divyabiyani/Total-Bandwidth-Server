// g++ -Wall -lm engine.cpp -o engine `pkg-config --cflags --libs allegro-5.0 allegro_primitives-5.0`
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>
#include <cmath>

#define PI M_PI

class gantt {
public :
    void drawBoundary(int x1,int y1, int x2, int y2, int t) {
        al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0), t);
    }

    void drawRectangle(int x1,int y1, int x2, int y2,char POrA) {
        if(POrA=='A')
            al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(50, 50, 50));
        else
            al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(150, 150, 150));
        //printf("2\n");
        drawBoundary(x1, y1, x2, y2, 2);
    }
    
    void drawLine(int x1,int y1, int x2, int y2, int t,char SOrD) {
        if (SOrD=='S')
            al_draw_line(x1, y1, x2, y2, al_map_rgb(0, 0, 255), t);
        else if (SOrD=='D')
            al_draw_line(x1, y1, x2, y2, al_map_rgb(255, 0, 0), t);
        else
            al_draw_line(x1, y1, x2, y2, al_map_rgb(0, 0, 0), t);
    }

    void drawVerticalRoad(float x1,float y1) {
        drawLine(x1, y1-50, x1, y1, 5,'S');
    }

    void drawVerticalRoadDead(float x1,float y1) {
        drawLine(x1, y1-50, x1, y1, 5,'D');
    }

    void drawRoad(float y1) {
        drawLine(25, y1, 1500, y1, 5,'N');
    }
};

