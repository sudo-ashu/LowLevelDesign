#include<bits/stdc++.h>
using namespace std;



// Liskov Substitution Principle (LSP) Violated Example


class Account {
public:
    virtual void deposit(int ammount) = 0;
    virtual void withdraw(int ammount) = 0; 
};




class SavingsAccount : public Account {
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

class CurrentAccount : public Account {
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

class FixedTermAccount : public Account {
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

    void withdraw(int withdraw) override {
        throw logic_error("Cannot withdraw from Fixed-Term account");
    }
};


class Client {
private:
    vector<Account*> accounts;

public:   
    Client (vector<Account*> accounts) {
        this -> accounts = accounts;

    }

    void transactionProcessor() {
        for (Account* account: accounts) {
            account -> deposit(1000);
            
            //assuming all accounts have the same withdraw amount
            
            try {
                account -> withdraw(500);
            } catch (logic_error& e) {
                cout << e.what() << endl;
            }
        }
    }
};


int main() {
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());
    
    
    Client* client = new Client(accounts);
    client -> transactionProcessor();
    

    return 0;
}