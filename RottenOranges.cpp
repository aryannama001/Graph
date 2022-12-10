#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans = grid;
        queue<pair<pair<int,int>,int>> q;

        int fresh =0;
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		if(grid[i][j]==2){
        			q.push({{i,j},0});
        		}
        		if(grid[i][j]==1) fresh++;
        	}
        }

        int time =0;
        int cnt=0;

        int dr[] ={-1,0,1,0};
		int dc[] = {0,1,0,-1};

        while(!q.empty()){
        	int row = q.front().first.first;
        	int col = q.front().first.second;
        	int t = q.front().second;
        	q.pop();
        	time = max(t,time);
        	for(int i=0;i<4;i++){
        		int nrow = row+dr[i];
        		int ncol = col + dc[i];

        		if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=2 && grid[nrow][ncol]==1){
        			ans[nrow][ncol] = 2;
        			cnt++;
        			q.push({{nrow,ncol},t+1});
        		}
        	}
        }

        if(fresh!=cnt) return -1;

        return time;


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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	
	return 0;
}
