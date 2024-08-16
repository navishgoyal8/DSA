#include <iostream>
#include <vector>
using namespace std;

// T.C is O(N+ 2E) where N is the number of nodes and E is the number of edges
// S.C is O(N+E) + O(N) = O(N+E)
void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
    ls.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}

vector<int> dfsOfGraph(int V,vector<int> adj[]){
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start,adj,vis,ls);

    return ls;
}

int main()
{
    return 0;
}