/*
Assignment Outline:

The price of an item is p dollars. Due to inflation, the price of the item is expected to increase by r% each year.
Write a program which:
    1. Read p and r
    2. Starting with year 1 print a table consisting of year and year-end price
    3. The table ends when the year-end price is at least 2 twice the original price
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int y=2010;
    double p, r, y_end_price;

    printf("--------------- Inflation Calculator ---------------");

    printf("\nPrice of Item ($): ");
    scanf("%lf", &p);
    y_end_price = p;

    printf("\nEstimated Rate of Inflation (%%): ");
    scanf("%lf", &r);
    r = r/100;

    system("clear");

    printf("--------------- Inflation Calculator ---------------");
    printf("\n\t|Year\t |  Year-End Price|");

    do
    {

        y_end_price = (p * r) + y_end_price;
        printf("\n\t|%d    |\t%.2lf   |", y, y_end_price);
        ++y;

        // printf("\n%.3lf", y_end_price/p);
        

    } 
    while ((y_end_price/p) < 2);
    

}