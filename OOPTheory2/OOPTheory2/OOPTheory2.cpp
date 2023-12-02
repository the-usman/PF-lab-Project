#include <iostream>
#include <string>
using namespace std;

class Student
{
    char* name;
    int rollNo;
    double age;
    float gpa;

public:
    Student()
    {
        name = nullptr;
        rollNo = 0;
        age = 0;
        gpa = 0.0;
    }

    Student(string aName)
    {
        cout << "I am in parameterized constructor with name parameter\n";
        name = new char[aName.length() + 1];
        for (int i = 0; i < aName.length(); i++)
        {
            name[i] = aName[i];
        }
        name[aName.length()] = '\0';
        rollNo = 0;
        age = 0;
        gpa = 0.0;
    }

    Student(int aRollNo)
    {
        cout << "I am in parameterized constructor with Rollno parameter\n";
        name = nullptr;
        rollNo = aRollNo;
        age = 0;
        gpa = 0.0;
    }

    Student(double aAge)
    {
        cout << "I am in parameterized constructor with age parameter\n";
        name = nullptr;
        rollNo = 0;
        age = aAge;
        gpa = 0.0;
    }

    Student(float aGpa)
    {
        cout << "I am in parameterized constructor with gpa parameter\n";
        name = nullptr;
        rollNo = 0;
        age = 0;
        gpa = aGpa;
    }

    Student(string aName, int aRollNo, int aAge, float aGpa)
    {
        cout << "I am in parameterized constructor with all parameters\n";
        name = new char[aName.length() + 1];
        for (int i = 0; i < aName.length(); i++)
        {
            name[i] = aName[i];
        }
        name[aName.length()] = '\0';
        rollNo = aRollNo;
        age = aAge;
        gpa = aGpa;
    }

    void showData()
    {
        cout << name << endl;
        cout << rollNo << endl;
        cout << age << endl;
        cout << gpa << endl;
    }
};

int main()
{
    string name;
    cout << "Enter name: ";
    cin >> name;
    Student student1(20);
    student1.showData();
    return 0;
}
