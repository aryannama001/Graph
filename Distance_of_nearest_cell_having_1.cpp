#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	  int n = grid.size();
	  int m = grid[0].size();
	  
	  vector<vector<int>> vis(n,vector<int>(m,0));
	  vector<vector<int>> dist(n,vector<int>(m,0));
	  
	 queue<pair<pair<int,int>,int>> q;
	 for(int i=0;i<n;i++){
	     for(int j=0;j<m;j++){
	         if(grid[i][j]==1){
	             vis[i][j]=1;
	             q.push({{i,j},0});
	         }
	     }
	 }
	 
	 int dr[] ={-1,0,1,0};
	 int dc[] = {0,1,0,-1}; 
	 
	 while(!q.empty())
	 {
	     int row = q.front().first.first;
	     int col = q.front().first.second;
	     int step = q.front().second;
	     q.pop();
	     
	     dist[row][col]=step;
	     
	     for(int i=0;i<4;i++){
	         int nrow = row + dr[i];
	         int ncol = col + dc[i];
	         
	         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
	             vis[nrow][ncol]=1;
	             q.push({{nrow,ncol},step+1});
	         }
	     }
	     
	 }
	 
	 return dist;
	}
};

int main(){
		#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	    #endif
	
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	
	return 0;
}
