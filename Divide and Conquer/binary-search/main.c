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

int GetSearchedNumber()
{
    int SearchedNumber;

    printf("Searched number = ");
    scanf("%d", &SearchedNumber);

    return SearchedNumber;
}

bool BinarySearch(int * Array, int Left, int Right, int SearchedNumber)
{
    if (Left <= Right)
    {
        int Mid = (Left + Right) / 2;

        if (Array[Mid] == SearchedNumber)
            return true;

        if (Array[Mid] < SearchedNumber)
            return BinarySearch(Array, Mid + 1, Right, SearchedNumber);
        else
            return BinarySearch(Array, Left, Mid + 1, SearchedNumber);
    }

    return false;
}

void TestsBinarySearch(int NumberOfElements, int * Array, int SearchedNumber)
{
    bool Found = BinarySearch(Array, 0, NumberOfElements - 1, SearchedNumber);

    if (Found)
        printf("The number %d has been found. ", SearchedNumber);
    else
        printf("The number %d has not been found. ", SearchedNumber);
}

int main()
{
    int NumberOfElements = GetNumberOfElements();

    int Array[NumberOfElements];
    ReadElements(Array, NumberOfElements);

    int SearchedNumber = GetSearchedNumber();
    TestsBinarySearch(NumberOfElements, Array, SearchedNumber);

    return 0;
}
