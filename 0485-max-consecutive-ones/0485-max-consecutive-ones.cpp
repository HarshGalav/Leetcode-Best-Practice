class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=INT_MIN;
        int cnt=0;
        for(auto i:nums){
            if(i==1){
                cnt++;
            }
            else{
                cnt=0;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
        
    }
};