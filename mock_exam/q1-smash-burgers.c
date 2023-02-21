// Joel Quintyn
// F-22-1009-1901
// Question 1

#include <stdio.h>
#include <stdlib.h>

int main() {
   int i, persons, b_choice, b1=0, b2=0, b3=0;
   float cost, discount_amt;
   const float burger_1 = 5600, burger_2 = 7000, burger_3 = 6200;
   
	
	
   printf("\tSmash Burgers\n");
   printf("---------------------------------\n");
   printf("   This Week's Discount = 5%%\n");
   printf("   Group of 4 or less persons\n");
   printf("   Burgers\t\t\tCost\n");
   printf("1. Cheese and Bacon \t$5600\n");
   printf("2. 1/4 Classic Beef \t$7000\n");
   printf("3. Sausage & Chicken \t$6200\n");
   printf("---------------------------------\n");
   printf("\nHow many persons in group: ");
   scanf("%d", &persons);
   
   if(persons > 0 && persons <= 4){
   	
    	for(i=0;i<persons;i++) {
	      	printf("Which Burger would you like (1, 2 or 3): ");
	      	scanf("%d", &b_choice);
	      	
	      	if(b_choice == 1){
	      		cost += burger_1;
	      		b1 += 1;
				  }
			
			else if(b_choice == 2){
	      		cost += burger_2;
	      		b2 += 1;
				  }
			
			else if(b_choice == 3){
	      		cost += burger_3;
	      		b3 += 1;
				  }
	   	   
	   	   	else {
				printf("\nNot an option, Goodbye...");
   				return 0;
				  }
			}
	   	   
	   	   	discount_amt = cost * 0.05;
	   	   	cost = cost - discount_amt;
   	}
   	
   	else {
   		printf("\nNot an option, Goodbye...");
   		return 0;
	   }
   	
   	system("cls");
   	
   	printf("\tSmash Burgers\n");
   	printf("---------------------------------\n");
	printf("\nGroup size: %d", persons);
	printf("\nNumber of Cheese and Bacon: %d", b1);
	printf("\nNumber of Classic Beef: %d",b2);
	printf("\nNumber of Sausage & Chicken: %d", b3);
	printf("\nDiscount: $%.2f", discount_amt);
	printf("\nGroup Cost: $%.2f", cost);

   
   	return 1;
}

