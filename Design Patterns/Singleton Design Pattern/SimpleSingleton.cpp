#include<bits/stdc++.h>
using namespace std;


class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "singleton constructor called, new object created" << endl;
    }

public:

    static Singleton* getInstance () {
        if(instance == nullptr)
            instance = new Singleton();
        
        return instance;

    }

};


//initialize a static member
Singleton* Singleton::instance = nullptr;


int main() {
    Singleton* ob1 = Singleton::getInstance();
    Singleton* ob2 = Singleton::getInstance();

    cout << (ob1 == ob2) << endl;

    return 0;
}
