/*
Date of Assignment: 09-01-2023
Assignment Outline:

Prompt the user to input their name, age, weight and height.
Calculate the user's Body Mass Index.

Output all variables and the calculated BMI to a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main()
{
    FILE *h_add;
    FILE *h_read;

    char f_name[20], l_name[20], name[40], line_44[] = "-------------------------------------------";
    float weight, height, bmi;
    int age, ch;


    while (1) {

        system("clear");
        printf("%34s", "Body Mass Idex Calculator");
        printf("\n%s\n", line_44);

        printf("Calculate Your BMI\t- 1\n");
        printf("View Previous Entries\t- 2");
        printf("\nEXIT\t\t\t- 3");
        printf("\n\n> ");
        
        scanf("%d", &ch);

        system("clear");

        if (ch == 1) {
            h_add = fopen("assets/history.txt", "a");

            printf("%34s", "Body Mass Idex Calculator");
            printf("\n%s\n", line_44);
            
            printf("First Name: ");
            scanf("%s", f_name);

            printf("Last Name: ");
            scanf("%s", l_name);

            printf("Age: ");
            scanf("%d", &age);

            printf("Weight (lbs): ");
            scanf("%f", &weight);

            printf("Height (inches): ");
            scanf("%f", &height);

            bmi = (weight / (height * height)) * 703;

            fprintf(h_add, "%s %s %d %.2f %.2f %.1f\n", f_name, l_name, age, weight, height, bmi);

            system("clear");

            printf("%34s", "Body Mass Idex Calculator");
            printf("\n%s\n", line_44);

            printf("Name: %s %s \n", f_name, l_name);
            printf("Age: %d \n", age);
            printf("Weight: %.2f \n", weight);
            printf("Height: %.2f \n", height);
            printf("Your BMI is %.1f \n", bmi);
            printf("You are ");

            if (bmi < 18.5)
            {
                printf("Underweight");
            }

            else if (18.5 <= bmi <= 24.9)
            {
                printf("Normal");
            }

            else if (25 <= bmi <= 29.9)
            {
                printf("Overweight");
            }

            else
            {
                printf("Obese");
            }

            printf("\n\n\nEnter 1 to continue\n> ");
            scanf("%d", &ch);
            if (ch == 1){continue;}
            fclose(h_add);
        }

        if (ch == 2) {
            printf("%34s", "Body Mass Idex Calculator");
            printf("\n%s\n", line_44);

            h_read = fopen("assets/history.txt", "r");
            
            if (!h_read || feof(h_read)){
                printf("No Previous Entries\n");
                sleep(2);
                continue;
            }

            fscanf(h_read, "%s", f_name);
            printf("Name            Age  Weight  Height   BMI");
            printf("\n%s\n", line_44);

            while (!feof(h_read))
            {
                fscanf(h_read, "%s %d %f %f %f", l_name, &age, &weight, &height, &bmi);
                strcpy(name, f_name); strcat(name, " "); strcat(name, l_name);

                printf("%-15s %3d %7.2f %7.2f %5.1f\n", name, age, weight, height, bmi);
                fscanf(h_read, "%s", f_name);
            }
            
            fclose(h_read);

            printf("\n\n\nEnter 1 to continue\n> ");
            scanf("%d", &ch);
            if (ch == 1){continue;}
        }

        if (ch == 3)
        {
            printf("%34s", "Body Mass Idex Calculator");
            printf("\n%s\n", line_44);
            printf("Thank You!\n");
            break;
        }

    }
}
