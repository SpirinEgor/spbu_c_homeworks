#include "arrayOperations.h"
#include <stdio.h>

void reverseArray(int* numbers, int first, int last)
{
    for (int i = 0; i <= (last - first) / 2; ++i) {
        swap(&numbers[first + i], &numbers[last - i]);
    }
}

void inputArray(int* numbers, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; ++i) {
        scanf("%d", &numbers[i]);
    }
}

void outputArray(int* numbers, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}
