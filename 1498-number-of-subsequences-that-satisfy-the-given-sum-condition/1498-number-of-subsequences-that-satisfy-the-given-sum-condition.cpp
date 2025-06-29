class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int s=0,e=n-1;
        int M=1e9+7;
        int ans=0;
        vector<int>Power(n);
        Power[0]=1;
        for(int i=1;i<n;i++){
            Power[i]=(2*Power[i-1])%M;
        }
        while(s<=e){
            if(nums[s]+nums[e]<=target){
                ans=(ans%M + Power[e-s])%M;
                s++;
            }
            else{
                e--;
            }
        }
        return ans;
    }
};