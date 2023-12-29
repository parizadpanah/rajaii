#include <iostream>
using namespace std;
int main()
{
    int n, m, i = 0;
    cin >> m;
    if (m <= 15)
    {
        for (int j = 0; j < m; j++)
        {
            int count = 0;
            cin >> n;
            int a[8], l = 0;
            while (n >= 1)
            {
                count++;
                a[l] = n % 10;
                n /= 10;
                ++l;
            }

            for (int k = 0; k < count; k++)
            {
                for (int h = k + 1; h < count; h++)
                {
                    if (a[k] == a[h])
                    {
                        ++i;
                        k = count;
                    }
                }
            }
        }
    }
    else
    {
        return 0;
    }
    cout << m - i;
}