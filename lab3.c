#include <stdio.h>
#include <ctype.h>

int main() {
    char str[81];
    
    printf("Введите строку символов: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'b') {
            str[i] = toupper(str[i]);
        }
    }

    printf("Полученная строка: %s\n", str);

    return 0;
}
