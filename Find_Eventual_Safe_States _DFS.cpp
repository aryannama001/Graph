#include <bits/stdc++.h>
using namespace std;




class Solution {
      bool dfs(int node,int vis[],int pathVis[], vector<int> adj[],int check[]){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj,check))  return true;
            }else if(pathVis[it]) return true;
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathVis[V] = {0};
        int check[V]={0};
        
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,adj,check);
            }
        }
         for(int i=0;i<V;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }

        
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
}

