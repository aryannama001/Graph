#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[V];
	    
	    for(auto it:prerequisites){
	        adj[it.first].push_back(it.second);
	    }
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
        
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(cnt == V) return true;
        return false;
	}
};

int main(){
	        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	
	return 0;
}
