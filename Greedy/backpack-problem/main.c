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

int GetBackpackCapacity()
{
    int BackpackCapacity;
    printf("Backpack capacity : ");

    scanf("%d", &BackpackCapacity);

    return BackpackCapacity;
}

int GetValueOfBackpackObjects(Object * Objects, int NumberOfObjects, int BackpackCapacity)
{
    int CurrentWeight = 0;
    int TotalValue = 0;

    for (int i = 0; i < NumberOfObjects; ++i)
        if (CurrentWeight + Objects[i].Weight <= BackpackCapacity)
        {
            CurrentWeight += Objects[i].Weight;
            TotalValue += Objects[i].Value;
        }

    return TotalValue;
}

void DisplayAvailableObjects(Object * Objects, int NumberOfObjects)
{
    printf("Available objects : \n");
    ShowObjects(Objects, NumberOfObjects);
    printf("\n");
}

void EstablishesTotalBackpackValue(Object * obiecte, int numarObiecte, int capacitateRucsac)
{
    int TotalValue = GetValueOfBackpackObjects(obiecte, numarObiecte, capacitateRucsac);
    printf("The value of the objects in the backpack is : %d.", TotalValue);
}

int main()
{
    FILE * File = ValidateFile("Objects.txt");

    int NumberOfObjects = GetNumberOfObjects(File);
    Object * Objects = GetObjects(File, NumberOfObjects);

    fclose(File);

    DisplayAvailableObjects(Objects, NumberOfObjects);

    SortObjects(Objects, NumberOfObjects);

    int BackpackCapacity = GetBackpackCapacity();
    EstablishesTotalBackpackValue(Objects, NumberOfObjects, BackpackCapacity);

    free(Objects);

    return 0;
}
