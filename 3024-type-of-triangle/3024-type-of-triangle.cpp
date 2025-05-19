class Solution {
public:
    bool f(vector<int>nums){
        return (nums[0] + nums[1] > nums[2] && 
        nums[0] + nums[2] > nums[1] && 
        nums[1] + nums[2] > nums[0]);
    }
    string triangleType(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        if(f(nums)){

        
        if(s.size()==3){
            return "scalene";
        }
        else if(s.size()==2){
            return "isosceles";
        }
        else {
            return "equilateral";
        }
        }
        return "none";
    }
};