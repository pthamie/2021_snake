#include <iostream>
#include <thread>
#include <chrono>
#include "snake.h"
#include "screen.h"
#include "board.h"


// Variables de contexte du board
std::map<std::pair<int,int>,bool> snake_board;

// Variables de contexte du snake
int snake_size = 5;
std::vector<snake_segment_st> snake_segments;

int main(int, char**) {
    std::cout << "Snake starting...\n";

    int x = 0,y = 0;

    while (true)
    {
        screen_clear();
        board_set_pixel(snake_board, x++, y++);
        screen_draw_board(snake_board);
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }
}
