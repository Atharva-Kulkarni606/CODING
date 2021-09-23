
#include<bits/stdc++.h>
using namespace std;

void TopologicalSort(int node,vector<int>&vis,stack<int>&st,vector<pair<int,int>>adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it.first]){
            TopologicalSort(it.first,vis,st,adj);
        }
    }
    st.push(node);

}


//SHORTEST PATH IN AN DAG GRAPH -> DIRECTED ACYCLIC GRAPH 
// USED ALGORITHM - BFS ALGORITHM 
void shortestPathDAG(int src,vector<pair<int,int>>adj[],int n,int m){
    vector<int>vis(n,0);
    stack<int>st;
    //Step-1 -> Find Topological Sort 
    for(int i = 0; i < n ; i++){
        if(!vis[i]){
            TopologicalSort(i,vis,st,adj);
        }
    }
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        //Check adj nodes
        for(auto it : adj[node]){
            if(dist[node] != INT_MAX){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }

    }

    //DISTANCE ARRAY STORES THE SHORTEST DISTANCE OF ALL THE NODES FROM SRC 

}

int main(){
    int n,m,wt;
    cin >> n >> m >> wt; 
    vector<pair<int,int>>adj[n];
    for(int  i = 0 ; i < m ; i++){
        int u,v;
        cin >> u >> v;
        //DIRECTED Acyclic graph
        adj[u].push_back({v,wt});
    }
    shortestPathDAG(adj,n,m);
    return 0;
}