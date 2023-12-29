#include <bits/stdc++.h>
using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b,int n) { return (a > b) ? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
 
    // Base Case
    if (n == 0 || W == 0){
        //cout<<"*"<<n<<"* ";
        return 0;}
 
    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
    if (wt[n - 1] > W){
        //cout<<"("<<n<<")";
        return knapSack(W, wt, val, n - 1);}
 
    // Return the maximum of two cases:
    // (1) item included
    // (2) not item included
    else
        //cout<<" "<<n<<"->";
        return max(
            val[n - 1]+ knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1),n);
}
 
int main()
{
    int profit[] = { 20 , 10 , 30 };
    int weight[] = { 5 , 5 , 11 };
    int W = 15;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}


/*int main()
{
    int n, W;
    int profit[20];
    int weight[20];
    
    cout<<"Enter number of item:";
    cin>>n;
    cout<<"Enter bound:";
    ciin>>W;
    cout<<"Enter weights: ";
    for(int i=0 ; i<n ; i++)
       {
          cin>>weight[i];
       }
    cout<<"Enter profits based on weights: ";
    for(int i=0 ; i<n ; i++)
       {
          cin>>profit[i];
       }
    cout << knapSack(W, weight, profit, n);
    return 0;


    int profit[] = { 50 , 60 , 140 };
    int weight[] = { 5 , 10 , 20 };
    int W = 30;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}*/