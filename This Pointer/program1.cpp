#include<iostream>
using namespace std;
// this pointer
// 1) It always points to the object data memebers or memebr function 
class Calculator{
    int a,b;

    public : 
    Calculator(int a,int b){
        this->a = a;   // this->a is pointing to the data member "a" of the class
        this->b = b;   // this->b is pointing to the data member "b" of the class
    }
};