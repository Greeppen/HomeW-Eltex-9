#include "graphics.h"
#include "functional.h"

int main(){
    FileManager fm;
    WINDOW *win_left,*win_right;
    getcwd(fm.current_path_left,sizeof(fm.current_path_left));
    getcwd(fm.current_path_right,sizeof(fm.current_path_right));
    fm.active_panel = true;
    fm.selected_left = 0;
    fm.selected_right = 0;

    win_init(&win_left,&win_right);
    list_directory(&fm, true);
    list_directory(&fm, false);
    
    int ch;
    while ((ch = getch())!=27){
        switch(ch){
            case(9):
                if (fm.active_panel == true){
                    fm.active_panel = false;
                }
                else{
                    fm.active_panel = true;
                }
                break;
            case KEY_UP:
                if (fm.active_panel && fm.selected_left > 0) fm.selected_left--;
                if (!fm.active_panel && fm.selected_right > 0) fm.selected_right--;
                break;
            case KEY_DOWN:
                if (fm.active_panel && fm.selected_left < fm.file_count_left - 1) fm.selected_left++;
                if (!fm.active_panel && fm.selected_right < fm.file_count_right - 1) fm.selected_right++;
                break;
            case(10):
                if (fm.active_panel == true){
                    if (fm.files_left[fm.selected_left].is_dir){
                        change_directory(&fm, fm.files_left[fm.selected_left].name, true);
                    }
                }
                else{
                    if (fm.files_right[fm.selected_right].is_dir){
                        change_directory(&fm, fm.files_right[fm.selected_right].name, false);
                    }
                }
                break;
        }
        win_edit(&fm, win_left, win_right);
    }
    endwin();
    return 0;
}
