#include <iostream>
using namespace std;

// Specify the number of rows and columns
#define num 8

// checkAttack function to check if a place is safe to put a queen or not 
int CheckAttack(int i, int j, int board[num+1][num+1], int N) {
  int k, l;
  // checking for column j
  for(k=1; k<=i-1; k++) {
    if(board[k][j] == 1)
      return 0;
  }

  // checking upper right diagonal
  k = i-1;
  l = j+1;
  while (k>=1 && l<=N) {
    if (board[k][l] == 1)
      return 0;
    k=k-1;
    l=l+1;
  }

  // checking upper left diagonal
  k = i-1;
  l = j-1;
  while (k>=1 && l>=1) {
    if (board[k][l] == 1)
      return 0;
    k=k-1;
    l=l-1;
  }

  return 1;
}

// n_queen function to Specifies queen

int n_queen(int row, int n, int N, int board[num+1][num+1]) {
  if (n==0 || n==2 || n==3)
    return 1;

  int j;
  for (j=1; j<=N; j++) {
    if(CheckAttack(row, j, board, N)) {
      board[row][j] = 1;

      if (n_queen(row+1, n-1, N, board))
        return 1;

      board[row][j] = 0;  //backtracking
    }
  }
  return 0;
}

int main() {
  int board[num+1][num+1];
  int i, j;

  for(i=0;i<=num;i++) {
    for(j=0;j<=num;j++)
      board[i][j] = 0;
  }

  n_queen(1, num, num, board);

  //printing the matix
  for(i=1;i<=num;i++) {
    for(j=1;j<=num;j++)
      cout<<"\t"<<board[i][j];
    cout<<"\n";
  }
  return 0;
}