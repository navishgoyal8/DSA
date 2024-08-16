#include <bits/stdc++.h>
using namespace std;

int rottenOranges(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int,int>,int>> q;
    int vis[n][m];
    int countFresh = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                vis[i][j] = 1;
                q.push({{i,j},0});
            }
            else{
                vis[i][j] = 0;
            }

            if(grid[i][j] == 1){
                countFresh++;
        }
    }

}

    int time = 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    int count = 0;

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        time = max(time,t);
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                vis[nrow][ncol] = 1;
                q.push({{nrow,ncol},t+1});
                count++;
            }
        }
    }

    if(count != countFresh){
        return -1;
    }

    return time;
}

int main()
{
    return 0;
}