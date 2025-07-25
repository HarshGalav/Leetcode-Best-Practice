class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int ans=0;
        for(auto i:s){
            if(i<0){
                continue;
            }
            ans+=i;
        }
        int flag=1;
        for(auto i:s){
            if(i>=0){
                flag=-1;
            }
        }
        if(flag==1){
            return *max_element(nums.begin(),nums.end());
        }
        return ans;
    }
};