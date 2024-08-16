#include <iostream>
using namespace std;

bool isSafe(int board[4][4],int row,int col){

    for(int i=0;i<4;i++){
        if(board[row][i] == 1){
            return false;
        }
    }

    for(int i=row,j = col;i>=0,j>=0;i--,j--){

        if(board[i][j] == 1){
            return false;
        }
    }

    for(int i= row,j = col;i<4,j>=0;i++,j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

void printSol(int board[4][4]){

    for(int i=0;i<4;i++){
        for(int j =0;j<4;j++){
            cout<<board[i][j]<<" ";
        }

        cout<<endl;
    }
}

bool nQueen(int board[4][4],int col){
    if(col >= 4){
        return true;
    }

    for(int i=0;i<4;i++){
        if(isSafe(board,i,col)){
            board[i][col] = 1;
            if(nQueen(board,col+1)){
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{   int n = 4;
    int board[4][4] = {{0}};

    if(nQueen(board,0) == true)
    {
        printSol(board);
    }
    else{
        cout<<"Solution is not found!";
    }

    return 0;
}