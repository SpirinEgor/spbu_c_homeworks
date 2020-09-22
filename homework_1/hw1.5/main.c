#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void siftUp(int* numbers, int position)
{
    while (position != 0 && numbers[position] > numbers[(position - 1) / 2]) {
        swap(&numbers[position], &numbers[(position - 1) / 2]);
        position = (position - 1) / 2;
    }
}

void siftDown(int* numbers, int n, int position)
{
    int next = position * 2 + 1;
    bool isHeap = false;
    while (next < n && !isHeap) {
        if (next + 1 < n && numbers[next] < numbers[next + 1])
            next++;

        if (numbers[next] > numbers[position]) {
            swap(&numbers[next], &numbers[position]);
            position = next;
            next = position * 2 + 1;
        } else {
            isHeap = true;
        }
    }
}

void buildHeap(int* numbers, int n)
{
    for (int i = n / 2; i >= 0; --i) {
        siftDown(numbers, n, i);
    }
}

int findSeveralMax(int* numbers, int n, bool* isFound)
{
    buildHeap(numbers, n);

    *isFound = false;
    int i = 0;
    int severalMax = 0;
    while (i < n - 1 && !(*isFound)) {
        swap(&numbers[n - 1 - i], &numbers[0]);
        siftDown(numbers, n - i - 1, 0);
        if (numbers[0] == numbers[n - i - 1]) {
            *isFound = true;
            severalMax = numbers[0];
        }
        ++i;
    }

    if (*isFound) {
        return severalMax;
    } else {
        return -1;
    }
}

int main()
{
    int n = 0;
    printf("Enter the length of array :\n");
    scanf("%d", &n);

    int* numbers = (int*)malloc(n * sizeof(int));
    printf("Enter the array :\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }

    bool isFound = false;
    int severalMax = findSeveralMax(numbers, n, &isFound);

    if (isFound) {
        printf("The maximum that is contained more than once is : %d", severalMax);
    } else {
        printf("The maximum that is contained more than once is not found");
    }

    free(numbers);
}
