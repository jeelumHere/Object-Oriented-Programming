/*
You are required to create a class template in C++ to calculate the area of a triangle given its three sides. The sides of the triangle can be of different numeric types such as integers, floats, or doubles. calcArea() function should be non inline function of the class. Main function is also required which shows multiple instances of class template. The formula to calculate the area is based on Heron’s formula:

*/
#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class Area {
    T a, b, c;
    double s;  // s should always be double, not T

public:
    Area(T a, T b, T c) : a(a), b(b), c(c) {}

    void input(T a, T b, T c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    bool isValid() {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    void calcSemiPerimeter() {
        s = (a + b + c) / 2.0;
    }

    void calcArea() {
        if (!isValid()) {
            cout << "Invalid triangle!" << endl;
            return;
        }
        calcSemiPerimeter();
        double res = s * (s-a) * (s-b) * (s-c);  // double, not T
        cout << "Area of triangle: " << sqrt(res) << endl;
    }
};

int main() {
    Area<double> a1(10.10, 13.34, 4.5);
    Area<float> a2(10.10, 13.34, 4.5);
    Area<int>    a3(10, 13, 4);

    a1.calcArea();
    a2.calcArea();
    a3.calcArea();
}