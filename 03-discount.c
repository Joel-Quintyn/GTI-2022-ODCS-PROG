/*
Assignment Outline:

Write a program which:
    1. Requests a price and a discount percent.
    2. Prints the original price, the discount amount, and how much the customer must pay for that item.
    3. Repeat 1 and 2 until both price and discount are 0, and display the number of items and the total the customer must pay.
*/

#include <stdio.h>
#include <stdlib.h> //For the system function e.g system("clear");

int main()
{
    double price, discount, dsc_amt, dsc_price, total;
    int i = 0;

    do
    {
        system("clear"); // To clear console/terminal output; Use "cls" for Windows, "clear" for Linux (optional)

        printf("Input Price ($): ");
        scanf("%lf", &price);

        printf("Input Discount (%%): ");
        scanf("%lf", &discount);

        if (price == 0 && discount == 0) // Checks if the user inputs 0 for both the price and discount percent
        {
            continue; // Starts over the loop to stop it
        }

        ++i;                         // Counting the items; Adds 1 to i
        discount = discount / 100;   // Turns the percent into decimal for calulations
        dsc_amt = price * discount;  // Calculates the amount of discount
        dsc_price = price - dsc_amt; // Caculates the discounted price
        total += dsc_price;          // Adding the discounted price for the current item to the total

        printf("\n----------------------------------");
        printf("\nItem #%d", i);
        printf("\nOriginal Price: $%.2lf", price);
        printf("\nDiscount Amount: $%.2lf", dsc_amt);
        printf("\nDiscounted Price: $%.2lf", dsc_price);
        printf("\n----------------------------------\n");

        sleep(2);

    } while (price != 0 && discount != 0); // Loop repeats once the price and discount is not 0

    system("clear");

    if (i > 0) // Checks if the user entered any items (optional)
    {

        printf("\n%d Items", i);
        printf("\nTotal Amount: %.2lf\n", total);
    }

    else // Executes if no items were enterd
    {
        printf("\nNo Items Entered!\n");
    }

    return 0;
}