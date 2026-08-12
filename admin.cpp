#include <iostream>
#include <string>
#include <conio.h>

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

int main()
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

    return 0;
}