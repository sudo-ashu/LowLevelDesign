#include<bits/stdc++.h>
#include<mutex>

using namespace std;


class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() {
        cout << "singleton constructor called, new object created" << endl;
    }

public:
    //double checking
    static Singleton* getInstance () {
        if(instance == nullptr) {
            lock_gaurd<mutex> lock(mtx);

            if(instance == nullptr)
                instance = new Singleton();
        }   
        return instance;

    }

};


//initialize a static member
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* ob1 = Singleton::getInstance();
    Singleton* ob2 = Singleton::getInstance();

    cout << (ob1 == ob2) << endl;

    return 0;
}
