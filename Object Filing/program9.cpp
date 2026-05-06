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
        int sid;
        cout<<"Enter id to search : ";
        cin>>sid;
        int count=0;
        fstream file;
        file.open("file.txt",ios::in | ios::binary);
        while(file.read((char*)this , sizeof(*this)))
        {
            if(id==sid){
                count++;
                show();
            }
        }
        count==0? cout<<"No record matched." : cout<<count<<" records mathced"<<endl;
        file.close();
    }

void deleteData() {
    int sid;
    int count = 0;
    cout << "Enter id to delete record: ";
    cin >> sid;

    fstream file, tempFile;
    file.open("file.txt",     ios::binary | ios::in);
    tempFile.open("temp.txt", ios::binary | ios::out);

    if (!file) {
        cout << "File does not exist.\n";
        tempFile.close();
        return;                // ✅ stop here — don't run remove/rename
    }

    while (file.read(reinterpret_cast<char*>(this), sizeof(Laptop))) {
        if (id == sid) {
            cout << "Record deleted:\n";
            show();
            count++;
        } else {
            tempFile.write(reinterpret_cast<char*>(this), sizeof(Laptop));
        }
    }

    file.close();
    tempFile.close();          // ✅ close before rename/remove

    remove("file.txt");
    rename("temp.txt", "file.txt");

    if (count == 0)
        cout << "No record found.\n";
    else
        cout << count << " record(s) deleted.\n";
}


void updateRecord()
	{
		fstream file("record.txt",ios::binary|ios::in|ios::out);
		/*we will not use ios::app because we need random updation,
		however ios::app only allow updation after the eof
		*/
		if(!file) 
		    cout<<"\nFile Reading error....";
		else
		{    cout<<"\nEnter id  you want to update:";
		     int sid;  int count=0;
		     cin>>sid;
		     file.read((char*)this, sizeof(*this));
		     while(!file.eof())
			 {
				if(sid==id)
				{
					count++;
					streampos rposition=file.tellg();
					 int size=sizeof(*this);

					file.seekp((int)rposition - size);
					input();
					file.write((char*)this, sizeof(*this));
					break; 	//removing one record at a time
				}
				file.read((char*)this, sizeof(*this));
			 }
			 if(count==0)
				cout<<"\nRecord not found";
			 else
				cout<<"\n"<<count<<" Record updated successfully";
		}
		file.close();
	}
};

int main(){
    Laptop lt1;
    lt1.updateRecord();
}
