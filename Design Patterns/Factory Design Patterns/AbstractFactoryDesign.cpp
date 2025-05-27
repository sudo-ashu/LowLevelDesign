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

//Concrete GarlicBreads

class BasicGarlicBread : public Burger {
    void prepare() override {
        cout << "Preparing Basic Garlic Bread" << endl;
    }
};

class StandardGarlicBread : public Burger {
    void prepare() override {
        cout << "Preparing Standard Garlic Bread" << endl;
    }
};

class PremiumGarlicBread : public Burger {
    void prepare() override {
        cout << "Preparing Premium Garlic Bread" << endl;
    }
};

// Concrete WheatGarlicBreads

class BasicWheatGarlicBread : public BasicGarlicBread {
    void prepare() override {
        cout << "Preparing Basic Wheat Garlic Bread" << endl;
    }
};

class StandardWheatGarlicBread : public StandardGarlicBread {
    void prepare() override {
        cout << "Preparing Standard Wheat Garlic Bread" << endl;
    }
};

class PremiumWheatGarlicBread : public PremiumGarlicBread {
    void prepare() override {
        cout << "Preparing Premium Wheat Garlic Bread" << endl;
    }
};


// Abstract Factory Pattern
class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual Burger* createGarlicBread(string& type) = 0;
    virtual ~BurgerFactory() {}

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

    Burger* createGarlicBread(string& type) override {
        if (type == "Basic") return new BasicGarlicBread();
        else if (type == "Standard") return new StandardGarlicBread();
        else if (type == "Premium") return new PremiumGarlicBread();
        else {
            cout << "Invalid Garlic Bread Type" << endl;
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

    Burger* createGarlicBread(string& type) override {
        if (type == "Basic") return new BasicWheatGarlicBread();
        else if (type == "Standard") return new StandardWheatGarlicBread();
        else if (type == "Premium") return new PremiumWheatGarlicBread();
        else {
            cout << "Invalid Garlic Bread Type" << endl;
            return nullptr;
        }
    }
};


int main() {
    string garlicBreadType = "Premium";
    string burgerType = "Standard";


    BurgerFactory* kingFactory = new KingBurger();
    Burger* burger = kingFactory -> createBurger(burgerType);
    BurgerFactory* singhFactory = new SinghBurger();
    Burger* garlicBread = singhFactory -> createGarlicBread(garlicBreadType);

    garlicBread -> prepare();
    burger -> prepare();
    
    delete garlicBread;
    delete burger;
    delete kingFactory;
    delete singhFactory;
    cout << "Order Completed!" << endl;

    return 0;
}