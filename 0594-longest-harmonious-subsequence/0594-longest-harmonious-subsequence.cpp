class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,ans=0;
        for(int r=0;r<n;r++){
            while(nums[r]-nums[l]>1){
                l++;
            }
            if(nums[r]-nums[l]==1){
                ans=max(ans,r-l+1);
            }
        }
        return ans;
       
    }
};