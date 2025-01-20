class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=target-nums[i];
            if(mp.find(num)!=mp.end()){
                return {mp[num],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
        
    }
};