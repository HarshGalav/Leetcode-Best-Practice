class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1 && mp[nums[i]-1]==0 && mp[nums[i]+1]==0){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};