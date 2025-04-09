class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(auto i:nums){
            if(i<k){
                return -1;
            }
        }
        set<int>s(nums.begin(),nums.end());
        vector<int>v(s.begin(),s.end());
        int n=v.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(v[i]>k){
                ans++;
            }
        }
        return ans;
    }
};