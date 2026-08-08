#include <iostream>
#include <fstream>
#include <string>
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
        cout << "|| Enter Student Details ||" << endl;
        ;
        line();
        cout << "Enter Student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter student age: ";
        cin >> age;
    }

    void pt() // Print into file
    {
        ofstream stu("student.txt", ios::app);
        stu.seekp(0, ios::end); // check the file is empty or not
        if (stu.tellp() == 0)
        {
            int ls = 100, cs = 37;
            for (int i = 0; i < ls; i++)
            {
                stu << "=";
            }

            stu << endl;

            for (int i = 0; i < cs; i++)
            {
                stu << " ";
            }
            stu << "|| Student Information ||" << endl;
            for (int i = 0; i < ls; i++)
            {
                stu << "=";
            }
            stu << endl
                << "\t\tNAME\t\t|\t AGE\t|" << endl;
            for (int i = 0; i < ls; i++)
            {
                stu << "=";
            }
            stu << endl;
        }
        stu << name << "\t" << "\t|\t  " << age << "\t|" << endl;
        stu.close();
    }

    void sd()
    {
        cls();
        line();
        center(40);
        cout << "|| Save Details ||" << endl;
        ;
        line();
        cout << "Do you want to record(Y/N): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
            pt();
    }

    int ad(char c)
    {
        cls();
        line();
        center(45);
        cout << "|| Add Details ||" << endl;
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
    while (c == 'y' || c == 'Y')
    {
        r.esd();
        r.sd();
        c = r.ad(c);
    }
    cls();
    return 0;
}