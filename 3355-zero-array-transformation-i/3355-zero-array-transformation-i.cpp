class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>temp(n,0);
        for(auto i:queries){
            temp[i[0]]+=1;
            if((i[1]+1)<n){
            temp[i[1]+1]-=1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+temp[i];
            temp[i]=sum;
        }
        for(int i=0;i<n;i++){
            if((nums[i]-temp[i])>0){
                return false;
            }
        }
        return true;
    }
};