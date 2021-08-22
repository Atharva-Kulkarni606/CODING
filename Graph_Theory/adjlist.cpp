#include<bits/stdc++.h>
using namespace std;

//Taking input in a graph

int main(){
    //n - No of nodes, m - edges
    int n,m,wt;
    cin >> n >> m >> wt; 
    //Make a adj matrix 
   vector<pair<int,int>>adj[n];
    //Take input for edges
    for(int i = 0 ; i < m ; i++){
        int u,v;
        cin >> u >> v;
        //For undirected
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});

        //For directed Graph
        // adj[u].push_back({v,wt});
    }

    //Print it
    for(int i = 0; i < n;  i++){
        cout << "ADJACENT NODES OF NODE " << i << " ARE " << adj[i].first << "WITH EDGE WEIGHT " << adj[i].second << endl;
     }

    return 0;
}