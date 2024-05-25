#include <stdio.h>
#include <time.h>

void calculateDayOfWeek(int year, int month, int day) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;

    mktime(&timeinfo);

    char* weekdays[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
    printf("Дата: %04d.%02d.%02d - День недели: %s\n", year, month, day, weekdays[timeinfo.tm_wday]);
}

void printCalendarForMonth(int year, int month) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = 1;

    mktime(&timeinfo);

    printf("Календарь на %04d.%02d:\n", year, month);

    int daysInMonth = 31; // Максимальное количество дней в месяце
    for (int day = 1; day <= daysInMonth; day++) {
        timeinfo.tm_mday = day;
        mktime(&timeinfo);
        if (timeinfo.tm_mon + 1 != month) {
            daysInMonth = day - 1;
            break;
        }
    }

    printf("Пн Вт Ср Чт Пт Сб Вс\n");
    for (int i = 0; i < timeinfo.tm_wday; i++) {
        printf("   ");
    }
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%2d ", day);
        if ((timeinfo.tm_wday + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void printCalendarForYear(int year) {
    for (int month = 1; month <= 12; month++) {
        printCalendarForMonth(year, month);
        printf("\n");
    }
}

int main() {
    time_t now;
    struct tm *local;
    now = time(NULL);
    local = localtime(&now);

    char userInput[10];
    int year, month, day;

    printf("Введите дату в формате (гггг.мм.дд, гггг.мм, гггг, now): ");
    scanf("%s", userInput);

    if (strcmp(userInput, "now") == 0) {
        printf("Текущая дата: %04d.%02d.%02d\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday);
    } else if (sscanf(userInput, "%d.%d.%d", &year, &month, &day) == 3) {
        calculateDayOfWeek(year, month, day);
    } else if (sscanf(userInput, "%d.%d", &year, &month) == 2) {
        printCalendarForMonth(year, month);
    } else if (sscanf(userInput, "%d", &year) == 1) {
        printCalendarForYear(year);
    } else {
        printf("Неверный формат ввода.\n");
    }

    return 0;
}
