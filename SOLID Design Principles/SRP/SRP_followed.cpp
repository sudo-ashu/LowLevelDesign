#include<bits/stdc++.h>
using namespace std;

// The code is following the Single Responsibility Principle (SRP)
// The Single Responsibility Principle (SRP) states that a class should have only one reason to change, meaning it should have only one job or responsibility.

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this -> name = name;
        this -> price = price;
    }
};

class Cart {
private:
    vector<Product*> products;

public:

    void addProduct(Product* product) {
        products.push_back(product);
    }

    const vector<Product*> getProducts() {
        return products;
    }
    
    //1. This method is responsible for calculating the total price of the products in the cart.
    double calcTotalPrice() {
        double totalPrice=0;
        for(auto product: products)
            totalPrice += product -> price;
        return totalPrice;
    }

};

class InvoicePrinter {
private:
    Cart* cart;

public:

    InvoicePrinter(Cart* cart) {
        this -> cart = cart;
    }

    //2. This method is responsible for printing the invoice.
    void printInvoice() {
        cout << "Invoice: " << endl;
        for (auto product: cart -> getProducts()) {
            cout<< product -> name << " : " << product -> price << " $" << endl;
        }
        cout << "Total price: " << cart -> calcTotalPrice() << endl;
    }
};


class saveToDB {
private:
    Cart* cart;
public:
    saveToDB(Cart* cart) {
        this -> cart = cart;
    }

    void saveToDataBase() {
        // Simulating saving to a database
        cout << "Saving cart to database..." << endl;
        for (auto product: cart -> getProducts()) {
            cout << "Saving product: " << product -> name << endl;
        }
    }

    
};


int main () {
    Cart* cart = new Cart;

    cart -> addProduct(new Product ("MacBook", 1000));
    cart -> addProduct(new Product ("iPhone", 800));
    cart -> addProduct(new Product ("iPad", 600));
    cart -> addProduct(new Product ("Apple Watch", 400));
    
    cart -> calcTotalPrice();
    
    InvoicePrinter* printer = new InvoicePrinter(cart);
    printer -> printInvoice();

    saveToDB * db = new saveToDB(cart);
    db -> saveToDataBase();
    delete printer;
    delete db;

    delete cart;
    return 0;
    // The code is following the Single Responsibility Principle (SRP)
}