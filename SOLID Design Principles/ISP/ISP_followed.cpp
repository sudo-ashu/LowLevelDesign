#include<bits/stdc++.h>
using namespace std;

class Shape_2d {
public:
    virtual double area() = 0;
};

class Shape_3d : public Shape_2d {
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape_2d {
private:
    double side;
public:
    // Constructor
    Square(double s) : side(s) {}


    double area() override {
        return side * side;
    }

};

class Rectangle : public Shape_2d {
private:
    double length;
    double breadth;    
public:
    // Constructor
    Rectangle(double l, double b) : length(l), breadth(b) {}


    double area() override {
        return length * breadth;
    }
};

class Cube : public Shape_3d {
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
    Shape_2d* square = new Square(5);
    Shape_2d* rectangle = new Rectangle(4, 5);
    Shape_3d* cube = new Cube(3);

    cout << "Area of Square: " << square->area() << endl;
    cout << "Area of Rectangle: " << rectangle->area() << endl;
    cout << "Area of Cube: " << cube->area() << endl;
    
    cout << "Volume of Cube: " << cube->volume() << endl;
    
    return 0;
}

