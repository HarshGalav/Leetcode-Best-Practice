class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=1;
        int cnt=1;
        if(n==0){
            return n;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                cnt=1;
            }
        }
        return maxi;

    }
};