#include <iostream>
#include <thread>
#include <chrono>

#include "snake.h"
#include "screen.h"
#include "board.h"
#include "keyboard.h"

#define UP_ARROW    65
#define LEFT_ARROW  68
#define DOWN_ARROW  66
#define RIGHT_ARROW 67

// Variables de contexte du board
std::map<std::pair<int,int>,bool> snake_board;

// Variables de contexte du snake
int snake_size = 5;
std::vector<snake_segment_st> snake_segments;

int main(int, char**) {
    std::cout << "Snake starting...\n";

    keyboard_init();

    int x = 0,y = 0;

    while (true)
    {

        // Affichage de la scène

        screen_clear();
        board_clear(snake_board);
        board_set_pixel(snake_board, x, y);
        screen_draw_board(snake_board);

        // Simulation d'un déplacement automatique/calculé
        x++;
        if (x >= 10)
        {
          x= 1;
        }
        // Fin simulation


        // Lecture clavier et actions
        int key_scan = keyboard_scan();
        if (key_scan == UP_ARROW)
        {
            x--;
        }
        else if (key_scan == DOWN_ARROW)
        {
            x++;
        }
        else if (key_scan == LEFT_ARROW)
        {
            y--;
        }
        else if (key_scan == RIGHT_ARROW)
        {
            y++;
        }
        // Contrôle  des limites
        if (x < 0) x=0;
        if (y < 0) y=0;


        // Exemple d'attente si besoin était (attention, suspend entièrement l'application)
        //std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }

    keyboard_end();

}
