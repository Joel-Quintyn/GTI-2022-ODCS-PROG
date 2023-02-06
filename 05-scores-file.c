/*
Date of Assignment: 30-Jan-2023
Outline:
Write a C program that will accept 8 scores from the user for eight different subjects.
Calculate the average score and also the final percentage out of 100%.
Print the following to a text file:
Name of student, subjects and score, average marks and the percentage.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float average_score(float scores[]);
float overall_percentage(float scores[]);

void main()
{
    FILE *scr_file = fopen("assets/scores.txt", "a+");

    float scores[8], avg_scr, percentage;
    char f_name[25], l_name[25], name[40], line_44[] = "-------------------------------------------",
            subjects[8][12] = {"English", "Hardware", "Software", "Management", "Statistics", "Web Design", "Programming", "Mathematics"};
    int i, ch;

    while (1)
    {
        system("clear");
        // UI-UX
        printf("%34s", "Test Scores Calculator");
        printf("\n%s\n", line_44);

        printf("Calculate Percentage\t- 1\n");
        printf("View Previous Entries\t- 2");
        printf("\nEXIT\t\t\t- 3");
        printf("\n\n> ");

        scanf("%d", &ch);

        system("clear");

        if (ch == 1)
        {
            fseek(scr_file, 0, SEEK_END); // Placing pointer at the end of the file for appending.

            printf("%34s", "Test Scores Calculator");
            printf("\n%s\n", line_44);

            printf("~First Name: ");
            scanf("%s", f_name);
            fprintf(scr_file, "%s ", f_name);

            printf("~Last Name: ");
            scanf("%s", l_name);
            fprintf(scr_file, "%s ", l_name);

            for (i = 0; i < 8; i++)
            {
                printf("~Input %s Score: ", subjects[i]);
                scanf("%f", &scores[i]);
                fprintf(scr_file, "%.2f ", scores[i]);
            }

            avg_scr = average_score(scores);
            // percentage = overall_percentage(scores);1
            fprintf(scr_file, "%.2f ", avg_scr);
            // fprintf(scr_file, "%.2f\n", percentage);

            system("clear");

            printf("%34s", "Test Scores Calculator");
            printf("\n%s\n", line_44);

            //Printing entered & calculated information
            printf("Name: %s %s \n", f_name, l_name);
            for (i = 0; i < 8; i++)
            {
                printf("%s Score: %.2f\n", subjects[i], scores[i]);
            }
            printf("Average Score: %.2f", avg_scr);
            // printf("\nOverall Percentage: %.2f%%", percentage);


            //Logic to restart main loop
            printf("\n\n\nEnter 1 to continue\n> ");
            scanf("%d", &ch);
            if (ch == 1){ch = 3; continue;}
        }

        if (ch == 2)
        {
            printf("%34s", "Test Scores Calculator");
            printf("\n%s\n", line_44);

            rewind(scr_file); //Placing pointer at the begining of file for reading.
            fscanf(scr_file, "%s", f_name);

            //Checking if file exists and has info
            if (!scr_file || feof(scr_file)){
                printf("No Previous Entries\n");
                sleep(2);
                continue;
            }

            while (!feof(scr_file)) //Checking if file pointer is at the end.
            {
                fscanf(scr_file, "%s", l_name);
                for (i; i <=33 8; i++)
                {
                    fscanf(scr_file, "%f", &scores[i]);
                }
                fscanf(scr_file, "%f", &avg_scr);
                // fscanf(scr_file, "%f", &percentage);

                printf("\n\nStudent: %s %s", f_name, l_name);
                for (i = 0; i < 8; i++)
                {
                    printf("\n~%s Score: ", subjects[i]);
                    printf("%.2f ", scores[i]);
                }
                printf("\nAverage Score: %.2f", avg_scr);
                // printf("\nOverall Percentage: %.2f", percentage);

                fscanf(scr_file, "%s", f_name);
            }

            //Logic to restart main loop
            printf("\n\n\nEnter 1 to continue\n> ");
            scanf("%d", &ch);
            if (ch == 1){ch = 3; continue;}
        }
        
        if (ch == 3)
        {
            printf("%34s", "Test Scores Calculator");
            printf("\n%s\n", line_44);
            printf("Thank You!\n");
            break;
        }
    }

    fclose(scr_file);
}

float average_score(float scores[])
{
    float average = 0.0;
    int i = 0;

    for (i; i < 8; i++)
    {
        average += scores[i];
    }

    return average / 8;
}

/* float overall_percentage(float scores[])
{
    float percentage;
    int i = 0;

    for (i; i < 8; i++)
    {
        percentage += scores[i];
    }

    percentage = percentage / 800;
    percentage = percentage * 100;

    return percentage;
} */