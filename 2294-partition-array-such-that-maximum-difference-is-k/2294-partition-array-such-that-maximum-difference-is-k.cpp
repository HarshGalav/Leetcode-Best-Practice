class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=1;
        int n=nums.size();
        int j=0;
        int count=1;
        while(i<n){
            if((nums[i]-nums[j])>k){
                count ++;
                j=i;
               
            }       
                i++;          
        }
        return count;
    }
};