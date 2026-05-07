// You are developing a math library for a school project in C++. The library includes a 
// complex number class to perform arithmetic operations on complex numbers. Complex numbers
// have both real and imaginary parts, and it is essential to provide a convenient way for
// students to perform addition, subtraction, multiplication, and division operations on 
// these numbers. To achieve this, you decide to utilize operator overloading, which 
// allows the use of familiar operators such as +, -, *, and / with complex numbers.

#include <iostream>
using namespace std;

template <class T>
class Complex {
    T real;
    T img;

public:
    // Default : 0 + 0i  (mathematically correct default)
    Complex() : real(0), img(0) {}
    Complex(T real, T img) : real(real), img(img) {}

    // ── Display ───────────────────────────────────────────
    void showComplex() const {
        if (img < 0)
            cout << real << " - " << -img << "i" << endl;
        else
            cout << real << " + " << img << "i" << endl;
    }

    // ── Addition : (a+bi) + (c+di) = (a+c) + (b+d)i ─────
    Complex<T> operator+(const Complex<T>& obj) const {
        return Complex<T>(real + obj.real, img + obj.img);
    }

    // ── Subtraction : (a+bi) - (c+di) = (a-c) + (b-d)i ──
    Complex<T> operator-(const Complex<T>& obj) const {
        return Complex<T>(real - obj.real, img - obj.img);
    }

    // ── Multiplication : (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    Complex<T> operator*(const Complex<T>& obj) const {
        T r = (real * obj.real) - (img * obj.img);
        T i = (real * obj.img) + (img * obj.real);
        return Complex<T>(r, i);
    }

    // ── Division : (a+bi)/(c+di) = ((ac+bd) + (bc-ad)i) / (c²+d²)
    Complex<T> operator/(const Complex<T>& obj) const {
        T denominator = (obj.real * obj.real) + (obj.img * obj.img);
        T r = ((real * obj.real) + (img * obj.img)) / denominator;
        T i = ((img * obj.real) - (real * obj.img)) / denominator;
        return Complex<T>(r, i);
    }
};

int main() {
    Complex<double> c1(12.34, 6.45);
    Complex<double> c2(10.38, 8.98);
    Complex<double> c3;

    cout << "c1 = "; c1.showComplex();
    cout << "c2 = "; c2.showComplex();
    cout << endl;

    c3 = c1 + c2;
    cout << "Addition       : "; c3.showComplex();

    c3 = c1 - c2;
    cout << "Subtraction    : "; c3.showComplex();

    c3 = c1 * c2;
    cout << "Multiplication : "; c3.showComplex();

    c3 = c1 / c2;
    cout << "Division       : "; c3.showComplex();

    return 0;
}