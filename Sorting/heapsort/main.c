#include <stdio.h>

int GetNumberOfElements() {
    int NumberOfElements;

    printf("Number of elements = ");
    scanf("%d", &NumberOfElements);

    return NumberOfElements;
}

void ReadElements(int * Array, int NumberOfElements) {
    for (int i = 1; i <= NumberOfElements; ++i)
        scanf("%d", &Array[i]);
}

void ShowAllElements(int * Array, int NumberOfElements) {
    for (int i = 1; i <= NumberOfElements; ++i)
        printf("%d ", Array[i]);

    printf("\n");
}

void SwapElements(int * FirstElement, int * SecondElement) {
    int Auxiliary = *FirstElement;
    *FirstElement = *SecondElement;
    *SecondElement = Auxiliary;
}

int LeftChild(int i) {
    return 2 * i;
}

int RightChild(int i) {
    return 2 * i + 1;
}

void MaxHeapify(int * Array, int i, int HeapSize) {
    int Largest;
    int Left = LeftChild(i);
    int Right = RightChild(i);

    if ((Left <= HeapSize) && (Array[Left] > Array[i]))
        Largest = Left;
    else
        Largest = i;

    if ((Right <= HeapSize) && (Array[Right] > Array[Largest]))
        Largest = Right;

    if (Largest != i) {
        SwapElements(&Array[i], &Array[Largest]);
        MaxHeapify(Array, Largest, HeapSize);
    }
}

void BuildHeap(int * Array, int ArrayLength) {
    for (int i = ArrayLength / 2; i >= 1; i--)
        MaxHeapify(Array, i, ArrayLength);
}

void Heapsort(int * Array, int ArrayLength) {
    BuildHeap(Array, ArrayLength);

    int ArrayLengthCopy = ArrayLength;

    for (int i = ArrayLength; i >= 2; i--) {
        SwapElements(&Array[1], &Array[i]);
        ArrayLengthCopy -= 1;

        MaxHeapify(Array, 1, ArrayLengthCopy);
    }
}

int main() {
    int NumberOfElements = GetNumberOfElements();
    int Array[NumberOfElements];

    ReadElements(Array, NumberOfElements);

    Heapsort(Array, NumberOfElements);
    ShowAllElements(Array, NumberOfElements);

    return 0;
}
