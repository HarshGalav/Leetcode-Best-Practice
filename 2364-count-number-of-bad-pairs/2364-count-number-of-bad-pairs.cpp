class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-i]++;

        }
        for(auto i:mp){
            long long cnt=i.second*(i.second-1)/2;
            ans=ans+cnt;
        }
        return ((long long)(nums.size() *( nums.size()-1))/2)-ans;

    }
};