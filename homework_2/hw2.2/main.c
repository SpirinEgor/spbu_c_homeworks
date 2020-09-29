#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateNum(int* secretNum, int n)
{
    srand((unsigned int)time(NULL));

    const int numOfNumerals = 10;
    bool usedNumerals[numOfNumerals];
    memset(usedNumerals, false, numOfNumerals * sizeof(bool));

    secretNum[0] = rand() % 9 + 1;
    usedNumerals[secretNum[0]] = true;

    for (int i = 1; i < n; ++i) {
        secretNum[i] = rand() % (10 - i);
        int j = 0;
        while (j <= secretNum[i]) {
            if (usedNumerals[j]) {
                ++secretNum[i];
            }
            ++j;
        }
        usedNumerals[secretNum[i]] = true;
    }
}

void getPlayerNum(int* playerNum, int n)
{
    char* number = (char*)calloc(n, sizeof(char));
    scanf("%s", number);
    for (int i = 0; i < n; ++i) {
        playerNum[i] = number[i] - '0';
    }
    free(number);
}

bool countBullsAndCows(int* playerNum, int* secretNum, const int n)
{
    int cowsCounter = 0;
    int bullsCounter = 0;
    const int numOfNumerals = 10;

    bool* areChecked = malloc(numOfNumerals * sizeof(bool));
    memset(areChecked, false, numOfNumerals * sizeof(bool));

    for (int i = 0; i < n; ++i) {
        areChecked[secretNum[i]] = true;
    }

    for (int i = 0; i < n; ++i) {
        if (playerNum[i] == secretNum[i]) {
            bullsCounter++;
        } else if (areChecked[playerNum[i]]) {
            cowsCounter++;
        }
    }
    printf("Number of cows : %d\n", cowsCounter);
    printf("Number of bulls : %d\n", bullsCounter);

    free(areChecked);
    return (bullsCounter == n);
}

int main()
{
    int n = 0;
    const int maxNumberOfDigits = 10;
    const int minNumberOfDigits = 4;
    printf("Enter amount of digits in secret number(from %d to %d):\n", minNumberOfDigits, maxNumberOfDigits);
    do {
        scanf("%d", &n);
    } while (n < minNumberOfDigits || n > maxNumberOfDigits);
    int* secretNum = (int*)calloc(n, sizeof(int));

    generateNum(secretNum, n);

    bool isFinished = false;
    int* playerNum = (int*)calloc(n, sizeof(int));
    while (!isFinished) {
        printf("Enter a number :\n");
        getPlayerNum(playerNum, n);
        isFinished = countBullsAndCows(playerNum, secretNum, n);
    }
    printf("Congratulations! You won!");
    free(secretNum);
    free(playerNum);
}
