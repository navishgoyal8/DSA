#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// T.C is O(N+E) where N is the number of nodes and E is the number of edges
// S.C is O(N+E) + O(N) + O(N) = O(N+E)
vector<int> bfsOfGraph(int V,vector<int> adj[]){
    // n is the number of nodes
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}

int main()
{
    return 0;
}