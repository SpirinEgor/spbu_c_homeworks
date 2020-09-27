#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateNum(int* secretNum, const int n)
{
    srand((unsigned int)time(NULL));

    const int numOfNumerals = 10;
    bool usedNumerals[numOfNumerals];
    for (int i = 0; i < numOfNumerals; ++i)
        usedNumerals[i] = false;

    secretNum[0] = rand() % 9 + 1;
    usedNumerals[secretNum[0]] = true;

    for (int i = 1; i < n; ++i) {
        secretNum[i] = rand() % (10 - i);
        int j = 0;
        while (j <= secretNum[i]) {
            if (usedNumerals[j])
                ++secretNum[i];
            ++j;
        }
        usedNumerals[secretNum[i]] = true;
    }
}

void getPlayerNum(int* playerNum, int n)
{
    char tmp = 0;
    for (int i = 0; i < n; ++i) {
        tmp = getchar();
        playerNum[i] = tmp - '0';
    }
    tmp = getchar();
}

bool countBullsAndCows(int* playerNum, int* secretNum, const int n)
{
    int cowsCounter = 0;
    int bullsCounter = 0;
    const int numOfNumerals = 10;

    bool* areChecked = malloc(numOfNumerals * sizeof(bool));
    for (int i = 0; i < numOfNumerals; ++i) {
        areChecked[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        areChecked[secretNum[i]] = true;
    }

    for (int i = 0; i < n; ++i) {
        if (playerNum[i] == secretNum[i]) {
            bullsCounter++;
        }
        if (areChecked[playerNum[i]]) {
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
    const int n = 4;
    int secretNum[n];

    generateNum(secretNum, n);

    bool isFinished = false;
    int playerNum[n];
    while (!isFinished) {
        printf("Enter a four-digit number :\n");
        getPlayerNum(playerNum, n);
        isFinished = countBullsAndCows(playerNum, secretNum, n);
    }
    printf("Congratulations! You won!");
}
