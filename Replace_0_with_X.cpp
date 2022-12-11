#include <bits/stdc++.h>
using namespace std;

class Solution{
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> mat,int n,int m){
        vis[row][col]=1;
        
        int dr[] ={-1,0,1,0};
	    int dc[] = {0,1,0,-1}; 
	    
	    for(int i=0;i<4;i++){
	        int nrow = row + dr[i];
	        int ncol = col + dc[i];
	        
	        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
	            dfs(nrow,ncol,vis,mat,n,m);
	        }
	        
	    }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++){
            if(!vis[0][i] && mat[0][i]=='O'){
                dfs(0,i,vis,mat,n,m);
            }
            if(!vis[n-1][i] && mat[n-1][i]=='O')
            dfs(n-1,i,vis,mat,n,m);
        }
        
          for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat,n,m);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O')
            dfs(i,m-1,vis,mat,n,m);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]) mat[i][j]='X';
            }
        }
        
        return mat;
        
        
        
    }
    
    
};


int main(){
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    
    return 0;
}
