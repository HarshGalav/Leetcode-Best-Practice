class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long n=nums.size();
        vector<long long>leftm(n);
        vector<long long>rightm(n);
        leftm[0]=nums[0];
        rightm[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            leftm[i]=max(leftm[i-1],(long long)nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            rightm[i]=max(rightm[i+1],(long long)nums[i]);
        }
        long long maxi=0;
        for(int i=1;i<n-1;i++){
            maxi=max(maxi,(leftm[i-1]-(long long)nums[i])*rightm[i+1]);
        }
        return maxi;

        
    }
};