#include<bits/stdc++.h>
using namespace std;


// Abstract Burger
class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};


//Concrete Burgers
class BasicBurger : public Burger {
    void prepare() override{
        cout << "Preparing Basic Burger" << endl;
    }
};

class StandarBurger : public Burger {
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger {
    void prepare() override{
        cout << "Preparing Premium Burger" << endl;
    }
};

class BasicWheatBurger : public BasicBurger {
    void prepare() override{
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};

class StandardWheatBurger : public StandarBurger {
    void prepare() override{
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};

class PremiumWheatBurger : public PremiumBurger {
    void prepare() override{
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};

// Abstract Factory Pattern
class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
};


// Concrete Factories
class SinghBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "Basic") return new BasicBurger();
        else if (type == "Standard") return new StandarBurger();
        else if (type == "Premium") return new PremiumBurger();
        else {
            cout << "Invalid Burger Type" << endl;
            return nullptr;
        }
    }
};

class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if( type == "Basic") return new BasicWheatBurger();
        else if (type == "Standard") return new StandardWheatBurger();
        else if (type == "Premium") return new PremiumWheatBurger();
        else {
            cout << "Invalid Burger Type" << endl;
            return nullptr;
        }
    }
};


int main() {
    string type = "Premium";
    BurgerFactory* factory = new KingBurger();
    Burger* burger = factory -> createBurger(type);
    

    burger -> prepare();
    delete burger;

    return 0;
}