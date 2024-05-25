#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int birthYear;
    char gender;
    float height;
} Person;

int compareByBirthYear(const void* a, const void* b) {
    const Person* personA = (const Person*)a;
    const Person* personB = (const Person*)b;
    return personA->birthYear - personB->birthYear;
}

int compareByName(const void* a, const void* b) {
    const Person* personA = (const Person*)a;
    const Person* personB = (const Person*)b;
    return strcmp(personA->name, personB->name);
}

int compareByGender(const void* a, const void* b) {
    const Person* personA = (const Person*)a;
    const Person* personB = (const Person*)b;
    return personA->gender - personB->gender;
}

int compareByHeight(const void* a, const void* b) {
    const Person* personA = (const Person*)a;
    const Person* personB = (const Person*)b;
    return personA->height - personB->height;
}

int main() {
    FILE* file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    Person people[100];
    int numPeople = 0;

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %d %c %f", people[numPeople].name, &people[numPeople].birthYear, &people[numPeople].gender, &people[numPeople].height);
        numPeople++;
    }

    fclose(file);

    int sortByBirthYear = 0;
    int sortByName = 0;
    int sortByGender = 0;
    int sortByHeight = 0;

    printf("Enter sorting parameters (1 - sort, 0 - do not sort):\n");
    printf("Sort by birth year: ");
    scanf("%d", &sortByBirthYear);
    printf("Sort by name: ");
    scanf("%d", &sortByName);
    printf("Sort by gender: ");
    scanf("%d", &sortByGender);
    printf("Sort by height: ");
    scanf("%d", &sortByHeight);

    if (sortByBirthYear) {
        qsort(people, numPeople, sizeof(Person), compareByBirthYear);
    }
    if (sortByName) {
        qsort(people, numPeople, sizeof(Person), compareByName);
    }
    if (sortByGender) {
        qsort(people, numPeople, sizeof(Person), compareByGender);
    }
    if (sortByHeight) {
        qsort(people, numPeople, sizeof(Person), compareByHeight);
    }

    printf("Sorting result:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s %d %c %.2f\n", people[i].name, people[i].birthYear, people[i].gender, people[i].height);
    }

    return 0;
}
