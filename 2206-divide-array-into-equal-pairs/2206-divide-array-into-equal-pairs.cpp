class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int sum=0;
        for(auto i:mp){
            if(i.second % 2 ==0){
                sum=sum+i.second;
            }
        }
        if(sum==nums.size()){
            return true;
        }
        return false;
    }
};