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
    for (int i = 1; i <= NumberOfElements; ++i)
        scanf("%d", &Array[i]);
}

void ShowAllElements(int * Array, int NumberOfElements)
{
    for (int i = 1; i <= NumberOfElements; ++i)
        printf("%d ", Array[i]);

    printf("\n");
}

void SwapElements(int * FirstElement, int * SecondElement)
{
    int Auxiliary = *FirstElement;
    *FirstElement = *SecondElement;
    *SecondElement = Auxiliary;
}

int Partition(int * Array, int Left, int Right) {
    int Pivot = Array[Right];

    int i = Left - 1;

    for (int j = Left; j <= Right - 1; j++) {
        if (Array[j] <= Pivot) {
            i += 1;

            SwapElements(&Array[i], &Array[j]);
        }
    }

    SwapElements(&Array[i + 1], &Array[Right]);

    return (i + 1);
}

void Quicksort(int * Array, int Left, int Right) {
    if (Left < Right) {
        int partition_index = Partition(Array, Left, Right);

        Quicksort(Array, Left, partition_index - 1);
        Quicksort(Array, partition_index + 1, Right);
    }
}

int main() {
    int NumberOfElements = GetNumberOfElements();
    int Array[NumberOfElements];

    ReadElements(Array, NumberOfElements);

    Quicksort(Array, 1, NumberOfElements);
    ShowAllElements(Array, NumberOfElements);

    return 0;
}
