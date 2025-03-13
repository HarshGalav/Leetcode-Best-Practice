class Solution {
public:
    bool f(vector<int>& nums, vector<vector<int>>& queries,int k){
        vector<int>diff(nums.size(),0);
        for(int i=0;i<k;i++){
            int fi=queries[i][0];
            int se=queries[i][1];
            int th=queries[i][2];
            diff[fi]+= th;
            if(se+1 < nums.size()){
                diff[se+1]-=th;
            }



        }
        int cumsum=0;
        for(int i=0;i<nums.size();i++){
            cumsum += diff[i];
            diff[i]=cumsum;

            if(nums[i]>diff[i]){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        int flag=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                flag=1;
            }
        }
        if(flag==0){
            return 0;
        }
        int l=0,r=q-1,result=-1;

        while(l<=r){
           int mid = l + (r - l) / 2;

            if(f(nums,queries,mid+1)){
                result=mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        
        return result;
    }
};