class Solution {
public:
int f(int n){
    int ans=0;
    while(n>0){
        ans=ans+n%10;
        n=n/10;
    }
    return ans;
}
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        int result=-1;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
           int ds=f(nums[i]);
           if(mp.count(ds)){
            result=max(result,nums[i]+mp[ds]);
           }
           mp[ds]=max(mp[ds],nums[i]);
        }
        return result;
    }
};