#include "../../library/commonUtils/numericOperations.h"
#include "malloc.h"
#include "stdio.h"

void nullsToEnd(int* numbers, int n)
{
    for (int i = n - 1; i > 0; --i) { //bubblesort-like
        for (int j = 0; j < i; ++j) {
            if (numbers[j] == 0 && numbers[j + 1] != 0)
                swap(&numbers[j], &numbers[j + 1]);
        }
    }
}

int main()
{
    int n = 0;
    printf("Enter size of the array:\n");
    scanf("%d", &n);

    int* numbers = (int*)calloc(n, sizeof(int));
    printf("Enter the array:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }

    nullsToEnd(numbers, n);

    printf("Entered array with moved nulls:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", numbers[i]);
}