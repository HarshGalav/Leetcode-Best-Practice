class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
       vector<int>temp(n); 
       int pos=0,neg=1,ind=0;
       while(ind<n){
        if(nums[ind]>0){
            temp[pos]=nums[ind];
            ind++;
            pos=pos+2;
        }
        else{
            temp[neg]=nums[ind];
            neg+=2;
            ind++;
            
        }
       }
       return temp;
    }
};