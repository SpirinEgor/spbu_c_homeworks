#include "numericOperations.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int factorialRecursive(int x)
{
    if (x <= 1) {
        return 1;
    }
    return x * factorialRecursive(x - 1);
}

int factorialIterative(int x)
{
    int factorial = 1;
    for (int i = 2; i <= x; ++i) {
        factorial *= i;
    }
    return factorial;
}
