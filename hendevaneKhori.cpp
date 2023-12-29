#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int max=-1;
    int count;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>max){
            max=a[i];
            count=i;
        }
    }
    cout<<count+1;
    
}