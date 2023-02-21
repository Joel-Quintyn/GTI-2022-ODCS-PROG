#include <stdio.h>
#include <string.h>

struct Customer
{
    char name[100];
    char id[20];
    char email[100];
    char username[50];
    char password[50];
    double balance;
};

void get_customer_info(struct Customer *customer)
{
    printf("Enter your name: ");
    fgets(customer->name, 100, stdin);
    // scanf("%s", customer->name);
    printf("Enter your ID: ");
    fgets(customer->id, 20, stdin);
    printf("Enter your email: ");
    fgets(customer->email, 100, stdin);
    printf("Enter a username: ");
    fgets(customer->username, 50, stdin);
    printf("Enter a password: ");
    fgets(customer->password, 50, stdin);
}

int authenticate_customer(struct Customer *customer)
{
    char id[20], password[50];
    printf("Enter your ID: ");
    fgets(id, 20, stdin);
    // scanf("%s", id);
    printf("Enter your password: ");
    fgets(password, 50, stdin);
    // scanf("%s", password);
    if (strcmp(customer->id, id) == 0 && strcmp(customer->password, password) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double calculate_savings_interest(double balance)
{
    return balance * 0.035;
}

double calculate_government_tax(double balance)
{
    return balance * 0.015;
}

double apply_government_tax(double balance)
{
    double tax = calculate_government_tax(balance);
    return balance - tax;
}

int main()
{
    struct Customer customer;
    get_customer_info(&customer);
    printf("Your personal details:\n");
    printf("Name: %s", customer.name);
    printf("Email: %s", customer.email);
    printf("Username: %s", customer.username);

    printf("Enter a starting balance: ");
    scanf("%lf", &customer.balance);

    double savings_interest = calculate_savings_interest(customer.balance);
    printf("Savings interest: %.2f\n", savings_interest);

    double new_balance = customer.balance + savings_interest;
    printf("New balance before tax: %.2f\n", new_balance);

    double taxed_balance = apply_government_tax(new_balance);
    printf("Government tax: %.2f\n", calculate_government_tax(new_balance));
    printf("New balance after tax: %.2f\n", taxed_balance);

    int authenticated = authenticate_customer(&customer);
    if (authenticated)
    {
        printf("Welcome, %s!\n", customer.name);
    }
    else
    {
        printf("Authentication failed.\n");
    }

    return 0;
}
