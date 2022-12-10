#include<bits/stdc++.h>
using namespace std;

class Solution {

	void bfs(int sr,int sc,vector<vector<int>> image,vector<vector<int>> &ans,int color,int newColor){
		ans[sr][sc]=newColor;
		queue<pair<int,int>> q;
		q.push({sr,sc});

		while(!q.empty()){
			int row = q.front().first;
			int col = q.front().second;
			q.pop();

			int dr[] ={-1,0,1,0};
			int dc[] = {0,1,0,-1};

			for(int i=0;i<4;i++){
			int nrow = row + dr[i];
			int ncol = col + dc[i];
			if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && image[nrow][ncol]==color && ans[nrow][ncol]!=newColor)
				{
					ans[nrow][ncol] = newColor;
					q.push({nrow,ncol});
				}
		}


		}
	}

	void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>& ans,int color,int newColor){
		ans[sr][sc]=newColor;

		int dr[] ={-1,0,1,0};
		int dc[] = {0,1,0,-1};


		for(int i=0;i<4;i++){
			int row = sr + dr[i];
			int col = sc + dc[i];
			if(row>=0 && row<image.size() && col>=0 && col<image[0].size() && image[row][col]==color && ans[row][col]!=newColor)
				dfs(row,col,image,ans,color,newColor);
		}

	}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    	vector<vector<int>> ans=image;
    	int color = image[sr][sc]; 
    	bfs(sr,sc,image,ans,color,newColor);

    	return ans;

    }
};

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	
	return 0;
}
