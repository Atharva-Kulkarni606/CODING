#include<bits/stdc++.h>
using namespace std;

//Taking input in a graph

int main(){
    //n - No of nodes, m - edges
    int n,m;
    cin >> n >> m;

    //Make a adj matrix 
    int adj[n + 1][n + 1];
    //Fill it with 0
    memset(adj,0,sizeof(adj));
    //Take input for edges
    for(int i = 0 ; i < m ; i++){
        int u,v;
        cin >> u >> v;

        //For undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;

        //For directed Graph
        // adj[u][v] = 1;
    }

    //Print it
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j  < n  ; j++){
            if(adj[i][j] == 1){
                cout << "EDGE " << i << "->" << j << endl;
            }  
        }
    }
    return 0;
}