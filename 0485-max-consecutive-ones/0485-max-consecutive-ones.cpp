class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
       
        int ans=0;
        int l=0;
        for(int i=0;i<n;i++){
            
            if(nums[i]==1){
                l++;
                ans=max(ans,l);
                
            }
            else{
                l=0;
            }
            

        }
        return ans;
    }
};