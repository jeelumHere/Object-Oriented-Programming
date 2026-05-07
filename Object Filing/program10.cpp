
// 01) exception handling
// 02) File handling

/*
<<<<-----File Handling----->>>>>
1- craetion of file
2- open the file
3- reading , writing , searching , updating , deletion
4- closing the file
*/

// 1- fstreamm
// for reading we use ios::in
// for writing we use ios::out

#include<iostream>
#include<fstream>
using namespace std;

class Student{
    int id;
    char name[20];

    public : 
    void getData(){
        cout<<"Enter name : ";cin>>name;
        cout<<"Id : ";cin>>id;
    }

    void showData(){
        cout<<"Name : "<<name<<endl;
        cout<<"Id : "<<id<<endl;
    }

    void writeData(){
        fstream file; // craetion
        file.open("file.txt",ios::out | ios::app | ios::binary);  // file opening

        if(!file){
            cout<<"File does not exist"<<endl;
            return;
        }
        else{
            getData();
            file.write((char*)this,sizeof(*this)); 
            showData();
        }
        file.close();  // closing the file

    }

    void readData(){
        fstream file;
        file.open("file.txt",ios::in | ios::binary);  // file reading

        if(!file){
            cout<<"File not found"<<endl;
            return;
        }

        else{
            while(file.read((char*)this,sizeof(*this))){
                showData();
            }
        }
        file.close();
    }

    void searchData(){
        fstream file;
        file.open("file.txt",ios::in | ios::binary);

        if(!file){
            cout<<"File does not exist"<<endl;
            return;
        }

        else{
            cout<<"Enter id to search student : "; int sid; cin>>sid;
            while(file.read((char*)this,sizeof(*this))){
                if(id==sid){
                    showData();
                }
            }
        }
        file.close();
    }
};

int main(){
    Student s1;
    s1.searchData();
}