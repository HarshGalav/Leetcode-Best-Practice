class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            mp[target-nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end() && i!=mp[nums[i]]){
                
                return {i,mp[nums[i]]};
            }
        }
        return {-1,-1};
    }
};