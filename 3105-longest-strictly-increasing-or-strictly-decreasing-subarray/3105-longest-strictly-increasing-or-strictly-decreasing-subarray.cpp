class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l=0,s=0;
        int n=nums.size();
        int ml=0,ms=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]){
                l++;
                s=0;
            }
            else if(nums[i+1]<nums[i]){
                s++;
                l=0;
            }
            else{
                l=0;
                s=0;
            }
            ml=max(ml,l);
            ms=max(ms,s);
        }
        return max(ml,ms)+1;
    }
};