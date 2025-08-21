class Solution {
public:
    int f(vector<int>& nums,int k){
        unordered_map<int,int>mp;
        int left=0,right=0,ans=0,n=nums.size();
        for(right=0;right<n;right++){
            mp[nums[right]]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};