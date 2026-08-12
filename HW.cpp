#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <conio.h>
#include <iomanip> //help to fix position

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

string hidePassword()
{
    string password;
    char ch;

    while (true)
    {
        ch = _getch();

        if (ch == 13)
        {
            break;
        }

        if (ch == 8)
        {
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }

        else
        {
            password += ch;
            cout << "*";
        }
    }

    cout << endl;
    return password;
}

void login()
{
    string username, password;
    int t = 3;
    while (t != 0)
    {
        cls();
        line();

        center(42);
        cout << "|| LOGIN PAGE ||" << endl;

        line();

        cout << "Username: ";
        getline(cin, username);

        cout << "Password: ";
        password = hidePassword();

        if (username == "admin" && password == "1234")
        {
            line();
            center(39);
            cout << "|| Login Successfuly ||" << endl;
            line();
            t = 0;
            system("pause");
        }
        else if (username != "admin" || password != "1234")
        {
            if (username == "admin")
            {
                line();
                center(39);
                cout << "|| Incorrect Password ||" << endl;
                center(40);
                cout << "|" << t - 1 << "| Attempts left.." << endl;
                line();
                system("pause");
            }
            else
            {
                line();
                center(39);
                cout << "|| Incorrect Username ||" << endl;
                center(44);
                cout << "|" << t - 1 << "| Attempts left.." << endl;
                line();
                system("pause");
            }
            t--;
        }
        else
        {
            line();
            center(39);
            cout << "|| Incorrect Username & Password ||" << endl;
            center(44);
            cout << "|" << t - 1 << "| Attempts left.." << endl;
            line();
            system("pause");
            t--;
        }
    }

}
class record
{
private:
    int ns, sn = 0;
    vector<string> age;
    vector<string> name;
    char c = 'y';

public:
    int mm()
    {
        int o;
        cls();
        line();
        center();
        cout << "|| Main Menu ||" << endl;
        line();
        cout << "1) ADD STUDENT." << endl
             << "2) DISPLAY ALL STUDENT INFO." << endl
             << "3) REMOVE STUDENT." << endl
             << "4) EXIT." << endl;
        line();
        cout << "Enter number to select given option: ";

        if (!(cin >> o))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return 0;
        }

        return o;
    }

    void nos()
    {
        cls();
        line();
        center(40);
        cout << "|| Number Of Student ||" << endl;
        line();
    }
    int esd()
    {
        nos();
        cout << "Enter the number oF student: ";
        cin >> ns;
        name.resize(ns);
        age.resize(ns);

        for (int i = 0; i < ns; i++)
        {
            cls();
            line();
            center(36);
            cout << "|| Enter Student Details ||" << endl;
            line();
            center(42);
            cout << "!! Student " << i + 1 << " !!" << endl;
            cout << "Enter Student name: ";
            getline(cin >> ws, name[i]);
            cout << "Enter student age: ";
            cin >> age[i];
        }
        return ns;
    }

    int getLastSN()
    {
        ifstream file("student.txt");

        string line;
        int lastSN = 0;

        while (getline(file, line))
        {
            if (line.length() > 1 && line[0] == '|')
            {
                try
                {
                    size_t first = line.find('|');
                    size_t second = line.find('|', first + 1);

                    string snText = line.substr(
                        first + 1,
                        second - first - 1);

                    int currentSN = stoi(snText);

                    if (currentSN > lastSN)
                    {
                        lastSN = currentSN;
                    }
                }
                catch (...)
                {
                    // Ignore header lines
                }
            }
        }

        file.close();

        return lastSN;
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
            stu << endl;

            stu << left // start from left side
                << setw(2) << "|"
                << "S.N"
                << setw(1) << " "
                << "|"
                << setw(11) << " "
                << "NAME"
                << setw(11) << " "
                << "|"
                << setw(3) << " "
                << "AGE"
                << setw(3) << " "
                << "|" << endl;

            for (int i = 0; i < ls; i++)
            {
                stu << "=";
            }
            stu << endl;
        }
        sn = getLastSN();
        sn++;
        for (int i = 0; i < ns; i++)
        {
            stu << "| "
                << right << setw(2) << sn
                << "  |"
                << left << setw(26) << name[i]
                << "|   "
                << left << setw(6) << age[i]
                << "|" << endl;
            sn++;
        }
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
        cout << "Do you want to record in file(Y/N): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
            pt();

        if (c == 'y' || c == 'Y')
        {
            line();
            center(35);
            cout << "|| Record Saved In File ||" << endl;
            line();
            system("pause");
        }
        else
        {
            line();
            center(32);
            cout << "|| Record Didn't Saved In File ||" << endl;
            line();
            system("pause");
        }
    }

    int ms()
    {
        char c;
        cls();
        line();
        center(45);
        cout << "|| More Students ||" << endl;
        line();
        cout << "Do you want add more student(Y/N): ";
        cin >> c;
        return c;
    }

    void ds()
    {
        cls();
        ifstream stu("student.txt");

        if (!stu)
        {
            cls();
            line();
            center(40);
            cout << "|| File Not Found ||" << endl;
        }

        string data;

        while (getline(stu, data))
        {
            cout << data << endl;
        }
        line();
        system("pause");
        stu.close();
    }

    void rs()
    {
        string tname;
        line();
        center();
        cout << "|| REMOVE STUDENT ||" << endl;
        line();

         ifstream stu("student.txt");
         ofstream tstu("tstudent.txt");

         if (!stu)
         {
             cls();
            line();
            center(40);
            cout << "|| File Not Found ||" << endl;
            line();
            system("pause");
         }

         cout << "Enter name of student to remove from file: ";
         
         
    }
};

int main()
{
    login();
    record r;
    while (true)
    {
        int sw = r.mm();
        switch (sw)
        {
        case 1:
        {
            char c = 'y';
            while (c == 'y' || c == 'Y')
            {
                r.esd();
                r.sd();

                c = r.ms();
            }
            break;
        }
        case 2:
        {
            r.ds();
            break;
        }
        case 3:
        {
            r.rs();
            break;
        }
        case 4:
            cls();
            return 0;
        default:
            cls();
            line();
            center(40);
            cout << "|| Invalid Input ||" << endl;
            line();
            system("pause");
        }
    }
    cls();
    return 0;
}