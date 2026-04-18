#include<iostream>
using namespace std;

class Number{
    int a1;
    float b1;
    char c1;

    public : 
    Number():a1(10),b1(10.1010),c1('.'){}
    void setInt(int a1){
        this->a1 = a1;
    }
    void setFloat(float b1){
        this->b1 = b1;
    }
    void setChar(char c1){
        this->c1 = c1;
    }
    void getInt(){
        cout<<"Integer : "<<a1<<endl;
    }
    void getFloat(){
        cout<<"Float : "<<b1<<endl;
    }
    void getChar(){
        cout<<"Character : "<<c1<<endl;
    }

    operator int(){
        return a1;
    }
    operator float(){
        return b1;
    }
    operator char(){
        return c1;
    }
};

int main(){
    int a;
    float b;
    char c;
    Number n1;
    n1.setInt(10);
    n1.setChar('n');
    n1.setFloat(10.1010);

    a = n1;
    b = n1;
    c = n1;

    cout<<"Value 1 in class : ";
    n1.getInt();
    cout<<"Value 2 in class : ";
    n1.getFloat();
    cout<<"Value 3 in class : ";
    n1.getChar();
    cout<<"<<<<<<<<<---------->>>>>>>>"<<endl;
    cout<<"Value 1 in main : "<<a<<endl;
    cout<<"Value 2 in main : "<<b<<endl;
    cout<<"Value 3 in main : "<<c<<endl;
}