class Solution {
public:
    int f2(vector<int>& nums,int mid){
        int sum=0;
        for(auto i:nums){
            sum+=ceil((double)i/(double)mid);
        }
        return sum;
    }
    int f(int l,int r,vector<int>& nums,int threshold){
        int ans =-1;
        while(l<=r){
            int mid=(l+r)/2;
            int val=f2(nums,mid);
            if(val>threshold){
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=*max_element(nums.begin(),nums.end());
        return f(1,maxi,nums,threshold);
    }
};