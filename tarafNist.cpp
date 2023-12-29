#include <iostream>
using namespace std;
int main(){
    int n;
    string q[7]={"shanbe","1shanbe","2shanbe","3shanbe","4shanbe","5shanbe","jome"};
    cin>>n;
    string a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        for (int j = 0; j < 7; j++)
        {
            if(q[j]==a[i]){
                q[j]="0";
            }
        }  
    }
    cin>>n;
    string b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
        for (int j = 0; j < 7; j++)
        {
            if(q[j]==b[i]){
                q[j]="0";
            }
        }  
    }
    cin>>n;
    string c[n];
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
        for (int j = 0; j < 7; j++)
        {
            if(q[j]==c[i]){
                q[j]="0";
            }
        }  
    }
    int count=0;
    for (int i = 0; i < 7; i++)
    {
        if(q[i] != "0"){
            count++;
        }
    }
    cout<<count;
    
    return 0;

}