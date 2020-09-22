#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

void inputString(char* myString, int length) {
    char tmp = 0;
    tmp = getchar();
    for (int i = 0; i < length; ++i) {
        tmp = getchar();
        myString[i] = tmp;
    }
}

int main() {
    int n = 0;
    printf("Enter the length of the string 's1' :\n");
    scanf("%d", &n);

    int m = 0;
    printf("Enter the length of the string 's2' :\n");
    scanf("%d", &m);

    char *s = (char*)malloc(n * sizeof(char));
    printf("Enter the string 's1' :\n");
    inputString(s, n);

    char *s1 = (char*)malloc(m * sizeof(char));
    printf("Enter the string 's2' :\n");
    inputString(s1, m);

    int substringCounter = 0;
    bool areEqual = true;
    int j = 0;
    for (int i = 0; i < (n - m + 1); ++i) {
        areEqual = true;
        j = 0;
        while (j < m && areEqual) {
            if (s[i + j] != s1[j])
                areEqual = false;
            ++j;
        }
        if (areEqual)
            ++substringCounter;
    }

    printf("The string 's2' is included in the string 's1' %d times", substringCounter);
    free(s);
    free(s1);
}