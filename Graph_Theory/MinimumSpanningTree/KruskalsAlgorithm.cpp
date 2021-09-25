#include<bits/stdc++.h>
using namespace std;

void makeSet(vector<int>&parent,vector<int>&rank) {
    for(int i = 1 ; i <= parent.size(); i++) {
        parent[i] = i;
        rank[i]   = 0;
    }
}

//FIND PARENT OF X -> PATH COMPRESSED
int find(int x,vector<int>parent) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x],parent);
}

//UNION - > BY RANK
void Union(int a,int b,vector<int>&parent,vector<int>&rank) {

    int p1 = find(a,parent);
    int p2 = find(b,parent);

    if(rank[p1] < rank[p2]) {
        parent[p1] = p2;
    } else if(rank[p2] < rank[p1]) {
        parent[p2] = p1;
    } else {
        parent[p2] = p1;
        rank[p1]++;
    }
}



int KruskalsAlgorithm(vector<pair<int,pair<int,int>>>edges,int totalnodes,vector<int>&parent,vector<int>&rank) {
    sort(edges.begin(),edges.end());
    int minCost = 0;
    for(auto it : edges) {
            //IF THEY HAVE DIFF PARENTS -> 
            //I.E. LIE IN DIFF COMPONENTS THEN TAKE IT
        if(find(it.second.first,parent) != find(it.second.second,parent)) {
            minCost += it.first;
            //combine them using union operation
            Union(it.second.first,it.second.second,parent,rank);
        }
    }
    return minCost;
}

int main() {
    vector<pair<int,pair<int,int>>>edges;
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++) {
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({wt,{u,v}});
    }
    //ASSUMING 1 BASED INDEXING SO TOOK N + 1 SIZED PARENT AND RANK ARRAYS
    vector<int>parent(n + 1,0);
    vector<int>rank(n + 1,0);
    makeSet(parent,rank);
    //FIND THE TOTAL WT OF MIN SPANNING TREE
    //KRUSKALS ALGORITHM
    int ans = KruskalsAlgorithm(edges,n,parent,rank);

    return 0;
}