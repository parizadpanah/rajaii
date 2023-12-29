#include <iostream>
using namespace std;
    int factorial(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        else
        {
            return n * factorial(n - 1);
        }
    }

    int main()
    {
        int n,x,a,combination=0;
        cin >>a>>x>>n;
        for (int k = 0; k <=n; k++)
        {
            int result1=1,result2=1;
            for (int i = 1; i <=k ; i++)
            {
                result1 *=x;
            }
            for (int i = 1; i <=(n-k) ; i++)
            {
                result2 *=a;
            }
            
            combination += ((factorial(n) / (factorial(k) * factorial(n - k)))*result1*result2);
        }
        cout<<combination;
        return 0;
    }