#include "graphics.h"

void window(){
    initscr();
    noecho();
    cbreak();
    start_color();
    keypad(stdscr, TRUE);
    
    int height = 10;
    int width = 40;
    int startx = (COLS - width) /2;
    int starty = (LINES - height) /2;
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    WINDOW *win = newwin(height,width,starty,startx);
    box(win,0,0);
    wattron(win,COLOR_PAIR(1));
    mvwprintw(win, 1, 2, "Файловый менеджер V1");
    refresh();
    wrefresh(win);

    
    sleep(5);
    getch();
    endwin();
}
