#include<iostream>
using namespace std;
int fard(int );
int Prime(int );
int Maghsom_alie(int );
int Fard(int );
int Maghlob(int );
int main()
{
    
    int n,sum=0;
    cin>>n;
for (int i = 399; i <=n; i++)
{
    if(Fard(i)==1 && fard(i)==1)
    {
        sum+=i;
    }
}
if(sum==0)
{
    cout<<"NOT FOUND!";
}
else{
cout<<Maghlob(sum);
}
}

//Function 1
int fard(int a)
{
    if(a%2==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
//Function 2
int Prime(int a){
 int flag=0;
 for(int i = 2; i < a ; i++){
   if( a % i == 0 ){
   flag = 1;
   } 
 }
 if(flag == 0){
   return 1;
 }else{
   return 0;
 }
}
//Function 3
int Maghsom_alie(int n)
{
    int tedad=0;
    	for(int i = 2; i < n ; i++){
		if( n % i == 0 && Prime(i)==1){
			++tedad;
		}}
        return tedad;
}
//Function 4
int Fard(int a)
{
    for(int i = 1; i <= a ; i++){
		if( a % i == 0 && Prime(i)==1){
			 if(Maghsom_alie(a)==i)
             {
                return 1;
             }
		}}
   
return 0;
}

int Maghlob(int n)
{
    int b=0;
 while(n>0)
{
b=b*10+n%10;
n/=10;
}
return b;
}