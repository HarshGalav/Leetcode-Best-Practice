class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long res=0;
        int n=nums.size();
        int srt=0;
        int cur=0;
        for(int i=0;i<n;i++){
            cur += mp[nums[i]];
            mp[nums[i]]++;
            while(cur >=k){
                res+= (n-i);
                cur -= mp[nums[srt]]-1;
                mp[nums[srt]]--;
                srt++;
            }
        }
        return res;

    }
};