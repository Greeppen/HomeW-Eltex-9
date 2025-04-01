#include "graphics.h"

void win_init(WINDOW **win_left, WINDOW **win_right){
    initscr();
    noecho();
    cbreak();
    start_color();
    keypad(stdscr, TRUE);
    curs_set(0);

    int width = (COLS - 4) / 2;
    int height = LINES - 2;
    
    *win_left = newwin(height,width,1,1);
    *win_right = newwin(height,width, 1, width + 2);

    init_pair(1,COLOR_CYAN,COLOR_MAGENTA);
    init_pair(2,COLOR_WHITE,COLOR_BLACK);
}

void win_edit(FileManager *fm, WINDOW *win_left, WINDOW *win_right){
    clear();


    wbkgd(win_left, COLOR_PAIR(fm->active_panel ? 1 : 2));
    box(win_left,0,0);
    for (int i = 0; i < fm->file_count_left; i++){
        if (i==fm->selected_left){
            wattron(win_left, A_REVERSE);
        }
        if (fm->file_count_left == 0){
            mvwprintw(win_left,1,2, "Empty directory! ");
        }
        mvwprintw(win_left,i+1,2,"%s%s",fm->files_left[i].name,fm->files_left[i].is_dir ? "/" : "");
        wattroff(win_left, A_REVERSE);
    }

    wbkgd(win_right, COLOR_PAIR(!fm->active_panel ? 1 : 2));
    box(win_right,0,0);
    for (int i = 0; i < fm->file_count_right; i++){
        if (i==fm->selected_right){
            wattron(win_right, A_REVERSE);
        }
        if (fm->file_count_right == 0){
            mvwprintw(win_right,1,2, "Empty directory! ");
        }
        mvwprintw(win_right,i+1,2,"%s%s",fm->files_right[i].name,fm->files_right[i].is_dir ? "/" : "");
        wattroff(win_right, A_REVERSE);
    }


    wrefresh(win_left);
    wrefresh(win_right);

    mvprintw(0,2,"L: %s", fm->current_path_left);
    mvprintw(0,(COLS /2) +2,"R: %s", fm->current_path_right);
    refresh();
}
