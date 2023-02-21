#include <stdio.h>

int main() {
    int sally_balance = 125000, notes_5k = 20, notes_1k = 25, withdrawal_amount, num_5k_notes, num_1k_notes, choice;
    
    
    printf("Enter the amount you would like to withdraw: ");
    scanf("%d", &withdrawal_amount);
    
    if (withdrawal_amount > sally_balance) {
        printf("Insufficient funds. Your balance is %d\n", sally_balance);
    } 
	else {
        printf("How would you like to receive your money? Enter 1 for $5,000 notes, 2 for $1,000 notes: ");
        scanf("%d", &choice);
        if (choice == 1) {
            num_5k_notes = withdrawal_amount / 5000;
            num_1k_notes = (withdrawal_amount % 5000) / 1000;
        } else {
            num_1k_notes = withdrawal_amount / 1000;
            num_5k_notes = (withdrawal_amount % 1000) / 5000;
        }
        printf("You will receive %d $5,000 notes and %d $1,000 notes.\n", num_5k_notes, num_1k_notes);
        notes_5k -= num_5k_notes;
        notes_1k -= num_1k_notes;
        sally_balance -= withdrawal_amount;
        printf("Your remaining balance is %d, with %d $5,000 notes and %d $1,000 notes.\n", sally_balance, notes_5k, notes_1k);
    }
    
    return 0;
}

