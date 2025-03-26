class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(),n=grid[0].size();
        vector<int>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int mid=(m*n)/2;
        int ans=0;
        for(int i=0;i<(m*n);i++){
            if((abs(v[i]-v[mid]))%x!=0){
                return -1;
            }
            ans+=abs(v[i]-v[mid])/x;
        }
        return ans;
    }
};