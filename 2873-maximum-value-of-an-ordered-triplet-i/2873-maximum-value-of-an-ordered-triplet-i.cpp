class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    maxi=max(maxi,(long long)(nums[i]-nums[j])*(long long)nums[k]);
                }
            }
        }
        return maxi;
    }
};