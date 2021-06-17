#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int StartTime;
    int EndTime;
} Interval;

int GetNumberOfIntervals()
{
    int NumberOfIntervals = 0;

    printf("Number of intervals : ");
    scanf("%d", &NumberOfIntervals);

    return NumberOfIntervals;
}

void GetTimeIntervals(Interval * TimeIntervals, int NumberOfIntervals)
{
    for (int i = 0; i < NumberOfIntervals; ++i)
        scanf("%d %d", &TimeIntervals[i].StartTime, &TimeIntervals[i].EndTime);
}

void SwapIntervals(Interval * FirstInterval, Interval * SecondInterval)
{
    Interval Auxiliary = *FirstInterval;
    *FirstInterval = *SecondInterval;
    *SecondInterval = Auxiliary;
}

void SortIntervals(Interval * TimeIntervals, int NumberOfIntervals)
{
    for (int i = 0; i < NumberOfIntervals; ++i)
        for (int j = i + 1; j < NumberOfIntervals; ++j)
            if (TimeIntervals[i].StartTime > TimeIntervals[j].StartTime)
                SwapIntervals(&TimeIntervals[i], &TimeIntervals[j]);
}

bool Condition(Interval TimeInterval, int Element)
{
    if ((Element >= TimeInterval.StartTime) && (Element <= TimeInterval.EndTime))
        return true;

    return false;
}

int GetMinimumNumberOfBoats(Interval * TimeIntervals, int NumberOfIntervals)
{
    int LastTime = -1;
    int NumberOfBoats = 1;

    for (int i = 0; i < NumberOfIntervals - 1; ++i)
        if (Condition(TimeIntervals[i], TimeIntervals[i + 1].StartTime) ||
            Condition(TimeIntervals[i], TimeIntervals[i + 1].EndTime))
        {
            NumberOfBoats += 1;

            if ((LastTime <= TimeIntervals[i + 1].StartTime) && (LastTime != -1))
                NumberOfBoats -= 1;

            LastTime = TimeIntervals[i + 1].EndTime;
        }

    return NumberOfBoats;
}

void ShowTimeIntervals(Interval * TimeIntervals, int NumberOfIntervals)
{
    printf("Time intervals : \n");

    for (int i = 0; i < NumberOfIntervals; ++i)
        printf("%d %d\n", TimeIntervals[i].StartTime, TimeIntervals[i].EndTime);
}

int main()
{
    int NumberOfIntervals = GetNumberOfIntervals();

    Interval TimeIntervals[NumberOfIntervals];
    GetTimeIntervals(TimeIntervals, NumberOfIntervals);
    ShowTimeIntervals(TimeIntervals, NumberOfIntervals);

    SortIntervals(TimeIntervals, NumberOfIntervals);

    int NumberOfBoats = GetMinimumNumberOfBoats(TimeIntervals, NumberOfIntervals);
    printf("Number of boats : %d.", NumberOfBoats);

    return 0;
}
