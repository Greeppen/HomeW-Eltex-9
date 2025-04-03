#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 128

int main() {
    FILE *file = fopen("output.txt", "w+");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    fprintf(file, "String from file");
    fflush(file);

    rewind(file);

    char content[MAX_SIZE];
    size_t i = 0;
    int c;

    while ((c = fgetc(file)) != EOF && i < MAX_SIZE - 1) {
        content[i++] = (char)c;
    }
    content[i] = '\0';

    printf("Обратный порядок:\n");
    for (int j = (int)i - 1; j >= 0; j--) {
        putchar(content[j]);
    }
    putchar('\n');

    fclose(file);
    return 0;
}
