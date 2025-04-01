#include "functional.h"

void list_directory(FileManager *fm, bool is_left){
    const char *path = is_left ? fm->current_path_left : fm->current_path_right;
    FileEntry *files = is_left ? fm->files_left : fm->files_right;
    int *count = is_left ? &fm->file_count_left : &fm->file_count_right;
    *count=0;
    DIR *dir = opendir(path);
    if (!dir) return;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (*count < MAX_FILES) {
            snprintf(files[*count].name,MAX_FILENAME,"%s", entry->d_name);
            files[*count].is_dir = (entry->d_type == DT_DIR);
            (*count)++;
        }
    }
    closedir(dir);
}

void change_directory(FileManager *fm, const char *new_dir, bool is_left) {
    char *path = is_left ? fm->current_path_left : fm->current_path_right;
    char temp_path[MAX_PATH+MAX_FILENAME];
    snprintf(temp_path, sizeof(temp_path), "%s/%s", path, new_dir);
    if (chdir(temp_path) == 0) {
        getcwd(path, MAX_PATH);
        if (is_left){
            fm->selected_left = 0;
        }
        else{
            fm->selected_right = 0;
        }
        list_directory(fm,is_left);
    }
}
