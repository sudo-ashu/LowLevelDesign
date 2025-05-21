#include<bits/stdc++.h>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape {
private:
    double side;
public:
    // Constructor
    Square(double s) : side(s) {}


    double area() override {
        return side * side;
    }

    double volume() override {
        throw logic_error("Volume not applicable for Square"); // Unnecessary method
    }

};

class Rectangle : public Shape {
private:
    double length;
    double breadth;    
public:
    // Constructor
    Rectangle(double l, double b) : length(l), breadth(b) {}


    double area() override {
        return length * breadth;
    }

    double volume() override {
        throw logic_error("Volume not applicable for Rectangle"); // Unnecessary method
    }
};

class Cube : public Shape {
private:
    double side;
public:
    // Constructor
    Cube(double s) : side(s) {}

    double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }

};


int main () {
    Shape* square = new Square(5);
    Shape* rectangle = new Rectangle(4, 5);
    Shape* cube = new Cube(3);

    cout << "Area of Square: " << square->area() << endl;
    cout << "Area of Rectangle: " << rectangle->area() << endl;
    cout << "Area of Cube: " << cube->area() << endl;
    
    cout << "Volume of Cube: " << cube->volume() << endl;


    try {
        cout << "Square volume: " << square->volume() << endl; // This will throw an error
    } catch (const logic_error& e) {
        cout << "Exception: " << e.what() << endl; // Handle the error

    }
    
    return 0;
}

