/*
You are required to create a class template in C++ to calculate the area of a triangle given its three sides. The sides of the triangle can be of different numeric types such as integers, floats, or doubles. calcArea() function should be non inline function of the class. Main function is also required which shows multiple instances of class template. The formula to calculate the area is based on Heron’s formula:
*/

#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class Area {
    T a, b, c;

public:
    Area(T a, T b, T c) : a(a), b(b), c(c) {}

    void input(T a, T b, T c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    bool isValidTriangle() {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    // Non-inline: defined outside the class body below
    void calcArea();
};

// ✅ Non-inline definition outside the class
template <class T>
void Area<T>::calcArea() {
    if (!isValidTriangle()) {
        cout << "Invalid triangle with sides ("
             << a << ", " << b << ", " << c << ")" << endl;
        return;
    }

    double s = (a + b + c) / 2.0;          // semi-perimeter
    double res = s * (s-a) * (s-b) * (s-c);
    cout << "Sides (" << a << ", " << b << ", " << c << ")"
         << "  =>  Area = " << sqrt(res) << endl;
}

int main() {
    Area<int>    a1(3, 4, 5);          // classic right triangle
    Area<int>    a2(10, 13, 4);        // valid int triangle
    Area<float>  a3(5.5f, 6.5f, 7.0f);// float sides
    Area<double> a4(10.10, 13.34, 4.5);// double sides
    Area<int>    a5(10, 13, 40);       // invalid triangle

    a1.calcArea();
    a2.calcArea();
    a3.calcArea();
    a4.calcArea();
    a5.calcArea();

    return 0;
}