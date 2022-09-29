/*
Assignment Outline:

Write a program which:
    1. Request a price and a discount percent.
    2. Prints the original price and the discount amount and the how much customer must pay for that item
    3. repeat 1 and 2 until both price and discount are 0 and display the number of items and the total the customer must pay
*/
#include <stdio.h>
#include <stdlib.h> //For system function
#include <unistd.h> //For linux pause

int main()
{
    double price, discount, dsc_amt, dsc_price, total;
    int i = 0;

    do
    {
        system("clear");

        printf("Input Price ($): ");
        scanf("%lf", &price);

        printf("Input Discount (%%): ");
        scanf("%lf", &discount);

        if (price == 0 && discount == 0)
        {
            continue;
        }

        ++i;
        discount = discount / 100;
        dsc_amt = price * discount;
        dsc_price = price - dsc_amt;
        total += dsc_price;

        printf("\n----------------------------------");
        printf("\nItem #%d", i);
        printf("\nOriginal Price: $%.2lf", price);
        printf("\nDiscount Amount: $%.2lf", dsc_amt);
        printf("\nDiscounted Price: $%.2lf", dsc_price);
        printf("\n----------------------------------\n");

        sleep(2);

    } while (price != 0 && discount != 0);

    system("clear");
    if (i > 0)
    {

        printf("\n%d Items", i);
        printf("\nTotal Amount: %.2lf\n", total);
    }

    else {
        printf("\nNo Items Entered!\n");
    }
    return 0;
}