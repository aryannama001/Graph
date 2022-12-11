#include <bits/stdc++.h>
using namespace std;



class Solution {
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> grid,vector<pair<int,int>> &v,int row0,int col0){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        v.push_back({row-row0,col-col0});
        int n = grid.size();
       int m = grid[0].size();
        
         int dr[] ={-1,0,1,0};
    	 int dc[] = {0,1,0,-1}; 
    	 
    	 while(!q.empty()){
    	     int r = q.front().first;
             int c = q.front().second;
    	     q.pop();
    	     
    	     for(int i=0;i<4;i++){
    	         int nrow = r + dr[i];
    	         int ncol = c + dc[i];
    	         
    	         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
    	             vis[nrow][ncol]=1;
    	             q.push({nrow,ncol});
    	             v.push_back({nrow-row0,ncol-col0});
    	         }
    	     }
    	 }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       
       vector<vector<int>> vis(n,vector<int>(m,0));
       set<vector<pair<int,int>>> st;
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(!vis[i][j] && grid[i][j]==1){
                   vector<pair<int,int>> v;
                   bfs(i,j,vis,grid,v,i,j);
                   st.insert(v);
               }
           }
       }
       
       int ans = st.size();
       return ans;
    }
};



int main() {
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif

   
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
}
