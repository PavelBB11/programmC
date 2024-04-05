#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
    char name[50];
    char surname[50];
    int birth;
    char gender;
    float height;
};

int comparePersons(const void *a, const void *b) {
    return (*(struct person*)a).birth - (*(struct person*)b).birth;
}

int main() {
    FILE *file;
    file = fopen("people.txt", "w");

    struct person people[5] = {{"Петр", "Васин", 2004, 'M', 1.75},
                               {"Василий", "Петин", 2005, 'M', 1.60},
                               {"Ипполит", "Воробьянинов", 1995, 'M', 1.80},
                               {"Мария", "Боброва", 1984, 'F', 1.95},
                               {"Алла", "Сидорова", 1988, 'F', 1.71}
        
    };

    for (int i = 0; i < 5; i++) {
        fprintf(file, "%s %s %d %c %.2f\n", people[i].name, people[i].surname, people[i].birth, people[i].gender, people[i].height);
    }
    fclose(file);

    int choice;
    printf("Выберите поле для упорядочивания (1 - год рождения, 2 - имя/фамилия, 3 - пол, 4 - рост): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            qsort(people, 5, sizeof(struct person), comparePersons);
            break;
    }

    printf("Результат упорядочивания:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s %s %d %c %.2f\n", people[i].name, people[i].surname, people[i].birth, people[i].gender, people[i].height);
    }

    return 0;
}
