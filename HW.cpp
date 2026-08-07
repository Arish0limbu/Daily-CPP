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
void lines(int l = 100)
{
    ofstream stu("student.txt", ios::app);
    stu << endl;
    for (int i = 0; i < l; i++)
    {
        stu << "=";
    }
    stu << endl;
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
void centers(int c = 45)
{
    ofstream stu("student.txt", ios::app);
    for (int i = 0; i < c; i++)
    {
        stu << " ";
    }
}

class record
{
private:
    string name;
    int age;
    char c = 'y';

public:
    void esd()
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
    }

    void pt()
    {
        ofstream stu("student.txt", ios::app);
        lines();
        centers(40);
        stu<<"|| Student Information ||";
        lines();
    }

    void sd()
    {
        ofstream stu("student.txt", ios::app);
        cls();
        line();
        center(40);
        cout << "|| Save Details ||";
        line();
        cout << "Do you want to record(Y/N): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
            stu << name << "\t" << age << endl;
        stu.close();
    }

    int ad(char c)
    {
        cls();
        line();
        center(45);
        cout << "|| Add Details ||";
        line();
        cout << "Do you want add another student(Y/N): ";
        cin >> c;
        return c;
    }
};

int main()
{
    record r;
    char c = 'y';
    while (c == 'y')
    {
        r.esd();
        r.sd();
        c = r.ad(c);
    }
    return 0;
}