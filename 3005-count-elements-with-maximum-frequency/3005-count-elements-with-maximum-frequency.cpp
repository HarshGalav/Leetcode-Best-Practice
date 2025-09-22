class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int sum=0;
        int cur_max=0;
        for(auto i:mp){
            if(i.second>cur_max){
                cur_max=i.second;
                sum=i.second;
            }
            else if(i.second == cur_max){
                sum+=i.second;
            } 
        }
        return sum;
    }
};