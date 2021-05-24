#include <stdio.h>
#include <stdbool.h>

int GetNumberOfElements()
{
    int NumberOfElements;

    printf("Number of elements = ");
    scanf("%d", &NumberOfElements);

    return NumberOfElements;
}

void ReadElements(int * Array, int NumberOfElements)
{
    for (int i = 0; i < NumberOfElements; ++i)
        scanf("%d", &Array[i]);
}

void ShowAllElements(int * Array, int NumberOfElements)
{
    for (int i = 0; i < NumberOfElements; ++i)
        printf("%d ", Array[i]);

    printf("\n");
}

void SwapElements(int * FirstElement, int * SecondElement)
{
    int Auxiliary = *FirstElement;
    *FirstElement = *SecondElement;
    *SecondElement = Auxiliary;
}

void BubbleSort(int * Array, int NumberOfElements)
{
    bool Swapped;

    do
    {
       Swapped = false;

        for (int i = 0; i < NumberOfElements - 1; ++i)
            if (Array[i] > Array[i + 1])
            {
                SwapElements(&Array[i], &Array[i + 1]);
                Swapped = true;
            }

        NumberOfElements -= 1;

    } while (Swapped);
}

int main()
{
    int NumberOfElements = GetNumberOfElements();
    int Array[NumberOfElements];

    ReadElements(Array, NumberOfElements);

    BubbleSort(Array, NumberOfElements);
    ShowAllElements(Array, NumberOfElements);

    return 0;
}
