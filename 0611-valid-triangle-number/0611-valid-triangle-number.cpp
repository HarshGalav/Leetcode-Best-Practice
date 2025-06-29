class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        if(n<3){
            return 0;
        }
        for(int k=2;k<n;k++){
            int s=0,e=k-1;
            while(s<e){
                if(nums[s]+nums[e]>nums[k]){
                    ans+= e-s;
                    e--;
                }
                else{
                    s++;
                }
            }
        }
        return ans;
    }
};