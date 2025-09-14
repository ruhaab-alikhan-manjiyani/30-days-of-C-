#include <iostream>
#include <string>
#include <limits> 

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    BankAccount(const std::string& accNum, const std::string& holder, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful. New balance: " << balance << "\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << "\n";
        } else {
            std::cout << "Invalid or insufficient funds.\n";
        }
    }

    void showBalance() const {
        std::cout << "Account Balance: " << balance << "\n";
    }

    void showDetails() const {
        std::cout << "\nAccount Details:\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Account Holder: " << accountHolder << "\n";
        std::cout << "Balance: " << balance << "\n";
    }
};

template <typename T>
bool safeInput(T& var) {
    std::cin >> var;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    std::string accNum, holder;
    double initial;

    std::cout << "Welcome to the Bank Account Simulator\n";
    std::cout << "Enter account number: ";
    std::cin >> accNum;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix getline issue
    std::cout << "Enter account holder name: ";
    std::getline(std::cin, holder);

    std::cout << "Enter initial balance: ";
    while (!safeInput(initial) || initial < 0) {
        std::cout << "Invalid input. Enter a valid starting balance: ";
    }

    BankAccount account(accNum, holder, initial);

    int choice;
    do {
        std::cout << "\nMenu ~\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Account Details\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option (1-5): ";

        if (!safeInput(choice)) {
            std::cout << "Invalid input. Please enter a number (1-5).\n";
            continue;
        }

        double amount;
        switch (choice) {
            case 1:
                std::cout << "Amount to deposit: ";
                if (safeInput(amount)) {
                    account.deposit(amount);
                } else {
                    std::cout << "Invalid amount.\n";
                }
                break;

            case 2:
                std::cout << "Amount to withdraw: ";
                if (safeInput(amount)) {
                    account.withdraw(amount);
                } else {
                    std::cout << "Invalid amount.\n";
                }
                break;

            case 3:
                account.showBalance();
                break;

            case 4:
                account.showDetails();
                break;

            case 5:
                std::cout << "Thank you for using the Bank Account Simulator.\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}