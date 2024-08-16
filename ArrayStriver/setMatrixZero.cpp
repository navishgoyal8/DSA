#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix,int n,int m){
    vector<int> row(n,0);
    vector<int> col(m,0);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;

}

vector<vector<int>> optimalZeroMatrix(vector<vector<int>> &matrix,int n,int m){

    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j != 0){
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j] != 0){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int i=0;i<m;i++){
            matrix[0][i] = 0;
        }
    }

    if(col0 == 0){
        for(int i=0;i<n;i++){
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: "<<endl;
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout<<endl;
    }

    cout<<endl;

    vector<vector<int>> matrix2 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> ans2 = optimalZeroMatrix(matrix2, n, m);
    cout << "The Second Final matrix is: " << endl;
    for (auto it : ans2)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}