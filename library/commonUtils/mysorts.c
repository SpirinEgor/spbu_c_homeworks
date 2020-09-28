#include "mysorts.h"
#include "malloc.h"

void countingSort(int* numbers, int n, int first, int last)
{
    int length = last - first + 1;
    int* counters = malloc(length * sizeof(int));
    for (int i = 0; i < length; ++i) {
        counters[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        ++counters[numbers[i] - first];
    }

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (counters[j] == 0) {
            ++j;
        }
        numbers[i] = first + j;
        counters[j]--;
    }
}
