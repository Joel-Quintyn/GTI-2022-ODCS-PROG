/*
Date of Assignment: 09-01-2023
Assignment Outline:

Prompt the user to input their name, age, weight and height.
Calculate the user's Body Mass Index.

Output all variables and the calculated BMI to a file.
*/

#include <stdio.h>
#include <stdlib.h> //For system function e.g system("clear")
#include <string.h> //For string functions e.g. strcpy(char[], "string")
#include <unistd.h> //For sleep function

void main()
{
    FILE *h_file = fopen("assets/history.txt", "a+"); //Initializing and opening file in read and write mode.

    //Variables for use in program
    char f_name[20], l_name[20], name[40], line_44[] = "-------------------------------------------";
    float weight, height, bmi;
    int age, ch;

    //Main execution loop
    while (1) {

        system("clear"); 
        //UI-UX
        printf("%34s", "Body Mass Idex Calculator");
        printf("\n%s\n", line_44);

        printf("Calculate Your BMI\t- 1\n");
        printf("View Previous Entries\t- 2");
        printf("\nEXIT\t\t\t- 3");
        printf("\n\n> ");
        
        scanf("%d", &ch);

        system("clear");

        if (ch == 1) {
            
            fseek(h_file, 0, SEEK_END); //Placing pointer at the end of the file for appending.

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

            bmi = (weight / (height * height)) * 703; //Calculate BMI

            fprintf(h_file, "%s %s %d %.2f %.2f %.1f\n", f_name, l_name, age, weight, height, bmi); //Appending info to the file.

            system("clear");

            printf("%34s", "Body Mass Idex Calculator");
            printf("\n%s\n", line_44);

            //Printing entered & calculated information
            printf("Name: %s %s \n", f_name, l_name);
            printf("Age: %d \n", age);
            printf("Weight: %.2f \n", weight);
            printf("Height: %.2f \n", height);
            printf("Your BMI is %.1f \n", bmi);
            printf("You are ");

            //Checking BMI score
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

            //Logic to restart main loop
            printf("\n\n\nEnter 1 to continue\n> ");
            scanf("%d", &ch);
            if (ch == 1){continue;}

        }

        if (ch == 2) {
            printf("%34s", "Body Mass Idex Calculator");
            printf("\n%s\n", line_44);
            
            rewind(h_file); //Placing pointer at the begining of file for reading.
            fscanf(h_file, "%s", f_name);
            
            //Checking if file exists and has info
            if (!h_file || feof(h_file)){
                printf("No Previous Entries\n");
                sleep(2);
                continue;
            }

            printf("Name            Age  Weight  Height   BMI");
            printf("\n%s\n", line_44);

            while (!feof(h_file)) //Checking if file pointer is at the end.
            {
                //Reding info from file
                fscanf(h_file, "%s %d %f %f %f", l_name, &age, &weight, &height, &bmi);
                //Creating name string for formatted output
                strcpy(name, f_name); strcat(name, " "); strcat(name, l_name);

                //Outputing formatted info
                printf("%-15s %3d %7.2f %7.2f %5.1f\n", name, age, weight, height, bmi);
                fscanf(h_file, "%s", f_name);
            }

            //Logic to restart main loop
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

    fclose(h_file); //Closing file
}
