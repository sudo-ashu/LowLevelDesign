#include<bits/stdc++.h>
using namespace std;


// Liskov Substitution Principle (LSP) is followed 


class DepositOnlyAccount {
public:
    virtual void deposit(int ammount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(int ammount) = 0; 
};



class SavingsAccount : public WithdrawableAccount {
private:
    int balance;
public:
    SavingsAccount() {
        balance = 0;
    }

    void deposit(int deposit) override {
        balance += deposit;
        cout << balance << " $ deposited to Savings account ";
        cout << "Total balance: " << balance << endl;
    }

    void withdraw(int withdraw) override {
        if (withdraw >= balance) {
            cout << "Insufficient funds" << endl;
            return;
        }
        balance -= withdraw;
        cout << withdraw << " $ withdrawn from Savings account ";
        cout << "Total balance: " << balance << endl;
    }
};

class CurrentAccount : public WithdrawableAccount {
private: 
    int balance;
public:
    CurrentAccount() {
        balance = 0;
    }

    void deposit(int deposit) override {
        balance += deposit;
        cout << balance << " $ deposited to Current account ";
        cout << "Total balance: " << balance << endl;
    }

    void withdraw(int withdraw) override {
        if (withdraw >= balance) {
            cout << "Insufficient funds" << endl;
            return;
        }
        balance -= withdraw;
        cout << withdraw << " $ withdrawn from Current account ";
        cout << "Total balance: " << balance << endl;
    }
};

class FixedTermAccount : public DepositOnlyAccount {
private:
    int balance;
public:
    FixedTermAccount() {
        balance = 0;
    }

    void deposit(int deposit) override {
        balance += deposit;
        cout << balance << " $ deposited to Fixed-Term account ";
        cout << "Total balance: " << balance << endl;
    }
};


class Client {
private:
    vector<DepositOnlyAccount*> depositAccounts;
    vector<WithdrawableAccount*> withdrawAccounts;

public:   
    Client ( vector<WithdrawableAccount*> withdrawAccounts, vector<DepositOnlyAccount*> depositAccounts) {
        this -> withdrawAccounts = withdrawAccounts;
        this -> depositAccounts = depositAccounts;

    }

    void transactionProcessor() {
        for (WithdrawableAccount* account: withdrawAccounts) {
            account -> deposit(1000);
            account -> withdraw(500);
        }

        for (DepositOnlyAccount* account: depositAccounts)
            account -> deposit(7000);
    }
};


int main() {
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingsAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    
    // withdrawableAccounts.push_back(new FixedTermAccount());
    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());
    
    Client* client = new Client(withdrawableAccounts, depositOnlyAccounts);
    client -> transactionProcessor();
    

    return 0;
}