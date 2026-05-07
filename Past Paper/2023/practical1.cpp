// You have a class named as ABC, a user is interested to store the data of few
// objects of this class to a file named as myFile.dat. The user may enter 
// data of as many objects he want to save to the file in an append mode.
// Write the required code to store data of objects to a file. One of the 
// class data member is objectID. 

#include<iostream>
#include<fstream>
using namespace std;

class ABC{
    int objectID;
    string ObjectName;

    public : 
    void getData(){
        cout<<"Enter object id : "; cin>>objectID;
        cout<<"Enter object name : ";cin>>ObjectName;
    }
    void showData(){
        cout<<"Id   : "<<objectID<<endl;
        cout<<"Name : "<<ObjectName<<endl;
    }
    void writeData(){
        fstream file;
        file.open("file.txt",ios::app|ios::out);
        ABC obj;
        obj.getData();
        file.write(reinterpret_cast<char*>(&obj),sizeof(ABC));
        obj.showData();
        file.close();
    }
};

int main(){
    bool con = true;
    ABC object;
    while(con){
        cout<<"Enter 1 to eneter object data : "<<endl;
        cout<<"Enter 2 exit the program : "<<endl;
        cout<<"Enter choice : "; int choice;
        cin>>choice;
        if(choice==1)
        object.writeData();
        else if(choice==2)
        con = false;
    }
}