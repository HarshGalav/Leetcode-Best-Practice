class Solution {
public:
    int dfs(int curr,int parent,unordered_map<int,vector<int>>&mp,vector<bool>&hasApple){
        int time=0;
        for(int nb:mp[curr]){
            if(nb!=parent){
                int timefchild=dfs(nb,curr,mp,hasApple);
                if(timefchild || hasApple[nb]){
                    time+=timefchild+2;
                }
            }
        }
        return time;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>mp;
        for(auto i:edges){
            int a=i[0];
            int b=i[1];
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        return dfs(0,-1,mp,hasApple);
    }
};