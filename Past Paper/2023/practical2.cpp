// You have a class named as ABC, the data of many objects is already stored in a 
// file named as myFile.dat. You are required to read data of each object and 
// search the object whose id is 101. 


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class ABC {
    int objectID;
    string ObjectName;

public:
    void getData() {
        cout << "Enter object id   : "; cin >> objectID;
        cout << "Enter object name : "; cin >> ObjectName;
    }

    void showData() {
        cout << "Id   : " << objectID   << endl;
        cout << "Name : " << ObjectName << endl;
    }

    void writeData() {
        fstream file;
        file.open("file.dat", ios::app | ios::out | ios::binary); // ✅ binary flag added
        ABC obj;
        obj.getData();
        file.write(reinterpret_cast<char*>(&obj), sizeof(ABC));
        cout << "Record saved : \n";
        obj.showData();
        file.close();
    }

    void readData() {
        fstream file;
        file.open("file.dat", ios::in | ios::binary);
        if (!file) {
            cout << "File does not exist" << endl;
            return;
        }
        ABC obj;
        while (file.read(reinterpret_cast<char*>(&obj), sizeof(ABC))) // ✅ read into obj
        {
            obj.showData();
        }
        file.close();
    }

    void searchData() {
        fstream file;
        file.open("file.dat", ios::in | ios::binary); // ✅ binary flag added
        if (!file) {
            cout << "File does not exist" << endl;    // ✅ typo fixed
            return;
        }
        ABC obj;
        cout << "Enter id to search record : "; int sid; cin >> sid;
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&obj), sizeof(ABC))) {
            if (sid == obj.objectID) {  // ✅ compare with obj.objectID
                obj.showData();
                found = true;
            }
        }
        if (!found) cout << "Record not found." << endl; // ✅ better UX
        file.close();
    }
};

int main() {
    bool con = true;
    ABC object;
    while (con) {
        cout << "\nEnter 1 to add object data    : " << endl;
        cout << "Enter 2 to read object data   : " << endl;
        cout << "Enter 3 to search object data : " << endl;
        cout << "Enter 4 to exit the program   : " << endl;
        cout << "Enter choice : "; int choice;
        cin >> choice;

        if      (choice == 1) object.writeData();
        else if (choice == 2) object.readData();
        else if (choice == 3) object.searchData(); // ✅ fixed from 2 to 3
        else if (choice == 4) con = false;
        else cout << "Invalid choice." << endl;    // ✅ handles bad input
    }
    return 0;
}