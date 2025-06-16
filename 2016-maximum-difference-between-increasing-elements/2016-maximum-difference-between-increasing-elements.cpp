class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini=nums[0],maxd=-1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<=mini){
                mini=nums[i];
            }
            else{
                maxd=max(maxd,nums[i]-mini);
            }
        }
        return maxd;
    }
};