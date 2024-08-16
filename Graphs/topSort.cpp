#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node,int vis[],stack<int> &st,vector<int> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,st,adj);
        }
    }

    st.push(node);
}


vector<int> topoSort(int V,vector<int> adj[]){
    int vis[6] = {0};
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    } 

    return ans;
}

int main()
{   
    int n;
    cin>>n;
    vector<int> adj[6];

    for(int i=0;i<6;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
    }
    
   
    vector<int> ans;
    ans = topoSort(6,adj);

    for(auto it: ans){
        cout<<it<<" ";
    }

    return 0;
}



// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;


// void dfs(int node,vector<int> adj[],int vis[],stack<int> st){
//     vis[node] = 1;

//     for(auto it: adj[node]){
//         if(!vis[it]){
//             dfs(it, adj, vis, st);
//         }
//         st.push(node);
//     }
// }

// vector<int> topoSort(vector<int> adj[],int vis[],int n){

//     vis[6] = {0};
//     stack<int> st;

//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             dfs(i,adj,vis,st);
//         }
//     }

//     vector<int> ans;

//     while(!st.empty()){
//         ans.push_back(st.top());
//         st.pop();
//     }


//     return ans;

// }

// int main()
// {      
//     vector<int> adj[6];

//     vector<int> ans;
//     int vis[6];

//     adj[2].push_back(3);
//     adj[3].push_back(1);
//     adj[4].push_back(0);
//     adj[4].push_back(1);
//     adj[5].push_back(2);
//     adj[5].push_back(0);

//     ans = topoSort(adj,vis,6);

//     for(auto i: ans){
//         cout<<i<<" ";
//     }

//     return 0;
// }