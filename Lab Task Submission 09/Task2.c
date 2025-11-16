#include <stdio.h>

void deposit(float *ptr, int accNo, float amount)
{
    *(ptr + accNo) += amount; 
    printf("\nDeposited %.2f to account %d", amount, accNo + 1);
}

void withdraw(float *ptr, int accNo, float amount)
{
    if (*(ptr + accNo) < amount)
    {
        printf("\nInsufficient Balance!");
        return;
    }
    *(ptr + accNo) -= amount;
    printf("\nWithdrawn %.2f from account %d", amount, accNo + 1);
}

float averageBalance(float *ptr)
{
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += *(ptr + i);
    }
    return sum / 5;
}

void display(float *ptr)
{
    printf("\n---- Account Balances ----\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Account %d: %.2f\n", i + 1, *(ptr + i));
    }
}

int main()
{
    float balance[5] = {1000, 1500, 2000, 800, 1200};

    int choice, accNo;
    float amount;

    do
    {
        printf("\n\n--- Bank Menu ---");
        printf("\n1. Deposit");
        printf("\n2. Withdraw");
        printf("\n3. Display All Balances");
        printf("\n4. Show Average Balance");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter account number (1-5): ");
                scanf("%d", &accNo);
                accNo--;
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(balance, accNo, amount);
                break;
            case 2:
                printf("Enter account number (1-5): ");
                scanf("%d", &accNo);
                accNo--;
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(balance, accNo, amount);
                break;
            case 3:
                display(balance);
                break;
            case 4:
                printf("\nAverage Balance = %.2f", averageBalance(balance));
                break;
            case 0:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid Choice!");
                break;
        }
    } while (choice != 0);

    return 0;
}
