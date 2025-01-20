class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=1;
        int cnt=1;
        if(nums.size()==0){
            return 0;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]==nums[i-1]+1){
                cnt++;
            }
            else{
                cnt=1;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};