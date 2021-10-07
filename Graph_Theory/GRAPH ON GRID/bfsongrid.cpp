#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

//BFS ON GRID
// GIVEN A N X N GRID....GIVEN A SRC POINT(X AND Y CORDINATE) ..FIND THE DIST FROM THAT POINT
// TO EVERY OTHER POINT

bool isValid(vector<vector<char>>&arr,vector<vector<int>>&vis,int x,int y) {

	if(x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size()){
		return false;
	} 
	if(vis[x][y] == 1) 
		return false;
	return true;

}


void bfs(vector<vector<char>>arr,vector<vector<int>>&vis,vector<vector<int>>&dist,int x,int y) {
	queue<pair<int,int>>q;
	q.push({x,y});
	vis[x][y] = 1;
	dist[x][y] = 0;
	while(!q.empty()) {
		int currx = q.front().first;
		int curry = q.front().second;
		q.pop();
		for(int i = 0;i < 4; i++) {
			int newx = currx + dx[i];
			int newy = curry + dy[i];
			if(isValid(arr,vis,newx,newy)) {
				dist[newx][newy] = dist[currx][curry] + 1;
				vis[newx][newy] = 1;
				q.push({newx,newy});
			}
		}
	}

}

int main() {

	int n;
	cin >> n;
	vector<vector<char>>mat(n , vector<char>(n,0));
	for(int i = 0; i < n ; i++) {
		vector<char>v(n,0);
		for(int j = 0;  j < n ; j++) {
			char x;
			cin >> x;
			v[j] = x;
		}
		mat[i] = v;
	}
	vector<vector<int>>vis(n , vector<int>(n,0));
	vector<vector<int>>dist(n , vector<int>(n,0));
		
	int srcx =0, srcy = 1;

    bfs(mat,vis,dist,srcx,srcy);
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n ; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}