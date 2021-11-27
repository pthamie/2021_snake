#pragma once
# include <vector>

struct snake_segment_st
{
    int dx = 0;
    int dy = 0;
    int size = 0;
    int x = 0;
    int y = 0;
};


// Fonctions du snake
void snake_init ();
