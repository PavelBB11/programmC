#include <stdio.h>
#include <ctype.h>

int main() {
    char str[81];

    printf("Введите строку символов: ");
    scanf("%80[^\n]", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'b') {
            str[i] = toupper(str[i]);
        }
    }

    printf("Полученная строкa: %s\n", str);

    return 0;
}
