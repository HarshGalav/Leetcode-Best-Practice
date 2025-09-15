class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,Element=-1;
        for(auto num:nums){
            if(count==0){
                count=1;
                Element=num;
            }
            else if(num==Element){
                count++;
            }
            else{
                count--;
            }
        }
        return Element;
    }
};