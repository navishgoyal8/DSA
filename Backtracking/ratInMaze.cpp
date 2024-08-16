#include <iostream>
#include <vector>
using namespace std;

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> ans, vector<vector<bool>> visited,string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    //4 movements  ---> D, L , R, U
    if (x + 1 >= 0 && x + 1 < n && y >= 0 && y < n && arr[x + 1][y] == 1 && visited[x + 1][y] != 1)
    {
        visited[x][y] = 1;
        solve(x+1,y,arr,n,ans,visited,path+'D');
        visited[x][y] = 0;
    }

    if (x >= 0 && x < n && y-1 >= 0 && y-1 < n && arr[x][y-1] == 1 && visited[x][y-1] != 1)
    {
        visited[x][y] = 1;
        solve(x, y-1, arr, n, ans, visited, path + 'L');
        visited[x][y] = 0;
    }

    if (x >= 0 && x < n && y+1 >= 0 && y+1 < n && arr[x][y+1] == 1 && visited[x][y+1] != 1)
    {
        visited[x][y] = 1;
        solve(x, y+1, arr, n, ans, visited, path + 'R');
        visited[x][y] = 0;
    }

    if (x - 1 >= 0 && x - 1 < n && y >= 0 && y < n && arr[x - 1][y] == 1 && visited[x - 1][y] != 1)
    {
        visited[x][y] = 1;
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
        visited[x][y] = 0;
    }
}

    vector<string> searchMaze(vector<vector<int>> &arr, int n)
{   
    
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool> (n,0));
    string path = "";

    if (arr[0][0] == 0)
    {
        return ans;
    }

    solve(0,0,arr,n,ans,visited,path);

    return ans;
}
int main()
{
    return 0;
}