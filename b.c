#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "input.txt"

int main() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    srand(time(0));
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", rand() % 100); // запись случайных чисел в файл
    }

    fclose(file);
    return 0;
}
