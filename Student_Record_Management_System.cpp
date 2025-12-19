#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    int marks;

    void input()
    {
        cout << "Enter Roll: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << roll << "\t" << name << "\t" << marks << endl;
    }
};

int main()
{
    Student s;
    fstream file;
    int choice;

    do
    {
        cout << "\n1. Add Student\n2. View Students\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            file.open("students.txt", ios::out | ios::app);
            s.input();
            file.write((char *)&s, sizeof(s));
            file.close();
        }

        else if (choice == 2)
        {
            file.open("students.txt", ios::in);
            cout << "Roll\tName\tMarks\n";
            while (file.read((char *)&s, sizeof(s)))
            {
                s.display();
            }
            file.close();
        }

    } while (choice != 3);

    return 0;
}
