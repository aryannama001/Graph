#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        st.erase(startWord);

        while(!q.empty()){
        	string word = q.front().first;
        	int len = q.front().second;
        	q.pop();

        	if(word == targetWord) return len;

        	for(int i=0;i<word.size();i++){
        		char org = word[i];
        		for(char ch ='a';ch<='z';ch++){
        			word[i]=ch;
        			if(st.find(word)!=st.end()){
        				q.push({word,len+1});
        				st.erase(word);
        			}
        		}
        		word[i]=org;
        	}
        }

        return 0;
    }
};

int main(){
	 #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
     #endif
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
	return 0;
}
