#include <stdio.h>

typedef struct
{
    int StartTime, EndTime;
    char ActivityName[100];
} Activity;

int GetNumberOfActivities(int *NumberOfActivities)
{
    printf("Number of activities : ");
    scanf("%d", NumberOfActivities);

    return (*NumberOfActivities);
}

void GetActivities(int NumberOfActivities, Activity *Activities)
{
    for (int i = 0; i < NumberOfActivities; ++i)
    {
        scanf("%d %d", &Activities[i].StartTime, &Activities[i].EndTime);
        gets(Activities[i].ActivityName);
    }
}

void SortActivities(Activity * Activities, int NumberOfActivities)
{
    for (int i = 0; i < NumberOfActivities; ++i)
        for (int j = i + 1; j < NumberOfActivities; ++j)
            if (Activities[i].StartTime > Activities[j].StartTime)
            {
                Activity Auxiliary = Activities[i];
                Activities[i] = Activities[j];
                Activities[j] = Auxiliary;
            }
}

void ShowSelectedActivities(Activity * Activities, int * SelectedActivities, int NumberOfSelectedActivities)
{
    for (int i = 0; i < NumberOfSelectedActivities; ++i)
        printf("%d %d %d %s\n", SelectedActivities[i], Activities[SelectedActivities[i]].StartTime,
               Activities[SelectedActivities[i]].EndTime, Activities[SelectedActivities[i]].ActivityName);
}

int main()
{

    return 0;
}
