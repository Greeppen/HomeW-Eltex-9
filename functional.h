#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME 256
#define MAX_FILES 256
#define MAX_PATH 1024

typedef struct{
    char name[MAX_FILENAME];
    int is_dir;
} FileEntry;
typedef struct{
    char current_path_left[MAX_PATH];
    char current_path_right[MAX_PATH];
    FileEntry files_left[MAX_FILES];
    FileEntry files_right[MAX_FILES];
    int selected_left;
    int selected_right;
    int file_count_left;
    int file_count_right;
    bool active_panel;
} FileManager;

void list_directory(FileManager *fm, bool is_left);
void change_directory(FileManager *fm,const char *new_dir, bool is_left);

#endif
