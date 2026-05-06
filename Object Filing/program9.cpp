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
    char name[50];
    int id;
    double price;

    public : 
    void input(){
        cout<<"Enter name : "; cin.getline(name,50);
        cout<<"Enter id : "; cin>>id;
        cout<<"Enter price : "; cin>>price;
        cin.ignore();
    }

    void show(){
        cout<<"Name : "<<name<<endl;
        cout<<"Id : "<<id<<endl;
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
            file.write(reinterpret_cast<char*>(this) , sizeof(Laptop));
            file.close();
        }
    }


    void readData(){
        ifstream file;
        file.open("file.txt", ios::binary);
        if(!file){
            cout<<"Error in file loading!"<<endl;
        }
        else{
            while(file.read((char*)this, sizeof(*this))){
                show();
            }
        }
        file.close();
    }

    void searchData(){
        int count = 0;
        fstream file;
        file.open("file.txt",ios::binary | ios::in);

        if(!file){
            cout<<"File does not exist"<<endl;
            return;
        }
        else{
            cout<<"Enter id to search..   : ";int sid; cin>>sid;
            while(file.read((char*)this,sizeof(*this))){
                if(sid==id)
                {
                    show();
                    count++;
                }
            }
        }
        if(count==0){
            cout<<"No record matched"<<endl;
        }
        else{
            cout<<count<<" reacord mathced"<<endl;
        }
        file.close();
    }


    void deleteData(){
        fstream file,tempFile;
        file.open("file.txt",ios::in | ios:: binary);
        tempFile.open("tempfile.txt",ios::out | ios::binary);

        if(!file || !tempFile){
            cout<<"Files do not exist"<<endl;
            return;
        }
        else{
            cout<<"Enter id t delete record  : "; int did; cin>>did;
            while(file.read((char*)this , sizeof(*this))){
                if(did==id){
                    cout<<"Record Found"<<endl;
                }
                else{
                    tempFile.write((char*)this, sizeof(*this));
                }
            }
        }
        file.close();
        tempFile.close();
        remove("file.txt");
        rename("tempfile.txt","file.txt");
    }

    void updateData(){
        cout<<"code updation."<<endl;
        fstream file;
        file.open("file.txt",ios::in | ios:: out | ios::binary);
        if(!file){
            cout<<"File not found"<<endl;
            return;
        }
        else{
            cout<<"Enter id to update record : "; int uid; cin>>uid;
            while(file.read((char*)this , sizeof(*this))){
                if(uid==id){
                    file.seekp(file.tellg() - sizeof(Laptop));
                    input();
                    file.write((char*)this , sizeof(*this));
                }
            }
        }
        file.close();
    }

};
// seekg & seekp
// tellg & tellp
// g -> get pointer  (reading pointer)
// p -> put pointer  (writing pointer)
// tell it only gives information.
// seek it moves the pointer.
// mainly used tellg & seekp.
int main(){
    Laptop lt1;
    bool condition = true;

    do{
        cout<<"Enter 1 to write data "<<endl;
        cout<<"Enter 2 to read data "<<endl;
        cout<<"Enter 3 to search data "<<endl;
        cout<<"Enter 4 to delete data "<<endl;
        cout<<"Enter 5 to update data "<<endl;
        cout<<"Enter 6 to exit"<<endl;
        cout<<"Enter choice : "; int choice; cin>>choice;
        switch(choice){
            case 1 : 
            lt1.writeData();
            break;

            case 2 : 
            lt1.readData();
            break;

            case 3 : 
            lt1.searchData();
            break;

            case 4 : 
            lt1.deleteData();
            break;

            case 5 : 
            lt1.updateData();
            break;

            case 6 : 
            condition = false;
            break;

            default : 
            cout<<"Enter appropriate choice"<<endl;

        }
    }
    while(condition);
}


