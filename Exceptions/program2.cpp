#include<iostream>
#include<string>
using namespace std;

class AccountSession{
public:
    double bal;

    AccountSession(double bal){
        this->bal = bal;
    }
};

class ATM{
    int cardNo;
    double balance;
    int pin;

public:

    ATM():cardNo(12345),balance(10000),pin(2007){}

    ATM(int cn,double b,int p){
        cardNo = cn;
        balance = b;
        pin = p;
    }

    void insertCard(){

        if(cardNo < 0)
            throw cardNo;

        string s ;
        s = to_string(cardNo);

        if(s.length() < 4)
            throw s;
    }

    void insertBalance(double b){

        balance = b;

        if(b < 0)
            throw AccountSession(b);
    }

    void withdraw(double amount){

        if(amount > balance)
            throw amount;

        if(amount <= 0)
            throw 'E';

        balance -= amount;
    }

    void Enterpin(int p){

        if(pin != p)
            throw "Wrong Pin";
    }

    void display(){
        cout<<"Balance = "<<balance<<endl;
    }
};

int main(){

    ATM atm;

    try{
        atm.insertCard();
        atm.insertBalance(23000);
        atm.withdraw(450);
        atm.Enterpin(20);
        atm.display();
    }

    catch(int err){
        cout<<"Integer Exception: "<<err<<endl;
    }

    catch(string err){
        cout<<"String Exception: "<<err<<endl;
    }

    catch(char err){
        cout<<"Char Exception: "<<err<<endl;
    }

    catch(double err){
        cout<<"Double Exception: Insufficient Balance "<<err<<endl;
    }

    catch(AccountSession err){
        cout<<"Object Exception: Negative Balance "<<err.bal<<endl;
    }

    catch(const char* err){
        cout<<"PIN Exception: "<<err<<endl;
    }

    catch(...){
        cout<<"Unknown Error"<<endl;
    }
}












