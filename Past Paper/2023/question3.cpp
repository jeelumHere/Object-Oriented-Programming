// You're developing a software application to model shapes with a base 
// class called Shape representing common properties and behaviours like
//  calculating area and perimeter. Each specific shape, such as Rectangle
//  or Triangle, has its own formula for area and perimeter calculation. 
// Using pure virtual functions, every derived class of Shape must implement 
// calculateArea() and calculatePerimeter(). This allows you to create objects,
//  invoke their behaviours, and get accurate results. You can use any formula 
// to calculate are or perimeter if you don’t know exact one. 

#include <iostream>
#include <cmath> // for sqrt()
using namespace std;

class Shape {
public:
    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;
    virtual ~Shape() {} // always add virtual destructor in base class
};

class Rectangle : public Shape {
    double length;
    double width;

public:
    void input() {
        cout << "Enter length : "; cin >> length;
        cout << "Enter width  : "; cin >> width;
    }

    void calculateArea() override {
        cout << "Area of Rectangle      : " << (length * width) << endl;
    }

    void calculatePerimeter() override {
        cout << "Perimeter of Rectangle : " << 2 * (length + width) << endl;
    }
};

class Triangle : public Shape {
    double base;
    double height;
    double side; // third side (slant), needed for perimeter

public:
    void input() {
        cout << "Enter base   : "; cin >> base;
        cout << "Enter height : "; cin >> height;
        // Compute hypotenuse as the third side (right triangle assumption)
        side = sqrt((base * base) + (height * height));
    }

    void calculateArea() override {
        cout << "Area of Triangle      : " << (0.5 * base * height) << endl;
    }

    void calculatePerimeter() override {
        // Perimeter = base + height + hypotenuse
        cout << "Perimeter of Triangle : " << (base + height + side) << endl;
    }
};

int main() {
    Shape *ptr;

    Triangle t;
    t.input();
    ptr = &t;
    ptr->calculateArea();
    ptr->calculatePerimeter();

    cout << endl;

    Rectangle r;
    r.input();
    ptr = &r;
    ptr->calculateArea();
    ptr->calculatePerimeter();

    return 0;
}