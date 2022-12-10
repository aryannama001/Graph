#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool detectCycle(int node,int vis[],vector<int> adj[]){
        vis[node]=1;

        queue<pair<int,int>> q;
        q.push({node,-1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }else if(parent != it){
                    return true;
                }
            }

          
        }
          return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectCycle(i,vis,adj)) return true;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    
    return 0;
}
