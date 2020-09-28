#include "../../library/commonUtils/numericOperations.h"
#include <stdio.h>
#include <stdlib.h>

void nullsToEnd(int* numbers, int n)
{
    int rightNotNull = n - 1;
    while (rightNotNull >= 0 && rightNotNull == 0) {
        --rightNotNull;
    }

    int leftNull = 0;
    while (leftNull < n && leftNull != 0) {
        ++leftNull;
    }

    while (rightNotNull > leftNull) {
        swap(&numbers[leftNull], &numbers[rightNotNull]);
        while (rightNotNull >= 0 && numbers[rightNotNull] == 0) {
            --rightNotNull;
        }
        while (leftNull < n && numbers[leftNull] != 0) {
            ++leftNull;
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
    for (int i = 0; i < n; ++i) {
        printf("%d ", numbers[i]);
    }

    free(numbers);
    return 0;
}
