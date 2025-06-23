class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp=nums;
        sort(nums.begin(),nums.end());
        int idx_r=-1,idx_l=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=temp[i]){
                idx_l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=temp[i]){
                idx_r=i;
                break;
            }
        }
        if(idx_r ==-1 || idx_l==-1){
            return 0;
        }
        return idx_r-idx_l+1;
    }
};