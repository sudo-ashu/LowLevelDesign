#include<bits/stdc++.h>
using namespace std;

// Class Invariant of a parent class Object should not be broken by child class Object.
// Hence child class can either maintain or strengthen the invariant but never narrows it down.

//Invariant : Balance cannot be negative
class BankAccount {
protected:
    double balance;
public:
    BankAccount(double initialBalance) : balance(initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
        balance = initialBalance;
    }

    virtual void withdraw(double amount) {
        if (amount < 0) {
            throw invalid_argument("Withdrawal amount cannot be negative");
        }
        if (balance - amount < 0) {
            throw invalid_argument("Insufficient funds");
        }
        balance -= amount;
    }
};

//Brakse invariant: Should not be allowed
class CheatAccount : public BankAccount {
public:
    CheatAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override {
        // This violates the invariant of the parent class
        // Allowing negative balance
        balance -= amount;
        cout << "CheatAccount: Withdrawn " << amount << ", new balance: " << balance << endl;
    }

};


int main () {
    BankAccount* backAccount = new BankAccount(100);
    // backAccount->withdraw(500);

    CheatAccount* cheatAccount = new CheatAccount(100);
    cheatAccount->withdraw(500); // This should not be allowed as it breaks the invariant
    delete backAccount;
    delete cheatAccount;
    return 0;
}