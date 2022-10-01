/*
Develop a C program that will produce calculations for a taxi service that will assist the
driver in obtaining the total cost to charged for the passenger for a trip.

Requirements:
    1. Accept total time taken for the trip in minutes.
    2. Calculate the cost using a fixed rate of $20/min.
    3. 10% of the cost should be calculated as tips for the driver.
    4. The total payment, which includes the cost for trip + tips.

Output; On a new screen, present the following:
    1. Total time taken for the trip
    2. Rate per minute, cost for trip
    3. Loyality for the driver
    4. Total to be paid for the trip.

The program should then allow for the entry of minutes and if 0 is inputted them produce the following summary info:
    1. Total trips made for the day
    2. Total money collected for the day
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define RATE 20
#define TIP_PER 0.1

int main()
{
    double time, trip_cost, loyalty, total, money_collected;
    int t = 0;

    do
    {
        system("clear");

        printf("\nTrip Time (mins): ");
        scanf("%lf", &time);

        if (time == 0){continue;}

        ++t;
        trip_cost = time * RATE;
        loyalty = trip_cost * TIP_PER;
        total = trip_cost + loyalty;
        money_collected += total;

        system("clear");

        printf("\nTrip Time: %.2lf mins.", time);
        printf("\nTrip Cost ($20/min): $%.2lf", trip_cost);
        printf("\nTip Amount (10%%): $%.2lf", loyalty);
        printf("\nTotal Payment: $%.2lf", total);

        sleep(2);

    } while (time != 0);

    system("clear");

    if (t == 0)
    {
        printf("\nNo trips logged.");
    }
    else
    {
        printf("\nTotal Trips: %d", t);
        printf("\nTotal Money Collected: $%.2lf", money_collected);
    }

    printf("\n");
    return 0;
}
