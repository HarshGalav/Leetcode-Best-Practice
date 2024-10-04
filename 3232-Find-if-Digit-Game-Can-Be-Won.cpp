class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int ones=0;
        int twos=0;
        for(auto i:nums){
            int temp=i;
            if(i/10 ==0){
                ones=ones+temp;
            }
            else{
                twos=twos+temp;
            }
        }
        if(ones==twos){
            return false;
        }
        return true;
    }
};