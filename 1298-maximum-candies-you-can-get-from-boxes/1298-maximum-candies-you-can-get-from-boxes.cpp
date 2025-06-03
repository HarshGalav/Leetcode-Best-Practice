class Solution {
public:
    int f(int idx,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes,int n,vector<int>&visited,unordered_set<int>&foundbox){
        if(visited[idx]==1){
            return 0;
        }
        if(status[idx]==0){
            foundbox.insert(idx);
            return 0;
        }
        visited[idx]=1;
        int c=candies[idx];
        for(auto& i:containedBoxes[idx]){
            c+=f(i,status,candies,keys,containedBoxes,initialBoxes,n,visited,foundbox);

        }
        for(auto& k:keys[idx]){
            status[k]=1;
            if(foundbox.count(k)){
                c+=f(k,status,candies,keys,containedBoxes,initialBoxes,n,visited,foundbox);
            }
        }
        return c;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<int>visited(n,0);
        unordered_set<int>foundbox;
        int ans=0;
        for(auto i:initialBoxes){
            ans+=f(i,status,candies,keys,containedBoxes,initialBoxes,n,visited,foundbox);
        }
        return ans;
    }
};