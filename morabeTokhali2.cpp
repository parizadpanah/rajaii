#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (b >= a)
    {
        cout << "Wrong order!";
    }
    else if (((a - b) % 2) != 0)
    {
        cout << "Wrong difference!";
    }
    else
    {

        for (int i = 0; i < ((a - b) / 2); i++)
        {
            for (int j = 0; j < a; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < ((a - b) / 2); j++)
            {
                cout << "*";
            }
            for (int j = 0; j < (b); j++)
            {
                cout << " ";
            }
            for (int j = 0; j < ((a - b) / 2); j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
        for (int i = 0; i < ((a - b) / 2); i++)
        {
            for (int j = 0; j < a; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
        system("pause");
        return 0;
    }

    system("pause");
    return 0;
}