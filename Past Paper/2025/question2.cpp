
// You are developing a currency conversion system that should support multiple numeric types for representing monetary
// amounts, such as int, float, or double. The system must handle different currencies, including USD, EUR, and PKR, 
// and allow operations between them. You are required to define a Currency class that can store both an amount and 
// its associated currency code (e.g., “USD” , “PKR”). 
// The class should maintain a set of fixed exchange rates internally, assuming USD as the base currency.
// For this purpose, use the following conversion parameters:
// 1 USD = 1.00 USD (base)
// 1 EUR = 0.90 USD
// 1 PKR = 1 / 275.0 USD
// Write a function to perform addition between two different currencies, which first convert both currencies to a 
// common base currency (like USD) to perform the addition. After getting the result, show the final amount using the 
// base currency type as the first value in the expression. The system must also allow comparison of two currency values
//  by checking their equivalence in the base currency.

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

template <typename T>
class Currency{
    T amount;
    string code;

    public :
    Currency():amount(10.0),code("USD"){}
    Currency(T a,string c):amount(a),code(c){
        if(code=="usd" || code=="Usd" || code=="USD")
        amount = amount;

        else if(code=="eur" || code=="Eur" || code=="EUR")
        amount = (0.90 * amount);

        else if(code=="pkr" || code=="Pkr" || code=="PKR")
        amount = (double)a/(275.0);

        else{code = "USD";amount = amount;}

        code="USD";

    }

    void getData(){
        cout<<"Enter Amount : "; cin>>amount;
        cout<<"Enter Code   : "; cin>>code;

        if(code=="usd" || code=="Usd" || code=="USD")
        amount = amount;

        else if(code=="eur" || code=="Eur" || code=="EUR")
        amount = (0.90 * amount);

        else if(code=="pkr" || code=="Pkr" || code=="PKR")
        amount = ((1/275)*amount);

        else{code = "USD";amount = amount;}
    }

    void showData(){
        cout<<"Amount : "<<amount<<"$"<<endl;
    }


    Currency<T> operator + (const Currency<T> &obj) const{
        Currency <double> c;
        c.amount = amount + obj.amount;
        return c;
    }

    bool operator == (const Currency<T> &obj) const{
        if(amount==obj.amount){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    Currency <double>c1,c2,c3;
    c1.getData();
    c2.getData();
    c3 = c1 + c2;
    c1.showData();
    c2.showData();
    c3.showData();
    if(c1==c2){
        cout<<"Both currency have the same usd"<<endl;
    }
    else{
        cout<<"They do not have the same usd"<<endl;
    }
}
