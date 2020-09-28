#include "../../library/commonUtils/numericOperations.h"
#include "stdio.h"

int main()
{
    int x = 0;
    printf("Enter the number to calculate the factorial :\n");
    scanf("%d", &x);
    printf("The factorial by the recursive method : %d\n", factorialRecursive(x));
    printf("The factorial by the iterative method : %d\n", factorialIterative(x));
}
