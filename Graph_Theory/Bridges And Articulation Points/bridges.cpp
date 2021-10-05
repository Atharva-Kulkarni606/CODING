#include<bits/stdc++.h>
using namespace std;

//GLOBAL VAR -> BY DEFAULT ZERO
int timer;

void dfs(vector<int>adj[],vector<int>&vis,vector<int>&in,vector<int>&low,int node,int par) {
    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;
    for(auto it : adj[node]) {
        if(it == par) {
            continue;
        }
        //its visited
        if(vis[it] == 1) {
            //BACKEDGE BETWEEN -> (NODE -> IT)
            low[node] = min(low[node],in[it]);
        } else {
            //FORWARD EDGE BETWEEN -> (NODE -> IT)
            //NOT VISITED CALL DFS
            dfs(adj,vis,in,low,it,node);
            low[node] = min(low[node],low[it]);
            if(low[it] > in[node]){
                cout << "BRIDGE FROM -> " << node << " " << it << endl;
            }
        }

    }


}

int main() {
    int n,m;
    cin >> n >> m;
    //o based indexing
    vector<int>adj[n];
    while(m--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    vector<int>in(n,0);
    vector<int>low(n,0);

    for(int i = 0; i < n; i++) {
        int node = 0, par = -1;
           if(!vis[i]) {
            dfs(adj,vis,in,low,node,par);
        }
    }

    return 0;
}