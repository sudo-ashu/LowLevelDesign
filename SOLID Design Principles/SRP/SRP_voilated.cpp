#include<bits/stdc++.h>
using namespace std;


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

    //2. SRP Violated: This method is responsible for printing the invoice.
    void printInvoice() {
        cout << "Invoice: " << endl;
        for (auto product: products) {
            cout<< product -> name << " : " << product -> price << " $" << endl;
        }
        cout << "Total price: " << calcTotalPrice() << endl;

    }
    //3. SRP Violated: This method is responsible for saving the cart to a database.
    // This is a violation of the Single Responsibility Principle (SRP) because this method is not related to the cart's primary responsibility.
    void saveToDB() {
        // Simulating saving to a database
        cout << "Saving cart to database..." << endl;
        for (auto product: products) {
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
    cart -> printInvoice();
    cart -> saveToDB();
    delete cart;
    return 0;
    // The code is not following the Single Responsibility Principle (SRP)
}