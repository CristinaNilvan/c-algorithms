#include <stdio.h>

int FindMinimumNumberOfBanknotes(int AmountOfMoney, int * TypesOfBanknotes, int NumberOfBanknoteTypes)
{
    int NumberOfBanknotes = 0;

    for (int i = NumberOfBanknoteTypes - 1; i >= 0; i--)
        if (AmountOfMoney >= TypesOfBanknotes[i])
        {
            int BanknotesOfTheSameType = AmountOfMoney / TypesOfBanknotes[i];
            printf("%d x %d     ", BanknotesOfTheSameType, TypesOfBanknotes[i]);

            NumberOfBanknotes += BanknotesOfTheSameType;
            AmountOfMoney -= BanknotesOfTheSameType * TypesOfBanknotes[i];
        }

    printf("\n");

    return NumberOfBanknotes;
}

void TestsFindingMinimumNumberOfBanknotes()
{
    int NumberOfBanknoteTypes = 7;
    int TypesOfBanknotes[] = {1, 5, 10, 50, 100, 200, 500};

    int NumberOfAmountsOfMoney = 5;
    int AmountsOfMoney[] = {23, 56, 70, 102, 15};

    for (int i = 0; i < NumberOfAmountsOfMoney; i++)
    {
        printf("The amount of money %d decomposed is : ", AmountsOfMoney[i]);
        printf("Number of banknotes used to decompose = %d.\n",
               FindMinimumNumberOfBanknotes(AmountsOfMoney[i],TypesOfBanknotes, NumberOfBanknoteTypes));
    }
}

int main()
{
    TestsFindingMinimumNumberOfBanknotes();

    return 0;
}
