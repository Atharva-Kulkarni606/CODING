#include<bits/stdc++.h>
using namespace std;


// STRONGLY CONNECTED COMPONENTS -> A COMPONENT IS SAID TO BE A SCC IF EACH VERTEX/NODE
// IS REACHABLE FROM EVERY OTHER VERTEX IN THAT COMPONENT 

//KOSARAJU'S ALGORITHM -> USED TO FIND STRONGLY CONNECTED COMPONENTS IN  A GRAPH
//NO OF STRONGLY CONNECTED COMPONENTS -> FIND



void Topo(vector<int>adj[],int node,int n,vector<int>&vis,stack<int>&st) {
    
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            Topo(adj,it,n,vis,st);
        }
    }
    st.push(node);

}

void dfs(vector<int>adj[],int node,int n,vector<int>&vis){
     vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(adj,it,n,vis);
        }
    }
}

void Transpose(vector<int>adj[],vector<int>transposed[],int n) {

    for(int i = 0 ; i < n; i++) {
        for(auto it : adj[i]){
            transposed[it].push_back(i);
        }
    }


}


void Kosaraju(vector<int>adj[],int n,int node,vector<int>&vis,int &ans) {

    //STEP-1 -> FIND ORDERING (TOPOSORT(NOT ACTUALLY (ONLY TO UNDERSTAND)))
    //USING DFS
    stack<int>st;
    for(int i = 0; i < n ; i++){
        if(!vis[i]){
            Topo(adj,node,n,vis,st);
        }
    }

    //STEP-2 -> TRANSPOSE THE GRAPH(REVERSE THE EDGES)
    vector<int>transposed[n];
    Transpose(adj,transposed,n);

    //APPLY DFS ACC TO FINISHING TIME
    vector<int>vis2(n,0);
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis2[node]) {
            ans++;
            dfs(transposed,node,n,vis2);
        }

    }


}



int main() {
    int n,m;
    cin >> n >> m;
    //0 based indexing
    vector<int>adj[n];
    while(m--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 0;
    vector<int>vis(n,0);
     Kosaraju(adj,n,0,vis,ans);

}