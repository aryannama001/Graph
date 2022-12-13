#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node,vector<int> adj[],vector<int> &ans,int vis[]){
        vis[node]=1;
        ans.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it])
                dfs(it,adj,ans,vis);
        }
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        vector<int> ans;
        dfs(0,adj,ans,vis);

        return ans;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
     #endif
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    
    return 0;
}
