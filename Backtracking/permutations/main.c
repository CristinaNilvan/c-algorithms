#include <stdio.h>
#include <stdlib.h>

void printVector(int number, int * result)
{
    for (int i = 0; i <= number; ++i)
        printf("%d ", result[i]);
}

int condition(const int * result, int current)
{
    for (int i = 0; i < current; ++i)
        if (result[i] == result[current])
            return 0;

    return 1;
}

void permutations(int number, int current, int * result)
{
    for (int i = 1; i <= number; ++i)
    {
        result[current] = i;

        printVector(current, result);

        if (condition(result, current) && (current == number - 1))
            printf(" -- Solution");

        printf("\n");

        if (condition(result, current) && (current < number - 1))
            permutations(number, current + 1, result);
    }
}

void testsPermutation()
{
    int number;
    printf("Give a number :");
    scanf("%d", &number);

    int * result = (int *)malloc(number * sizeof(int));

    permutations(number, 0, result);

    free(result);
}

int main()
{
    testsPermutation();

    return 0;
}

