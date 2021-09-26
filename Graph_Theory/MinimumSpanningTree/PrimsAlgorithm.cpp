#include<bits/stdc++.h>
using namespace std;

//PRIMS ALGORITHM - TO FIND THE MINIMUM SPANNING TREE OF A GRAPH
//BRUTE FORCE -> TIME -> O(N^2)
int PrimsAlgorithm(vector<pair<int,int>>adj[],int n,int src){ 
    vector<int>key(n,INT_MAX);
    vector<bool>mst(n,false);
    vector<int>parent(n,-1);
    key[0] = 0;
    for(int count = 1; count < n; ++count){
            //1st
            int mini_val = INT_MAX, mini_idx = -1;
            for(int i = 1 ; i < n ; i++){
                if(mst[i] == false && mini_val > key[i]){
                    mini_val = key[i];
                    mini_idx = i;
                }
            }
            mst[mini_idx] = true;
            //mini_idx is a node now 
            for(auto it : adj[mini_idx]){
                int value = it.first;
                int weight = it.second;
                if(mst[value] == false && weight < key[value]){
                    key[value] = weight;
                    parent[value] = mini_idx;
                }
            }
    }
}


//OPTIMISED -> HEAP -> TIME -> O(N + E)
// int PrimsAlgorithmFast(vector<pair<int,int>>adj[],int n,int src){ 
//     vector<int>key(n,INT_MAX);
//     vector<bool>mst(n,false);
//     vector<int>parent(n,-1);
//     key[0] = 0;
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     pq.push({0,0});
//     for(int count = 1; count < n; ++count){
//         int mini_idx =0;
//         mini_idx = pq.top().second;
//         pq.pop();
//             //1st
//         mst[mini_idx] = true;
//         //mini_idx is a node now 
//         for(auto it : adj[mini_idx]){
//             int node = it.first;
//             int weight = it.second;
//             if(mst[node] == false && weight < key[node]){
//                 key[node] = weight;
//                 pq.push({key[node],node});
//                 parent[node] = mini_idx;
//             }
//         }
//     }

// }

int main(){
    int n,m,wt;
    cin >> n >> m;
    vector<pair<int,int>>adj[n];
    for(int i = 0 ; i < m; i++){
        int u,v,wt; 
        cin >> u >> v >> wt;
        //Undirected Graph
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int src = 0;
    cout << PrimsAlgorithm(adj,n,src);

    return 0;
}