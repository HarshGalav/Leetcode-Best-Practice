class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int>temp;
        for(auto i:nums){
            temp.push_back(i%2);
        }
        int ans1=0,ans2=0,ans3=1,ans4=1;
        for(auto i:temp){
            if(i==0){
                ans1++;
            }
            if(i==1){
                ans2++;
            }
        }
        int eve=0,od=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==0){
                eve=i;
                break;
            }
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i]==1){
                od=i;
                break;
            }
        }
        for(int i=eve+1;i<temp.size();i++){
            if(temp[i]!=temp[eve]){
                ans3++;
                eve=i;
            }
        }
         for(int i=od+1;i<temp.size();i++){
            if(temp[i]!=temp[od]){
                ans4++;
                od=i;
            }
        }
        return max({ans1,ans2,ans3,ans4});
    }
};