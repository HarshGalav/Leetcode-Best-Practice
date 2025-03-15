class Solution {
public:
    bool f(vector<int>& nums,int mid,int k){
        int cnt=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <= mid){
                cnt++;
                i++;
            }
        }
        return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(nums,mid,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        return ans;
    }
    
};