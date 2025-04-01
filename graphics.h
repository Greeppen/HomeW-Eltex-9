#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "functional.h"

void win_init(WINDOW **win_left, WINDOW **win_right);
void win_edit(FileManager *fm, WINDOW *win_left, WINDOW *win_right);

#endif
