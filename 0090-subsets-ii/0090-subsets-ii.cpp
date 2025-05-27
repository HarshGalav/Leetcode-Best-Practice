class Solution {
public:
    void f(int idx,vector<vector<int>>&ans,vector<int>&temp,vector<int>nums){
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            f(i+1,ans,temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        f(0,ans,temp,nums);
        return ans;
    }
};