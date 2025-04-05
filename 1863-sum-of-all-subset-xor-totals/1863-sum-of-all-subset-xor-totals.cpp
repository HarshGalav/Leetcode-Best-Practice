class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int t=1 <<n;
        int total=0;
        for(int mask=0;mask<t;++mask){
            int sum=0;
            for(int i=0;i<n;i++){
                if(mask & (1 << i)){
                    sum=sum^nums[i];
                }
            }
            total+=sum;
        }
        return total;

    }
};