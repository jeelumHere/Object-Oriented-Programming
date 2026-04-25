//Tested on Visual Studio 2015
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>	//for dos remove and rename command

using namespace std;

class Student
{
	int rollno;
	char name[20];
public:
	void getData()
	{
		cout << "\nEnter Roll No;"; cin >> rollno;
		cout << "Enter First Name:"; cin >> name;
	}
	void showData()
	{
		cout << "\n" << rollno << "\t" << name;
	}
	void writeFile()
	{
		fstream file("record.txt", ios::binary | ios::out | ios::app);
		if (!file)
			cout << "\nFile Writing Object Error....";
		else
		{
			getData();
			file.write((char*)this, sizeof(*this));
			cout << "\nThe following record added successfully";
			cout <<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
			cout << "\nRoll No\tFirst Name:";
			cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
			showData();
		}
		file.close();
	}
	
void readFile()
	{
		int count = 0;
		fstream file("record.txt", ios::binary | ios::in);
		if (!file)
			cout << "File reading error....";
		else
		{
			cout << "\nFollowing are the Records from File";
			cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
			cout << "\nRoll No\tFirst Name:";
			cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
			file.read((char*)this, sizeof(*this));
			while (!file.eof())
			{
				count++;
				showData();
				file.read((char*)this, sizeof(*this));
			}
			cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
		}
		if(count==0)
				cout<<"\nRecord not found";
		else
				cout<<"\nTotal Records found="<<count;
		file.close();
	}
	void searchFile()
	{
		fstream file("record.txt",ios::binary|ios::in);
		if(!file) 
		    cout<<"\nReading error";
		else
		{    cout<<"\nEnter Roll No you want to search:";
		     int r;  int count=0;
		     cin>>r;
		     file.read((char*)this, sizeof(*this));
		     while(!file.eof())
			 {
				if(r==rollno)
				{
					showData();
					count++;
				}
				file.read((char*)this, sizeof(*this));

			 }
			 if(count==0)
				cout<<"\nRecord not found";
			 else
				cout<<"\nTotal Records found="<<count;
		}
		file.close();
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
		{    cout<<"\nEnter Roll No you want to update:";
		     int r;  int count=0;
		     cin>>r;
		     file.read((char*)this, sizeof(*this));
		     while(!file.eof())
			 {
				if(r==rollno)
				{
					count++;
					streampos rposition=file.tellg();
					 int size=sizeof(*this);

					file.seekp((int)rposition - size);
					getData();
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
	void deleteRecord()
	{
		fstream file("record.txt",ios::binary|ios::in|ios::out);
		fstream tempfile("record_t.txt", ios::binary  | ios::out);
		if(!file) 
			cout<<"\nFile Reading error";
		else
		{    
		     cout<<"\nEnter Roll No you want to delete:";
		     int r;  int count=0;
		     cin>>r;
			 file.read((char*)this, sizeof(*this));
			 while (!file.eof())
			 {
				 if (r == rollno)
				 {
					 count++;
				 }
				 else
				 {
					 tempfile.write((char*)this, sizeof(*this));
				 }
				 file.read((char*)this, sizeof(*this));

			 }	
			 if (count == 0)
				 cout << "\nRecord not found";
			 else
			 {
				 cout << "\n" << count << " Record deleted successfully";
				 tempfile.close();
				 file.close();
				 remove("record.txt");
				 rename("record_t.txt", "record.txt");
			 }

		}
		file.close();
	}

};
int main()
{
	int option;
	Student s1;

	do
	{
		system("cls");
		cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
		cout << "\n\tWelcome to the UIIT Filing Program";
		cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
		cout << "\n\tDeveloped by Dr. Kashif Sattar";
		cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
		cout << "\n\tPress 1 for write data into file";
		cout << "\n\tPress 2 for read data from file";
		cout << "\n\tPress 3 for search data from file";
		cout << "\n\tPress 4 for update record in file";
		cout << "\n\tPress 5 for delete record from file:";
		cout << "\n\tEnter Option:";
		cin >> option;
		switch (option)
		{
		case 1: s1.writeFile();     break;
		case 2: s1.readFile();      break;
		case 3: s1.searchFile();    break;
		case 4: s1.updateRecord();  break;
		case 5: s1.deleteRecord();  break;
		}
		cout << "\n\n\tDo you want to continue...y/n:";
	} while (_getche() == 'y');
	cout << "\n\tThanks for using this program, Bye!";

	_getch();
	return 0;
}
