class Solution{
    private:
    vector<int> topoSort(int V, vector<int> adj[]) {
	    int indegree[V]={0};
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    vector<int> ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    return ans;
	}
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            for(int j=0;j<min(s1.size(),s2.size());j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> ans = topoSort(K,adj);
        
        string res = "";
        for(auto it:ans){
            res.push_back(it+'a');
        }
        
        return res;
    }
};