#include <iostream>
#include "screen.h"

void screen_clear()
{
    std::cout << "\033[2J";
    std::cout << "\033[1;1H";
}

void screen_draw_board(const std::map<std::pair<int,int>,bool> &board)
{
    for (std::pair<const std::pair<int, int>, bool> element : board)
    {
        std::pair<int, int> coords = element.first;
        bool bdummy = element.second;
        int x = coords.first;
        int y = coords.second;

        std::cout << "\033["<<x << ";"<< y <<"H";
        std::cout << "*";

    }
}