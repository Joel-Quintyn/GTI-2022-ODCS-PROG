/*
    A fixed percentage of water is taken each day from a well, request value for W and E.
    Where W is the amt in litres of water in the well at the start of the day
    and E is the percentage of water in the well taken out.

    Write a program that prints the number of days,
    the amount taken for that day and the amount remaining until 30 days have passed.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double w, e, day_w, e_amt;
    int i = 0;

    printf("Well Amount (liters): ");
    scanf("%lf", &w);

    printf("Percent of Water (%%): ");
    scanf("%lf", &e);

    system("clear");

    printf("-----------------------------------------\n");
    printf("| Day\t| Amt. Taken\t| Amt Left\t|\n");
    printf("-----------------------------------------\n");

    do
    {
        ++i;
        e_amt = (e / 100) * w;
        w = w - e_amt;

        printf("| %i\t| %.1lf\t\t| %.1lf\t\t|\n", i, e_amt, w);
        // printf("\nDay #%i:", i);
        // printf("\nAmount Taken: %.2lfl", e_amt);
        // printf("\nAmount Remaining: %lfl", w);

    } while (i < 30);

    printf("-----------------------------------------");

    printf("\n");
    return 0;
}
