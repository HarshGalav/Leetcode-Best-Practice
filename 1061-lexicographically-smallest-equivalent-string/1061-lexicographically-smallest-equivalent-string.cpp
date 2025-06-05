class Solution {
public:
    char dfs(char a,vector<int>& visited,unordered_map<char,vector<char>>mp){
        visited[a-'a']=1;
        char mini=a;
        for(auto v:mp[a]){
            if(visited[v-'a']==-1){
                mini=min(mini,dfs(v,visited,mp));
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>>mp;
        int n=s1.size();
        int m=baseStr.size();
        string ans="";
        for(int i=0;i<n;i++){
            char ch1=s1[i];
            char ch2=s2[i];
            mp[ch1].push_back(ch2);
            mp[ch2].push_back(ch1);
        }
        for(int i=0;i<m;i++){
            vector<int>visited(26,-1);
            char a=dfs(baseStr[i],visited,mp);
            ans+=a;
        }
        return ans;
        
    }
};