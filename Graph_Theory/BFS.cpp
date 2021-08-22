#include<bits/stdc++.h>
using namespace std;

//BFS-ALGORITHM IN AN UNDIRECTED GRAPH

void BFS(vector<int>adj[], vector<int>&vis,int node){

    queue<int>q;
    q.push(node);
    vis[node] = 1;
    while(q.empty()){
        int node = q.front();
        //Go on printing the nodes that will make up ur traversal
        cout << node << " ";
        q.pop();
        //Check for adj nodes of curr node in adj list
        for(auto it : adj[node]){
            if(vis[it] == 0){
                q.push(it);
                vis[it];
            }
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
            BFS(adj,vis,i);
        }
    }

    return 0;
}