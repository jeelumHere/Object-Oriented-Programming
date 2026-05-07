
#include<iostream>
using namespace std;

template <class t>
class Currency{
    t usd;
    t pkr;
    t euro;

    public : 
    Currency(t usd){
        this->usd = usd;
        pkr =(1.0/(275.0 * usd));
        euro = (0.90*usd);
    }

    void AddCurrency(t curr1, t curr2){
        curr1 = 
    }
};