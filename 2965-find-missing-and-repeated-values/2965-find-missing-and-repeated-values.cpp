class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int maxi=INT_MIN;
        int n=grid[0].size()*grid.size();
        unordered_map<int,int>mp;
        for(auto i:grid){
            for(auto j:i){
                mp[j]++;
            }
        }
        int a,b;
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                a=i;
            }
            else if(mp[i]>1){
                b=i;
            }
        }
        return {b,a};
    }
    
};