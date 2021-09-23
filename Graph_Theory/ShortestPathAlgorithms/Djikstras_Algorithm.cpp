#include<bits/stdc++.h>
using namespace std;

//WORKS FOR BOTH DIRECTED + UNDIRECTED GRAPHS
//DJIKSTRAS ALGORITHM ->  SINGLE SOURCE SHORTEST PATH ALGORITHM 
//FAILS FOR NEGATIVE WEIGHTS
//FOR IMPLEMENTATION PURPOSE I AM TAKING UNDIRECTED GRAPH

void Dijkstras(vector<pair<int,int>>adj[],int n,int src){
    //0 based indexing
    vector<int>dist(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop(); 
        //Implement bfs i.e. check for adj nodes now
        for(auto it : adj[node]){
               if(curr_dist + it.second < dist[it.first]){
                   dist[it.first] = curr_dist + it.second;
                   pq.push({dist[it.first],it.first});
               }
        }
    }

}

int main(){
    int n,m,wt;
    cin >> n >> m >> wt;
    vector<pair<int,int>>adj[n];
    for(int i = 0 ; i < m ; i++){
        int u,v,w;
        cin >> u >> v >> wt;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    //Take a dist array to store dist from src to all other nodes
    int src;
    cin >> src;
    Dijkstras(adj,n,src);


    return 0;
}