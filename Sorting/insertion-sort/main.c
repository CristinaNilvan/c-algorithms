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

void InsertionSort(int * Array, int NumberOfElements)
{
    int Auxiliary, Position;

    for (int i = 1; i < NumberOfElements; ++i)
    {
        Auxiliary = Array[i];
        Position = i - 1;

        while ((Position >= 0) && (Array[Position] > Auxiliary))
        {
            Array[Position + 1] = Array[Position];
            Position -= 1;
        }

        Array[Position + 1] = Auxiliary;
    }
}

int main()
{
    int NumberOfElements = GetNumberOfElements();
    int Array[NumberOfElements];

    ReadElements(Array, NumberOfElements);

    InsertionSort(Array, NumberOfElements);
    ShowAllElements(Array, NumberOfElements);

    return 0;
}
