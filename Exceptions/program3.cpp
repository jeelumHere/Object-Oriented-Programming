#include<iostream>
using namespace std;

class error{
    public : 
    string s ;
    error(string s)
    {
        this->s = s ;
    }
};

class setString{
    string str;
    public :
    setString(string str){
        this->str = str;
        if(str=="syed sharjeel ahmed")
        throw error(str);
    else{
        string s = "Write correct name";
        throw s;
    }
    }
};

int main(){
    try{
        setString s4("syed sharjeel ahmed");
    }
    catch(string err){
        cout<<"String exception : "<<err<<endl;
    }
    catch(error err){
        cout<<"Object exception : "<<err.s<<endl;
    }
    catch(...){
        cout<<"default error"<<endl;
    }
}


