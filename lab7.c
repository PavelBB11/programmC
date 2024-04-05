#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct human {
    char name[50];
    char surname[50];
    int birth;
};

int comparebirth(const void *a, const void *b) {
    return ((struct human*)a)->birth - ((struct human*)b)->birth;
}

int main() {
    struct human array1[4];
    struct human array2[4];

    for (int i = 0; i < 4; i++) {
        printf("Введите имя, фамилию и год рождения %d-го человека: ", i+1);
        scanf("%s %s %d", array1[i].name, array1[i].surname, &array1[i].birth);
    }

    memcpy(array2, array1, sizeof(array1));
    qsort(array2, 4, sizeof(struct human), comparebirth);

    printf("Элементы второго массива, упорядоченные по годам рождения:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s %s %d\n", array2[i].name, array2[i].surname, array2[i].birth);
    }

    return 0;
}
