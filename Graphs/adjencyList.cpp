#include <iostream>
#include <vector>
using namespace std;
int main()
{   
    int n = 5;
    int m = 6;

    vector<int> adj[6];

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    

    return 0;
}