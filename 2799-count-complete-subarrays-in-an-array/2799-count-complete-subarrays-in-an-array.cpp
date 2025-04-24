class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int x=nums.size();
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int n=mp.size();
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<int,int>mp1;
        while(j<x){
            mp1[nums[j]]++;
            while(mp1.size()==n){
                ans+=x-j;
                mp1[nums[i]]--;
                if(mp1[nums[i]]==0){
                    mp1.erase(nums[i]);
                }
                i++;

            }

            j++;

        }
        return ans;
        
    }
};