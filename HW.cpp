#include <iostream>
#include <fstream>
using namespace std;
void line(int l = 100)
{
    cout << endl;
    for (int i = 0; i < l; i++)
    {
        cout << "=";
    }
    cout << endl;
}

void cls()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void center(int c = 45)
{
    for (int i = 0; i < c; i++)
    {
        cout << " ";
    }
}

int main()
{
    string name;
    char c = 'y';
    int age;

    ofstream stu("student.txt", ios::app);

    while (c == 'y')
    {
        cls();
        line();
        center(36);
        cout << "|| Enter Student Details ||";
        line();
        cout << "Enter Student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter student age: ";
        cin >> age;
        cls();
        line();
        center(40);
        cout << "|| Save Details ||";
        line();
        cout << "Do you want to record(Y/N): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
            stu << name << "\t" << age << endl;
        cls();
        line();
        center(45);
        cout << "|| Add Details ||";
        line();
        cout << "Do you want add another student(Y/N): ";
        cin >> c;
    }
    stu.close();
    return 0;
}