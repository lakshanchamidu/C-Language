#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char accountHolderName[100];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("\nMaximum account limit reached.\n");
        return;
    }

    BankAccount newAccount;
    newAccount.accountNumber = accountCount + 1;

    printf("\nEnter account holder name: ");
    scanf("%s", newAccount.accountHolderName);

    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("\nAccount created successfully. Account Number: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("\nInvalid account number.\n");
        return;
    }

    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    accounts[accountNumber - 1].balance += amount;

    printf("\nAmount deposited successfully. New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("\n\nEnter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("\nInvalid account number.\n");
        return;
    }

    printf("\n\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (accounts[accountNumber - 1].balance < amount) {
        printf("\nInsufficient balance.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;

    printf("\nAmount withdrawn successfully. New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void displayAccountDetails() {
    int accountNumber;

    printf("\n\nEnter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("\nInvalid account number.\n");
        return;
    }

    printf("\n\nAccount Number: %d\n", accounts[accountNumber - 1].accountNumber);
    printf("\nAccount Holder Name: %s\n", accounts[accountNumber - 1].accountHolderName);
    printf("\nBalance: %.2f\n", accounts[accountNumber - 1].balance);
}

int main() {
    int choice;

    while (1) {
        printf("\n\n     Welcome to Bank Management System\n\n");
        printf("\n               Menu Option\n\n");
        printf("01.  Create a New Account.");
        printf("\n02.  Depositing Money.");
        printf("\n03.  Withdrawal Money.");
        printf("\n04.  Display the Account Details.");
        printf("\n05.  Exit the System.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                displayAccountDetails();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
