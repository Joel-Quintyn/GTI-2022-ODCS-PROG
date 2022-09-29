/*
Assignment Outline:

The price of an item is p dollars. Due to inflation, the price of the item is expected to increase by r% each year.
Write a program which:
    1. Read p and r
    2. Starting with year 1 print a table consisting of year and year-end price
    3. The table ends when the year-end price is at least 2 twice the original price
*/
#include <stdio.h>
#include <stdlib.h> // For the system function e.g system("clear");

int main()
{
    int y = 2010; // Set default start year (y = 1, recommended)
    double p, r, y_end_price;

    printf("--------------- Inflation Calculator ---------------");

    printf("\nPrice of Item ($): ");
    scanf("%lf", &p);
    y_end_price = p; // Initialize the year end price to first price entered

    printf("\nEstimated Rate of Inflation (%%): ");
    scanf("%lf", &r);
    r = r / 100; // Converts the inflation percent into decimal for calulations

    system("clear"); // To clear console/terminal output; Use "cls" for Windows, "clear" for Linux (optional)

    printf("--------------- Inflation Calculator ---------------");
    printf("\n\t|Year\t |  Year-End Price|");

    do
    {

        y_end_price = (p * r) + y_end_price; // Calculates the *current* year price and the inflation amount
        printf("\n\t|%d    |\t%.2lf   |", y, y_end_price);
        ++y; // Counting the years; Adds 1 to y

    } while ((y_end_price / p) < 2); // Loop repeats if the quotient of dividing the current year end price and the original price is less than 2
}
