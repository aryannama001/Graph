#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int node,int vis[],int pathVis[], vector<int> adj[]){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj))  return true;
            }else if(pathVis[it]) return true;
        }
        
        pathVis[node]=0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathVis[V] = {0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true) return true;
            }
        }
        
        return false;
    }
};


int main() {
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif

    
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

    return 0;
}

