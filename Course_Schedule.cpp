#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
         vector<int> adj[V];
	    
	    for(auto it:prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    int indegree[V]={0};
        
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans.size() == V) return ans;
        return {};
    }
};




int main() {
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif

        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        
        for(auto it:res) cout<<it<<" ";

    
    
    return 0;
}
