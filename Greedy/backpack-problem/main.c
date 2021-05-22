#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int Weight, Value;
    char ObjectName[50];
} Object;

FILE * OpenFile(const char * FileName)
{
    FILE * File = fopen(FileName, "r");

    return File;
}

FILE * ValidateFile(const char * FileName)
{
    FILE * File = OpenFile(FileName);

    if (!File)
    {
        printf("File not found.");
        exit(5);
    }

    return File;
}

int GetNumberOfObjects(FILE * File)
{
    int NumberOfObjects;
    fscanf(File, "%d", &NumberOfObjects);

    return NumberOfObjects;
}

Object * GetObjects(FILE * File, int NumberOfObjects)
{
    Object * Objects = (Object *)malloc(NumberOfObjects * sizeof(Object));

    for (int i = 0; i < NumberOfObjects; i++)
    {
        fscanf(File, "%d %d", &Objects[i].Weight, &Objects[i].Value);

        fgets(Objects[i].ObjectName, sizeof(Objects[i].ObjectName), File);
        Objects[i].ObjectName[strlen(Objects[i].ObjectName) - 1] = '\0';
    }

    return Objects;
}

bool Condition(Object FirstObject, Object SecondObject)
{
    if ((float)FirstObject.Value / FirstObject.Weight < (float)SecondObject.Value / SecondObject.Weight)
        return true;

    return false;
}

void SwapObjects(Object * FirstObject, Object * SecondObject)
{
    Object Auxiliary = *FirstObject;
    *FirstObject = *SecondObject;
    *SecondObject = Auxiliary;
}

void SortObjects(Object * Objects, int NumberOfObjects)
{
    for (int i = 0; i < NumberOfObjects; ++i)
        for (int j = i + 1; j < NumberOfObjects; ++j)
            if (Condition(Objects[i], Objects[j]))
                SwapObjects(&Objects[i], &Objects[j]);
}

void ShowObjects(Object * Objects, int NumberOfObjects)
{
    for (int i = 0; i < NumberOfObjects; ++i)
        printf("%d %d %s\n", Objects[i].Weight, Objects[i].Value, Objects[i].ObjectName);
}

int main()
{
    printf("Hello, World!\n");
    return 0;
}
