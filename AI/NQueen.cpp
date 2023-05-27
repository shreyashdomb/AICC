/* C++ program to solve N Queen Problem using
backtracking */
#include <bits/stdc++.h>
using namespace std;
class Board{
/* A utility function to print solution */
public:
int N;
Board(int n){
N = n;
}
void printSolution(int **board)
{
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++)
if(board[i][j])
cout << "Q ";
else cout<<". ";
printf("\n");
}
}
bool isSafe(int **board, int row, int col)
{
int i, j;
/* Check this row on left side */
for (i = 0; i < col; i++)
if (board[row][i])
return false;
/* Check upper diagonal on left side */
for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
if (board[i][j])
return false;
/* Check lower diagonal on left side */
for (i = row, j = col; j >= 0 && i < N; i++, j--)
if (board[i][j])
return false;
return true;
}
/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int **board, int col)
{
/* base case: If all queens are placed
then return true */
if (col >= N)
return true;
/* Consider this column and try placing
this queen in all rows one by one */
for (int i = 0; i < N; i++) {
/* Check if the queen can be placed on
board[i][col] */
if (isSafe(board, i, col)) {
/* Place this queen in board[i][col] */
board[i][col] = 1;
/* recur to place rest of the queens */
if (solveNQUtil(board, col + 1))
return true;
board[i][col] = 0; // BACKTRACK
}
}
/* If the queen cannot be placed in any row in
this column col then return false */
return false;
}
bool solveNQ(int **board)
{
if (solveNQUtil(board, 0) == false) {
cout << "Solution does not exist"<<endl;
return false;
}
printSolution(board);
return true;
}
};
// driver program to test above function
int main()
{
int ch;
cout<<"1. Run code 0. Stop"<<endl;
cout<<"Enter the choice: ";
cin>>ch;
while(ch==1){
int n;
cout<<"Enter the N: ";
cin>>n;
Board b(n);
int **board = new int*[n];
for(int i=0;i<n;i++){
board[i] = new int[n];
for (int j=0;j<n;j++){
board[i][j]=0;
}
cout<<endl;
}
b.solveNQ(board);
cout<<endl;
cout<<"Enter the choice: ";
cin>>ch;
cout<<endl;
}
return 0;
}
