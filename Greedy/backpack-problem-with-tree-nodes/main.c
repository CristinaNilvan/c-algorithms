#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER_OF_NODES 100

typedef struct node
{
    int Id;
    int Value;
    int Weight;
    struct node * Left;
    struct node * Right;
} Node;

typedef struct
{
    int Id;
    int Value;
    int Weight;
} NodeCharacteristics;

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

void PrintError()
{
    printf("We don't have enough memory!");
    exit(5);
}

Node * CreateBinaryTreeFromFile(FILE * File)
{
    Node * CurrentNode;
    int Id, Value, Weight;

    fscanf(File, "%d", &Id);

    if (Id == 0)
        return NULL;
    else
    {
        CurrentNode = (Node *)malloc(sizeof(Node));

        if (CurrentNode == NULL)
            PrintError();

        fscanf(File, "%d %d", &Value, &Weight);

        CurrentNode->Id = Id;
        CurrentNode->Value = Value;
        CurrentNode->Weight = Weight;
        CurrentNode->Left = CreateBinaryTreeFromFile(File);
        CurrentNode->Right = CreateBinaryTreeFromFile(File);
    }

    return CurrentNode;
}

void InOrderCrossing(Node * CurrentNode, NodeCharacteristics * VectorOfNodes, int * NumberOfNodes)
{
    if (CurrentNode != NULL)
    {
        InOrderCrossing(CurrentNode->Left, VectorOfNodes, NumberOfNodes);

        VectorOfNodes[*NumberOfNodes].Id = CurrentNode->Id;
        VectorOfNodes[*NumberOfNodes].Value = CurrentNode->Value;
        VectorOfNodes[*NumberOfNodes].Weight = CurrentNode->Weight;

        *NumberOfNodes += 1;

        InOrderCrossing(CurrentNode->Right, VectorOfNodes, NumberOfNodes);
    }
}

bool Condition(NodeCharacteristics FirstNode, NodeCharacteristics SecondNode)
{
    if ((float)FirstNode.Value / FirstNode.Weight < (float)SecondNode.Value / SecondNode.Weight)
        return true;

    return false;
}

void SwapObjects(NodeCharacteristics * FirstNode, NodeCharacteristics * SecondNode)
{
    NodeCharacteristics Auxiliary = *FirstNode;
    *FirstNode = *SecondNode;
    *SecondNode = Auxiliary;
}

void SortNodes(NodeCharacteristics * VectorOfNodes, int NumberOfNodes)
{
    for (int i = 0; i < NumberOfNodes; ++i)
        for (int j = i + 1; j < NumberOfNodes; ++j)
            if (Condition(VectorOfNodes[i], VectorOfNodes[j]))
                SwapObjects(&VectorOfNodes[i], &VectorOfNodes[j]);
}

int GetBackpackCapacity()
{
    int BackpackCapacity;
    printf("Backpack capacity : ");

    scanf("%d", &BackpackCapacity);

    return BackpackCapacity;
}

void ShowChosenNode(NodeCharacteristics ChosenNode)
{
    printf("Node %d with value = %d and wight %d. \n", ChosenNode.Id, ChosenNode.Value, ChosenNode.Weight);
}

int GetValueOfBackpackNodes(NodeCharacteristics * VectorOfNodes, int NumberOfNodes, int BackpackCapacity)
{
    int CurrentWeight = 0;
    int TotalValue = 0;

    for (int i = 0; i < NumberOfNodes; ++i)
        if (CurrentWeight + VectorOfNodes[i].Weight <= BackpackCapacity)
        {
            CurrentWeight += VectorOfNodes[i].Weight;
            TotalValue += VectorOfNodes[i].Value;

            ShowChosenNode(VectorOfNodes[i]);
        }

    return TotalValue;
}

void EstablishesTotalBackpackValue(NodeCharacteristics * VectorOfNodes, int NumberOfNodes, int BackpackCapacity)
{
    int TotalBackpackValue = GetValueOfBackpackNodes(VectorOfNodes, NumberOfNodes, BackpackCapacity);
    printf("Total value of backpack : %d.", TotalBackpackValue);
}

int main()
{
    FILE * File = ValidateFile("Tree.txt");

    Node * Root = CreateBinaryTreeFromFile(File);

    fclose(File);

    int NumberOfNodes = 0;
    NodeCharacteristics * VectorOfNodes = (NodeCharacteristics *)malloc(MAX_NUMBER_OF_NODES * sizeof(NodeCharacteristics));

    InOrderCrossing(Root, VectorOfNodes, &NumberOfNodes);

    SortNodes(VectorOfNodes, NumberOfNodes);

    int BackpackCapacity = GetBackpackCapacity();
    EstablishesTotalBackpackValue(VectorOfNodes, NumberOfNodes, BackpackCapacity);

    free(VectorOfNodes);

    return 0;
}
