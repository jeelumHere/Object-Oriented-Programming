
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

class Exception{

    public : 

    double value;
    string err;
    string location;

    Exception(){}
    Exception(double value,string err, string location):value(value),err(err),location(location){}

};

template <class t>
class Coordinates{
    t x,y;

    public : 
    Coordinates():x(10),y(10){}

    Coordinates(t x, t y):x(x),y(y){
        if(x<0 || y<0){
            int a;
            x<0? a = x : a = y;
            throw Exception(a,"-ive value found","Constructor");
        }
    }

    void input(t x1, t y1){
        x = x1;
        y = y1;
        if(x<0 || y<0){
            t a;
            a = x<0? x : y;
            Exception e(a,"-ive value found","input function.");
            writeException(e);
            throw e;
        }
    }

    void writeException(Exception& e){
        fstream file;
        file.open("ExceptionReport.dat",ios::binary | ios::out);
        if(!file){
            cout<<"File does not exist"<<endl;
            return;
        }
        else{
            file.write(reinterpret_cast<char*>(&e) , sizeof(Exception));
        }
    };

    void readException(){
        int count = 0;
        fstream file;
        file.open("ExceptionReport.dat",ios::binary | ios::in);
        if(!file){
            cout<<"File does not exist"<<endl;
            return;
        }
        else{
            Exception obj;
            while(file.read(reinterpret_cast<char*>(&obj),sizeof(Exception)));
            {
                cout<<"value : "<<obj.value<<endl;
                cout<<"Error : "<<obj.err<<endl;
                cout<<"Locat : "<<obj.location<<endl;
                if(obj.location=="Constructor"){
                    count++;
                }
            }
        }
        file.close();
        if(count==0)
        cout<<"No -ive in constructor"<<endl;
    else{
        cout<<"-ive vallue found in constructor : "<<count<<endl;
    }
    }
};

int main(){
    try{
        Coordinates <float> c1;
        c1.readException();
        c1.input(-10.45,-45.87);
    }
    catch(Exception& e){
        cout<<"Value : "<<e.value<<endl;
        cout<<"Error : "<<e.err<<endl;
        cout<<"Location : "<<e.location<<endl;
    }
    catch(...){
        cout<<"Default Exception."<<endl;
    }
    
}
