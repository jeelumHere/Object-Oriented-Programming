#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student{
    int rollNo;
    char name[30];

    public : 
    void getData(){
        cout<<"Enter Roll number : "; cin>>rollNo;
        cin.ignore();
        cout<<"Enter name : "; cin.getline(name,30);
    }
    
    void showData(){
        cout<<"Name : "<<name<<endl;
        cout<<"Roll number : "<<rollNo<<endl;
    }

    void writeData(){
        getData();
        fstream file;
        file.open("file.txt",ios::out | ios::binary | ios::app);
        if(!file){
            cout<<"File not found"<<endl;
        }
        else{
            file.write((char*)this , sizeof(*this));
            cout<<"Data added successfully.";
        }
        file.close();
    }

    void readData(){
        fstream file;
        file.open("file.txt",ios::binary | ios::in);
        if(!file){
            cout<<"Error in file loading!"<<endl;
        }
        else{
            file.read((char*)this , sizeof(*this));
            while(!file.eof()){
                file.read((char*)this , sizeof(*this));
                showData();
            }
        }
        file.close();
    }

    void updateData(){
        cout<<"Enter roll number : "; int r; cin>>r;
        fstream file;
        file.open("file.txt",ios::in | ios::binary | ios:: out);
        if(!file){
            cout<<"file not found"<<endl;
        }
        else{
            file.read((char*)this , sizeof(*this));
            while(!file.eof())
            {
                if(r==rollNo){
                   streampos repos = file.tellg();
                   int size = sizeof(*this);
                   file.seekp((int) repos - size);
                   getData();
                   file.write((char*)this , sizeof(*this));
                   break;
                }
                file.read((char*)this , sizeof(*this));
            }
        }
        file.close();
        
    }

    void deleteData(){
        fstream file;
        file.open("file.txt",ios::in |ios::binary);
        fstream tempFile;
        tempFile.open("tempfile.txt",ios::out | ios::binary | ios::app);
        if(!file || !tempFile){
            cout<<"Error in loading file"<<endl;
        }
        else{
            cout<<"Enter roll number : "; int r; cin>>r;
            file.read((char*)this , sizeof(*this));
            while(!file.eof()){
                if(r==rollNo){
                    cout<<"File founded and deleted."<<endl;
                }
                else{
                    tempFile.write((char*)this , sizeof(*this));
                }
                file.read((char*)this , sizeof(*this));
            }
        }
        file.close();
        tempFile.close();
        remove("file.txt");
        rename("tempfile.txt","file.txt");
    }
};

int main(){
    Student s1;
    s1.readData();
    s1.updateData();
    s1.deleteData();
}
