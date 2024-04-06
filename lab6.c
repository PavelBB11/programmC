#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char firstName[20], lastName[20], middleName[20];
    int year;

    inputFile = fopen("people.txt", "w");
    if (inputFile == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }
    fprintf(inputFile, "Иванов Петр Сергеевич 1975\n");
    fprintf(inputFile, "Сидоров Николай Андреевич 1981\n");
    fprintf(inputFile, "Воробьянинов Ипполит Матвеевич 1978\n");
    // ...
    fclose(inputFile);

    inputFile = fopen("people.txt", "r");
    outputFile = fopen("people_filtered.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка при открытии файлов.\n");
        return 1;
    }
    while (fscanf(inputFile, "%s %s %s %d", lastName, firstName, middleName, &year) != EOF) {
        if (year > 1980) {
            fprintf(outputFile, "%s %s %s %d\n", lastName, firstName, middleName, year);
        }
    }
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
