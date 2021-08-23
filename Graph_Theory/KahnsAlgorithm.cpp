#include<bits/stdc++.h>
using namespace std;


// TOPOLOGICAL SORT -> ONLY APPLICABLE FOR DAG 
// DAG -> DIRECTED ACYCLIC GRAPH 


//TOPOLOGICAL SORTING -> LINEAR ORDERING OF VERTICES SUCH THAT IF THERE IS A DIRECTED
// EDGE FROM U -> V, U ALWAYS APPEARS BEFORE V IN THAT ORDERING 

//USED BFS ALGORITHM -> KNOWN KAHN'S ALGORITHM

void topoBFS(vector<int>adj[],vector<int>&indeg,int node,int n){
    
    //STEP 1 -> CALCULATE INDEGREE OF EACH AND EVERY VERTEX 
    for(int i = 0 ; i < n; i++){
        for(auto it : adj[i]){
            indeg[it]++;
        }
    }   

    queue<int>q;
    //STEP 2 -> PUT VERTICES WITH INDEG = 0 INTO THE QUEUE

    for(int i = 0 ; i < n ; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    //STEP 3 -> APPLY BFS 
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        //PRINT THE TOPO SORT ONE BY ONE AS U KEEP REMOVING THE NODES FROM THE QUEUE
        cout << curr << " ";
        for(auto it : adj[curr]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(indeg[it]);
            }
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>adj[n];
    //DAG
    for(int  i = 0 ; i < m ; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int>indeg(n,0);
    for(int i = 0; i < n ; i++){
        if(!indeg[i]){
            topoBFS(adj,indeg,i,n);
        }
    }
   
    return 0;
}