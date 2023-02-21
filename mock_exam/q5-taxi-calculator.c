#include <stdio.h>

// Function to calculate cost for distance traveled
int calculateDistanceCost(int distance) {
    int cost;
    if (distance <= 3) {
        cost = 500;
    } else {
        cost = 500 + (distance - 3) * 100;
    }
    return cost;
}

// Function to calculate cost for time hired
int calculateTimeCost(int time) {
    int cost;
    if (time <= 5) {
        cost = time * 95;
    } else {
        cost = 5 * 95 + (time - 5) * 105;
    }
    return cost;
}

int main() {
    int option;
    int distance, time, distanceCost, timeCost;

    printf("Welcome to the taxi service calculator.\n");
    printf("Please select an option:\n");
    printf("1. Calculate cost for distance traveled\n");
    printf("2. Calculate cost for time hired\n");

    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter distance traveled in kilometers: ");
            scanf("%d", &distance);
            distanceCost = calculateDistanceCost(distance);
            printf("The cost for distance traveled is $%d\n", distanceCost);
            break;
        case 2:
            printf("Enter time hired in minutes: ");
            scanf("%d", &time);
            timeCost = calculateTimeCost(time);
            printf("The cost for time hired is $%d\n", timeCost);
            break;
        default:
            printf("Invalid option selected\n");
            break;
    }

    return 0;
}

