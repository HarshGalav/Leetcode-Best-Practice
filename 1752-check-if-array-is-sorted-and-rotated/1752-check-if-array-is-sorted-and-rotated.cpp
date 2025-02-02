class Solution {
public:
    bool check(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                k=i+1;
            }
        }
        vector<int>nums2;
        for(int i=k;i<nums.size();i++){
            nums2.push_back(nums[i]);
        }
        for(int i=0;i<k;i++){
            nums2.push_back(nums[i]);
        }
        for(int i=0;i<nums2.size()-1;i++){
            if(nums2[i+1]<nums2[i]){
                return false;
            }
        }
        return true;
        
    }
};