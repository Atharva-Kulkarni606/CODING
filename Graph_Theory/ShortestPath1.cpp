
#include<bits/stdc++.h>
using namespace std;


//SHORTEST PATH IN AN UNDIRECTED GRAPH -> UNIT WEIGHTS
// USED ALGORITHM - BFS ALGORITHM 


void ShortestPath(vector<int>adj[],vector<int>&dist){
    
    queue<int>q;
    q.push(0);
    //Dist from src to node0 is 0
    dist[0] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto it : adj[curr]){
            if(dist[curr] + 1 < dist[it]){
                dist[it] = dist[curr] + 1;
                q.push(it);
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
    vector<int>dist(n,INT_MAX);
    ShortestPath(adj,dist);

    return 0;
}