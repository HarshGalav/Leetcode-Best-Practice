class Solution {
public:
int f(vector<int>& nums,int k){
    int r=0,l=0,count=0,cur=0;
    for(r=0;r<nums.size();r++){
        if(nums[r]%2!=0){
            cur++;
        }
        while(cur>k){
            if(nums[l]%2 !=0){
                cur--;
            }
            l++;
        }
        count+=(r-l+1);
    }
    return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
    

};