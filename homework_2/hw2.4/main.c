#include "../../library/commonUtils/mysorts.h"
#include "malloc.h"
#include <stdio.h>

void showNumerals(int* numerals, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d", numerals[i]);
}

void inputNumerals(int* numerals, int n)
{
    char tmp = 0;
    for (int i = 0; i < n; ++i) {
        tmp = getchar();
        numerals[i] = tmp - '0';
    }
}

int main()
{
    int n = 0;
    printf("Enter the length of number :\n");
    scanf("%d", &n);

    char tmp = 0;
    printf("Enter the number :\n");
    int* numerals = calloc(n, sizeof(int));

    tmp = getchar();
    inputNumerals(numerals, n);
    countingSort(numerals, n, 0, 9);
    showNumerals(numerals, n);

    free(numerals);
}
