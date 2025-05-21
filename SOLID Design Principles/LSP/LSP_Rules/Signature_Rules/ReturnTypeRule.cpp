#include<bits/stdc++.h>
using namespace std;


class Animal {

};

class Dog : public Animal {

};

class Parent {
public:
    virtual Animal* getAnimal() {
        cout << "Parent: returning animal instance" << endl;
        return new Animal();
    }

};

class Child : public Parent {
public:
    Dog* getAnimal() override {
        cout << "Child: returning dog instance" << endl;
        return new Dog();
    }
};


class Client : public Parent {
private:
    Parent* p;
public:
    Client(Parent* p) {
        this -> p = p;
    }

    void  takeAnima() {
        p->getAnimal();
    }
};


int main() {
    Parent* parent = new Parent();
    Child* child = new Child();
    Client* c = new Client(child);
    c->takeAnima();

    return 0;
}