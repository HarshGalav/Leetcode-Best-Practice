class Solution {
public:
    int find(int mid,vector<int>& nums){
        int total=0;
        int temp=1;
        for(auto i:nums){
            if(i+total<=mid){
                total=i+total;
            }
            else{
                temp++;
                total=i;
            }
        }
        return temp;
    }
    int f(int l,int h,vector<int>& nums,int k){
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            int cal=find(mid,nums);
            if(cal>k){
                l=mid+1;
            }
            else{
                ans=mid;
                h=mid-1;
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);

        return f(l,h,nums,k);
    }
};