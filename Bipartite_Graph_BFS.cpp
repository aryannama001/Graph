#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(int i,vector<int> &color,vector<int> adj[]){
        color[i]=0;
        queue<int> q;
        q.push(i);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }else if(color[it]==color[node]){
                    return false;
                }
            }
            
        }
            return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(solve(i,color,adj)==false) return false;
	        }
	    }
	    
	    return true;
	}

};

int main(){
	 #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
			int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	
	return 0;
}
