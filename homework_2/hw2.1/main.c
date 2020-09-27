#include <malloc.h>
#include <stdio.h>

void showPartitions(int* parts, int remainder, int previous)
{
    if (remainder == 0) {
        for (int i = 1; i <= previous; ++i) {
            printf("%d", parts[i]);
            if (i != previous)
                printf(" + ");
        }
        printf("\n");
        return;
    }

    for (int i = parts[previous]; i <= remainder; ++i) {
        parts[previous + 1] = i;
        showPartitions(parts, remainder - i, previous + 1);
    }
}

int main()
{
    int n = 0;
    printf("Enter the number :\n");
    scanf("%d", &n);

    int* parts = (int*)calloc(n + 1, sizeof(int));
    parts[0] = 1;

    printf("The entered number can be represented as :\n");
    showPartitions(parts, n, 0);

    free(parts);
}
