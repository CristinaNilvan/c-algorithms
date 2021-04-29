#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    int k;
} Combination;

void printVector(int number, int * result)
{
    for (int i = 1; i <= number; ++i)
        printf("%d ", result[i]);

    printf("\n");
}

int condition(const int * result, int current)
{
    if (current == 1)
        return 1;

    if (result[current] <= result[current - 1])
        return 0;

    return 1;
}

void combinations(Combination combination, int current, int * result, int * numberOfSolutions)
{
    for (int i = 1; i <= combination.n; ++i)
    {
        result[current] = i;

        if (condition(result, current))
        {
            if (current < combination.k)
                combinations(combination,current + 1, result, numberOfSolutions);
            else
            {
                printVector(combination.k, result);
                *numberOfSolutions += 1;
            }
        }
    }
}

void testsCombinations()
{
    Combination combination;
    scanf("%d %d", &combination.n, &combination.k);

    int * result = (int *)malloc(combination.n * sizeof(int));

    printf("Combinations of %d taken %d :\n", combination.n, combination.k);

    int numberOfSolutions = 0;
    combinations(combination, 1, result, &numberOfSolutions);

    printf("Number of solutions : %d", numberOfSolutions);

    free(result);
}

int main()
{
    testsCombinations();

    return 0;
}
