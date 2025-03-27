class Solution {
public:
    int minimumIndex(vector<int>& nums) {
       map<int,int>mp1;
       map<int,int>mp2;
       
       for(auto i:nums){
        mp2[i]++;
       }
       int n=nums.size();
       for(int i=0;i<n;i++){
        int num=nums[i];
        mp2[num]--;
        mp1[num]++;
        int n1=i+1;
        int n2=n-i-1;
        if(mp1[num]>n1/2 && mp2[num]>n2/2){
            return i;
        }
       }

       return -1;

    }
};