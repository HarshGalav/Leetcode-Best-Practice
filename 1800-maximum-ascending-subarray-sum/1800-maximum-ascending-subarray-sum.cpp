class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxsum=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<nums[i+1]){
                sum=sum+nums[i];
            }
            else{
                sum=sum+nums[i];
                maxsum=max(maxsum,sum);
                sum=0;
            }
        }
        return maxsum;
    }
};