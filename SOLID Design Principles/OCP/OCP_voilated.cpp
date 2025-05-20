#include<bits/stdc++.h>
using namespace std;


// OCP Violated Example
// In this example, we have a Cart class that is responsible for managing products in the cart.

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
    Cart *cart;

public:
    InvoicePrinter(Cart *cart) {
        this->cart = cart;
    }

    // 2. This method is responsible for printing the invoice.
    void printInvoice()
    {
        cout << "Invoice: " << endl;
        for (auto product : cart->getProducts())
        {
            cout << product->name << " : " << product->price << " $" << endl;
        }
        cout << "Total price: " << cart->calcTotalPrice() << endl;
    }
};

// 3. ShoppingCartStorage: Only responsible for saving cart to DB
class saveToDB {
private:
    Cart* cart;
public:
    saveToDB(Cart* cart) {
        this -> cart = cart;
    }

    //now lets say we have to save our data to several databases
    void saveToLocal () {
        cout << "Saving cart to local database..." << endl;
    }

    void saveToCloud () {
        cout << "Saving cart to cloud database..." << endl;
    }

    void saveToMongo () {
        cout << "Saving cart to Mongo database..." << endl;
    }
};


int main() {
    Cart* cart = new Cart;
    cart -> addProduct(new Product("MacBook", 1000));
    cart -> addProduct(new Product("iPhone", 600));
    cart -> addProduct(new Product("iPad", 800));
    cart -> addProduct(new Product("Apple Watch", 400));

    cart -> calcTotalPrice();
    
    InvoicePrinter* printer = new InvoicePrinter(cart);
    printer -> printInvoice();

    saveToDB* db = new saveToDB(cart);
    db -> saveToLocal();
    db -> saveToCloud();
    db -> saveToMongo();

    // Clean up memory
    delete cart;
    delete printer;
    delete db;


    return 0;
}