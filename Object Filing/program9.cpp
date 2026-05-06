// ifstream   reading
// ofstream   writing
// fstream   reading and writing


// 1) create file  
// 2) open file
// 3) read write search file
// 4) file close


#include<iostream>
#include<fstream>  // header file for file handling
using namespace std;

class Laptop{
    string name;
    string model;
    double price;

    public : 
    void input(){
        cout<<"Enter name : "; cin>>name;
        cout<<"Enter model : "; cin>>model;
        cout<<"Enter price : "; cin>>price;
    }

    void show(){
        cout<<"Name : "<<name<<endl;
        cout<<"Model : "<<model<<endl;
        cout<<"Price : "<<price<<endl;
    }

    void writeData(){
        ofstream file;
        file.open("file.txt",ios::app | ios::binary);

        if(!file){
            cout<<"File not found"<<endl;
            return ;
        }

        else{
            input();
            file.write((char*)this,sizeof(*this));
            file.close();
        }
    }


    void readData(){
        fstream file;
        file.open("file.txt",ios::binary | ios::in);
        if(!file){
            cout<<"Error in file loading!"<<endl;
        }
        else{
            while(!file.eof()){
                file.read((char*)this , sizeof(*this));
                show();
            }
        }
        file.close();
    }
};

int main(){
    Laptop lt1;
    lt1.readData();
}
