#include<iostream>
using namespace std;

class Number{
    int a1;
    float b1;
    char c1;

    public : 
    Number(int a1){
        this->a1 = a1;
        this->b1 = 10.00;
        this->c1 = '.';
    }
    Number(float b1){
        this->a1 = 10;
        this->b1 = b1;
        this->c1 = '.';

    }
    Number(char c1){
        this->a1 = 10;
        this->b1 = 10.00;
        this->c1 = c1;
    }

    void show() const{
        cout<<"Value 1 : "<<a1<<endl;
        cout<<"Value 2 : "<<b1<<endl;
        cout<<"Value 3 : "<<c1<<endl;
    }
};

int main(){
    int a = 100;
    float b = 100.100;
    char c = 's';

    Number n1 = a;
    Number n2 = b;
    Number n3 = c;

    n1.show();
    n2.show();
    n3.show();
}