#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node,int vis[],vector<int> adj[],stack<int> &st){
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,vis,adj,st);
        }
        
        st.push(node);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    int vis[V]={0};
	    stack<int> st;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,adj,st);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};



int main() {
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
  
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        for(auto it:res) cout<<it<<" ";
    
    
    return 0;
}
