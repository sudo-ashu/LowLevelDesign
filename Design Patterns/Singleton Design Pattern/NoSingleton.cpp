#include<bits/stdc++.h>
using namespace std;

class NoSingleton {
public:
    NoSingleton () {
        cout << "singleton contructor called. new object created." << endl;
    }
};

int main() {
    NoSingleton* ob1 = new NoSingleton;
    NoSingleton* ob2 = new NoSingleton;

    cout << (ob1 == ob2) << endl;
}