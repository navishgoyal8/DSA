#include <iostream>
#include <vector>
using namespace std;

void dfs(int node,vector<int> adjList[],int vis[]){
    vis[node] = 1;
    for(auto it: adjList[node]){
        if(!vis[it]){
            dfs(it,adjList,vis);
        }
    }
}


int numProvinces(vector<vector<int>> adj,int V){
    vector<int> adjList[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 && i!=j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int vis[V] = {0};
    int provinces = 0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            provinces++;
            dfs(i,adjList,vis);
        }
    }

    return provinces;
}

int main()
{
    return 0;
}