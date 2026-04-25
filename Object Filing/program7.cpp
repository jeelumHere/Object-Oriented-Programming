#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

class Student{
    int rollNo;
    string name;

    public : 

    void getData(){
        cout<<"Enter your roll number (max 4 digits) : "; cin>>rollNo;
        int len = to_string(rollNo).length();
        while(len>4){
            cout<<"Enter roll number again (max 4 digits) : ";cin>>rollNo;
            len = to_string(rollNo).length();
        }
        cin.ignore();
        cout<<"Enter your name : "; getline(cin,name);
        while(name.length()<=0){
        cout<<"Enter your name : "; getline(cin,name);
        }
    }

    void showData() const {
        cout<<"Roll Number : "<<rollNo<<"\t Name : "<<name<<endl;
    }    

    void writeData(){
        fstream file;
        file.open("file.txt",ios::out | ios::app);
        if(!file){
            cout<<"File not found"<<endl;
        }
        getData(); // Get data frm the user.
        file<<rollNo<<"\t"<<name<<endl; // save input in the file.txt
        showData(); // show data to user on console
        file.close(); // closing file always remember it.
    }

    void readData(){
        int count = 0 ;
        fstream file;
        file.open("file.txt",ios::in);
        if(!file){
            cout<<"file not found"<<endl;
        }
        while(file>>rollNo){
            file.ignore();
            getline(file,name);
            showData();
            count++;
        }
        count==0 ? cout<<"No records found!!"<<endl : cout<<"Total Records : "<<count<<endl;

        file.close();
    }

    void searchData(){
        fstream file;
        file.open("file.txt",ios::in);
        if(!file)
        cout<<"File not found"<<endl;
        int r;
        int count = 0;
        cout<<"Enter roll number to search : ";
        cin>>r;
        while(file>>rollNo){
            file.ignore();
                getline(file,name);
                if(rollNo==r){
                cout<<"Data Found !!!"<<endl;
                showData();
                count++;
            }
        }
        if(count==0)
            cout<<"No records matched : "<<endl;
        else{
            cout<<"Total records matched : "<<count<<endl;
        }
        file.close();
    }

    void updateData(){
        int count = 0;
        fstream file;
        fstream tempFile;
        file.open("file.txt",ios::in);
        tempFile.open("tempFile.txt",ios::out);
        if(!file){
            cout<<"File not found"<<endl;
        }
        else{
            int r;
            cout<<"Enter roll number to update : ";
            cin>>r;
            while(file>>rollNo){
                file.ignore();
                getline(file,name);
                if(r==rollNo){
                    getData();
                    tempFile<<rollNo<<"\t"<<name<<endl;
                    count++;
                }
                else{
                    tempFile<<rollNo<<"\t"<<name<<endl;
                }
            }
            file.close();
            tempFile.close();
            remove("file.txt");
            rename("tempFile.txt","file.txt");
        }
        count==0? cout<<"No match found."<<endl : cout<<count<<" Records updated."<<endl;
    }

    void deleteData(){
        int count = 0;
        fstream file;
        fstream tempFile;
        file.open("file.txt",ios::in);
        tempFile.open("tempFile.txt",ios::out);
        if(!file){
            cout<<"File not found"<<endl;
        }
        else{
            int r;
            cout<<"Enter roll number to delete : ";
            cin>>r;
            while(file>>rollNo){
                file.ignore();
                getline(file,name);
                if(r==rollNo){
                    count++;
                }
                else{
                    tempFile<<rollNo<<"\t"<<name<<endl;
                }
            }
            file.close();
            tempFile.close();
            remove("file.txt");
            rename("tempFile.txt","file.txt");
        }
        count==0? cout<<"No match found."<<endl : cout<<count<<" records deleted."<<endl;
    }
};
int main()
{
    Student s1;
    bool con = true;
    do{
        int choice;
        cout<<"Press 1 to write data"<<endl;
        cout<<"Press 2 to read data"<<endl;
        cout<<"Press 3 to delete data"<<endl;
        cout<<"Press 4 to update data"<<endl;
        cout<<"Press 5 to exit"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: s1.writeData(); break;
            case 2: s1.readData(); break;
            case 3: s1.deleteData(); break;
            case 4: s1.updateData(); break;
            case 5: con = false; break;
            default : cout<<"Enter appropriate choice"<<endl;
        }
    }
    while(con);
}
