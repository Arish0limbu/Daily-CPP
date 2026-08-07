#include <iostream>
#include <fstream>
using namespace std;
void line(int l = 100)
{
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
        cout << "Enter Student Details" << endl;

        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;
        cout << "Do you want to record(Y/N): ";
        cin >> c;
        if (c == 'y' || 'Y')
            stu << name << "\t" << age << endl;
        cout << "Do you want enter another name and age: ";
        cin >> c;
    }
    stu.close();
    return 0;
}