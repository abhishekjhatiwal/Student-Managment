#include <iostream>
#include <fstream>
using namespace std;

class temp
{
private:
    string rollNum, name, fName, address, search;
    fstream file;

public:
    void addStu();
    void viewStu();
    void searchStu();
} obj;

int main()
{
    char choice;
    cout << "=======================================\n";
    cout << "1- Add Student Record\n";
    cout << "2- View All tudent Record \n";
    cout << "3- Search Student Record \n";
    cout << "4- Exit \n";
    cout << "========================================\n";
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.addStu();
        break;
    case '2':
        cin.ignore();
        obj.viewStu();
        break;
    case '3':
        cin.ignore();
        obj.searchStu();
        break;
    case '4':
        return 0;
        break;

    default:
        cout << "Invalid Choice ";
        break;
    }

    return 0;
}

void temp::addStu()
{
    cout << "\nEnter Student Roll Number : ";
    getline(cin, rollNum);
    cout << "Enter Student Name : ";
    getline(cin, name);
    cout << "Enter Students Fathers Name : ";
    getline(cin, fName);
    cout << "Enter Student Adderss : ";
    getline(cin, address);

    file.open("stuData.txt", ios::out | ios ::app);
    file << rollNum << "*";
    file << name << "*";
    file << fName << "*";
    file << address << endl;
    file.close();
}

void temp::viewStu()
{
    file.open("stuData.txt", ios::in);
    getline(file, rollNum, '*');
    getline(file, name, '*');
    getline(file, fName, '*');
    getline(file, address, '\n');
    while (!file.eof())
    {
        cout << endl;
        cout << "Student Roll Number : " << rollNum;
        cout << "Student Name : " << name;
        cout << "Student Father's Name : " << fName;
        cout << "Student Adderss : " << address << endl;
        getline(file, rollNum, '*');
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
    }
    file.close();
}

void temp::searchStu()
{
    cout << "Enter Student Roll Number : ";
    getline(cin, rollNum);

    file.open("StuData.txt", ios::in);
    getline(file, rollNum, '*');
    getline(file, name, '*');
    getline(file, fName, '*');
    getline(file, address, '\n');
    while (!file.eof())
    {
        if (rollNum == search)
        {
            cout << "Student Roll Number : " << rollNum;
            cout << "Student Name : " << name;
            cout << "Student Fathers Name : " << fName;
            cout << "Student Address : " << address << endl;
        }
        getline(file, rollNum, '*');
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
    }
    file.close();
}