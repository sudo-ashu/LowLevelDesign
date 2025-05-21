#include<bits/stdc++.h>
using namespace std;

class Parent {
private:
    int x;
public:
    Parent() {
        x = 0;
    }

    virtual void func(int a) {
        cout << "Parent func called with " << a << endl;
    }
};


//here we are following the methoid argument rule of LSP

class Child : public Parent {
private:
    int y;
public:
    Child() {
        y = 0;
    }

    void func(int a) override {
        cout << "Child func called with " << a << endl;
    }
};

class Client : public Parent {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this -> p = p;
    }

    void printMsg() {
        p -> func(5);
    }

};


int main() {
    Parent* parent = new Parent();
    Parent* child = new Child();
    
    
    Client* client = new Client(child);
    client -> printMsg();
    
    return 0;
}