#include<bits/stdc++.h>
using namespace std;

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger {
    void prepare() {
        cout << "Preparing Basic Burger" << endl;
    }
};

class StandarBurger : public Burger {
    void prepare() {
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger {
    void prepare() {
        cout << "Preparing Premium Burger" << endl;
    }
};

class BurgerFactory {
public:
    Burger* createBurger(string& type) {
        if (type == "Basic") return new BasicBurger();
        else if (type == "Standard") return new StandarBurger();
        else if (type == "Premium") return new PremiumBurger();
        else {
            cout << "Invalid Burger Type" << endl;
            return nullptr;
        }
    }
};

int main() {
    string type = "Standard";
    BurgerFactory* factory = new BurgerFactory();
    Burger* burger =  factory -> createBurger(type);

    burger -> prepare();
    delete burger;

    return 0;
}