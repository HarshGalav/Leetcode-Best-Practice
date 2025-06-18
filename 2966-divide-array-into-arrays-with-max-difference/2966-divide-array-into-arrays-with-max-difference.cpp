class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i=i+3){
            if(nums[i+2]-nums[i]<=k){
                vector<int>subarray(nums.begin()+i,nums.begin()+i+3);
                ans.push_back(subarray);
            }
            else{
                return {};
            }
        }
        return ans;

    }
};