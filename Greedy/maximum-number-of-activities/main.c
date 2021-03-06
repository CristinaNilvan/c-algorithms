#include <stdio.h>

typedef struct
{
    int StartTime, EndTime;
    char ActivityName[100];
} Activity;

int GetNumberOfActivities()
{
    int NumberOfActivities = 0;

    printf("Number of activities : ");
    scanf("%d", &NumberOfActivities);

    return NumberOfActivities;
}

void GetActivities(int NumberOfActivities, Activity *Activities)
{
    for (int i = 0; i < NumberOfActivities; ++i)
    {
        scanf("%d %d", &Activities[i].StartTime, &Activities[i].EndTime);
        gets(Activities[i].ActivityName);
    }
}

void SwapActivities(Activity * FirstActivity, Activity * SecondActivity)
{
    Activity Auxiliary = *FirstActivity;
    *FirstActivity = *SecondActivity;
    *SecondActivity = Auxiliary;
}

void SortActivities(Activity * Activities, int NumberOfActivities)
{
    for (int i = 0; i < NumberOfActivities; ++i)
        for (int j = i + 1; j < NumberOfActivities; ++j)
            if (Activities[i].EndTime > Activities[j].EndTime)
                SwapActivities(&Activities[i], &Activities[j]);
}

void SelectActivities(Activity * Activities, int NumberOfActivities, int * SelectedActivities, int * NumberOfSelectedActivities)
{
    SelectedActivities[0] = 0;
    *NumberOfSelectedActivities = 1;

    for (int i = 1; i < NumberOfActivities; ++i)
        if (Activities[i].StartTime >= Activities[SelectedActivities[*NumberOfSelectedActivities - 1]].EndTime)
        {
            SelectedActivities[*NumberOfSelectedActivities] = i;
            *NumberOfSelectedActivities += 1;
        }
}

void ShowSelectedActivities(Activity * Activities, int * SelectedActivities, int NumberOfSelectedActivities)
{
    printf("\nThe selected activities are : \n");

    for (int i = 0; i < NumberOfSelectedActivities; ++i)
        printf("\n%d %d %d %s\n", SelectedActivities[i], Activities[SelectedActivities[i]].StartTime,
               Activities[SelectedActivities[i]].EndTime, Activities[SelectedActivities[i]].ActivityName);
}

void ShowTheNumberOfActivities(int NumberOfSelectedActivities)
{
    printf("\nThe maximum number of selected activities is : %d. ", NumberOfSelectedActivities);
}

int main()
{
    int NumberOfActivities;
    NumberOfActivities = GetNumberOfActivities();

    Activity Activities[NumberOfActivities];
    GetActivities(NumberOfActivities, Activities);

    SortActivities(Activities, NumberOfActivities);

    int SelectedActivities[NumberOfActivities];
    int NumberOfSelectedActivities;
    SelectActivities(Activities, NumberOfActivities, SelectedActivities, &NumberOfSelectedActivities);

    ShowSelectedActivities(Activities, SelectedActivities, NumberOfSelectedActivities);
    ShowTheNumberOfActivities(NumberOfSelectedActivities);

    return 0;
}
