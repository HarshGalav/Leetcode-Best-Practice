class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
};