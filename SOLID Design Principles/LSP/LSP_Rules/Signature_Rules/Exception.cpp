#include<bits/stdc++.h>
using namespace std;

// the child class can thow an exception to to exception of parent class or narrower

/*
├── std::logic_error        <-- For logical errors detected before runtime
│   ├── std::invalid_argument   <-- Invalid function argument
│   ├── std::domain_error       <-- Function argument domain error
│   ├── std::length_error       <-- Exceeding valid length limits
│   ├── std::out_of_range       <-- Array or container index out of bounds
│
├── std::runtime_error      <-- For errors that occur at runtime
│   ├── std::range_error        <-- Numeric result out of range
│   ├── std::overflow_error     <-- Arithmetic overflow
│   ├── std::underflow_error   
*/

class Parent {
public:
    virtual void getValue() noexcept(false) {
        throw logic_error("Parent exception");
    }
};


class Child : public Parent {
    void getValue() noexcept(false) override {
        throw out_of_range("Child exception");
    }
};

class Client : public Parent {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this -> p = p;
    }

    void takeValue() {
        try {
            p -> getValue();
        } catch (const logic_error& e) {
            cout << "Caught logic_error: " << e.what() << endl;
        }
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();
    Client* client = new Client(child);

    client->takeValue();
    delete parent;
    delete child;
    delete client;
    // Memory leak check
    return 0;
}