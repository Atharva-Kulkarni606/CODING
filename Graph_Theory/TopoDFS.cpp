#include<bits/stdc++.h>
using namespace std;


// TOPOLOGICAL SORT -> ONLY APPLICABLE FOR DAG 
// DAG -> DIRECTED ACYCLIC GRAPH 

//TOPOLOGICAL SORTING -> LINEAR ORDERING OF VERTICES SUCH THAT IF THERE IS A DIRECTED
// EDGE FROM U -> V, U ALWAYS APPEARS BEFORE V IN THAT ORDERING 

//USED DFS ALGORITHM
void topoDFS(vector<int>adj[],vector<int>&vis,stack<int>&st,int node){
    //Mark the node as visited
    vis[node] = 1;
    //Traverse the adjacent nodes of current node
    for(auto it : adj[node]){
        if(!vis[it]){
            topoDFS(adj,vis,st,it);
        }
    }
    //Push the node in the stack after the dfs call is over
    st.push(node);
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<int>adj[n];
    for(int  i = 0 ; i < m ; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    stack<int>st;
    for(int i = 0; i < n ; i++){
        if(!vis[i]){
            topoDFS(adj,vis,st,i);
        }
    }
   
    return 0;
}