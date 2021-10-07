#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


bool isValid(vector<vector<int>>&vis,int x,int y,int n,int m) {

    if(x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    if(vis[x][y] == 1) {
        return false;
    }
    return true;
}


//first version -> code a bit lenghty
void dfs(vector<vector<int>>&vis,int x,int y,int n,int m) {
    //MARK THE NODE AS VISITED
    vis[x][y] = 1;

    cout << x << " " << y << " \n";

    //UP
    if(isValid(vis,x,y,n,m)){
        dfs(vis,x - 1,y,n,m);
    }
    //RIGHT
    if(isValid(vis,x,y,n,m)){
        dfs(vis,x,y + 1,n,m);
    }
    //DOWN 
    if(isValid(vis,x,y,n,m)){
        dfs(vis,x + 1,y,n,m);
    }
    //LEFT
    if(isValid(vis,x,y,n,m)){
        dfs(vis,x,y - 1,n,m);
    }
    
}

//REFACTORED DFS -> SMALL CODE
// CHECK GLOBAL ARRAYS DX AND DY AT THE TOP 
void dfs(vector<vector<int>>&vis,int x,int y,int n,int m) {
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        if(isValid(vis,x + dx[i],y + dy[i],n,m)) {
            dfs(vis,x + dx[i],y + dy[i],n,m);
        }
    }
}



int main() {
    int n,m;
    //n x m grid
    cin >> n >> m;
    //0 BASED INDEXING
    vector<vector<int>>vis(n,vector<int>(m,0));    
    //n x m grid 
    dfs(vis,0,0,n,m);
    return 0;
}