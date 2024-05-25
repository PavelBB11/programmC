#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signal) {
    switch (signal) {
        case SIGABRT:
            printf("Получен сигнал SIGABRT\n");
            break;
        case SIGFPE:
            printf("Получен сигнал SIGFPE\n");
            break;
        case SIGILL:
            printf("Получен сигнал SIGILL\n");
            break;
        case SIGINT:
            printf("Получен сигнал SIGINT\n");
            break;
        case SIGSEGV:
            printf("Получен сигнал SIGSEGV\n");
            break;
        case SIGTERM:
            printf("Получен сигнал SIGTERM\n");
            break;
        default:
            printf("Получен неизвестный сигнал\n");
            break;
    }
}

int main() {
    signal(SIGABRT, signalHandler);
    signal(SIGFPE, signalHandler);
    signal(SIGILL, signalHandler);
    signal(SIGINT, signalHandler);
    signal(SIGSEGV, signalHandler);
    signal(SIGTERM, signalHandler);

    char userInput[10];
    printf("Введите сигнал для генерации (SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM): ");
    scanf("%s", userInput);

    if (strcmp(userInput, "SIGABRT") == 0) {
        raise(SIGABRT);
    } else if (strcmp(userInput, "SIGFPE") == 0) {
        raise(SIGFPE);
    } else if (strcmp(userInput, "SIGILL") == 0) {
        raise(SIGILL);
    } else if (strcmp(userInput, "SIGINT") == 0) {
        raise(SIGINT);
    } else if (strcmp(userInput, "SIGSEGV") == 0) {
        raise(SIGSEGV);
    } else if (strcmp(userInput, "SIGTERM") == 0) {
        raise(SIGTERM);
    } else {
        printf("Неверный ввод для генерации сигнала\n");
    }

    return 0;
}
