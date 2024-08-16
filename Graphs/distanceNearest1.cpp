#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid){

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> ans(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                vis[i][j] = 1;
                q.push({{i,j},0});
            }
            else{
                vis[i][j] = 0;
            }
        }
    }
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        ans[row][col] = dist; 
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                q.push({{nrow,ncol},dist+1});
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}