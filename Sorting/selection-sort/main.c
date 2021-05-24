#include <stdio.h>

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

int FindPositionOfMinimum(const int *Array, int NumberOfElements, int i)
{
    int PositionOfMin = i;

    for (int j = i + 1; j < NumberOfElements; ++j)
        if (Array[j] < Array[PositionOfMin])
            PositionOfMin = j;

    return PositionOfMin;
}

void SelectionSort(int * Array, int NumberOfElements)
{
    int PositionOfMin;

    for (int i = 0; i < NumberOfElements - 1; ++i)
    {
        PositionOfMin = FindPositionOfMinimum(Array, NumberOfElements, i);

        if (PositionOfMin != i)
            SwapElements(&Array[i], &Array[PositionOfMin]);
    }
}

int main()
{
    int NumberOfElements = GetNumberOfElements();
    int Array[NumberOfElements];

    ReadElements(Array, NumberOfElements);

    SelectionSort(Array, NumberOfElements);
    ShowAllElements(Array, NumberOfElements);

    return 0;
}
