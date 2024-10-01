class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            int temp=nums[i];
            while(temp!=0){
                sum=sum+temp%10;
                temp=temp/10;
            }
            nums[i]=sum;
        }
        return *min_element(nums.begin(),nums.end());
    }
};