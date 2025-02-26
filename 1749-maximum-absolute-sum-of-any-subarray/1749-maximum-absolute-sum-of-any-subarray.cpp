class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            
            sum=sum+nums[i];
            if(sum<0){
                sum=0;
            }
            maxi=max(maxi,sum);
        }   
        int mini=INT_MAX;
        int sum2=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum>0){
                sum=0;
            }
            mini=min(mini,sum);
        }
        mini=abs(mini);
        return max(mini,maxi);
    }
};