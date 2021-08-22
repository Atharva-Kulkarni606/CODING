#include<bits/stdc++.h>
using namespace std;

//DFS-ALGORITHM IN AN UNDIRECTED GRAPH

void DFS(vector<int>adj[], vector<int>&vis,int node){
    cout << node << " ";
    vis[node] = 1;
    //Check for adj nodes of "node"
    for(auto it : adj[node]){
        if(!vis[it]){
            DFS(adj,vis,it);
        }

    }
    
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<int>adj[n];
    for(int  i = 0 ; i < m ; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>vis(n + 1,0);

    //Assuming 1 based indexing
    for(int i = 1; i <= n ; i++){
        if(!vis[i]){
            DFS(adj,vis,i);
        }
    }

    return 0;
}