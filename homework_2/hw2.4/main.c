#include "../../library/commonUtils/mysorts.h"
#include <stdio.h>
#include <stdlib.h>

void showNumerals(int* numerals, int n)
{
    int i = 0;
    while (numerals[i] == 0) {
        ++i;
    }
    int firstNumeral = i;
    printf("%d", numerals[firstNumeral]);

    i = 0;
    while (i < n) {
        if (i != firstNumeral) {
            printf("%d", numerals[i]);
        }
        ++i;
    }
}

void inputNumerals(int* numerals, int n)
{
    int number = 0;
    scanf("%d", &number);
    for (int i = n - 1; i >= 0; --i) {
        numerals[i] = number % 10;
        number /= 10;
    }
}

int main()
{
    int n = 0;
    printf("Enter the length of number :\n");
    scanf("%d", &n);

    printf("Enter the number :\n");
    int* numerals = calloc(n, sizeof(int));

    inputNumerals(numerals, n);
    countingSort(numerals, n, 0, 9);
    showNumerals(numerals, n);

    free(numerals);
    return 0;
}
