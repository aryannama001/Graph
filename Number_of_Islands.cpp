#include <bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
         int n=grid.size();
        int m = grid[0].size();

        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int r = row+dr;
                    int c = col+dc;

                    if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]=='1' ){
                        vis[r][c]=1;
                        q.push({r,c});
                    }
                }
            }

        }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};

int main() {
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
   
    
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
    return 0;
}
