#include <iostream>
using namespace std;
int CountMult(int x){
    if(x<10){
        return 0;
    }
    int y=1;
    while (x!=0)
    {
        /* code */
        y*=x%10;
        x/=10;
    }
    return 1+CountMult(y);
}
int main(){
    int number;
    cin>>number;
    if(number>=0){
        cout<<CountMult(number);
    }
    return 0;

}